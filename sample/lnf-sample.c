#include <lnf.h>

#include <stdio.h>

int
main (int argc, char **argv)
{
  lnf_slice slice = { 0 };
  lnf_slice_init (&slice, sizeof (char), 10, 10);
  printf ("is size_of_type set properly : %d\n",
	  (sizeof (char) == slice._slice_intl.size_of_type));

  lnf_slice_finalize (&slice);

  lnf_object * object = lnf_object_ref(lnf_object_init(lnf_object_alloc()));
  lnf_object_unref (object);

  return 0;
}
