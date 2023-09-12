#include<stdio.h>
#include<string.h>  //字符串操作                         
#include<conio.h>   //用getchar（）                   
#include<cstdlib>  // 这两个是清屏暂停操作所加头文件 
#include<iostream> //  
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
 km a[M];            //M门课，一个km类型的数组
 int ave;             
};                   
stu d[N];          //N个学生
FILE *fp;         //文件指针 
void dayin()     //一级菜单 
{
	printf("*****************学生成绩管理系统**********************\n");
	printf("*    1  成绩录入     2   成绩查询     3 计算平均分    *\n");
	printf("*    4  计算最高分   5   排名         6 浏览学生信息  *\n");
	printf("*    7  编程记录     8   退出                         *\n"); 
	printf("*******************************************************\n");
	printf("请选择功能\n");
} 
void dayin2()//录入功能的二级菜单 
{
	   printf("你选择的是第1项功能：成绩录入\n");
	   printf("************成绩录入***********\n");
	   printf("*          1 手工录入         *\n");
	   printf("*          2 批量录入         *\n");
	   printf("*          3 返回上一级       *\n");
	   printf("*******************************\n");
	   printf("请选择录入成绩的方式：\n");
}
int  name(char x[5])//用户名 
{
	int i,j;
	char  a[3][5]={"张三","李四","王五"};
	printf("欢迎使用学生成绩管理系统\n");
  	for(i=0;i<3;i++)           //三次机会输入用户名 
	{   
		printf("请输入用户名:");
		scanf("%s",x);
		for(j=0;j<3;j++)     //分别将三个用户名与输入的用户名比对  
		{
			if(strcmp(x,a[j])==0)
			{
			c=j;
			break;
		    }
		else continue;
		}
		if(j==3)                
		{
		printf("用户名输入错误\n");
		printf("还有%d次机会...\n",2-i);
		system("pause");
		system("cls");
		printf ("请再次输入用户名\n");
		}
		else break;
	}  //end 三次用户名机会 
		if(i==3)
		{
		printf("机会用完，正在退出系统...\n");
		return 0;
	    }
		else
		{ 
		printf("输入%s的密码:\n",x);
		return 1;
	    }
}
int pass(char y[6])	//密码 
{
	int i,j,f=0;
	char  b[3][6]={'1','1','1','1','1','1','2','2','2','2','2','2','3','3','3','3','3','3'};
    for(i=0;i<3;i++)        //三次机会输入密码 
	{
		for(j=0;j<100;j++)//100是因为给的机会多点，输错了以后按退格啥的 
		{
		    y[j]=getch();
			if(y[j]!=8&&y[j]!=13)
			printf("*");
			 if(y[j]==13)
			 break;
			 if(y[j]==8)
			{
			printf("\b \b");//实现了密文的退格问题 
			j=j-2;
			}
		}
		printf ("\n");	
		for(j=0;j<6;j++)
		{
		  if (b[c][j]!=y[j])
		   break;
		  else
		   continue ;
		}
		if(j!=6)
		 {
		 printf("密码输入错误\n");
		 printf("还有%d次机会...\n",2-i);
		 system("pause");
		 system("cls");
		 printf ("请再次输入密码 \n");
		 continue;
		 }	
		if (j==6) 
		 break;  
	}  //end 三次密码机会 
	 if(i==3)
	 {
	 printf("机会用完，正在退出系统...\n");
	 return 0;
     }
	 else 
	 {
	 printf ("密码正确，正在进入系统.......\n");
	 system("pause");
	 system("cls");
	 return 1;
     }
}
int login()  //登录 
{
	char a[5];
	char b[6]; 
    if (name(a))        //用户名 
	  if (pass(b))     //密码 
	   return 1;
	return 0;
}
void compare (stu e[N])
{
	int f3,i,j;
	stu t;
	f3=1;
	for(i=0;i<N;i++)  //求平均分最高者 
	 {                //用冒泡改进 
	 	if (f3==0)
	 	break;
	 	for (f3=0,j=0;j<N-1-i;j++)
	 	{
	 		if(e[j].ave<e[j+1].ave)
	 		 {
	 		 	t=e[j];
	 		 	e[j]=e[j+1];
	 		 	e[j+1]=t;
	 		 	f3=1;
	 		 }  
	 	}
	 }
} 
int  test(int j)//进行科目信息校验 
{
	int i;
	for(i=0;i<j;i++)
	{
		if(strcmp(d[0].a[i].subject,d[0].a[j].subject))
		 continue;
		else 
		 break;
	}
	if(i==j)
	 return 1;
	else
	 return 0;
} 
int test2(int i)//进行学生信息校验 
{
 int a=1,b=1,j;
 char c4;
 for(j=0;j<i;j++)
 {
 	if (d[j].num==d[i].num)
 	{
 	 a=0;
 	 printf("学号重复录入！！！\n");
 	 break;
    }
 }
 for (j=0;j<i;j++)
 {
 	if(strcmp(d[i].name,d[j].name))
 	  continue;
 	else 
 	  {
 	   b=0;
 	   printf("姓名重复录入！！！\n"); 
	   break;
      }
 }
 if(a==0||b==0)
 {
  printf("是否确认本次录入有效？Y or N\n");
  fflush(stdin);
  scanf("%c",&c4); 
   if (c4=='y')
   return 1;
   else
   return 0;
 }
 else 
  return 1;
}
int live(stu d[N]) //保存文件 
{
	int i,j;
  if((fp=fopen("student.txt","w"))==NULL)
	{
	 printf("文件打开错误,成绩保存失败\n");  
	 exit(0); 
	}
 
  fprintf (fp,"学号\t姓名\t");
  for(i=0;i<M;i++)
    fprintf (fp,"%s\t",d[0].a[i].subject);
  fprintf(fp,"\n");
  for(i=0;i<N;i++)
   {
   	fprintf (fp,"%-d\t%-s\t",d[i].num,d[i].name);
	for(j=0;j<M;j++)
	fprintf(fp,"%-s\t",d[i].a[j].score);   	
    fprintf(fp,"\n");
   }
  fclose(fp);
  printf("保存成功！\n");	
}
void  ManualInput(stu d[N]) //手工录入功能 
{
  	int i,j; //i控制人；j控制科目
	char c;   //控制是否保存到文件中           
  	for (j=0;j<M;)//只初始化一个人的四门课名称
  	{
  	  printf("请输入第%d门科目的名称：\n",j+1);
  	  scanf("%s",d[0].a[j].subject);
  	  if(j!=0)
        if(test(j))//若test为真则表明无重复。科目，不需要判断是否重新输入。 
		j++;
	    else 
	    printf("此科目重复录入，本次录入无效！\n");
	  else
	    j++;	    
  	  printf("*******************************\n"); 
    }
    for (i=1;i<N;i++)      //由一个人来推到三个人，循环两次 
    {
     	for (j=0;j<M;j++)//M门课，每门课都需要copy 
     	strcpy(d[i].a[j].subject,d[0].a[j].subject);
    }
	system("pause");
	system("cls");
    for (i=0;i<N;)
    {
    	printf("**********************************\n"); 
    	printf("请输入第%d个学生的学号及姓名：\n",i+1);
    	scanf("%d %s",&d[i].num,d[i].name);
	    if(i==0)
	      {
	    	for (j=0;j<M;)
	    	{
			 printf("请输入%s的%s的成绩\n",d[i].name,d[i].a[j].subject); 
	    	 scanf ("%d",&d[i].a[j].score);
	    	 if (d[i].a[j].score<=100&&d[i].a[j].score>=0)
			    j++;
	         else 
			 printf("输入错误，请重新输入\n");
			}
			i++;
		  }
		else
		  {
		   if(test2(i))//无重复或有重复选择不重新输入 
		   {
		    for (j=0;j<M;)
	    	{
			 printf("请输入%s的%s的成绩\n",d[i].name,d[i].a[j].subject); 
	    	 scanf ("%d",&d[i].a[j].score);
	    	 if (d[i].a[j].score<=100&&d[i].a[j].score>=0)
	           j++;
	         else 
			 printf("输入错误，请重新输入\n");
			}
		    i++; 
	       }
	       else
		   printf("本次录入无效！\n");
	      }
		system("pause");
	    system("cls"); 
    }
	 	for (i=0;i<N;i++)
	  {
	  	 d[i].ave=0;
	     for (j=0;j<M;j++)
	       d[i].ave+=d[i].a[j].score;
	       d[i].ave=d[i].ave/M;   
      }  
    printf ("您录入的成绩如下\n");
	printf ("*************************************************\n");
	printf ("*学号\t姓名\t");
	for(j=0;j<M;j++)
	printf("%-s\t",d[0].a[j].subject);
	printf("\t*\n");
	for(i=0;i<N;i++)
	{ 
	  printf ("*%-d\t%-s\t",d[i].num,d[i].name);	
      for(j=0;j<M;j++)
       printf("%-d\t",d[i].a[j].score);
      printf("\t*\n");
	}
	printf("*************************************************\n");
    printf("是否保存您录入的成绩？'y'or'n'\n");
    printf("（提示：可能会将原文件内容覆盖）\n");
   	fflush(stdin);
	scanf("%c",&c);
	if (c=='y')
	live(d);
} 
int BatchInput(stu d[N])//批量录入 
{
  int i,j;
  char a[5],b[5];
  if((fp=fopen("student.txt","r"))==NULL)
  {
	printf("文件打开错误,成绩导入失败\n");  
	return 0; 
  }
  fscanf(fp,"%s%s",a,b);
  for(i=0;i<M;i++)
  fscanf(fp,"%s",d[0].a[i].subject);
  for(i=0;i<N+1;i++)
  {
   fscanf(fp,"%d%s",&d[i].num,d[i].name);
   for(j=0;j<M;j++)
   fscanf(fp,"%d",&d[i].a[j].score);
  }
  fclose (fp);
  for (i=1;i<N;i++)     //只导入了一个人的科目名称。需要copy到N个人身上去。 
    {
     	for (j=0;j<M;j++)//M门课，每门课都需要copy 
     	strcpy(d[i].a[j].subject,d[0].a[j].subject);
    }
  for (i=0;i<N;i++)
	{
     d[i].ave=0;
	 for (j=0;j<M;j++)
	 d[i].ave+=d[i].a[j].score;
	 d[i].ave=d[i].ave/M;   
    }  
  printf ("您录入的成绩如下\n");
  printf ("*************************************************\n");
  printf ("*学号\t姓名\t");
  for(i=0;i<M;i++)
  printf("%-s\t",d[0].a[i].subject);
  printf("*\n");
  for(i=0;i<N;i++)
  {
  printf ("*%-d\t%-s\t",d[i].num,d[i].name);
  for(j=0;j<M;j++)
  printf ("%-d\t",d[i].a[j].score);
  printf("*\n");
}
  printf("*************************************************\n");
  return 1;  	
} 
int input (stu d[N])//录入的二级菜单选择 
{
	   int choose3,f3;
	   system("pause");
	   system("cls");
	   dayin2();
	   do 
	   {
	   	scanf("%d",&choose3);
	   	switch (choose3)
	   	{
	   		case 1:ManualInput(d);//人工录入
			   f3=0;
			   return 1; 
			   break;
			case 2:
			   f3=0;
			   return BatchInput(d);
			   break;
			case 3:
			   printf("正在返回上一级...\n");
			   f3=0;
			   system("pause");
	           system("cls");
			   return 0 ;
			   break; 
			default :
			   printf ("输入有误，请重新输入！\n");
			   f3=1;
			   return 1;
			   break;  
		}  
	   }
	   while (f3==1);
	system("pause");
	system("cls");
	dayin();
}
void avg(stu d[N])//计算平均分（横向求and纵向求） 
{
	int i,j,sum[M],choose5;
	printf("您选择的是功能3：计算平均分\n");
	printf ("请选择计算平均分的方式：\n");
	printf ("     1  单人计算平均分\n");
	printf ("     2  单科计算平均分\n");
	printf ("     3  返回上一级\n"); 
	printf("**********************************\n");//求每个人的最高分 
	scanf("%d",&choose5); 
	switch(choose5)
	{ case 1:
	  printf("单人计算平均分如下：\n");
	  printf("***************************\n");
	  printf ("学号\t姓名\t平均分\n");
	  for (i=0;i<N;i++)
	   printf ("%-d\t%-s\t%-d\n",d[i].num,d[i].name,d[i].ave); 
	  printf ("**************************\n");
	  break;
	 case 2:
	  printf("******************\n");
	  for(j=0;j<M;j++)//大循环是单门科目 
	    for (sum[j]=0,i=0;i<N;i++)     //小循环是N个人该科成绩
	      sum[j]+=d[i].a[j].score; 
	  printf ("单科计算平均分如下：\n");
	  printf ("科目\t平均分\n");
	  for (j=0;j<N;j++)
	   printf ("%-s\t%-d\n",d[0].a[j].subject,sum[j]/N);
	  printf("******************\n");
	  break;
	 case 3:
	 	break;
	 default:
	 	printf("输入错误，请重新输入！\n");
	 	break;
    }
	system("pause");
	system("cls");
	dayin();
}
void max(stu d[N])//计算平均分and各科最高分 
{
	 int i,j,f4,n,choose6;//f4,冒泡改进用。n,i,j计数用。 
	 km t1;//中间变量 
	 stu t2;
	 printf ("您选择的是功能四：计算最高分：\n");
	 printf ("请选择最高分的方式：\n");
	 printf ("     1  单人科目最高分\n");
	 printf ("     2  单科学生最高分\n");
	 printf ("     3  返回上一级\n"); 
	 printf("**********************************\n");//求每个人的最高分 
	 scanf("%d",&choose6);
	 switch (choose6)
	 {
	  case 1:
		 for(f4=1,n=0;n<N;n++)//N个人
		  {
		   for (i=0;i<M-1;i++)//M门课  冒泡改进 
			{
			 if(f4==0) break;
			 for(f4=0,j=0;j<M-1-i;j++)
			  {
				if(d[n].a[j].score<d[n].a[j+1].score)
			   {
				t1=d[n].a[j];
				d[n].a[j]=d[n].a[j+1];
				d[n].a[j+1]=t1;
				f4=1;
			   }    
			  }
			}
		 
		   for (i=0;i<M;i++)//不止一个最高分 
			{
			 if (d[n].a[i].score==d[n].a[0].score)
			 continue;
			 else 
			 break;
			}	
		   printf("*****************************************\n");
		   printf("*学号为%-d姓名为%-s的同学最高分有%d门*\n",d[n].num,d[n].name,i);
		   for(j=0;j<i;j++) 
		     printf("%s\t%d\n",d[n].a[j].subject,d[n].a[j].score);
		  } 
		  printf("****************************************\n");//求每门课的最高分  
	  break;
	  case 2:
	  	int max;
			for(i=0;i<M;i++)//各科最高分
			{
				max=0;
				for(j=0;j<N;j++)
				{
					if(max<d[j].a[i].score)
						max=d[j].a[i].score;
				}
				printf("%s的最高分：\n",d[0].a[i].subject);
				for(j=0;j<N;j++)
				{
					if(max==d[j].a[i].score)
					printf("%s  %d\n",d[j].name,max);
				}
			}
	  break;
	  case 3:
	  	printf("正在返回上一级...\n");
	  	break;
	  default:
	  	printf ("输入错误！\n");
	 }
	system("pause");
	system("cls");
	dayin();
}
void search (stu d[N])
{
	int a,i,choose4;
	char b[10];
	printf ("您选择的是功能2：成绩查询\n");
	printf ("请您选择查询方式：\n");
	printf ("        1    按学号查询\n");
	printf ("        2    按姓名查询\n");
	printf ("        3    返回上一级\n");
	scanf ("%d",&choose4);
	switch(choose4)
	  {
		case 1:
		    int j; 
			printf ("请输入您要查询的学号\n");
			 scanf ("%d",&a);
			for (i=0;i<N;i++)
			 {
				  if (a==d[i].num)
				break;
				  else
				continue;
			 }
			if(i==N)
			 printf ("查无此人！\n");
			else
			 {
			  printf ("该学生信息如下\n");
			  printf ("*************************************************\n");
			  printf ("*学号\t姓名\t");
			for(j=0;j<M;j++)
			  printf("%-s\t",d[i].a[j].subject);
			  printf("\t*\n");
			  printf ("*%-d\t%-s\t",d[i].num,d[i].name);	
			for(j=0;j<M;j++)
			  printf("%-d\t",d[i].a[j].score);
			  printf("\t*\n");
			  printf ("*************************************************\n");
		     }
			break;
		case 2:
			printf ("请输入您要查询的姓名\n");
			scanf("%s",b);
			for (i=0;i<N;i++)
			 {
				  if (strcmp(b,d[i].name))
				  continue;
				  else
				  break;
			 }
			if(i==N)
			 printf ("查无此人！\n");
			else
              {
              printf ("该学生信息如下\n");
			  printf ("*************************************************\n");
			  printf ("*学号\t姓名\t");
			for(j=0;j<M;j++)
			  printf("%-s\t",d[i].a[j].subject);
			  printf("\t*\n");
			  printf ("*%-d\t%-s\t",d[i].num,d[i].name);	
			for(j=0;j<M;j++)
			  printf("%-d\t",d[i].a[j].score);
			  printf("\t*\n");
			  printf ("*************************************************\n");
              }
			break;
		case 3:
			printf ("正在返回上一级...\n");
			break;
		default :
			printf("输入错误\n");
			break;
      }
	system("pause");
	system("cls");
	dayin();
}
void sort (stu d[N])//排名不能修改原来的数据 
{
	 int i,j;
	 stu e[N];//用e[N]代替d[N]来完成排序，防止数据混乱 
	 for(i=0;i<N;i++)
	   e[i]=d[i];
	 printf ("您选择的是功能5：排名\n");
	 compare(e);
	 printf ("成绩排名后为：\n");
	 printf ("*****************************************************************\n");
	 printf ("*名次\t学号\t姓名\t");
	 for(j=0;j<M;j++)
	 printf ("%-s\t",e[0].a[j].subject);
	 printf("平均分\t*\n");
	 for(i=0;i<N;i++)
	  {
	   printf ("*%-d\t%-d\t%-s\t",i+1,e[i].num,e[i].name);
	   for(j=0;j<M;j++)
       printf("%-d\t",d[i].a[j].score);	  
       printf("%-d\t*\n",e[i].ave);     
 	  }
	 printf ("*****************************************************************\n");
	 system("pause");
	 system("cls");
	 dayin();
}
void notes()
{
 printf("            ||*****2020112233  孙元晨 *******||\n"); 
 printf("   ㈠主函数基本思路 （《大前提》→→『菜单循环∈初始化循环』\n");
 printf("    ①大前提：首先需要成功登录，这是运行系统的大前提。机会用尽，\n自动退出系统\n"); 
 printf("    ②初始化：进入系统后需要进行数据的初始化，否则只能退出系统。\n不进入菜单循环\n");
 printf("    ③功能实现：通过菜单的循环来反复调用各个函数，实现功能。\n");  
 printf("**********************************************************************\n");
 printf("编写记录：\n");
 printf("自526行代码开始"); 
 printf("第一次修改,完善登录系统。\n");
 printf("第二次修改，完善录入时重复输入验证，加入test函数和test2函数\n");
 printf("第三次修改，加入功能6，查看成绩明细。\n");
 printf("第四次修改，加入成绩录入二级菜单中功能3：返回上一级。\n");
 printf("第五次修改，加入文件，成绩手工录入后可以实现保存到文件中,加入live函数\n");
 printf("第六次修改，加入批量录入功能，加入BatchInput函数\n");
 printf("第七次修改，完善系统，增加功能7，加入notes函数\n"); 
 printf("第八次修改，发现修改科目数后的大漏洞，并及时修改整体的数据输出格式！！！（790）\n");
}
int main()
{
 int choose1,choose2,f1=1,f2=1,i,j;//菜单循环用的f1，初始化循环f2。
            //choose1,实现初始化选择。choose2实现菜单循环选择 
 char c,c2;//c判断是否退出系统,区分作为全局变量的int c;
             //c2判断是否重新输入 
if (login())//大前提，用户名and密码正确 
{    
	do    // 初始化大循环
	{  
			do
			{	
			 dayin ();
		     printf ("（提示：请先录入初始成绩）\n");
			 scanf("%d",&choose1);
			 //首先，必须输入成绩，否则无法进行下一步。 	
			   if(choose1!=1&&choose1!=7&&choose1!=8)
				 {
				  printf("输入错误:\n");
				  system("pause");
			      system("cls");
			     }
			   else if(choose1==1)
			   choose1=input(d);//来接收判断一下返回值。确定是录入成功还是失败 
			}//返回上一级属于录入失败。若成功，返回值为1，否则，返回值为0； 
			while (choose1!=1&&choose1!=7&&choose1!=8);
			switch(choose1)//不选1，只能选7或8 
			{
			 case 1:
			    printf("初始化成功！请继续\n");
			    system("pause");
			    system("cls");
				dayin ();
				do                   //菜单的循环选择 
				{                   //此时已经录入过成绩了 
				scanf("%d",&choose2);
				  switch (choose2)
				  {
				  	  case 1:
						 printf ("您已经录入成绩，是否重新录入成绩？ ‘y’or‘n’\n");
					     fflush(stdin);
						 scanf("%c",&c2); 
					     if (c2=='y')//判断是否重新录入 
					     {
				          j=input(d);//j来接收返回值，来确定是录入失败还是已录入成功。 
				          if(j==1) //返回上一级属于录入失败情况中。返回值为假 
						   break;
						  else
						  {
	                      dayin();
					      break;
					      }
						 }
						 else
					     {
						  system("pause");
	                      system("cls");
	                      dayin();
					      break;
					     }
				      case 2:search(d);
					    break;  
					  case 3:avg(d);
					    break;
					  case 4:max(d);   //求最高分，先调用sort函数来排名  
					    break ;
					  case 5:sort(d);//排名注意防止数据混乱 
					    break;
					  case 6:
					  	 printf ("您选择的是功能6：浏览学生信息\n");
						 printf ("*********************************************************\n");
						 printf ("*学号\t姓名\t");
						 for(j=0;j<M;j++)
						 printf("%-s\t",d[0].a[j].subject);
						 printf("平均分\t*\n");
						 for(i=0;i<N;i++)
						 { 
						  printf ("*%-d\t%-s\t",d[i].num,d[i].name);	
					      for(j=0;j<M;j++)
					      printf("%-d\t",d[i].a[j].score);
					      printf("%d\t*\n",d[i].ave);
						 }
						 printf("*********************************************************\n");
					   system("pause");
	                   system("cls");
	                   dayin();
					    break;
					  case 7:notes();
					         system("pause");
	                         system("cls");
	                         dayin();
					    break; 
					  case 8:
					     printf ("您确定退出系统？ ‘y’or‘n’\n");
					     fflush(stdin);
						 scanf("%c",&c); 
					     if (c=='y')
					     { 
				         f1=0; //退出菜单循环 
						 f2=0;//退出初始化的循环
						 break;
						 }
						 else
					     {
						  system("pause");
	                      system("cls");
	                      dayin();
					      break;
					     }
					  default:
					  	printf ("输入错误，请重新输入功能选项\n");
					    break;
				  }
				}     //菜单循环结束
				while (f1==1);           
			  break;	  
			 case 7:
			  notes();
			  break;	
			 case 8:
			  printf ("您确定退出系统？ ‘y’or‘n’\n");
			  fflush(stdin);
			  scanf("%c",&c); 
			  if (c=='y')
			   f2=0;//退出初始化循环
			  else
			     system("pause");
			     system("cls");
			  break; 
		    }
    }                      //end 初始化大循环 
	while(f2==1); 
}                        //end 大前提
    printf ("谢谢使用，再见。\n");
	return 0;
}
