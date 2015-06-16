/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C)
 *			 
 *History:
 *
 */

#include<stdio.h>

float fun()
{
	float x = 1.0;
	return x;
}

void main()
{
	int intnum = (int)(4.8);
	float floatnum = (float)(12);
	intnum = (int)fun();
	printf("%d",intnum);
}
