#ifndef __LNF_SLICE_INTL_H__
#define __LNF_SLICE_INTL_H__

#ifndef __LNF_TYPE_H_INSIDE__
#error You cannot include this. Please include lnf-type.h
#endif

#include <stddef.h>

typedef struct _lnf_slice_intl lnf_slice_intl;
struct _lnf_slice_intl
{
  size_t len, cap;
  size_t size_of_type;
  void *_data;
};

lnf_slice_intl *lnf_make_slice_intl_from_len (size_t s, size_t len);
lnf_slice_intl *lnf_make_slice_intl_from_len_cap (size_t s, size_t len, size_t cap);

lnf_slice_intl *lnf_make_slice_intl_from_array (void *arr, size_t typesize, size_t arrsize);

void lnf_slice_intl_init (lnf_slice_intl * slice, size_t s, size_t len, size_t cap);
void lnf_slice_intl_finalize (lnf_slice_intl * slice);

size_t lnf_slice_intl_len (lnf_slice_intl slice);
size_t lnf_slice_intl_cap (lnf_slice_intl slice);

/**
 * @lnf_slice The slice that will be resliced
 * @return A "new" resliced lnf_slice
 */
lnf_slice_intl *lnf_slice_intl_reslice (lnf_slice_intl slice, size_t start, size_t end);

lnf_slice_intl *lnf_slice_intl_reslice_head (lnf_slice_intl slice, size_t end);

lnf_slice_intl *lnf_slice_intl_reslice_tail (lnf_slice_intl slice, size_t start);

lnf_slice_intl *lnf_slice_intl_array (void *arr, size_t size_of_type,
				      size_t start, size_t end);

lnf_slice_intl *lnf_slice_intl_array_head (void *arr, size_t size_of_type, size_t end);

lnf_slice_intl *lnf_slice_intl_array_tail (void *arr, size_t size_of_type,
					   size_t start);

lnf_slice_intl *lnf_slice_intl_append (lnf_slice_intl slice1, lnf_slice_intl slice2);

#endif // __LNF_SLICE_INTL_H__
