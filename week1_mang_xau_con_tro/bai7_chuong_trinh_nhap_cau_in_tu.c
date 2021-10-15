#include<stdio.h>
#include<string.h>
char *TachTen(char *s)
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
        {
            s[i] = '\0';
        }
    }
    return s;
}
char *TachPhanSau(char *s1, char *s2)/*chi tren ham ms dc khai bao mang la con tro
con duoi ham chinh phai dung []*/
{
    int i;
    for(i=0;s1[i]!=' ';i++)
    {
        s2 = &s1[i+2];
        /*vi tai vong lap cuoi cung truoc khi thoat thi s1[i] bang chu cuoi cung gan dau cach
        nhat , s1[i+1] dang la dau cach.s1[i+2] se la chu dau tien cua phan sau ten. Vi vay
        ta can cho con tro s2 den phan tu s1[i+2]*/
    }
    return s2;
}
int main()
{
    char str[100];
    char s1[100];
    char *s2;
    printf("Nhap vao ten :");
    gets(str);
    strcpy(s1,str);//copy xau str vao xau s1 de luu tru ten , sau khi cat 
    printf("%s\n",TachTen(str));
    printf("%s\n",TachPhanSau(s1,s2));
    return 0;
}