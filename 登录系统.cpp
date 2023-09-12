//登录系统，总共三次机会。三个人对应三个密码 
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main ()
{
	char a[7];
	char b[3][7]={"张三","李思","王武"};//账号 
	int i,j,d;
	int c[3]={111111,222222,333333};//密码
     printf ("请输入账号\n");
	for (i=0;i<3;i++)
	{
		scanf ("%s",&a);			
		for (j=0;j<3;j++)
		{
	     if (strcmp(a,b[j]))//错误时候走if 1
		 continue;
		 else	break;
		}//end j
		if (j==3)//if 2
		{
			printf ("输入错误\n");
		    printf ("您还有%d次机会\n",2-i);
		}//end if 2
		else 
	    break;	
	}//end i
	if (i!=3)//if 3
	{	
		printf("请输入密码\n");
		for (i=0;i<3;i++)
		{
			scanf ("%d",&d);
			for (j=0;j<3;j++)
			  {
			  if (strcmp(a,b[j]))//错误时候走if
			     continue; 
			  else 
			    break;
			  }
			if(d==c[j])
			  break;
			else 
			printf("输入错误，您还有%d次机会\n",2-i);	  
	    } 
	}
	if (i!=3) 
	printf("输入正确，欢迎进入系统。");
	return 0;
}
