#ifndef __LNF_OBJECT_H__
#define __LNF_OBJECT_H__

#ifndef __LNF_TYPE_H_INSIDE__
#error You cannot include this. Please include lnf-type.h
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _lnf_slice lnf_slice;

typedef size_t lnf_type_id;

typedef struct _lnf_args_desc lnf_args_desc;
typedef struct _lnf_method lnf_method;
typedef struct _lnf_interface lnf_interface;
typedef struct _lnf_object lnf_object;

/**
 * Argument descriptor
 */
struct _lnf_args_desc
{
  size_t count;
  lnf_type_id *types;
};

typedef size_t method_id;

struct _lnf_method
{
  const char *name;

  lnf_args_desc args;
  lnf_args_desc returns;

  // The function pointer
  void *function;

  method_id _id;
};

struct _lnf_interface
{
  lnf_type_id _id;
  const char *name;

  // I believe slice will be faster than hash table data structure in this case.
  // It should be very rare care that an interface has hundreds or thousands of
  // methods.
  // The slice type should be lnf_method
  lnf_slice *methods;
};

_Bool lnf_interface_register (lnf_interface interface);

_Bool lnf_interface_is_registered (lnf_interface interface);

_Bool lnf_interface_inherit (lnf_interface * interface, lnf_slice * parents);

void
lnf_object_declare_method (lnf_object * object, lnf_args_desc descriptor,
			   void *func_ptr);

struct _lnf_object
{
  // TODO replace this with lnf_slice
  // I believe slice will be faster than hash table data structure in this case.
  // It should be rare care that an object has hundreds or thousands of
  // methods.
  // The slice type should be lnf_method
  lnf_slice *methods;

  /**
   * private
   */
  // reference count. Should be thread-safe.
  int _ref_cnt;
};
 
lnf_object *lnf_object_alloc ();

lnf_object *lnf_object_init (lnf_object * object);

void *lnf_object_ref (lnf_object * object);

void lnf_object_unref (lnf_object * object);

#endif // __LNF_OBJECT_H__
