#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>

//给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式
//请你计算该表达式。返回一个表示表达式值的整数

bool isOperand(const char* str)
{
	if (str[0] >= '0' && str[0] <= '9')
	{
		return true;
	}
	else if (str[0] == '-' && str[1] >= '0' && str[1] <= '9')
	{
		return true;
	}
	return false;

}


int evalRPN(char** tokens, int tokensSize)
{
	int stackArr[10000];
	int top = 0;
	for (int i = 0; i < tokensSize; i++)
	{
		if (isOperand(tokens[i]))
		{
			stackArr[top++] = atoi(tokens[i]);
		}
		else
		{
			int right = stackArr[--top];
			int left = stackArr[--top];
			switch (tokens[i][0])
			{
			case '+':
				stackArr[top++] = left + right;
				break;

			case '-':
				stackArr[top++] = left - right;
				break;

			case '*':
				stackArr[top++] = left * right;
				break;

			case '/':
				stackArr[top++] = left / right;
				break;

			}
		}

	}
	return stackArr[top - 1];
}