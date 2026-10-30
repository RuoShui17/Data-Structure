#include "LinkQueue.h"

// 初始化队列
void QueueInit(LinkQueue* q) {
	assert(q);

	// 选择带头结点的结构
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));
	if (q->front == NULL) {
		printf("QueueInit: 申请结点失败\n");
		exit(-1);
	}
	q->front->next = NULL;
	q->size = 0;
}


// 销毁队列
void QueueDestroy(LinkQueue* q) {
	assert(q);

	QNode* cur = q->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}


// 检测队列是否为空，空返回真，否则返回假
bool QueueEmpty(LinkQueue* q) {
	assert(q);

	return q->size == 0;
}


// 获取队列中有效元素个数
int QueueSize(LinkQueue* q) {
	assert(q);

	return q->size;
}


// 获取队头元素
QDataType QueueFront(LinkQueue* q) {
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->next->data;
}

// 将x入队列
void EnQueue(LinkQueue* q, QDataType x) {
	assert(q);

	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		printf("EnQueue: 申请结点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}


// 出队并返回队头数据
QDataType DeQueue(LinkQueue* q) {
	assert(q);
	assert(!QueueEmpty(q));

	QNode* delNode = q->front->next;
	QDataType x = delNode->data;

	// 删除第一个结点
	q->front->next = delNode->next;
	free(delNode);
	delNode = NULL;
	q->size--;

	// 最后一个结点被删掉，rear 要指向哨兵的头结点
	if (q->front->next == NULL) {
		q->rear = q->front;
	}

	return x;
}