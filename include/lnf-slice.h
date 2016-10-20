#ifndef __LNF_SLICE__
#define __LNF_SLICE__

#include <stddef.h>

#ifndef __LNF_TYPES_H_INSIDE__
#error You cannot include this. Please include lnf-types.h
#endif // __LNF_TYPES_H_INSIDE__

typedef struct _lnf_slice lnf_slice;

struct _lnf_slice
{
  void *_buf;
  size_t _typesize;
  size_t _len;
  size_t _cap;
};

int lnf_slice_init (lnf_slice * self, size_t typesize, size_t len,
		    size_t cap);

void lnf_slice_fin (lnf_slice * self);

size_t lnf_slice_len (lnf_slice self);

size_t lnf_slice_cap (lnf_slice self);

lnf_slice lnf_slice_append (lnf_slice former, lnf_slice latter);

lnf_slice lnf_slice_reslice (lnf_slice self, ptrdiff_t start, ptrdiff_t end);

lnf_slice lnf_slice_from_array (void *array, size_t nmemb, size_t size,
				ptrdiff_t start, ptrdiff_t end);

#endif // __LNF_SLICE__
