#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//模拟实现strncat

char* my_strncat(char* dest, const char* src, size_t n)
{
	char* p = dest;

	// 1. 找到 dest 的末尾
	while (*p != '\0') {
		++p;
	}

	// 2. 追加最多 n 个字符
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; ++i) {
		p[i] = src[i];
	}

	// 3. 添加终止符
	p[i] = '\0';

	return dest;
}