#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//写一个代码打印1-100之间所有3的倍数的数字
int main() {
	for (int i = 3; i <= 100; i += 3) {
		printf("%d ", i);
	}
	return 0;
}