#define _CRT_SECURE_NO_WARNINGS 1
#include "SqList.h"

int main()
{
    SqList s;
    SqListInit(&s);

    // 尾插
    SqListPushBack(&s, 10);
    SqListPushBack(&s, 20);
    SqListPushBack(&s, 30);
    SqListPushBack(&s, 40);
    SqListPrint(&s);  // 10 20 30 40

    // 头插
    SqListPushFront(&s, 5);
    SqListPrint(&s);  // 5 10 20 30 40

    // 按下标插入
    SqListInsert(&s, 2, 99);
    SqListPrint(&s);  // 5 10 99 20 30 40

    // 头删
    SqListPopFront(&s);
    SqListPrint(&s);  // 10 99 20 30 40

    // 尾删
    SqListPopBack(&s);
    SqListPrint(&s);  // 10 99 20 30

    // 查找
    int idx = LocateElem(&s, 99);
    printf("99 的下标是：%d\n", idx);  // 1

    // 按下标删除
    SqDataType x = SqListDelete(&s, 1);
    printf("删除的值是：%d\n", x);  // 99
    SqListPrint(&s);  // 10 20 30

    // 获取元素个数
    printf("元素个数：%d\n", SqListSize(&s));  // 3

    // 判空
    printf("是否为空：%d\n", EmptySqList(&s));  // 0（false）

    // 销毁
    SqListDestroy(&s);

    return 0;
}