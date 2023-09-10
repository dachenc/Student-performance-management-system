#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>//通过该函数头部里的函数，改变控制台的背景和颜色  
#include<windows.h>
//头文件声明，下文用到了改变控制台的宽度和高度 
#define M 100
 
struct student
{
	char name[25];//姓名  
	char num[25];//学号  
	char credit[20];//身份证号  
	char native[35];//籍贯  
	char tel[25];//手机号  
	int special;//专业  
	int banji;//班级  
	int math,yy,wl,cyy,pe;//数学、英语、物理、C语言、体育  
	double ave;//平均分 
};
 
void input(struct student stu[M]);
void output(struct student stu[M]);
void lookfor(struct student stu[M]); //自定义查询学生信息函数
void modify(struct student stu[M]); //修改信息 
void order(struct student stu[M]); //排序 
void delete_student(struct student stu[M]); //删除信息 
void xuehao(struct student stu[M]);        
void xingming(struct student stu[M]);  
void fileread(struct student stu[M]);  //保存学生信息 
void filewrite(struct student stu[M]);  
void yanshi(char *p); 
void kaifaren(struct student stu[M]);
void xitongjieshao(struct student stu[M]);
 
int count=0; 
struct student t;
 
int main()   
{  
	int choice,sum;  
	struct student stu[M];         
	system("mode con:cols=400 lines=30000"); //调节控制台的宽度和高度  
	system("color 0b");  //调节控制台的背景和字体颜色  
	point1:    
	sum=0;
	
	char qwe[105] = {"\t\t\t\t\t\t\t\t\3\3\3\3\3\3\3\3\3\3\3\3\3欢迎使用学生信息管理系统\3\3\3\3\3\3\3\3\3\3\n"};
	yanshi(qwe);
	do
	{  
		printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");  
		printf("\t\t\t\t\t\t\t\t+               学生信息管理系统            +\n");  
		printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");  
		printf("\t\t\t\t\t\t\t\t\t\t ***************\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 1、添加学生信息\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 2、浏览学生信息\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 3、查询学生信息\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 4、修改学生信息\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 5、删除学生信息\n");  
		printf("\t\t\t\t\t\t\t\t\t\t 6、排列学生信息\n");   
		printf("\t\t\t\t\t\t\t\t\t\t 7、读取文件学生\n");
		printf("\t\t\t\t\t\t\t\t\t\t 8、保存到文件\n");
		printf("\t\t\t\t\t\t\t\t\t\t 9、退出系统\n"); 
		printf("\t\t\t\t\t\t\t\t\t\t 10、开发人员介绍\n");
		printf("\t\t\t\t\t\t\t\t\t\t 11、系统介绍\n");
		printf("\t\t\t\t\t\t\t\t\t\t ***************\n");   
		printf("请输入你的选择\n");
		
		scanf("%d",&choice);
		fflush(stdin);       //清除输入缓冲区  
		if (choice>9||choice<=0)
		{ 
			sum++;
			if (sum>=5)  
			{  
				printf("输入错误次数过多,程序将重新开始\n"); 
				system("pause");  //程序暂停  
				system("cls");   //清屏语句 
				goto point1;
			}
		}
		switch (choice)       //根据选择，调用不同的函数来完成不同的任务  
		{  
			case 1:input(stu);break;         
			case 2:output(stu);break;  
			case 3:lookfor(stu);break;  
			case 4:modify(stu);break;  
			case 5:delete_student(stu);break;  
			case 6:order(stu);break;  
			case 7:fileread(stu);break;  
			case 8:filewrite(stu);break; 
			case 9:printf("感谢使用学生信息管理系统,请关掉程序!!!\n");system("pause");break;
			case 10:kaifaren(stu);break;
			case 11:xitongjieshao(stu);break;
			
			default:printf("无效的选择!!!请重新输入!!!\n");break;
		} 
	}while (choice!=9);
	
	printf("the program is over!!!\n");
	return 0;
}
 
