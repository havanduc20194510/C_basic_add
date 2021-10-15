#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i;
    printf("Nhap vao mot cau:");
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!=' ')
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("\n");
        }
        
    }
    return 0;
}