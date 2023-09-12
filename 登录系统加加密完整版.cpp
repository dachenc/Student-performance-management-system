#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int c;
char x;
void name(char x[5])
{
	int i,j;
	char  a[3][5]={"张三","李四","王五"};
  	for(i=0;i<3;i++)
	{   
		printf("请输入用户名:");
		scanf("%s",&x[0]);
		for(j=0;j<3;j++)
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
	//	system("cls");
		printf("用户名输入错误，请重新输入!\n");
		printf("还有%d次机会...\n",2-i);
		}
		else break;
	}
		if(i==3)printf("机会用完，正在退出系统...\n");
		else printf("输入%s的密码:\n",x);
	}
void pass(char y[6])	
{
	int i,j,f=0;
	char  b[3][6]={49,49,49,49,49,49,50,50,50,50,50,50,51,51,51,51,51,51};
	//因为用的是getcha()来输入，所以输入1，对应码为49。 
    for(i=0;i<3;i++)//三次机会 
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
			printf("\b \b");
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
		// system("cls");
		 //printf("账号：%s\n",x);
		 printf("密码输入错误\n");
		 printf("还有%d次机会...\n",2-i);
		 continue;
		 }
		
		if (j==6) 
		 break;  
	}
	 if(i==3)printf("机会用完，正在退出系统...\n");
	 else 
	 printf ("密码正确，正在进入系统\n");	
	
}
int  main()
{   
	char c[5];
	char d[6];
    name(c);
	pass(d);
	return 0;
}
