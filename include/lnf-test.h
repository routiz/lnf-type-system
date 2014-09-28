#ifndef __LNF_TEST_H__
#define __LNF_TEST_H__

#include <stdbool.h>
#include <stdio.h>

#define lnf_return_if_fail(expr) if (expr) {} else {return;}

#define LNF_TEST_ASSERT(expr, msg) if (expr) {} else {printf (msg); return false;}

typedef struct _lnf_test lnf_test;

struct _lnf_test
{
  const char *name;
    _Bool (*test_func) (void);
};

void lnf_test_register (lnf_test test);

void lnf_test_run (void);

#endif // __LNF_TEST_H__
