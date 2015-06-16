/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C, std=C99)
 *		algorithm		 
 *History:
 *2015-5-17	megan	algorithm:bubble,select,insert 
 *2015-5-18 megan	algorithm:shell;summary
 *2015-5-19 megan	debug
 */

#include<stdio.h>
//#define DEBUG

//两数交换
void Swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//打印数组
void PrintfArray(int a[],int n)
{
	for(int i=0; i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}

/*冒泡算法
 *从数组末尾(或开头)开始比较相邻两元素,将最大(或最小)元素冒到头(或尾)
 *最好情况：数组已经排好序，此时比较次数n-1，交换次数0
 *最坏情况：数组逆序，此时比较次数n-1+...+1，交换次数n-1+...+1
 *时间复杂度：O(n^2)
 */
void Bubble(int a[], int n)
{
	#ifdef DEBUG
	int exchangeTimes=0,compareTimes=0; 
	#endif
	for(int i=0; i<n-1; i++)
	{
		//bool isExchanged = false; //gcc编译器不支持bool类型(g++支持)
		int isExchanged = 0;
		for(int j=n;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				Swap(a+j,a+j-1);
				isExchanged = 1;
				#ifdef DEBUG
				exchangeTimes++;
				#endif 
			}
			#ifdef DEBUG
			compareTimes++;
			#endif
		}
		if(!isExchanged)
			break;
	}
	#ifdef DEBUG
	printf("%s:compareTimes=%d,exchangeTimes=%d\n",__FUNCTION__,compareTimes,exchangeTimes);
	#endif
}

/*选择算法
 *每次排序找出最大数,记录其下标,与本次排序首元素交换
 *最好情况：数组已经排好序，此时比较次数n-1+...+1，交换次数0
 *最坏情况：数组逆序，此时比较次数n-1+...+1，交换次数n-1
 *时间复杂度：O(n^2)
 */
void Select(int a[],int n)
{
	#ifdef DEBUG
	int exchangeTimes = 0, compareTimes=0; 
	#endif
	
	for(int i=0; i<n-1; i++)
	{
		int max = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			{
				max = j;
			}			
			#ifdef DEBUG
			compareTimes++;
			#endif
		}
		if(max != i)
		{	
			Swap(a+i,a+max);
			#ifdef DEBUG
			exchangeTimes++;
			#endif 
		}
	}
	#ifdef DEBUG
	printf("%s:compareTimes=%d,exchangeTimes=%d\n",__FUNCTION__,compareTimes,exchangeTimes);
	#endif
}

/*直接插入算法
 *思路：
 *同理牌,从第二张牌起,将牌插入前面的牌中
 *找到要插入的位置,位置之后的牌依次移位,腾出位置给目标牌插入
 *最好情况：数组已经排好序，此时比较次数n-1，移动次数0，插入次数0
 *最坏情况：数组逆序，此时比较次数1+...+n-1，移动次数1+...+n-1，插入次数n-1
 *时间复杂度：O(n^2)
 *性能比冒泡和选择排序要好一些//？
 */ 
void Insert(int a[],int n)
{
	#ifdef DEBUG
	int insertTimes = 0, moveTimes = 0, compareTimes=1;
	#endif
	for(int i=1; i<n; i++)
	{
		int obj = a[i]; //要插入的目标牌
		int j = i;
	  	//while(j>i && a[j]>a[j-1]) //error:应该为j>0, j>i的话就不用比了
		//while(j>0 && a[j]>a[j-1]) //error:比较的应该是目标元素,而不是相邻元素
		while(j>0 && obj>a[j-1]) 
		{
			a[j] = a[j-1]; //移位
			j--;
			#ifdef DEBUG
			compareTimes++, moveTimes++;
			#endif
		}
		if(j != i ) //如果发生了移位(即腾出了位置),就插入空位
		{
			a[j] = obj;
			#ifdef DEBUG
			insertTimes++;
			#endif
		}
	}
	#ifdef DEBUG
	printf("%s:compareTimes=%d,moveTimes=%d,insertTimes=%d\n",__FUNCTION__,compareTimes,moveTimes,insertTimes); 
	#endif
}

/*希尔算法——直接插入算法升级
 *思路：
 *当数组基本有序时，直接算法在O(n^2)复杂度的算法中最高效
 *——>想方设法使数组基本有序后再进行直接插入算法
 *——>对数组进行间隔(增量)直接插序，使数组基本有序
 *间隔(增量)选择：数组大小/3+1 
 *最好的增量还没法确定，研究表明增量=log2(n+1)时效果最好
 *时间复杂度O(n^3/2)
 */
void Shell(int a[],int n)
{
	#ifdef DEBUG
	int insertTimes=0,moveTimes=0,compareTimes=1;
	#endif
	int increment = n; //增量
	do
	{	
		increment = increment/3 + 1;
		for(int i=increment;i<n;i++)
		{
			int obj = a[i];
			int j = i;
			//while(j>increment && obj>a[j-increment]) //error:应为j>0,否则不用比了
			//while(j>0 && obj>a[j-increment]) //error:j-increment 可能小于0，插入时就有可能污染数组外的内存,运行时一旦发生污染将会报错：error,段错误（吐核）
			while(j>=increment && obj>a[j-increment])
			{
				#ifdef DEBUG
				compareTimes++, moveTimes++;
				#endif
				a[j] = a[j-increment];
				j-=increment;
			}	
			if(i!=j)	
			{
				#ifdef DEBUG
				//printf("move:a[%d]=%d,insert[%d]=%d\n",j,a[j],i,obj);
				insertTimes++;
				#endif
				a[j] = obj;
			}
		}
	}while(increment>1);
	#ifdef DEBUG
	printf("%s:compareTimes=%d,moveTimes=%d,insetTime=%d\n",__FUNCTION__,compareTimes,moveTimes,insertTimes);
	#endif
}

void main()
{
	int a[10]={23,44,14,77,3,58,1,90,16,81};
	int n=10;	
	PrintfArray(a,n);
	//Bubble(a,n);//Bubble:compareTimes=45,exchangeTimes=26
	//Select(a,n);//Select:compareTimes=45,exchangeTimes=8
	//Insert(a,n);//Insert:compareTimes=27,moveTimes=26,insertTimes=6
	Shell(a,n);//Shell:compareTimes=25,moveTimes=24,insetTime=13
	PrintfArray(a,n);
}
