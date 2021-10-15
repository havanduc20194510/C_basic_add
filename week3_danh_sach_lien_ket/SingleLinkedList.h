#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay doi kieu int thanh kieu du lieu mong muon
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;
/*Khoi tao 3 con tro quan trong de thao tac voi danh sach lien ket don hieu qua hon*/

// ham 1 . khoi tao mot node moi
Node *makeNewNode(ElementType element)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;
	return newNode;
}

// ham 2 . Them mot node vao dau danh sach lien ket
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

// ham 3 . Them mot node vao danh sach lien ket
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

// ham 4 . Them mot node vao sau vi tri hien thoi cua danh sach lien ket 
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

// ham 5 . Them mot node vao truoc vi tri hien thoi cur cua danh sach lien ket
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

// ham 6 . Them mot node vao tai position
Node * insertAtPosition(ElementType element , int n)// n la vi tri them vao
{
	int i=0;
   	Node *p = root; 
   	Node *newNode;
	prev =p;
	if (n==0 || root==NULL) 
	{ 
		newNode = makeNewNode(element); 
		newNode->next=root; 	
		root=newNode; 
		cur= newNode; 
		return newNode; 
	}
   	while((i<n) && (p->next != NULL)) 
	{ 
		prev=p; 
		p=p->next; 
		i++;
	} 
   	if (i<n) prev = p; 
   	newNode = makeNewNode(element); 
	newNode->next = prev->next;
	prev->next = newNode; 
	cur = newNode;
	return newNode;
}	 

// ham 7 . Xoa node dau cua danh sach lien ket
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

// ham 8 . Xoa mot node hien thoi cur cua danh sach
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

// ham 9 . Xoa node cuoi cua danh sach
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

// ham 10 . Xoa mot node tai position
Node *deleteAtPosition(int n)
{
	int i=0;
   	Node *p = root; 
   	Node *del; 
	prev = p;
	if (n==0 || root==NULL) 
	{ 
		del = root; 
		root=del->next; 
		cur= root; 
		free(del); 
		cur=root; 
		return root; 
	}
   	while ((i<n) && (p->next!= NULL)) 
	{ 
	   prev=p; 
	   p=p->next; 
	   i++;
	} 
   	if(i<n) return root; // do nothing 
   	prev->next = p->next;
	free(p); 
	cur=root; 
	return root;
}	 

// ham 11 . Dao nguoc linked list
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

// ham 11 . free linked list
void freeList()
{
	Node *freeList;
	while(root!=NULL)
	{
		freeList = root;
		root = root->next;
		free(freeList);
	}
}

// ham 12 . In linked list
void Traverse()
{
	Node *p;
	for(p=root;p!=NULL;p=p->next)
	{
		printf("%d\n",p->element);
	}
}

// ham 13 . Tach linked list thanh 2 linked list
Node *splitlist( int n1, int n2)
{
  Node *r1=NULL;
  Node *p, *cur;
  int i=0;
  if(n1<0||n2<0){
    printf("n1 and n2 must >0\n");
    return r1;
  }
  if(n1==0)
  {
    r1=root;
    p=r1;
    for(i=1;i<n2;i++)
	{
      root=root->next;
    }
    p=root;
    root=root->next;
    p->next=NULL;
    return r1;
  }
  for(p=root;i<n1-1;i++)
  {
    p=p->next;
  }
  cur=p;
  r1=p->next;
  for(i=0;i<n2+1;i++)
  {
    cur=cur->next;
  }
  p->next=cur;
  for(p=r1,i=1;i<n2;i++)
  {
    p=p->next;
  }
  p->next=NULL;
  
  return r1;
}


