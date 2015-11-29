/*
 * lnf-slice.c
 *
 * Copyright (C) 2014 - isryu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "lnf.h"

/**
 * @param s sizeof slice type
 * @param len length of the slice
 * @return new slice pointer
 */
lnf_slice_intl *
lnf_make_slice_intl_len (size_t s, size_t len)
{
  lnf_slice_intl *slice =
    (lnf_slice_intl *) calloc (sizeof (lnf_slice_intl), 1);
  lnf_slice_intl_init (slice, s, len, len * 2);

  return slice;
}

lnf_slice_intl *
lnf_make_slice_intl_len_cap (size_t s, size_t len, size_t cap)
{
  if (len > cap)
    {
      // TODO warn user
      return NULL;
    }

  lnf_slice_intl *slice =
    (lnf_slice_intl *) calloc (sizeof (lnf_slice_intl), 1);
  lnf_slice_intl_init (slice, s, len, cap);

  return slice;
}

lnf_slice_intl *
lnf_make_slice_intl_array (void *arr, size_t typesize, size_t arrsize)
{
  // TODO stub
  return 0;
}

void
lnf_slice_intl_init (lnf_slice_intl * slice, size_t s, size_t len, size_t cap)
{
  slice->_data = calloc (s, len);
  if (slice->_data == NULL)
    {
      return;
    }

  slice->len = len;
  slice->cap = cap;

  slice->size_of_type = s;
}

void
lnf_slice_intl_finalize (lnf_slice_intl * slice)
{
  free (slice->_data);
  slice->len = 0;
  slice->cap = 0;
}

size_t
lnf_slice_intl_len (lnf_slice_intl slice)
{
  return slice.len;
}

size_t
lnf_slice_intl_cap (lnf_slice_intl slice)
{
  return slice.cap;
}

lnf_slice_intl *
lnf_intl_reslice (lnf_slice_intl slice, size_t start, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_reslice_head (lnf_slice_intl slice, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_reslice_tail (lnf_slice_intl slice, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_slice_array (void *arr, size_t size_of_type, size_t start,
		      size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_slice_array_head (void *arr, size_t size_of_type, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_slice_array_tail (void *arr, size_t size_of_type, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice_intl *
lnf_intl_slice_append (lnf_slice_intl slice1, lnf_slice_intl slice2)
{
  // TODO stub
  return 0;
}
