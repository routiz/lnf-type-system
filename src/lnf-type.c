#include <stdlib.h>

#include "lnf.h"

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

