#include <lnf.h>

#include <stdio.h>

int
main (int argc, char **argv)
{
  lnf_slice slice = { 0 };
  lnf_slice_init (&slice, sizeof (char), 10, 10);
  printf ("is size_of_type set properly : %d\n",
	  (sizeof (char) == slice.size_of_type));

  lnf_slice_finalize (&slice);

  return 0;
}
