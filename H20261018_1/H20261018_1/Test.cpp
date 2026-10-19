#include "Heap.h"

int main()
{
	Heap hp;
	HeapInit(&hp);

	int arr[] = { 4, 2, 8, 1, 5, 6, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("--- 测试 Push ---\n");
	for (int i = 0; i < n; i++) {
		HeapPush(&hp, arr[i]);
	}

	printf("当前堆顶(最小值): %d\n", HeapTop(&hp));

	printf("依次出堆(Pop): ");
	while (!HeapEmpty(&hp)) {
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
	HeapDestroy(&hp);

	// ------------------------

	printf("\n--- 测试 InitArray ---\n");
	Heap hp2;
	HeapInitArray(&hp2, arr, n);

	printf("直接建堆后的堆顶: %d\n", HeapTop(&hp2));
	printf("依次出堆(Pop): ");
	while (!HeapEmpty(&hp2)) {
		printf("%d ", HeapTop(&hp2));
		HeapPop(&hp2);
	}
	printf("\n");
	HeapDestroy(&hp2);

	return 0;
}