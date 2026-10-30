#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h>
#include<string.h> 

typedef int HeapDataType;
typedef struct {
	HeapDataType* a;
	int size;
	int capacity;
}Heap;

void Swap(int* x, int* y);

//向上调整算法
void AdjustUp(HeapDataType* a, int child);

//堆的插⼊
void HeapPush(Heap* hp, HeapDataType x);


//向下调整算法
void AdjustDown(HeapDataType* a, int n, int parent);

// 堆的删除，删除堆顶数据
void HeapPop(Heap* hp);


//默认初始化堆
void HeapInit(Heap* hp);

//堆的销毁
void HeapDestroy(Heap* hp);

//利⽤给定数组初始化建堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n);


// 获取堆顶数据
HeapDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
bool HeapEmpty(Heap* hp);