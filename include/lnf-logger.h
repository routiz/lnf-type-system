#ifndef __LNF_LOGGER_H__
#define __LNF_LOGGER_H__

#include <stdio.h>

#define LNF_LOG(x) printf("%s:%d:%s - %s\n", __FILE__, __LINE__, __func__, x)

#endif // __LNF_LOGGER_H__
