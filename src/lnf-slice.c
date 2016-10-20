#include <lnf-types.h>

#include <stdlib.h>
#include <string.h>

int
lnf_slice_init (lnf_slice * self, size_t typesize, size_t len, size_t cap)
{
  self->_buf = calloc (cap, typesize);

  if (self->_buf == NULL)
    {
      self->_typesize = typesize;
      self->_len = 0;
      self->_cap = 0;
      return -1;
    }

  self->_typesize = typesize;
  self->_len = len;
  self->_cap = cap;
  return 0;
}

void
lnf_slice_fin (lnf_slice * self)
{
  self->_typesize = 0;
  self->_len = 0;
  self->_cap = 0;
  free (self->_buf);
}

size_t
lnf_slice_len (lnf_slice self)
{
  return self._len;
}

size_t
lnf_slice_cap (lnf_slice self)
{
  return self._cap;
}

lnf_slice
lnf_slice_append (lnf_slice former, lnf_slice latter)
{
  lnf_slice slice;

  slice._buf = NULL;
  slice._typesize = 0;
  slice._len = 0;
  slice._cap = 0;

  if (former._typesize != latter._typesize)
    {
      return slice;
    }

  slice._typesize = former._typesize;
  slice._len = former._len + latter._len;
  slice._cap = 2 * slice._len;
  slice._buf = calloc (slice._typesize, slice._cap);

  const size_t former_size = former._typesize * former._len;
  memcpy (slice._buf, former._buf, former_size);
  const size_t latter_size = latter._typesize * latter._len;
  memcpy (slice._buf + former_size, latter._buf, latter_size);

  return slice;
}

lnf_slice
lnf_slice_reslice (lnf_slice self, ptrdiff_t start, ptrdiff_t end)
{
  if (start < 0)
    {
      start = 0;
    }
  if (end < 0)
    {
      end = self._len;
    }
  lnf_slice slice;
  slice._buf = NULL;
  slice._typesize = 0;
  slice._len = 0;
  slice._cap = 0;

  if ((start > end) || ((size_t) end > self._len))
    {
      return slice;
    }

  slice._typesize = self._typesize;
  slice._len = end - (start - 1);
  slice._cap = 2 * slice._len;
  slice._buf = calloc (slice._cap, slice._typesize);

  memcpy (slice._buf, self._buf + (self._typesize * start),
	  self._typesize * (end - start));

  return slice;
}

lnf_slice
lnf_slice_from_array (void *array, size_t nmemb, size_t typesize,
		      ptrdiff_t start, ptrdiff_t end)
{
  if (start < 0)
    {
      start = 0;
    }
  if (end < 0)
    {
      end = nmemb;
    }

  lnf_slice slice;
  slice._buf = NULL;
  slice._typesize = 0;
  slice._len = 0;
  slice._cap = 0;

  if ((start > end) || ((size_t) end > nmemb))
    {
      return slice;
    }

  const size_t len_new_slice = end - start;
  const size_t cap_new_slice = 2 * len_new_slice;
  lnf_slice_init (&slice, typesize, len_new_slice, cap_new_slice);

  memcpy (slice._buf, array + (typesize * start), typesize * nmemb);

  return slice;
}
