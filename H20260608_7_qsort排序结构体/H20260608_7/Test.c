#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//使⽤qsort排序结构数据

struct Stu
{
	char name[20];
	int age;
};

//假设按照年龄来⽐较

int cmp_stu_by_age(const void* p1, const void* p2)
{
	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
	//return (*(struct Stu*)p1).age - (*(struct Stu*)p2).age;
}

void test1()
{
	struct Stu s[] = { {"zhangsan", 20}, {"lisi", 30}, {"wangwu", 15} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}

//假设按照名字来⽐较

int cmp_stu_by_name(const void* p1, const void* p2)
{
	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

void test2()
{
	struct Stu s[] = { {"zhangsan", 20}, {"lisi", 30}, {"wangwu", 15} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}

int main()
{
	test1();
	test2();
	return 0;
}