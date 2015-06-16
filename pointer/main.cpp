/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C++
 *		ponter		 
 *History:
 *2015-5-16	megan	function-pointer
 *2015-5-20	megan	pointer	
 */

#include<stdio.h>
#include<string.h>

int Max(int x, int y)
{
	return x>y?x:y;
}

int Min(int x, int y)
{
	return x<y?x:y;
}

int Add(int x, int y)
{
	return x+y;
}

/*Function-Pointer as function arguments
 */
int fun(int x, int y,int (*p)(int,int))
{
	return p(x,y);
}


/*Multy-Array Pointer as function argument
 * Visit Multy-Array by pointer to single-dimentional array
 */
void VisitMultyArray(int(*p)[3],int n)
{
	for(int i=0; i<n; i++,p++)
	{
		for(int j=0; j<3; j++)
		{
			printf("%2d ",(*p)[j]);
		}
		printf("\n");
	}
}

/*Visit Multy-Array by pointer to array-element
 */
void VisitMultyArray(int *p,int m,int n) //C不支持重载
{
	for(int i=0; i<m*n; i++,p++)
	{
		printf("%2d ",*p);
		if((i+1)%n==0) 
			printf("\n");
	}
}

//pointer array
void SortStringsByInsert(char **str,int n) //注意别漏了[],表示为数组类型
{
	//insert sorting
	for(int i=1;i<n;i++)
	{
		char* obj = str[i];
		int j = i;
		//for(j>0;strcmp(obj,str[j-1])<0;) //error:段错误，for的第一个分句为初值语句
		while(j>0 && strcmp(obj,str[j-1])<0)
		{
			str[j] = str[j-1];
			j--;
		}
		if(j!=i)
		{
			str[j]=obj;
		}
	}
}

void SortStringsBySelect(char *str[],int n)
{
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(str[j],str[min])<0)
				min = j;
		}
		if(min!=i)
		{
			char *temp = str[i];
			str[i] = str[min];
			str[min] = temp;
		}
	}
}

void PrintfStrings(char **str, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%s\\",str[i]);
	}
	printf("\n");
}

//int main() //()=(void)
int main(int argc, char *argv[])
{
 int a[5][3]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

/*pointer to multy array
 *Type Array[m][n][o]
 *Type (*p)[m][o] = Array
 */
	//一维数组指针访问二维数组
	//int (*p)[3]=a;
	//VisitMultyArray(p,5);

/*pointer to array-element
 *Type Array[n]
 *Type *p = Array
 */
	//元素类型指针访问二维数组
	//int *ps = a[0];
	//VisitMultyArray(ps,5,3);


/*pointer to pointer
 *Type *pt;
 *Type **p = &pt;
 *相当于Type* (*p)，(*p)表示p是指针变量，Type* 表示p指向的类型
 */
	char* strings[3]={"Program C","Compile by g++","ANSI C"};
	int n = 3;
	//strings[0] = strings[1];
	//字符串指针数组排序
	//PrintfStrings(strings,n);
	//SortStringsBySelect(strings,n);
	//SortStringsByInsert(strings,n);
	//PrintfStrings(strings,n);
/*main(int argc, char *argv[])
 *运行时输入参数：
 *$ ./main test multy-argument argv
	argv[0]:./main
	argv[1]:test
	argv[2]:multy-argument
	argv[3]:argv
 */
	//for(int i=0; i<argc; i++)
		//printf("argv[%d]:%s\n",i,argv[i]);
	for(argv += argc-1;argc>0;argc--,argv--)
		printf("argv[%d]:%s\n",argc-1,*argv);

/*pointer array
 *Type *p[m][n][o]
 *[]的优先级高于*,p与[]先结合成数组，其类型为Type*
 */
 
	
/*poniter to function
 *function: TypeA Function(TypeB x, TypeC y, ...)
 *pointer:  TypeA (*Pointer)(TypeB,TypeC, ...)
 */
//	int (*p)(int,int)=NULL; 
//	int a,b;
//	//scanf("input a number");//error:什么也没有显示,scanf是输入,printf才是输出
//	printf("input a number:");
//	scanf("%d",&a);
//	printf("input a number:");
//	scanf("%d",&b);
//	printf("which one do you want:\n1:max,2:min,3:sum\n");
//	int choose = 0;
//	scanf("%d",&choose);	
//	//swich(choose)//error：expected ‘;’ before ‘{’ token;实际上是switch拼写错误
//	switch(choose) //switch 是关键字,显示的颜色不同就对了
//	{
//		case 1:
//			printf("the max is:%d\n",fun(a,b,Max));
//			break;已写入已写入
//		case 2:
//			printf("the min is:%d\n",fun(a,b,Min));
//			break;
//		case 3:
//			printf("the sum is:%d\n",fun(a,b,Add));
//			break;
//		default:
//			break;
//	}	
//	printf("which one do you want? 1:max,2:min\n");
//	int choose = 0;
//	scanf("%d",&choose);
//	if(choose==1)
//	{
//		p=Max;
//		printf("the max is:%d\n",(*p)(a,b));//调用时有无*都可以,p(a,b)等同于(*p)(a,b)
//	}else if(choose==2)
//	{
//		p=Min;
//		printf("the min is:%d\n",p(a,b));
//	}
	
	return 0;
}

