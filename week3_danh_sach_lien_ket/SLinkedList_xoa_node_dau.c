#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop hon voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khai bao 3 cn tro quan trong cho cac thao tac cua single linked list

void DelHead()
{
	Node *p;
	p = root;
	root = root->next;
	cur = root;
	/*prev = NULL*/
	free(p);
	return ;
}

int main()
{
	printf("Ham xoa node dau danh sach\n");
  return 0;
}

