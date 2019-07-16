#ifndef __DLL_HDR_GUARD__
#define __DLL_HDR_GUARD__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct list_node {
	struct list_node *prev;
	struct list_node *next;
	void *value;
} listnode;

typedef struct list {
	struct list_node *head;
	struct list_node *tail;
	int count;
} list;

list *list_create();
void list_insert(list *root, void *value);
void list_remove(list *root, void *value);
void fetch_list_node_values(list *root, void **A);
void list_insert_head(list *root, void *value);
int get_list_size(list *root);

#define CHECK_MEM_ALLOC(P) { void *__ptr = P; \
       	if (__ptr == (void *)NULL) { \
	fprintf(stderr,"ERROR! Allocating memory (%s:%d) -- %s\n" \
		,__FILE__, __LINE__, strerror(errno)); \
	exit(-1); }}

#define CHECK_LIST_IS_EMPTY(P) {list *__root = P; \
	if ( __root->count == 0) { \
	fprintf(stdout,"Cannot remove Link - List is Empty\n"); \
	return; }}

#define FIND_NODE_VALUE_LIST(L, V, N) { \
	int __i; N = NULL; listnode *_N = L->head; \
	for (__i = 0; __i < L->count; __i++) { \
        if ((_N->value - V) == 0) { N = _N; break; } _N = _N->next;} \
	}

#endif	
