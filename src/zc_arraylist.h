/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
 *
 * Licensed under the LGPL v2.1, see the file COPYING in base directory.
 */

#ifndef __zc_arraylist_h
#define __zc_arraylist_h

#define ARRAY_LIST_DEFAULT_SIZE 32

/* make zc_arraylist_foreach speed up, so keep struct defination here */
typedef struct {
	void **array;
	int len;
	int size;
	void (*del)(void *data);
	void *(*dup)(void *data);
	int (*cmp)(void *data1, void *data2);
} zc_arraylist_t;

zc_arraylist_t *zc_arraylist_new(int size);
void zc_arraylist_del(zc_arraylist_t * a_list);
zc_arraylist_t *zc_arraylist_dup(zc_arraylist_t * a_list);

int zc_arraylist_set(zc_arraylist_t * a_list, int i, void *data);
int zc_arraylist_add(zc_arraylist_t * a_list, void *data);
int zc_arraylist_sortadd(zc_arraylist_t * a_list, void *data);

#define zc_arraylist_len(a_list)  (a_list->len)
#define zc_arraylist_set_dup(a_list, d)  (a_list->dup = (d))
#define zc_arraylist_set_del(a_list, d)  (a_list->del = (d))
#define zc_arraylist_set_cmp(a_list, c)  (a_list->cmp = (c))

#define zc_arraylist_get(a_list, i) ((i >= a_list->len) ? NULL : a_list->array[i])

#define zc_arraylist_foreach(a_list, i, a_unit) \
	for(i = 0, a_unit = a_list->array[0]; (i < a_list->len) && (a_unit = a_list->array[i], 1) ; i++)

#endif
