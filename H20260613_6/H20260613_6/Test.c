#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//模拟实现strncpy

char* my_strncpy(char* dest, const char* src, size_t n)
{
    char* p = dest;
    size_t i;

    // 复制最多 n 个字符
    for (i = 0; i < n && src[i] != '\0'; ++i) {
        p[i] = src[i];
    }

    // 如果 src 长度小于 n，用 '\0' 填充剩余部分
    for (; i < n; ++i) {
        p[i] = '\0';
    }
    return dest;
}