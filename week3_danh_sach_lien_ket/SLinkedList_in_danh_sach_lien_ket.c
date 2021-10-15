#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *prev = NULL , *cur = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua linked list
void Traverse()
{
	Node *p;
	for(p=root;p!=NULL;p=p->next)
	{
		printf("%d\n",p->element);
	}
}
int main()
{
	printf("Ham in ra danh sach lien ket don\n");
  return 0;
}

