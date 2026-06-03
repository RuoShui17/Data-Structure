#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//给定两个数，求这两个数的最大公约数
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d", &a, &b);
	while (c = a % b) {
		a = b;
		b = c;
	}
	printf("%d", b);
	return 0;
}