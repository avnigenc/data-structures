#include <stdlib.h>
#include <stdio.h>

struct n {
	int x;
	struct n * next;
};

typedef struct n node;
int count = 0;

void print(node * r){
	printf("\n");
	if(count != 0)
		printf("linked list'in yeni hali\n");
	if(count == 0)
		printf("linked list'in ilk hali\n");
	while(r != NULL){
		printf("%d\n", r -> x);
		r = r -> next;
	}
	printf("\n");
	count++;
}

node * sortedAdd(node * r, int x){

	if(r  == NULL){ // linked list boş ise
		r = (node *) malloc(sizeof(node));
		r -> x = x;
		r -> next = NULL;
		return r;
	}

	if(r -> x > x){ // linked list de bir eleman var ve ilk eleman daha küçük ise
		node * temp = (node *) malloc(sizeof(node));
		temp -> x = x;
		temp -> next = r;
		r = temp;
		return r;
	}

	node * iter = r;
	while(iter -> next != NULL && iter -> next -> x < x){
		iter = iter -> next;
	}

	node * temp = (node *) malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> x = x;
	return r;

}

node * removeNode(node * r, int x){

	node * temp;
	node * iter = r;

	if(r -> x == x){ // ilk elemani silmek
		temp = r;
		r = r -> next;
		free(temp);
		return r;
	}

	while(iter -> next != NULL && iter -> next -> x != x){
		iter = iter -> next;
	}

	if(iter -> next == NULL){
		printf("silinmek istenen sayi bulunamadi \n");
		return r;
	}

	temp = iter -> next;
	iter -> next = iter -> next -> next;
	free(temp);
	return r;

}

int main(){

	node * root;
	root = NULL;

	FILE * stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	stream = fopen("/home/avni/workspace/Cicek/src/ciceklistesi.txt", "r");
	if (stream == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, stream)) != -1) {
		int intLine = atoi(line);
		root = sortedAdd(root, intLine);
	}
	print(root);
	root = removeNode(root, 12);
	print(root);
	root = removeNode(root, 14);
	print(root);
	root = sortedAdd(root, 9);
	print(root);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);

}

