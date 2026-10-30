#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

// 模拟实现 strncpy
char* my_strncpy(char* dest, const char* src, size_t n)
{
    assert(dest != NULL && src != NULL);
    char* p = dest;
    size_t i;
    
    // 1. 复制最多 n 个字符，遇到 src 的 '\0' 提前停止
    for (i = 0; i < n && src[i] != '\0'; ++i) 
    {
        p[i] = src[i];
    }

    // 2. 如果 src 长度小于 n，剩余部分用 '\0' 填充
    //    (若 src 长度 >= n，此时 i == n，此循环直接跳过，不补 '\0')
    for (; i < n; ++i)
    {
        p[i] = '\0';
    }
    return dest;
}
