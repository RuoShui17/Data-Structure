#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

const char* my_strstr(const char* str1, const char* str2)
{
    const char* s1;
    const char* s2;
    const char* pc = str1;

    if (*str2 == '\0')          // 空子串，直接返回 str1
    {
        return str1;
    }

    while (*pc)                 // 遍历每个可能的起点
    {
        s1 = pc;
        s2 = str2;

        // 逐字符比较，直到某个字符串结束或字符不同
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
        {
            s1++;
            s2++;
        }

        if (*s2 == '\0')        // str2 走完 = 匹配成功
        {
            return pc;
        }

        pc++;                   // 换下一个起点
    }

    return NULL;                // 没找到
}

int main()
{
    char str[] = "This is a simple string";
    const char* pch;

    pch = my_strstr(str, "simple");
    if (pch != NULL)
        printf("%s\n", pch);
    else
        printf("查找的字符串不存在\n");

    return 0;
}
