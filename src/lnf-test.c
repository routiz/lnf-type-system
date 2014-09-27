#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "lnf-test.h"
#include "lnf-type.h"

// Not thread safe
lnf_slice TESTS = { 0 };

// Not thread safe
_Bool _is_init = false;

void
_lnf_test_print (const char *msg, ...)
{
  size_t len = strlen (msg);

  va_list args;
  va_start (args, msg);
  vprintf (msg, args);
  va_end (args);
}

void
_lnf_test_init (void)
{
  _lnf_test_print ("Initializing");

  _is_init = true;

  lnf_slice_init (&TESTS, sizeof (lnf_slice *), 0, 10);
}

// Not thread safe
void
lnf_test_register (lnf_test test)
{
  if (!_is_init)
    {
      _lnf_test_init ();
    }
}

// Not thread safe
void
lnf_test_run (void)
{
  if (!_is_init)
    {
      _lnf_test_print ("TEST : No test is registered\n");
      exit (EXIT_FAILURE);
    }

  for (int i = 0; i < TESTS.len; i++)
    {
      _lnf_test_print ("TEST : Tes\n");
    }

  _lnf_test_print ("TEST : Finished!\n");
}
