/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C,Posix)
 *	    handle variable argument list by <stdarg.h>,Posix standard 
 *History:
 *2015-05-20	megan	first-release:implement multy-argument calculation
 */

#include<stdio.h>
#include<stdarg.h>

int Add(int num, ...)
{
	va_list argument;
	int sum = 0;
	
	va_start(argument,num); //初始化va_list = num;
	for(int i=0;i<num;i++)
	{
		sum += va_arg(argument,int); //va_arg指向下一个参数
	}
	va_end(argument); //清空argument

	printf("the sum of %d numbers:%d\n",num,sum);
	return sum;
}


void main()
{
	Add(3,4,4,4); //12
	Add(6,1,2,3,4,5,6); //21
}
