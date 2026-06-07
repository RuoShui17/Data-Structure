#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符（408题）
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

void reverseOne(char arr[], int len)
{
	char tmp = arr[0];
	for (int i = 1; i < len; i++)
	{
		arr[i - 1] = arr[i];
	}
	arr[len - 1] = tmp;
}

void reversePlural(char arr[], int len, int n)
{
	n = n % len;
	for (int i = 0; i < n; i++)
	{
		reverseOne(arr, len);
	}

}
//以上为暴力解法


void reverse_part(char* str, int start, int end) //将字符串从start到end这一段逆序
{
	int i, j;
	char tmp;

	for (i = start, j = end; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void leftRound(char* src, int time)
{
	int len = strlen(src);
	int pos = time % len;
	reverse_part(src, 0, pos - 1); //逆序前段
	reverse_part(src, pos, len - 1); //逆序后段
	reverse_part(src, 0, len - 1); //整体逆序
}
//以上为最优解法


int main()
{
	char arr[] = "abcdefg";
	leftRound(arr, 3);
	printf("%s", arr);
	return 0;
}