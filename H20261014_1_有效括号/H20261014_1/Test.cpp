#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <stdbool.h> 

//栈具有后进先出的性质，括号类型和顺序和数量都要匹配，可以遍历字符串
//遇到左括号就⼊栈，遇到右括号就取栈顶的左括号进⾏匹配

typedef char STDataType;
typedef struct {
	STDataType* arr;//指向栈数组空间的指针

	int top;//栈顶位置

	int capacity;//容量

}Stack;

//栈的初始化
void StackInit(Stack* s)
{
	assert(s);
	s->arr = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (s->arr == NULL)
	{
		printf("申请空间失败");
		exit(-1);
	}
	s->top = 0;
	s->capacity = 4;
}


//栈的销毁
void StackDestroy(Stack* s)
{
	assert(s);
	if (s->arr)
	{
		free(s->arr);
		s->arr = NULL;
		s->top = 0;
		s->capacity = 0;
	}
}


//x元素⼊栈(进栈)
void StackPush(Stack* s, STDataType x)
{
	assert(s);
	if (s->capacity == s->top)
	{
		STDataType* tmp = (STDataType*)realloc(s->arr, sizeof(STDataType) * s->capacity * 2);
		if (tmp == NULL)
		{
			printf("扩容空间失败");
			exit(-1);
		}
		s->arr = tmp;
		s->capacity *= 2;
	}

	s->arr[s->top] = x;
	s->top++;
}


//将栈顶元素出栈，并⽤返回栈顶元素
STDataType StackPop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	STDataType x = s->arr[s->top - 1];
	s->top--;
	return x;
}


//获取栈顶元素并返回
STDataType StackTop(Stack* s)
{
	assert(s);
	assert(!StackEmpty(s));
	return s->arr[s->top - 1];
}


// 获取栈中有效元素个数
int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}


// 检测栈是否为空，如果是空返回真，否则返回假
bool StackEmpty(Stack* s)
{
	assert(s);
	return s->top == 0;
}

bool isValid(char* s) 
{
	Stack st;
	StackInit(&st);

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else
		{
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackPop(&st);
			if ((top == '(' && *s != ')') || (top == '[' && *s != ']') || (top == '{' && *s != '}'))
			{
				StackDestroy(&st);
				return false;
			}
		}
		s++;
	}
	bool empty = StackEmpty(&st);
	StackDestroy(&st);
	return empty;

}