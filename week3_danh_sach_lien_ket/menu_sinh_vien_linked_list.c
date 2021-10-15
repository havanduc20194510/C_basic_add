#include<stdio.h>
#include"SingleLinkedList_structure.h"
int main()
{
	int key;
	char Mssv_S[10];
	char Mssv_D[10];
	ElementType Student[20];
	do
	{
		printf("\n===================Nhap vao chuc nang ban mong muon=================================\n");
		printf("1. Nhap vao tu ban phim thong tin cua 1 sinh vien sau do chen vao linked list\n");
		printf("2. Tim kiem sinh vien thong qua MSSV\n");
		printf("3. Xoa sinh vien thong qua MSSV\n");
		printf("4. Hien thi tat ca thong tin cua sinh vien trong linked list\n");
		printf("5. Thoat\n");
		printf("6. Ghi thong tin sinh vien co trong list ra file sinhvien.dat\n");
		printf("7. Doc file sinhvien.dat , in ra sinh vien dat , ti le sinh vien dat\n");
		printf("=======================================================================================\n");
		scanf("%d",&key);
		switch(key)
		{
			case 1 :
				// ham nhap vao thong tin 1 sinh vien sau do luu vao linked list
				getchar();
				Input();
				break;
			case 2 :
				{
					getchar();
					printf("Nhap vao MSSV can tim kiem\n");
					gets(Mssv_S);
					// tim kiem sinh vien co MSSV da nhap vao
					Node *result=find_MSSV(Mssv_S);
					if(result!=NULL)
					{
						printf("MSSV\t\tName\t\t\t\tGrade\n");
						printf("%-10s\t%-30s\t%.2f\n",result->element.mssv,result->element.name,result->element.grade);
					}
					else
						printf("Khong tim thay sinh vien co MSSV nhu vay\n");
					break;
				}
			case 3 :
				{
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
				}
				
			case 4 :
				{
					printf("DANH SACH SINH VIEN CO TRONG DANH SACH LA\n");
					Traverse();
					break;
				}
			case 5 :
				{
					printf("===================================EXIT=================================");
					break;
				} 
				
			case 6 :
				{
					printToFile();
					printf("Danh sach sinh vien da duoc ghi ra file , vui long kiem tra lai nhe\n");
					break;
				}
				
			case 7 :
			{
				int i=0;	
				FILE *fin;
				int dem = 0;
				fin = fopen("sinhvien.dat","rb");
				if(fin==NULL)
				{
					printf("Loi o buoc doc file , kiem tra lai nhe\n");
					exit(0);
				}
				while(!feof(fin))
				{
					fscanf(fin,"%[^,],%[^,],%f%*c",Student[i].mssv,Student[i].name,&Student[i].grade);
					i++;
					dem=i-1;
				}
				printf("dem = %d\n",dem);
				int pass=0;
				printf("DANH SACH SINH VIEN PASS\n");
				printf("MSSV\t\tName\t\t\t\tGrade\n");
				for(i=0;i<dem;i++)
				{
					if(Student[i].grade>=4)
					{
						printf("%-10s\t%-30s\t%.2f\n",Student[i].mssv,Student[i].name,Student[i].grade);
						pass++;
					}
				}
				printf("Ti le sinh vien dau la : %.2f\n",(float)pass/dem);
				break;
			}
			default :
				{
					printf("chon key sai , chon lai nhe\n");
					break;
				}	
		}
	}
	while(key!=5);
  return 0;
}

