#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#include "config.h"

#include "lnf-test.h"
#include "lnf-type.h"
#include "lnf-logger.h"

_Bool
test_lnf_slice_len (void)
{
  LNF_LOG ("TESTING :: lnf_slice_len");

  lnf_slice *intslice = make_slice_from_len (sizeof (int), 20);
  LNF_TEST_ASSERT (intslice != NULL, "TEST FAILED :: New slice is NULL\n\n");

  assert (lnf_slice_len (*intslice) == 0);
  LNF_LOG ("TEST DONE :: lnf_slice_len\n");

  return true;
}

_Bool
test_lnf_slice_cap (void)
{
  LNF_LOG ("TESTING :: lnf_slice_cap");

  lnf_slice *intslice = make_slice_from_len (sizeof (int), 20);
  LNF_TEST_ASSERT (intslice != NULL, "TEST_FAILED :: New slice is NULL\n\n");

  assert (lnf_slice_cap (*intslice) == 0);
  LNF_LOG ("TEST DONE :: lnf_slice_cap\n");

  return true;
}

int
main (int argc, char **argv)
{
  lnf_test test1 = { "len test", test_lnf_slice_len };
  lnf_test_register (test1);

  lnf_test test2 = { "cap test", test_lnf_slice_len };
  lnf_test_register (test2);

  lnf_test_run ();

  return 0;
}
