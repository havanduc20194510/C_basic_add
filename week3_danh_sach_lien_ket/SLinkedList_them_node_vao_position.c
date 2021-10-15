#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay the kieu int thanh kieu du lieu phu hop voi de bai
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
// khoi tao 3 con tro quan trong cho cac thao tac cua linked list

// ham khoi tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}

// ham them mot node moi vao sau mot vi tri position (vi tri bat dau tu 1 - vi tri thu nhat )
Node *insertAtPosition(ElementType element , int n)
{
	Node *newNode = makeNewNode(element);
	Node *p;
	int count;
	for(p=root,count =1; count <n && p!=NULL ;count++ , p= p->next );
	/*vong for ben tren dung de cap nhat con tro p den vi tri can xoa*/
	cur = p;
	if(root == NULL)
	{
		root = newNode;
		cur = root;
	}
	else
	{
		newNode->next = cur->next;
		cur->next = newNode;
		prev = cur;
		cur = cur->next;
	}
	return newNode;
}

int main()
{
	printf("Ham them node vao danh sach qua position\n");
  return 0;
}