void input(struct student stu[M])
{
	int len,size; 
	system("cls");  
	printf("请添加要输入学生的信息\n"); 
	printf("%d",count); 
	 
	do
	{  
		printf("请输入由11位数字组成的学生学号\n"); 
		scanf("%s",&stu[count].num); 
		len=strlen(stu[count].num);
	}while(len < 11);
	  
	printf("请输入同学的姓名\n");  
	scanf("%s",stu[count].name); 
	 
	do
	{
		printf("请输入由18位数字组成的学生身份证号\n");
		scanf("%s",&stu[count].credit);
		size=strlen(stu[count].credit);  
	}while(size!=18);
	                                               
	printf("请输入学生的籍贯\n");
	scanf("%s",&stu[count].native);
	printf("请输入学生的手机号码\n");
	scanf("%s",&stu[count].tel);  
	printf("请输入所需要的专业代号：1、计算机科学 2、通信工程 3、软件工程\n");
	scanf("%d",&stu[count].special);  
	printf("请输入对应的学生班级号码:1、软工一班 2、软工二班 3、软工三班\n");  
	scanf("%d",&stu[count].banji); 
	do
	{  
		printf("请依次输入不大于100的学生各科成绩\n"); 
		scanf("%d%d%d%d%d",&stu[count].math,&stu[count].yy,&stu[count].wl,&stu[count].cyy,&stu[count].pe);
	}while(stu[count].math>100||stu[count].yy>100||stu[count].wl>100||stu[count].cyy>100||stu[count].pe>100);
	  
	stu[count].ave=(stu[count].math+stu[count].yy+stu[count].wl+stu[count].cyy+stu[count].pe)/5.0;
	count++;  
}
 
