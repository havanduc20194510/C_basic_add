#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;// thay kieu int thanh kieu du lieu phu hop voi de bai 
typedef struct node
{
	ElementType element;
	struct node *next;
}Node;
Node *root = NULL , *cur = NULL , *prev = NULL;

// ham tach linked list thanh 2 list
Node *splitlist( int n1, int n2){
  Node *r1=NULL;
  Node *p, *cur;
  int i=0;
  if(n1<0||n2<0){
    printf("n1 and n2 must >0\n");
    return r1;
  }
  if(n1==0){
    r1=root;
    p=r1;
    for(i=1;i<n2;i++){
      root=root->next;
    }
    p=root;
    root=root->next;
    p->next=NULL;
    return r1;
  }
  for(p=root;i<n1-1;i++){
    p=p->next;
  }
  cur=p;
  r1=p->next;
  for(i=0;i<n2+1;i++){
    cur=cur->next;
  }
  p->next=cur;
  for(p=r1,i=1;i<n2;i++){
    p=p->next;
  }
  p->next=NULL;
  
  return r1;
}

int main()
{
	printf("Ham tach list thanh 2 list\n");
  return 0;
}

