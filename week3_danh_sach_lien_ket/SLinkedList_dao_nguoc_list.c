#include<stdio.h>
#include<stdlib.h>
typedef int ElementType ; // thay the kieu int thanh kieu du lieu phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua linked list
Node *list_reverse()
{
	Node *cur , *prev;
	cur = prev = NULL;
	while(root != NULL)
	{
		cur = root;
		root = root->next;
		cur->next = prev;
		prev = cur;
	}
	root = cur;
	return prev;
}

int main()
{
	printf("Ham dao nguoc danh sach lien ket\n");
  return 0;
}

