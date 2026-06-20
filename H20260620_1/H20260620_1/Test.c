#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//使用所学文件操作，在当前目录下放一个文件data.txt
//写一个程序，将data.txt文件拷贝一份，生成data_copy.txt文件
//基本思路：
//打开文件data.txt，读取数据
//打开文件data_copy.txt，写数据
//从data.txt中读取数据存放到data_copy.txt文件中，直到文件结束
//关闭两个文件

int main()
{
	FILE* pr = fopen("data.txt", "r");
	if (NULL == pr)
	{
		perror("fopen for read");
		return 1;
	}
	FILE* pw = fopen("data_copy.txt", "w");
	if (NULL == pw)
	{
		perror("fopen for write");
		fclose(pr);
		return 1;
	}

	int ch = 0;
	while ((ch = fgetc(pr)) != EOF)
	{
		fputc(ch, pw);
	}

	fclose(pr);
	fclose(pw);
	pr = NULL;
	pw = NULL;
}