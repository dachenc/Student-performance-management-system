#include<stdio.h>
#include<string.h>                           
#include<conio.h>                     
#include<stdlib.h>
#include<cstdlib>   
#include<iostream>   
#define   N   3  //学生数 ////|>>>> 修改区 
#define   M   4 //课程数 /////|>>>>
#define  stu  struct student
#define  km   struct kemu
int c;      //挑选用户名所对应的密码 
char x;      //存用户名
struct kemu //定义结构体km
{
  char subject[10];
  int  score;
};
struct student           //定义结构体stu 
{
 int num;              //学号 
 char name[10];       //姓名 
 km a[M];
 int ave;            //M门课，一个km类型的数组 
};                   
stu d[N];          //N个学生
FILE *fp;         //文件指针 
int BatchInput(stu d[N])//批量录入 
{
  int i,j;
  char a[5],b[5];
  if((fp=fopen("student.txt","r"))==NULL)
  {
	printf("文件打开错误,成绩导入失败\n");  
	return 0; 
  }//文件已打开 
  fscanf(fp,"%s%s%s%s%s%s",a,b,d[0].a[0].subject,d[0].a[1].subject,d[0].a[2].subject,d[0].a[3].subject);
  for(i=0;i<N;i++)
  fscanf(fp,"%d%s%d%d%d%d",&d[i].num,d[i].name,&d[i].a[0].score,&d[i].a[1].score,&d[i].a[2].score,&d[i].a[3].score);
  fclose (fp);//文件关闭 
  for (i=1;i<N;i++)     //只导入了一个人的科目名称。需要copy到N个人身上去。 
    {
     	for (j=0;j<M;j++)//M门课，每门课都需要copy 
     	strcpy(d[i].a[j].subject,d[0].a[j].subject);
    }
  printf ("您录入的成绩如下\n");
  printf ("********************************************\n");
  printf ("*学号\t姓名\t%-s\t%-s\t%-s\t%-s\t*\n",d[0].a[0].subject,d[0].a[1].subject,d[0].a[2].subject,d[0].a[3].subject);
  for(i=0;i<N;i++)
  printf ("*%-d\t%-s\t%-d\t%-d\t%-d\t%-d\t*\n",d[i].num,d[i].name,d[i].a[0].score,d[i].a[1].score,d[i].a[2].score,d[i].a[3].score);	
  printf("*********************************************\n");
  return 1;  	
} 
int main ()
{
	int a,i;
	a=BatchInput(d);
	printf("*****************\n");
	printf("%d\n",a);
	printf("*****************\n");
	printf ("******************************************************************\n");
	printf ("学号\t姓名\t%-s\t%-s\t%-s\t%-s\t平均分\n",d[0].a[0].subject,d[0].a[1].subject,d[0].a[2].subject,d[0].a[3].subject);
	for (i=0;i<N;i++)
	printf ("%-d\t%-s\t%-d\t%-d\t%-d\t%-d\t%-d\n",d[i].num,d[i].name,d[i].a[0].score,d[i].a[1].score,d[i].a[2].score,d[i].a[3].score,d[i].ave);	
	printf ("******************************************************************\n");
return 0;
}
