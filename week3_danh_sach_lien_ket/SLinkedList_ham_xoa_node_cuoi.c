#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int thanh kieu du lieu phu hop voi de bai 
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac co ban cua linked list

// ham xoa node dau linked list
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

// ham xoa node cuoi linked list
void DelTail()
{
	if(root == NULL || root->next == NULL)// khi linked list trong hoac chi co 1 phan tu
	{
		return DelHead();
	}
	Node *p = root;
	while(p->next->next != NULL)
	{
		p = p->next;
	}
	p->next = NULL;// cho node gan cuoi tro den NULL
	cur = p;
}

int main()
{
	printf("Ham xoa node cuoi linked list\n");
  return 0;
}

