#include "dlinked_list.h"

list *list_create() {

	return calloc(1, sizeof(list));
}

/* Inserts the value at the end of the list */

void list_insert(list *root, void *value) {
	
	listnode *node = calloc(1, sizeof(listnode));
	CHECK_MEM_ALLOC(node);
	node->value = value;

	if (root->count == 0) {
		root->head = node;
		root->tail = node;
	} else {
		node->prev = root->tail;
		node->next = NULL;
	        root->tail->next = node;
		root->tail = node;
	}
	root->count++;	
	return;
}

void list_remove(list *root, void *value) {
	
	CHECK_LIST_IS_EMPTY(root);	
	
	if ((root->head->value - value) == 0) {
		if (root->count == 1) {
			root->head = NULL;
			root->tail = NULL;
		} else {
			listnode *temp = root->head->next;
			temp->prev = NULL;
			root->head = temp;
		}
	} else if ((root->tail->value - value) == 0) {
		listnode *temp = root->tail->prev;
		free(root->tail);
		root->tail = temp;
	} else {
		listnode *node;
		FIND_NODE_VALUE_LIST(root,value,node);
		if (node) {
			listnode *temp = node->prev;
			temp->next = node->next;
			node->next->prev = temp;
			free(node);
		}	
	}
	root->count--;
}

/* This will fill the void pointer array with the values in the list */
void fetch_list_node_values(list *root, void **A) {

	int i;
	listnode *node = root->head;
	for (i = 0; i < root->count; i++) {
		A[i] = node->value;
		node = node->next;
	}
}

void list_insert_head(list *root, void *value) {

	listnode *node = calloc(1,sizeof(listnode));
	CHECK_MEM_ALLOC(node);
        node->value = value;

	if (root->count == 0) {
		root->head = node;
	        root->tail = node;
	} else {
		listnode *temp = root->head;
		root->head = node;
		node->next = temp;
		temp->prev = node;
	}
	root->count++;
	return;
}

int get_list_size(list *root) {
	return root->count;
}
