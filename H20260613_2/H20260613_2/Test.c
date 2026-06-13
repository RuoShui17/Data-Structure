#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟实现strcpy

char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	//while ((*dest++ = *src++))
	//{
	//	;
	//}
	*dest = *src;
	return ret;
}

int main()
{
	char arr1[10] = { 0 };
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}