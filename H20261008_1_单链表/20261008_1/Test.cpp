#include "List.h"

// 手动创建链表 [1, 2, 3, 4, 5]
LNode* CreateList()
{
    // 创建头结点
    LNode* L = BuyListNode(-1);

    // 先快速构造 5 个结点，方便测试
    LNode* node1 = BuyListNode(1);
    LNode* node2 = BuyListNode(2);
    LNode* node3 = BuyListNode(3);
    LNode* node4 = BuyListNode(4);
    LNode* node5 = BuyListNode(5);

    // 然后通过手动的方式将结点链接起来
    L->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    return L;
}


// 测试打印、长度、判空
void Test1()
{
    printf("===== Test1: 打印 + 长度 + 判空 =====\n");
    LNode* L = CreateList();
    ListPrint(L);                                          // head->1->2->3->4->5->NULL
    printf("长度：%d\n", ListSize(L));                       // 5
    printf("是否为空：%s\n", ListEmpty(L) ? "true" : "false");  // false
    ListDestroy(L);
    printf("\n");
}


// 测试查找
void Test2()
{
    printf("===== Test2: 查找 =====\n");
    LNode* L = CreateList();

    LNode* p = ListLocateElem(L, 3);
    printf("找到 3，值：%d\n", p->data);                    // 3

    p = ListLocateElem(L, 99);
    printf("找到 99：%s\n", p == NULL ? "没找到" : "找到了");  // 没找到

    p = ListGetElem(L, 2);
    printf("下标 2 的值：%d\n", p->data);                    // 3

    ListDestroy(L);
    printf("\n");
}


// 测试插入
void Test3()
{
    printf("===== Test3: 插入 =====\n");
    LNode* L = CreateList();

    ListInsert(L, 0, 99);              // head->99->1->2->3->4->5->NULL
    ListPrint(L);

    ListInsert(L, 3, 88);              // head->99->1->2->88->3->4->5->NULL
    ListPrint(L);

    ListInsert(L, ListSize(L), 77);    // 尾插
    ListPrint(L);

    ListPushFront(L, 66);              // 头插
    ListPrint(L);

    ListPushBack(L, 55);               // 尾插
    ListPrint(L);

    ListDestroy(L);
    printf("\n");
}


// 测试删除
void Test4()
{
    printf("===== Test4: 删除 =====\n");
    LNode* L = CreateList();

    LDataType x = ListDelete(L, 2);    // 删除下标 2（值为 3）
    printf("删除：%d\n", x);
    ListPrint(L);                      // head->1->2->4->5->NULL

    x = ListPopFront(L);               // 头删
    printf("头删：%d\n", x);
    ListPrint(L);                      // head->2->4->5->NULL

    x = ListPopBack(L);                // 尾删
    printf("尾删：%d\n", x);
    ListPrint(L);                      // head->2->4->NULL

    ListDestroy(L);
    printf("\n");
}


// 测试边界情况
void Test5()
{
    printf("===== Test5: 边界情况 =====\n");
    LNode* L = ListInit();
    printf("空链表：");
    ListPrint(L);                                          // head->NULL
    printf("长度：%d\n", ListSize(L));                       // 0
    printf("是否为空：%s\n", ListEmpty(L) ? "true" : "false");  // true

    ListPushBack(L, 10);
    ListPushBack(L, 20);
    ListPushBack(L, 30);
    ListPrint(L);                                          // head->10->20->30->NULL

    ListDestroy(L);
    printf("\n");
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}