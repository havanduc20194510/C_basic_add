#include<stdio.h>
#include"SingleList_int_floatType.h"
int main()
{
	Node head1;
	Node head2;
	int m,n;
	printf("Nhap vao 2 so n , m = ");
	scanf("%d%d",&n,&m);
	printf("Nhap vao %d phan tu cho list 1 :\n",n);
	head1 = Input(n);
	printf("Nhap vao %d phan tu cho list 2 :\n",m);
	head2 = Input(m);
	Node result = InItHead();
	printf("\nCac phan tu co trong list 1 :\n");
	Tranverser(head1);
	printf("\nCac phan tu co trong list 2 :\n");
	Tranverser(head2);
	Node temp1 = head1;
	while(temp1 != NULL)
	{
		result = AddTail(result,temp1->data);
		temp1 = temp1->next;
	}
	Node temp2 = head2;
	while(temp2 != NULL)
	{
		result = AddTail(result,temp2->data);
		temp2 = temp2->next;
	}
	printf("\nCac phan tu co trong list result la :\n");
	Tranverser(result);
	printf("\nDanh sach gop la:\n");
	Sort(result);
	Tranverser(result);
  return 0;
}

