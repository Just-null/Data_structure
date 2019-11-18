# include <stdio.h>
# include <malloc.h>
#include <stdlib.h>
# define Empty 0
# define Have  1
# define ERROR 0
# define OK 1
typedef int Status;
typedef struct Node
{
	char str;
	struct Node *next;
}Node,*Link;

typedef struct
{
	Node *top;//栈顶指针
	Node *base;//栈底元素指针
	int heigth;//栈高
}List;

Status StackEmpty(List p)
{
	if(p.top==NULL&&p.base==NULL)
	{
		return Empty;
	}
	else 
		return Have;
}

void InitStack(List &p)//初始化栈
{
	p.top=p.base=NULL;//top初始化为base，空栈
	p.heigth=0;//栈高为0
	printf("初始化栈成功\n");
}

List Push(List p)
{
	

	Link temp;
	
		
		if((temp = (Link)malloc(sizeof(Node)))==NULL)
		{
			printf("内存不足\n");
			return p;

		}
		if(StackEmpty(p)==Empty)//StackEmpty(p)是判断栈是否为空的函数
		{
			p.top = p.base =temp;//栈顶，栈底指向新节点
			temp->next = NULL;
			printf("请输入栈元素：");
			scanf("%s",&p.top->str);
			p.heigth++;

			return p;
			
		}
		else //栈不为空
		{
			temp->next = p.top;//新建节点指向原来的栈顶
			p.top=temp;//栈顶指针指向新节点
			printf("请输入栈元素：");
			scanf("%s",&p.top->str);
			p.heigth++;
			return p;
			
		}

}

void DisplyStack(List p)
{
	if(StackEmpty(p)==Empty)
	{
		printf("栈为空，无法遍历！！");
		exit(-1);
	}
	printf("栈中元素[");
	while(p.top!=NULL)
	{
		printf("%-2C",p.top->str);
		p.top=p.top->next;
	}
	printf("]\n");
}

void  Pop(List &p)
{
	Link q=NULL;
	if(StackEmpty(p)==Empty)
	{
		printf("栈空，无法出栈！！");
		exit(-1);
	}
	printf("出栈元素为依次为:");
	while(p.top!=NULL)
	{

	if(p.top==p.base)//如果出栈源元素为最后一个
	{
		printf("%-2C",p.top->str);
		free(p.top);
		p.top=p.base=NULL;
		p.heigth--;
		
	}
	else
	{
	printf("%-2c",p.top->str);
	q=p.top->next;
	free(p.top);//释放栈顶元素
	p.top=q;
	p.heigth--;
	}

	}
	printf("\n");

}
void DeletStack(List p)
{
	Link d=NULL;
	while(p.top!=NULL)
	{
		d=p.top->next;
		free(p.top);
		p.top=d;
	}
	free(d);
	printf("清空栈成功\n");


}

int main(void)
{
	List p;

	int choose;
	char ch;
	printf("\t\t\t\t\n");
	printf("\t1.栈的初始化\t\n ");
	printf("\t2.入栈\t\n ");
	printf("\t3.遍历栈元素\t\n ");
	printf("\t4.出栈\t\n ");
	printf("\t5.清空栈\t\n ");
	printf("\t0.退出\t\n ");
	printf("\t\t\t\t\n");
	while(1)
	{
	printf("请输入你的选择：");
	scanf("%d",&choose);

		while(choose<0 || choose >5)
		{
			printf("输入错误，请重新输入你的选择：");
        	scanf("%d",&choose);
		}
		switch (choose)
        {
        case 1:///初始化栈
           InitStack(p);
            break;
        case 2://入栈
	printf("是否输入栈元素（Y/N）:");
	getchar();//消化回车符
	scanf("%c",&ch);
	while(ch=='Y'||ch=='y')
	{
		p=Push(p);
		
		printf("是否输入栈元素（Y/N）:");
	    getchar();//消化回车符
	    scanf("%s",&ch);
	}
        break;


        case 3://遍历栈元素
          DisplyStack(p);
           break;

     case 4://出栈 
		 Pop(p);
        break;

	 case 5:
		DeletStack(p);
		 break;
        default:printf("ERROE");
            break; 
    }
   
	}
	 return 0;


}
