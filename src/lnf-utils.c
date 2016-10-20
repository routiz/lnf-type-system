#include "lnf-utils.h"

#include <stdio.h>
#include <stdlib.h>

static _Bool _is_strict = false;

_Bool
lnf_util_is_strict ()
{
  return _is_strict;
}

void
lnf_util_set_strict (_Bool strict)
{
  _is_strict = strict;
}

void
lnf_util_not_implemented ()
{
  fprintf (stderr, "NOT IMPLEMENTED\n");
  if (lnf_util_is_strict ())
    {
      exit (-1);
    }
}
