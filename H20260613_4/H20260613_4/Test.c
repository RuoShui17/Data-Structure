#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟实现strcmp

char* my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	if (ret > 0)
		printf("arr1 > arr2\n");
	else if (ret == 0)
		printf("arr1 == arr2\n");
	else
		printf("arr1 < arr2\n");
	return 0;
}