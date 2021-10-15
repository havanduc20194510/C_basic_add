#include<stdio.h>
#include"SingleLinkedList_structure.h"
int main()
{
	int key;
	char Mssv_S[10];
	char Mssv_D[10];
	ElementType element;// node luu thong tin can them vao list
	do
	{
		printf("\n===================Nhap vao chuc nang ban mong muon=================================\n");
		printf("1. Nhap thong tin va them sinh vien vao linked list theo diem tang dan\n");
		printf("2. Tim kiem sinh vien thong qua MSSV\n");
		printf("3. Xoa sinh vien thong qua MSSV\n");
		printf("4. Hien thi tat ca thong tin cua sinh vien trong linked list\n");
		printf("5. Thoat\n");
		printf("=======================================================================================\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1 :
				// ham nhap vao thong tin 1 sinh vien sau do luu vao linked list theo thu tu diem tang
				//Input();
				printf("Nhap vao thong tin sinh vien can them :\n");
				getchar();
				printf("MSSV : ");
				gets(element.mssv);
				printf("Name : ");
				gets(element.name);
				printf("Grade : ");
				scanf("%f",&element.grade);
				root = Add_grade_up(element);
				break;
			case 2 :
				getchar();
				printf("Nhap vao MSSV can tim kiem\n");
				gets(Mssv_S);
				// tim kiem sinh vien co MSSV nhu the
				Node *result=find_MSSV(Mssv_S);
				if(result!=NULL)
				{
					printf("MSSV\t\tName\t\t\t\tGrade\n");
					printf("%-10s\t%-30s\t%.2f\n",result->element.mssv,result->element.name,result->element.grade);
				}
				else
					printf("Khong tim thay sinh vien co MSSV nhu vay\n");
				break;
			case 3 :
				getchar();
				printf("Nhap vao MSSV can xoa\n");
				gets(Mssv_D);
				// xoa sinh vien co MSSV nhap vao
				Node *remove = Del_MSSV(Mssv_D);
				if(remove!=NULL)
				{
					printf("Da xoa thanh cong\n");
				}
				else
				{
					printf("Khong co sinh vien co MSSV nhu MSSV can xoa\n");
				}
				break;
			case 4 :
				printf("DANH SACH SINH VIEN CO TRONG DANH SACH LA\n");
				Traverse();
				break;
			case 5 : 
				printf("===================================EXIT=================================");
				break;
			default :
				printf("chon key sai , chon lai nhe\n");
				break;
		}
	}
	while(key!=5);
  return 0;
}

