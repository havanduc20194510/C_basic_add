#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int de phu hop voi de bai 
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root =NULL , *cur = NULL , *prev =NULL;
// khoi tao 3 con tro quan trong can thiet cho cac thao tac cua liked list

// ham khoi tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}

// ham them mot node vao ngay sau vi tri hien tai (cur)
void insertAfterCur(ElementType element)
{
	Node *newNode = makeNewNode(element);// khoi tao mot node moi de them vao
	if(root == NULL)
	{
		root = newNode;
		cur = root;
	}
	else if(cur == NULL)
	{
		printf("cur pointer is NULL\n");
		return ;
	}
	else
	{
		newNode->next = cur->next;
		cur->next = newNode;
		prev = cur;// update prev pointer for use later
		cur = cur->next;
	}
	return;
}

int main()
{
	printf("Ham them mot node vao ngay sau vi tri hien tai\n");
  return 0;
}

