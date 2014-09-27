#include <stdlib.h>

#include "lnf-type.h"

_Bool
lnf_interface_register (lnf_interface interface)
{
  // TODO stub
  return false;
}

_Bool
lnf_interface_is_registered (lnf_interface interface)
{
  // TODO stub
  return false;
}

_Bool
lnf_interface_inherit (lnf_interface * interface, lnf_slice * parent)
{
  // TODO stub
  return false;
}

void
lnf_object_declare_method (lnf_object * object, lnf_args_desc descriptor,
                           void *func_ptr)
{
}

void *
lnf_object_ref (lnf_object * object)
{
  __sync_fetch_and_add (&object->_ref_cnt, 1);
  return object;
}

void
lnf_object_unref (lnf_object * object)
{
  __sync_fetch_and_sub (&object->_ref_cnt, 1);
}

lnf_slice *
make_slice_from_len (size_t s, size_t len)
{
  lnf_slice *slice = (lnf_slice *) calloc (sizeof (lnf_slice), 1);
  lnf_slice_init (slice, s, len, len * 2);

  return slice;
}

lnf_slice *
make_slice_from_len_and_cap (size_t s, size_t len, size_t cap)
{
  lnf_slice *slice = (lnf_slice *) calloc (sizeof (lnf_slice), 1);
  lnf_slice_init (slice, s, len, cap);

  return slice;
}

lnf_slice *
make_slice_from_array (void *arr, size_t arrsize)
{
  // TODO stub
  return 0;
}

void
lnf_slice_init (lnf_slice * slice, size_t s, size_t len, size_t cap)
{
  slice->len = len;
  slice->cap = cap;
}

size_t
lnf_slice_len (lnf_slice slice)
{
  // TODO stub
  return 0;
}

size_t
lnf_slice_cap (lnf_slice slice)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice (lnf_slice slice, size_t start, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice_head (lnf_slice slice, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice_tail (lnf_slice slice, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array (void *arr, size_t size_of_type, size_t start,
                       size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array_head (void *arr, size_t size_of_type, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array_tail (void *arr, size_t size_of_type, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_append (lnf_slice slice1, lnf_slice slice2)
{
  // TODO stub
  return 0;
}
