#include <stdint.h>
#include <stdio.h>

#include <lnf-types.h>


int
test_slice_init ()
{
  lnf_slice slice;

  if (lnf_slice_init (&slice, sizeof (uint32_t), 5, 5) != 0)
    {
      fprintf (stderr, "%s:%d:%s - Failed to init a slice.\n", __FILE__,
	       __LINE__, __func__);
      return -1;
    }

  uint32_t *as_uint32_t_arr = (uint32_t *) slice._buf;
  as_uint32_t_arr[4] = 32;

  lnf_slice_fin (&slice);

  return 0;
}

int
test_slice_append ()
{
  lnf_slice slice1, slice2;
  lnf_slice_init (&slice1, sizeof (uint32_t), 3, 5);
  lnf_slice_init (&slice2, sizeof (uint32_t), 4, 10);

  uint32_t *as_uint32_t_arr1 = (uint32_t *) slice1._buf;
  uint32_t *as_uint32_t_arr2 = (uint32_t *) slice2._buf;

  as_uint32_t_arr1[0] = 0;
  as_uint32_t_arr1[1] = 1;
  as_uint32_t_arr1[2] = 2;

  as_uint32_t_arr2[0] = 3;
  as_uint32_t_arr2[1] = 2;
  as_uint32_t_arr2[2] = 1;
  as_uint32_t_arr2[3] = 0;

  lnf_slice slice_appended = lnf_slice_append (slice1, slice2);
  lnf_slice_fin (&slice1);
  lnf_slice_fin (&slice2);

  if (lnf_slice_len (slice_appended) != 7)
    {
      fprintf (stderr, "%s:%d:%s - Failed to append slice.\n", __FILE__,
	       __LINE__, __func__);
      return -1;
    }

  uint32_t *as_uint32_t_arr3 = (uint32_t *) slice_appended._buf;
  if (as_uint32_t_arr3[3] != 3)
    {
      fprintf (stderr,
	       "%s:%d:%s - Failed to append slice. as_uint32_t_arr3[3]:%d\n",
	       __FILE__, __LINE__, __func__, as_uint32_t_arr3[3]);
      return -1;
    }

  lnf_slice_fin (&slice_appended);

  return 0;
}

int
test_slice_append_wrong ()
{
  lnf_slice slice1, slice2;
  lnf_slice_init (&slice1, sizeof (uint16_t), 3, 5);
  lnf_slice_init (&slice2, sizeof (uint32_t), 4, 10);

  lnf_slice slice_appended = lnf_slice_append (slice1, slice2);
  lnf_slice_fin (&slice1);
  lnf_slice_fin (&slice2);

  if (slice_appended._typesize != 0)
    {
      fprintf (stderr,
	       "%s:%d:%s - Failed to detect error of slice appending.\n",
	       __FILE__, __LINE__, __func__);
      return -1;
    }

  return 0;
}

int
test_slice_reslice ()
{
  lnf_slice slice;
  lnf_slice_init (&slice, sizeof (uint16_t), 4, 5);

  lnf_slice resliced = lnf_slice_reslice (slice, 2, 3);
  if (resliced._len != 2)
    {
      fprintf (stderr, "%s:%d:%s - Failed to reslice. Length is wrong.\n",
	       __FILE__, __LINE__, __func__);
      fprintf (stderr, "%s:%d:%s - expected:%d, current:%lu.\n",
	       __FILE__, __LINE__, __func__, 2, resliced._len);
      return -1;
    }

  lnf_slice_fin (&slice);
  return 0;
}

int
test_slice_from_array ()
{
  uint32_t arr[4] = {9, 3, 0, 4};

  lnf_slice slice = lnf_slice_from_array (arr, 4, sizeof(uint32_t), -1, -1);
  if (lnf_slice_len (slice) != 4)
    {
      fprintf (stderr, "%s:%d:%s - expected:%d, current:%lu",
               __FILE__, __LINE__, __func__, 4, lnf_slice_len (slice));
      return -1;
    }

  const uint32_t *const arr_in_slice = (const uint32_t *const) slice._buf;
  for (int i = 0; i < 4; i++)
    {
      if (arr[i] != arr_in_slice[i])
        {
          return -1;
        }
    }

  return 0;
}

int
main (int argc, char **argv)
{
  if (test_slice_init () != 0)
    {
      return -1;
    }

  if (test_slice_append () != 0)
    {
      return -1;
    }

  if (test_slice_append_wrong () != 0)
    {
      return -1;
    }

  if (test_slice_reslice () != 0)
    {
      return -1;
    }

  if (test_slice_from_array () != 0)
    {
      return -1;
    }

  return 0;
}
