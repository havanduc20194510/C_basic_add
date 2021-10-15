#include<stdio.h>
#include<stdlib.h>
int tim_post(int *p1,int x,int pos,int n)
{
    int i;
    pos = -1;
    for(i=0;i<n;i++)
    {
        if(*(p1+i)==x)
        {
            pos = i;
        }
    }
    return pos;
}
void XoaPhanTu(int *p1,int pos,int n)
{
    int i;
    for(i=pos;i<n-1;i++)
    {
        *(p1+i)=*(p1+i+1);
        // copy phan tu sau sang phan tu truoc
    }
    // sau khi xoa xong thi giam phan tu mang
    --n;
    printf("Mang sau khi cat bo la :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p1+i));
    }
}
int main()
{
    int *p1;
    int pos;
    int x;
    int n,i;
    printf("Nhap vao so phan tu mang:");
    scanf("%d",&n);
    p1 = (int *)malloc(n*sizeof(int));
    printf("Nhap vao cac phan tu mang:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p1+i));
    }
    printf("Nhap vao phan tu x= ");
    scanf("%d",&x);
    while(tim_post(p1,x,pos,n)!=-1)
    {
        XoaPhanTu(p1,pos,n);
    }
    return 0;
}