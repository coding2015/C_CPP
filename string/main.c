/* 
 *Linux version: 3.10.0-229.4.2.el7.x86_64 (builder@kbuilder.dev.centos.org)  
 *GCC version: 4.8.2 20140120 (Red Hat 4.8.2-16) (GCC) )  
 *Release:#1 SMP Wed May 13 10:06:09 UTC 2015 
 *
 *Copyright (C）2015, Megan, All Rights Reserved.
 *
 *Description:
 *		Program Language:C (ANSI C)
 *      string
 *History:
 *2015/05/14 megan strlen()
 *2015/05/15 megan copy_string()
 */



#include<stdio.h>
#include<string.h> //strlen()等字符串处理函数


void copy_string(char *from, char *to)
{
	//while(*from != '\0')
	//{
	//	*to++ = *from++;
	//}
	//*to='\0';
	
	//while((*to++=*from++)!='\0');//先赋值，再与‘\0'比较，最后to与from再自增
	while(*to++=*from++);//'\0'的ASCII值为0
}


int main()
{

	/***copy_string***/
	/* error from与to被赋予的是字符串常量，常量储存空间内容不可更改，故通过指针修改常量存储空间报错
	char* from = "I am the present.";
	char* to = "I am the future.";
	copy_string(from,to);//段错误(吐核)
	*/
	//char from[]="I am the present1.";
	//char to[]="I am the future.";//注意：复制的空间应比复制的空间大,虽然结果显示正确，但超出的复制会改写to溢出的空间	
	char to[25]="I am the present.";
	char from[25]="I am the future.";

	printf("%s(%d)\n",to,strlen(to));
	copy_string(from,to);
	printf("%s(%d)\n",to,strlen(to));


//	char *string = "Hello world!";
//	printf("%s\n",string);	
//	string = "I'm a geek.";	
//	printf("%s\n",string);	
//	
//	char a[]="test";
//	//a++; //error: a is a constant
//	string = a;
//	string++;
//	string = NULL;
//
//	//strlen(const char*):返回字符串的实际长度，不包括‘\0’
//	printf("strlen(\"test\")=%d\n",strlen(a)); //4
//	int length = 0;
//	//length = strlen('w');//error:从类型‘char’到类型‘const char*’的转换无效 [-fpermissive]	
//	length = sizeof(strlen(""));
//	printf("sizeof(strlen(a))=%d\n",sizeof(strlen(a))); //8
//	printf("sizeof(size_t)=%d\n",sizeof(size_t));
//	printf("strlen(\"\")=%d\n",strlen("")); 
//	printf("sizeof(int)=%d\n",sizeof(int)); 
//	printf("sizeof(char)=%d\n",sizeof(char));

	return 0;
}
