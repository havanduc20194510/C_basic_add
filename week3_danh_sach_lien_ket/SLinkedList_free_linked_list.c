#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua linked list

void freeList()
{
	Node *freeList;
	while(root!=NULL)
	{
		freeList = root;
		root = root->next;
		free(freeList);
	}
}
int main()
{
	printf("Ham free danh sach lien kiet\n");
  return 0;
}

