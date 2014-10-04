#ifndef __LNF_SLICE_H__
#define __LNF_SLICE_H__

#ifndef __LNF_TYPE_H_INSIDE__
#error You cannot include this. Please include lnf-type.h
#endif

struct _lnf_slice
{
  lnf_object _object;

  size_t len, cap;
  size_t size_of_type;
  void *_data;
};

lnf_slice *lnf_make_slice_from_len (size_t s, size_t len);
lnf_slice *lnf_make_slice_from_len_cap (size_t s, size_t len, size_t cap);

lnf_slice *lnf_make_slice_from_array (void *arr, size_t typesize, size_t arrsize);

void lnf_slice_init (lnf_slice * slice, size_t s, size_t len, size_t cap);
void lnf_slice_finalize (lnf_slice * slice);

size_t lnf_slice_len (lnf_slice slice);
size_t lnf_slice_cap (lnf_slice slice);

/**
 * @lnf_slice The slice that will be resliced
 * @return A "new" resliced lnf_slice
 */
lnf_slice *lnf_slice_reslice (lnf_slice slice, size_t start, size_t end);

lnf_slice *lnf_slice_reslice_head (lnf_slice slice, size_t end);

lnf_slice *lnf_slice_reslice_tail (lnf_slice slice, size_t start);

lnf_slice *lnf_slice_array (void *arr, size_t size_of_type,
			    size_t start, size_t end);

lnf_slice *lnf_slice_array_head (void *arr, size_t size_of_type, size_t end);

lnf_slice *lnf_slice_array_tail (void *arr, size_t size_of_type,
				 size_t start);

lnf_slice *lnf_slice_append (lnf_slice slice1, lnf_slice slice2);

#endif // __LNF_SLICE_H__
