#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong de phuc vu cho cac thao tac co ban cua linked list

// ham xoa node dau danh sach
void DelHead()
{
	Node *p;
	p = root;
	root = root->next;
	cur = root;
	/*prev = NULL*/
	free(p);
}

// ham xoa node o vi tri hien thoi cur
void DelCurrent()
{
	if(cur == NULL)
		return ;
	if(cur == root)
		DelHead();
	else
	{
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	return ;
}
int main()
{
	printf("Ham xoa phan tu hien thoi cua linked list\n");
  return 0;
}

