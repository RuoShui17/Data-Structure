#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

char* strstr(const char* str1, const char* str2)
{
	char* s1;
	char* s2;
	char* pc = str1;
	if (*str2 == '\0')
	{
		return str1;
	}
	while (*pc)
	{
		s1 = pc;
		s2 = str2;
		while (s1 && s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return pc;
		}
		pc++;
	}
	return NULL;
}

int main()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = strstr(str, "simple");
	if (pch != NULL)
		printf("%s\n", pch);
	else
		printf("查找的字符串不存在\n");
	return 0;
}