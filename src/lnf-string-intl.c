#include "lnf.h"

void
lnf_string_intl_init (lnf_string_intl * self)
{
  // TODO:implement this.
}

void
lnf_string_intl_init_from_arr (lnf_string_intl * self, void *arr)
{
  // TODO:implement this.
}

void
lnf_string_intl_init_from_arr_with_encoding (lnf_string_intl * self,
					     void *arr,
					     lnf_string_encoding encoding)
{
  // TODO:implement this.
}

size_t
lnf_string_intl_length (lnf_string_intl * self)
{
  // FIXME: String length should be decided by both byte array and encoding.
  // Currently, this function is valid only if the string is  ASCII null
  // terminated string.
  return lnf_slice_intl_len (self->_char_slice);
}

const char *
lnf_string_intl_to_const_char (lnf_string_intl * self)
{
  // FIXME: String length should be decided by both byte array and encoding.
  // Currently, this function is valid only if the string is  ASCII null
  // terminated string.
  return (const char *) (self->_char_slice._data);
}
