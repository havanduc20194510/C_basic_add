#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
void ghiFile(int n)
{
	FILE *fout;
	fout = fopen("float.txt","w");
	if(fout==NULL)
	{
		printf("Loi o buoc mo file , kiem tra lai nhe\n");
		return ;
	}
	int i;
	float arr[n];
	printf("Nhap vao cac phan so thuc:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&arr[i]);	
	}
	fprintf(fout,"%d\n",n);
	for(i=0;i<n;i++)
	{
		fprintf(fout,"%f\n",arr[i]);	
	}
	fclose(fout);
}
void docFile()
{
	FILE *fin,*fout;
	int i,count=0,dem=0;
	float B[100];
    fin = fopen("float.txt","r");
    if(fin ==NULL)
    {
        printf("Khong tho mo file de doc, kiem tra lai\n");
        return ;
    }
    fscanf(fin,"%d",&count);
    for(i=0;i<count;i++)
    {
    	fscanf(fin,"%f",&B[i]);
    	if(B[i]>5)
    	dem++;
	}
	// ghi ra file cac so thuc co gia tri lon hon 5
	fout = fopen("float2.txt","w");
	fprintf(fout,"%d\n",dem);
	for(i=0;i<count;i++)
	{
		if(B[i]>5)
		{
			fprintf(fout,"%f\n",B[i]);
		}
	}
	fclose(fin);
	fclose(fout);
}
int main()
{

	int n;
	printf("Nhap vao so luong cac chu so thuc: ");
	scanf("%d",&n);
	ghiFile(n);
	docFile();
    return 0;
}
