#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int sao cho phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong su dung cho cac thao tac cua linked list

// ham khoi tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}

// ham them mot node vao truoc con tro cur
void insertBeforeCur(ElementType element)
{
	Node *newNode = makeNewNode(element);
	if(root == NULL)
	{
		root = newNode;
		cur = root;
		prev = NULL;
	}
	else
	{
		newNode->next = cur;
		// neu cur o dau danh sach
		if(cur == root)
		{
			root = newNode;
		}
		else
		{
			prev->next = newNode;
		}
		cur = newNode;
	}
}
int main()
{
	printf("Ham them mot node vao truoc phan tu hien thoi cur\n");
  return 0;
}

