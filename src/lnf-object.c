#include <lnf.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

lnf_object *
lnf_object_alloc ()
{
  lnf_object * object = calloc(sizeof(lnf_object), 1);
  return object;
}

lnf_object *
lnf_object_init (lnf_object * raw_object)
{
  lnf_object *object = (lnf_object *) raw_object;
  // TODO initialize here.
  return object;
}

void *
lnf_object_ref (lnf_object * object)
{
  __sync_fetch_and_add (&(object->_ref_cnt), 1);
  return object;
}

void
lnf_object_unref (lnf_object * object)
{
  // TODO NOT thread safe YET
  __sync_fetch_and_sub (&(object->_ref_cnt), 1);
  if (object->_ref_cnt == 0)
    {
      free(object);
    }
}
