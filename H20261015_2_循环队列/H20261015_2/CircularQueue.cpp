#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* arr;//指向数组的指针
	int front;//指向对头
	int rear;//指向队尾的下⼀个位置
	int N;//空间⼤⼩，队列⻓度为N - 1
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->arr = (int*)malloc(sizeof(int) * (k + 1));
	obj->front = 0;
	obj->rear = 0;
	obj->N = k + 1;
	return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->arr[obj->rear++] = value;
	obj->rear %= obj->N;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front++;
	obj->front %= obj->N;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->arr[(obj->rear - 1 + obj->N) % obj->N];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % obj->N == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->arr);
}
