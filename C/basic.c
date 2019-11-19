#include <stdio.h>
#include <string.h>
/*
	包含char、short、int、float、double、long
		char|一个byte|8bit
		shor|两个byte|16bit

	sizeof是一种运算符（类似+-），其值在编译时已经计算好了
	strlen为函数，是计算有效长度的，其值在运行时才算出。遇到第一个'\0'则结束计数

	预编译：gcc -E basic.c -o basic.i
			gcc -E -C circle.c -o circle.c --->不会删除源码中注释部分
*/

int main()
{
	char str[20] = "hello world";
	char *test = "hello world";
	// printf("%s",str);
	printf("sizeof(*test) = %d\n",sizeof(test));
	printf("sizeof(str)   = %d\n",sizeof(str));
	printf("sizeof(str[0])= %d\n",sizeof(str[0]));
	printf("sizeof(char)  = %d\n",sizeof(char));
	printf("strlen(test)   = %d\n",strlen(test));	
	printf("strlen(str)   = %d\n",strlen(str));
	
	//常用--遍历--不定长数组
	int arr[]={1,2,3};
	for(int i=0;i<(sizeof(arr)/sizeof(int));i++)
	{
		printf("%d,",arr[i]);
	}
	return 0;
}