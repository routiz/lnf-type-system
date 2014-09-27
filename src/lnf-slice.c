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

lnf_slice *
lnf_make_slice_from_len (size_t s, size_t len)
{
  lnf_slice *slice = (lnf_slice *) calloc (sizeof (lnf_slice), 1);
  lnf_slice_init (slice, s, len, len * 2);

  return slice;
}

lnf_slice *
lnf_make_slice_from_len_cap (size_t s, size_t len, size_t cap)
{
  lnf_slice *slice = (lnf_slice *) calloc (sizeof (lnf_slice), 1);
  lnf_slice_init (slice, s, len, cap);

  return slice;
}

lnf_slice *
lnf_make_slice_from_array (void *arr, size_t arrsize)
{
  // TODO stub
  return 0;
}

void
lnf_slice_init (lnf_slice * slice, size_t s, size_t len, size_t cap)
{
  slice->len = len;
  slice->cap = cap;
}

size_t
lnf_slice_len (lnf_slice slice)
{
  // TODO stub
  return 0;
}

size_t
lnf_slice_cap (lnf_slice slice)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice (lnf_slice slice, size_t start, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice_head (lnf_slice slice, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_reslice_tail (lnf_slice slice, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array (void *arr, size_t size_of_type, size_t start,
                       size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array_head (void *arr, size_t size_of_type, size_t end)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_slice_array_tail (void *arr, size_t size_of_type, size_t start)
{
  // TODO stub
  return 0;
}

lnf_slice *
lnf_slice_append (lnf_slice slice1, lnf_slice slice2)
{
  // TODO stub
  return 0;
}
