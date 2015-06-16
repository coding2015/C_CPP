/*
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org) 
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) ) 
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C)
 *	 	文件输入与输出		 
 *History:
 *
 */

#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *file = "./txt" ;
	FILE *fp = fopen(file,"r");
	if(fp == NULL)
	{
		printf("file %s doesn't exist!\n",file);
	}
	if(!(fp=fopen(file,"w")))
	{
		printf("creating file failed\n");
		exit(EOF);
	}
	
	printf("please input characters,or type '#'to teminate:\n");
	while(1)
	{
		char ch;
		//stdin,stdout,stderr point to system standard flue
		ch = fgetc(stdin); //用户可以从键盘连续输入一长串，然后fgetc逐个读取赋给ch处理
		if(EOF == ch)
			continue;
		if('#' == ch)
			break;
		fputc(ch,fp);
	}
	printf("fp:%p\n",fp);
	fclose(fp);
	printf("fp closed:%p\n",fp);
	fp = NULL;	
	printf("fp = NULL:%p\n",fp);
}
