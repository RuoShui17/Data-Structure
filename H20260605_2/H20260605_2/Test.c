#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//写一个函数，可以逆序一个字符串的内容

void reverseString(char* str)
{
	char* p = str + strlen(str) - 1;
	while (p >= str)
	{
		printf("%c", *p);
		p--;
	}

}

int main()
{
	char arr[] = "Hello World!";
	reverseString(arr);

	return 0;
}