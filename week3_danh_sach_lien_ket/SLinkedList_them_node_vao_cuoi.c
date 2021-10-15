#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node * next;
}Node;
Node *root = NULL , *cur = NULL , * prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua single linked list

// ham khoi tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL ;
	return newNode;
}

// ham them mot node vao cuoi singhle linked list
void AddTail(ElementType element)
{
	Node *temp , *p;
	temp = makeNewNode(element);
	/* *temp : tao node moi them vao single linked list
	   *p : duyet single linked list*/
	if(root == NULL)  // neu linked list dang trong thi temp them vao chinh la root luon
	{
		root = temp;
		cur = root;
		prev = NULL;
	}
	else
	{
		p = root;
		while(p->next != NULL) // duyet den khi nao den con tro cuoi thi thoat
		{
			p = p->next;	
		}
		p->next = temp; // cho node cuoi tro den temp , khi do temp thanh node cuoi luon
		cur = temp; // update cur
	}
}

int main()
{
	printf("Ham them mot node vao cuoi danh sach lien ket don\n");
  return 0;
}

