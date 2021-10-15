#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int de phu hop voi yeu cau cua de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua single linked list

// ham tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}

// ham them mot node vao dau
void AddHead(ElementType element)
{
	Node *newNode = makeNewNode(element);// tao mot node moi
	if(root == NULL)
	{
		root = newNode;
		cur = root;
		prev = NULL;
	}
	else
	{
		newNode->next = root;
		root = newNode;
		cur = root;// cap nhat con tro cur
	}
}
int main()
{
	printf("Ham them node vao dau danh sach lien ket\n");
  return 0;
}

