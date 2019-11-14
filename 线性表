# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# define MAXSIZE 100
# define OK 1
# define ERROR 0
# define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct book
{
    char  id[20];//图书的ISBN
    char name[20];//图书名字
    float price;//图书价格
}book;
typedef struct 
{
   book *elem;//存储空间的基地址
   int length;//图书表中当前的图书个数  相当于线性表的长度

}Sqlist;
Status InitList(Sqlist &L)//构造一个空的顺序表L
{
    L.elem= (struct book *)malloc(sizeof(struct book)*100);//为顺序表分配一个大小为MAXSIZE的空间
    if(!L.elem)
    {
        printf("存储空间分配失败！！");
        exit(OVERFLOW);
    }
    L.length = 0;
    return OK;
}
void shuru(Sqlist &L)
{
    int i=0;
    FILE *fp;
    char name[20];//文件名
    char c;
    L.elem=(struct book *)malloc(sizeof(struct book)*100);
    if(!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length=0;
    if((fp = fopen ("book.txt","a"))==NULL)
    {
        fp=fopen("book.txt","w");
		fclose(fp);
    }
	   fp=fopen("book.txt","a");//追加写打开进行录入数据 
        printf("请输入图书数据 （id  name  price）\n");
		scanf("%s%s%f",L.elem[i].id,L.elem[i].name,&L.elem[i].price);
        fprintf(fp,"%-4s%-5s%-6f\n",L.elem[i].id,L.elem[i].name,L.elem[i].price);
        i++;
		getchar();
        printf("是否继续输入？(Y/N)");
        scanf("%s",&c);
        while(c!='N') 
        {
        printf("请输入图书数据 （id  name  price）\n");
		scanf("%s%s%f",L.elem[i].id,L.elem[i].name,&L.elem[i].price);
        fprintf(fp,"%-4s%-5s%-6f\n",L.elem[i].id,L.elem[i].name,&L.elem[i].price);
        i++;
		printf("是否继续输入？(Y/N)");
		scanf("%s",&c);
        }
        if(c=='N')
        {
            printf("输入信息完毕\n");
            L.length =i;
        }
        fclose(fp);//关闭文件
    
}
Status GetElem (Sqlist L,int i,book &e)
{
    if(i<1 || i>L.length)//i值不合理
    return ERROR;
    e=L.elem[i-1];//下标要减1
    return OK;
}
int LocateElem(Sqlist L,float price)
{
    for(int j=0;j<L.length;j++)
    {
        if(L.elem[j].price==price)
        {
            return ++j;
        }
    }
    return 0;
}
Status ListInsert(Sqlist & L,int i,book e)
{
    if(i<1||i>L.length)//i值不合法
    return ERROR;
    if(L.length == MAXSIZE)
    return ERROR;//存储空间已经满了
	else
	{
    for(int j = L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];//插入位置之后的元素后移  
    }
	   L.elem[i-1]=e;//将新元素放入要插入的位置
        ++L.length;//表长加1
        return OK;
	}

}
Status ListDelete(Sqlist &L,int d)
{
    if(d<1||d>L.length)
    return ERROR;
	else
	{
    for(int j =d;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
       
    }
	 --L.length;
        return OK;
	}
}
void shuchu(Sqlist L)
{
    printf("当前图书系统信息读出：\n");
    for(int i=0;i<L.length;i++)
    {
        printf("%-6s%-5s%-5.2f%\n",L.elem[i].id,L.elem[i].name,L.elem[i].price);
    }
}
void save(Sqlist L)
{
	FILE *fp;
	int i=0;
	fp=fopen("book.txt","w");//清空文件，只写打开，然后关闭
	fclose(fp);
	fp=fopen("book.txt","a");//追加文件
	while(L.length != i)//把链表内容覆盖到文件
	{
		fprintf(fp,"%-4s%-5s%-6f\n",L.elem[i].id,L.elem[i].name,&L.elem[i].price);
		i++;
	}
	printf("成功退出系统");
	fclose(fp);//关闭文件
	

}
int main()
{
    Sqlist L;
    book e;
    int i,temp,choose,a,d;
    float price;
    printf("***************************************  \n");
    printf("*              1.建立                   *\n");
    printf("*              2.输入                   *\n");
    printf("*              3.取值                   *\n");
    printf("*              4.查找                   *\n");
    printf("*              5.插入                   *\n");
    printf("*              6.删除                   *\n");
    printf("*              7.输出                   *\n");
    printf("*              0.退出                   *\n");
    printf("**************************************** \n");
	while(1)
	{
		printf("请输入您的选择：");
    scanf ("%d",&choose);
    while (choose<0||choose>7)
    {
		printf("输入错误，请重新输入你的选择：");
		scanf("%d",&choose);

	}
        switch (choose)
        {
        case 1://顺序表的创建
           if(InitList (L))
           {
               printf("创建顺序表成功\n");
           } else
           {
               printf("顺序表创建失败！！\n");
           }
           
            break;
        case 2://顺序表信息输入
        shuru(L);
           break;
        case 3://顺序表的取值
          printf("请输入一个位置来取值：");
          scanf("%d",&i);
           if(GetElem(L,i,e))
           {
               printf("查找成功\n");
               printf("第%d本图书的信息是：\n",i);
               printf("%-5s%-6s%-5.2f",e.id,e.name,e.price);
			   printf("\n");
           }
           else
           {
            printf("查找失败！！\n");
           }
           break;
        
     case 4://顺序表的查找
        printf("请输入需要查找的价格：");
        scanf("%f",&price);
        temp=LocateElem(L,price);
        if(temp!=0)
        {
            printf("查找成功\n");
            printf("该价格对应的图书的书名为：%-6s",L.elem[temp-1].name);
			printf("\n");
        }
        else printf("查找失败。没有该价格的图书\n");
        break;
    case 5://顺序表的插入
    printf("请输入插入的位置和书本信息，包括（ id name price）\n");
    printf("插入位置：");
    scanf("%d",&a);
    printf("插入的信息：");
    scanf("%s%s%f",e.id,e.name,&e.price);
    if(ListInsert (L,a,e))
    {
        printf("插入成功\n");
    }
    else printf("插入失败！！\n");
      break;
	case 6://顺序表的删除
		{
      printf("请输入要删除的位置：");
      scanf("%d",&d);
      if(ListDelete(L,d))
      printf("删除成功\n");
      else printf("顺序失败\n");
      break;
		}
      case 7://顺序表的输出
      shuchu(L);
      break;
	  case 0:
		  save(L);//退出之前保存数据
		break;
     
        default:printf("ERROE");
            break;
        }
    }
    return 0;
}


