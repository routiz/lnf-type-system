/*
 * lnf-string-intl.h
 *
 *  Created on: Oct 11, 2014
 *      Author: isryu
 */

#ifndef __LNF_STRING_INTL_H__
#define __LNF_STRING_INTL_H__

#ifndef __LNF_TYPE_H_INSIDE__
#error You cannot include this. Please include lnf.h
#endif

typedef struct _lnf_string_intl lnf_string_intl;

typedef unsigned short lnf_string_encoding;

static const unsigned short LNF_STRING_ENCODEING_UTF8 = 0;

struct _lnf_string_intl
{
  lnf_string_encoding _encoding;
  lnf_slice_intl _char_slice;
};

void lnf_string_intl_init (lnf_string_intl *);

void lnf_string_intl_init_from_arr (lnf_string_intl *, void*);

void lnf_string_intl_init_from_arr_with_encoding (lnf_string_intl *, void *,
						  lnf_string_encoding);

size_t lnf_string_intl_length (lnf_string_intl *);

const char *lnf_string_intl_to_const_char (lnf_string_intl *);

#endif /* __LNF_STRING_INTL_H__ */
