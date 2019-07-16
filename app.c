
#include "dlinked_list.h"

int main(int argc, char *argv[]) {
	list *root;
	int i;
        float values[] = {2.0,3.14,6.8,4.5};
	float **gvalues;
	int size;

	printf("Creating List......\n");
	root = list_create();
        CHECK_MEM_ALLOC(root);
	printf("Created List Successfully\n");
	printf("Inserting 3 elements\n");
	list_insert(root, &values[0]);
	list_insert(root, &values[1]);
	list_insert(root, &values[2]);
	size = get_list_size(root);
	if (size == 3) {
		printf("Inserted 3 elements\n");
	}
	gvalues = malloc(size * sizeof(listnode *));
        fetch_list_node_values(root, (void **)gvalues);

	printf("printing current list\n");
	for (i = 0; i < size; i++) {
		printf("element %d = %f\n",i, *gvalues[i]);
		gvalues[i] = 0;
	}

	printf("Removing element %f\n",values[2]);
	list_remove(root,&values[2]);

	size = get_list_size(root);
        fetch_list_node_values(root, (void *)gvalues);

	printf("Printing current list\n");
	for (i = 0; i < size; i++) {
		printf("element %d = %f\n",i, *gvalues[i]);
		gvalues[i] = 0;
	}

	printf("inserting %f at start\n",values[3]);
	
	list_insert_head(root,&values[3]);
	size = get_list_size(root);
        fetch_list_node_values(root, (void *)gvalues);

	printf("Printing current list\n");
	for (i = 0; i < size; i++) {
		printf("element %d = %f\n",i, *gvalues[i]);
		gvalues[i] = 0;
	}


	printf("deleting element at start\n");
	list_remove(root,&values[3]);
	size = get_list_size(root);
        fetch_list_node_values(root, (void *)gvalues);

	printf("Printing current list\n");
	for (i = 0; i < size; i++) {
		printf("element %d = %f\n",i, *gvalues[i]);
		gvalues[i] = 0;
	}

}
