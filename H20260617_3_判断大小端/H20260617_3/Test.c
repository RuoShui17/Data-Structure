#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//使用联合体的知识，写一个函数判断当前机器是大端还是小端，
//如果是小端返回1，如果是大端返回0

int check_sys()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}