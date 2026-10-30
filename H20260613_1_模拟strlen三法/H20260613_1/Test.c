#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟实现strlen

int my_strlen1(const char* p)
{
	//计数器⽅式
	int count = 0;
	assert(p);
	while (*p)
	{
		count++;
		p++;
	}
	return count;
}

int my_strlen2(const char* p)
{
	//不能创建临时变量计数器
	assert(p);
	if (*p)
	{
		return 1 + my_strlen2(p + 1);
	}
	else
	{
		return 0;
	}
}

int my_strlen3(const char* p)
{
	//指针-指针的⽅式
	assert(p);
	char* start = p;
	while (*p)
	{
		p++;
	}
	return p - start;
}

int main()
{
	char arr[] = "abcdef";
	printf("%d\n", my_strlen1(arr));
	printf("%d\n", my_strlen2(arr));
	printf("%d\n", my_strlen3(arr));
	return 0;
}