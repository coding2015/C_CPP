/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C)
 *	    Recursion Function
 *	    递归函数虽编写代码量少，但其编译时展开的代码量却是倍数计的，而且因为多次 * 调用函数，运行效率低 
 *History:
 *2015-5-21	megan	最大公约数：辗转相除法，更相减损法
 */

#include<stdio.h>

/*最大公约数(Greatest Common Divisor)
 *两数公有约数的乘积（两数各自分解的质因数中公共约数的乘积）
 *一、辗转相除法：
 *		两数辗转相除，直到余数为0
 *		A/B=B1...r1，B/B1=B2...r2 ...，直到余数为0，对应除数即为最大公约数
 *二、更相减损法：
 *		不同时为偶的两数（若同时为偶，先去偶化，保存约数）辗转相减，直到差为0
 *		|A-B|=B1，|B-B1|=B2 ...,，直到差为0，则最大公约数为约数*差为0对应的减数  * */
int AltermatingDivision(int x, int y)
{
//	printf("%d/%d=%d...%d\n",x,y,x/y,x%y);
//	if(x%y)
//	{
//		AltermatingDivision(y,x%y);
//	}
//	printf("return y = %d\n",y);
//	return y; //error 这样返回的是第一次调用的结果

	printf("%d/%d=%d...%d\n",x,y,x/y,x%y);
	if(x%y)
	{
		return AltermatingDivision(y,x%y);		
		//展开：
		//设共调用了3次
		//return A1 == return A2 == return A3
		//故最终的返回值为A3
	}
	printf("return y = %d\n",y);
	return y;
}

int GreatestCommonDivisor(int x, int y)
{
	int AltermatingSubtraction(int,int);
	//先去偶化，使两数不同时为偶数
	int factor = 1;
	while((x%2==0) && (y%2==0))
	{
		factor *= 2;
		x /= 2;
		y /= 2;
	}
	return factor*AltermatingSubtraction(x,y);
}

int AltermatingSubtraction(int x, int y)
{
	if(x!=y)
	{
		//x=|x-y|;//error:C语言不支持“||”绝对值符号
		x = x>y?(x-y):(y-x);//取两数差的绝对值
		return AltermatingSubtraction(y,x);
	}
	return x;
}

void main()
{
	int x,y;
	int divisor = 0;
	printf("input 2 integers:\n");
	scanf("%d%d",&x,&y); //scanf以输入的回车或空格或tab作为一个整数输入的结束
	//scanf("%d,%d",&x,&y);//用户必须输入‘，’，否则scanf不知到一个整数的结束
	//divisor = AltermatingDivision(x,y);
	divisor = GreatestCommonDivisor(x,y);
	printf("the greatest common divisor of %d and %d is:%d\n",x,y,divisor);
}
