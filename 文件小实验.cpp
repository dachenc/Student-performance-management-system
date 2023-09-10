#include<stdio.h>
int main()
{
int i,j;
FILE *fp;
char a[5],b[5],c[5],d[5],e[5],f[5];
  if((fp=fopen("student.txt","r"))==NULL)
  {
	printf("文件打开错误,成绩导入失败\n");  
	return 0; 
  }
  fscanf(fp,"%s%s%s%s%s%s",a,b,c,d,e,f);
  printf("%s%s%s%s%s%s\n",a,b,c,d,e,f);
  
}
