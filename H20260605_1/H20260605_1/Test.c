#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//模拟实现库函数strlen

size_t my_strlen(char* p)
{
	char* start = p;
	while (*p != '\0')
	{
		p++;
	}
	return p - start;
}

int main()
{
	char arr[] = "abcdef";
	size_t len1 = strlen(arr);//接收无符号整型
	printf("%zu\n", len1);
	size_t len2 = my_strlen(arr);
	printf("%zu\n", len2);


	return 0;
}