void output(struct student stu[M]) 
{  
	int j;  
	system("cls");  
	if (count==0)  
	{  
		printf("当前已存学生信息为0个\n");  
		return;  
	}
	
	for (j=0;j<count;j++)  
	{  
		printf("学号\t\t  姓名\t\t身份证号\t籍贯\t手机号\t\t专业\t\t班级\t数学\t英语\t物理\tC语言\t体育\t平均分\n");  
		for (j=0;j<count;j++)
		{
			printf("%s\t",stu[j].num);  
			printf("%s\t",stu[j].name);  
			printf("%s\t",stu[j].credit);  
			printf("%s\t",stu[j].native);  
			printf("%s\t",stu[j].tel);
			
			if (stu[j].special==1)
				printf("计算机科学\t");
			else if (stu[j].special==2)
				printf("通信工程\t");
			else  
				printf("软件工程\t");
			printf("%d\t",stu[j].banji);
			printf("%d\t",stu[j].math);
			printf("%d\t",stu[j].yy);
			printf("%d\t",stu[j].wl);
			printf("%d\t",stu[j].cyy);
			printf("%d\t",stu[j].pe);
			printf("%.1lf\t\n",stu[j].ave); 
		}  
	}  
}
void lookfor(struct student stu[M])       //自定义查询学生信息函数  
{  
	int j,flag=0;  
	char xh[25];  
	system("cls");  
	if (count==0)  
	{  
		printf("当前已存学生信息为0个,无法查询!!!\n");  
		return;
	}
	else
	{
		printf("请输入你想要查看的同学学号\n");
		scanf("%s",&xh);
		fflush(stdin);
		for (j=0;j<count;j++)  
		{  
			if (strcmp(stu[j].num,xh)==0)  //通过字符函数对已存入的学生信息进行比较,找出要查看的学生  
			{  
				printf("学号\t\t姓名\t\t\t\t身份证号\t\t\t\t\t籍贯\t手机号\t\t\te\t\t专业\t\t班级\t数学\t英语\t物理\tC语言\t体育\t平均分\n");
				printf("%s\t",stu[j].num);  
				printf("%s\t",stu[j].name);  
				printf("%s\t",stu[j].credit);  
				printf("%s\t",stu[j].native);  
				printf("%s\t",stu[j].tel);  
				if (stu[j].special==1)  
					printf("计算机科学\t");  
				else if (stu[j].special==2)  
					printf("通信工程\t");      
				else  
					printf("软件工程\t");
				printf("%d\t",stu[j].banji);
				printf("%d\t",stu[j].math);
				printf("%d\t",stu[j].yy); 
				printf("%d\t",stu[j].wl);  
				printf("%d\t",stu[j].cyy);  
				printf("%d\t",stu[j].pe);  
				printf("%.1lf\t",stu[j].ave);  
			}  
		}  
		if (j==count)  
			printf("很抱歉,没有你所需要的学生信息\n");  
	}  
}  
void modify(struct student stu[M])
{  
	int j,flag=0,course;
	char xh[25];
	system("cls");
	if (count==0)
	{
		printf("当前已存学生信息为0个,无法修改!!!\n");
		return;
	}
	else  
	{  
		printf("请输入你想要修改的同学学号\n");
		scanf("%s",&xh);  
		fflush(stdin);  
		for (j=0;j<count;j++)  
			if (strcmp(stu[j].num,xh)==0)
			{  
				printf("你确定要修改学生的信息吗???如果不确定的话,请关掉本程序!!!\n");  
				printf("选择课程: 1、数学 2、英语 3、物理 4、C语言 5、体育\n");
				scanf("%d",&course);  
				printf("请输入你想要修改后的学生成绩\n");
				switch(course)  
				{  
					case 1:scanf("%d",&stu[j].math);break;  
					case 2:scanf("%d",&stu[j].yy);break;
					case 3:scanf("%d",&stu[j].wl);break;  
					case 4:scanf("%d",&stu[j].cyy);break;  
					case 5:scanf("%d",&stu[j].pe);break;  
					default:printf("无效的选择!!!请重新输入!!!\n");break;  
				} 
			}
	}  
}  
void delete_student(struct student stu[M])
{  
	int choice;  
	system("cls");  
	if (count==0)  
	{  
		printf("当前已存学生信息为0个,无法删除!!!\n");  
		return;  
	}  
	else  
	{  
		printf("请选择你所要删除的方式:1、学号 2、姓名(如果你的姓名是中文,那么无法删除,请选择学号删除) 3、取消\n");
		scanf("%d",&choice);  
		switch(choice)
		{  
			case 3:return;break;  
			case 2:xingming(stu);break;
			case 1:xuehao(stu);break;  
			default:printf("无效的选择!!!请重新输入!!!\n");break;  
		}  
	}  
}  
void order(struct student stu[M])
{  
	int j,k,choice,index;  
	system("cls");  
	printf("请输入你想要进行排序的方式(所有排序的方式均是降序)!!!\n");  
	printf("1、数学 2、英语 3、物理 4、C语言 5、体育 6、平均分\n");  
	scanf("%d",&choice);
	
	switch (choice)  
	{
		case 1:for (j=0;j<count;j++)  
		{
			index=j;   
			for (k=j+1;k<count;k++)  
				if (stu[k].math>stu[index].math)  
				{
					t=stu[k];stu[k]=stu[index];stu[index]=t;
				}  
		};break; 
		 
		case 2:for (j=0;j<count;j++)
		{
			index=j;   
			for (k=j+1;k<count;k++)
				if (stu[k].yy>stu[index].yy)
				{
					stu[k]=stu[index];
				}
		 };break;
		 
		case 3:for (j=0;j<count;j++)  
		{
			index=j;   
			for (k=j+1;k<count;k++)  
				if (stu[k].wl>stu[index].wl)  
				{
					t=stu[k];stu[k]=stu[index];stu[index]=t;
				}  
		};break;
		
		case 4:for (j=0;j<count;j++)  
		{
			index=j;   
			for (k=j+1;k<count;k++)  
				if (stu[k].cyy>stu[index].cyy)  
				{
					t=stu[k];stu[k]=stu[index];stu[index]=t;
				}  
		};break;
		
		case 5:for (j=0;j<count;j++)  
		{
			index=j;   
			for (k=j+1;k<count;k++)  
				if (stu[k].pe>stu[index].pe)  
				{
					t=stu[k];stu[k]=stu[index];stu[index]=t;
				}  
		};break;
		 
		case 6:for (j=0;j<count;j++)
		{
			index=j;   
			for (k=j+1;k<count;k++)  
			if (stu[k].ave>stu[index].ave)  
			{
				t=stu[k];stu[k]=stu[index];stu[index]=t;
			}
		};break;
		  
		default:printf("无效的选择!!!请重新输入!!!\n");break;  
	}  
}  
void xuehao(struct student stu[M])      //自定义通过学号方式删除学生信息函数  
{  
	int j,index=0,k=count;  
	char xh[25];  
	system("cls");  
	printf("请输入你想要删除的同学学号\n");
	scanf("%s",xh);
	
	fflush(stdin);  
	for (j=0;j<count;j++)  
	{
		if (strcmp(stu[j].num,xh)==0)  
		{     
			for (j=index;j<count;j++)  
				stu[j]=stu[j+1];  
			count--;  
			if (count<k)  
				printf("你已经删除成功\n");  
		}  
		index++;
	}
	  
	if (j==count)  
		printf("抱歉!!!没有你所需要删除的学生信息!*_*!\n");  
}
void xingming(struct student stu[M])       //自定义通过姓名方式删除学生信息函数  
{  
	int flag=0,j,k=count;  
	char xm[25];  
	system("cls");  
	printf("请输入你想要删除的同学姓名\n");  
	scanf("%s",xm);
	 
	fflush(stdin);  
	for(j=0;j<count;j++)  
	{  
		if (strcmp(stu[j].num,xm)==0)  
		{  
		
			for (j=flag-1;j<count;j++)               
				stu[j]=stu[j+1];  
			count--;  
			if (count<k)  
				printf("你已经删除成功\n");  
		}     
		flag++;
	}
	 
	if (j==count)  
		printf("抱歉!!!没有你所需要删除的学生信息!*_*!\n");  
}  
void yanshi(char *p)
{  
	while (1)  
	{  
		if (*p!=0)  
			printf("%c",*p++);  
		else  
			break;  
		Sleep(100);
	}  
}
void filewrite(struct student stu[M])
{  
	int j=0;  
	char c;  
	FILE *fp;  
	printf("请选择是否要存入已输入的学生信息:'y'还是'n'		\n");  
	scanf("%c",&c);
	  
	fflush(stdin);  
	while(c!='y'&&c!='n')
	{  
		if (c!='y'&&c!='n')  
			printf("输入错误,请重新输入\n");  
		printf("以下操作将会覆盖已存储的数据,确定请输入'y'或'n'		\n"); 
		scanf("%c",&c); 
		fflush(stdin);  
	}
	  
	if (c=='y')  
	{  
		if((fp=fopen("d:\\stu.dat","wb"))==NULL)  
		{  
		    printf("文件打开错误,程序无法进行\n");  
		    exit(0);  
		}  
		for(j=0;j<count;j++)  
		{
			fwrite(&stu[j],sizeof(struct student),1,fp);  
		}  
		fclose(fp);  
		if(count==0)  
		    printf("没有文件，无法保存\n");  
		else  
			printf("数据存储完毕\n");  
		system("pause");  
	}  
	else  
	    return;  
}  
void fileread(struct student stu[M])
{  
	int j=0;  
	char c;  
	FILE *fp;  
	system("cls");  
	printf("请选择是否要存入已输入的学生信息:'y'还是'n'		\n");  
	scanf("%c",&c);
	
	fflush(stdin);  
	while(c!='y'&&c!='n')
	{  
		if (c!='y'&&c!='n')  
		printf("输入错误,请重新输入\n");  
		printf("以下操作将会覆盖已存储的数据,确定请输入'y'或'n'		\n");  
		scanf("%c",&c);  
		fflush(stdin);  
	} 
	if (c=='y')  
	{  
		if((fp=fopen("d:\\stu.dat","rb"))==NULL)  
		{  
		    printf("文件打开错误,程序无法进行\n");  
		    exit(0);  
		}  
		fread(&stu[j],sizeof(struct student),1,fp);   
		count=0;  
		count++;  
		j++;  
		while(fread(&stu[j],sizeof(struct student),1,fp))  
		{  
		    j++;  
		    count++;  
		}  
		fclose(fp);  
		printf("数据读取完毕!!!\n");  
		system("pause");  
	}  
	else  
		return;  
} 
void kaifaren(struct student stu[M])
{
	printf("201705010309 张子敏\n");
	printf("201705010303 李玉红\n");
	printf("201705010311 訾海燕\n");
	return; 
}
void xitongjieshao(struct student stu[M])
{
	printf("系统介绍：\n");
	printf("本菜单设计主要是学生信息的浏览情况。\n");
	printf("分别用十几个函数实现了：添加学生信息、浏览学生信息、查询学生信息、修改学生信息、删除学生信息、\n");
	printf("排列学生信息、读取文件学生、保存到文件、退出系统九个功能。另外还有开发人介绍和系统介绍两部分。\n");
	printf("在运行此系统是，可根据界面提示完成自己的目的。\n");
	printf("最后退出即可。\n");
	return;
}
