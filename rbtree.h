/*

  Copyright (c) 2016 Martin Sustrik

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom
  the Software is furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.

*/

#ifndef DILL_RBTREE_INCLUDED
#define DILL_RBTREE_INCLUDED

#include <stdint.h>

struct dill_rbtree {
    int red;
    struct dill_rbtree *left;
    struct dill_rbtree *right;
    struct dill_rbtree *up;
    int64_t val;
};

/* Initialize the tree. */
void dill_rbtree_init(struct dill_rbtree *self);

/* Returns 1 if there are no items in the tree. 0 otherwise. */
int dill_rbtree_empty(struct dill_rbtree *self);

/* Isert item into the tree. Set its value to 'val' */
void dill_rbtree_insert(struct dill_rbtree *self, int64_t val,
    struct dill_rbtree *item);

/* Remove an item from a tree. */
void dill_rbtree_erase(struct dill_rbtree *item);

/* Find item with specified value. If there are multiple such items,
   one of them is returned. */
struct dill_rbtree *dill_rbtree_find(struct dill_rbtree *self, int64_t val);

/* Return item with the lowest value. If there are no items in the tree NULL
   is returned*/
struct dill_rbtree *dill_rbtree_first(struct dill_rbtree *self);

/* Iterate throught the tree. Items are returned starting with those with
   the lowest values and ending with those with highest values. Items with
   equal values are returned in no particular order. If 'it' points to the
   las item NULL is returned. */
struct dill_rbtree *dill_rbtree_next(struct dill_rbtree *it);

#endif
