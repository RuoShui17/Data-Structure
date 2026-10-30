#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 建小堆的向下调整算法
void AdjustDown(int* a, int n, int parent)
{
    // 假设左孩子是较小的
    int child = parent * 2 + 1;

    // 只要孩子节点还在数组范围内，就继续比
    while (child < n)
    {
        // 1. 找出左右孩子中【较小】的那一个
        // 注意：必须加 child + 1 < n 的判断，防止右孩子越界
        if (child + 1 < n && a[child + 1] < a[child])
        {
            child++; // 如果右孩子更小，child就指向右孩子
        }

        // 2. 如果较小的孩子，比父亲还要小，说明破坏了小堆的性质
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]); // 孩子和父亲交换，小的往上走
            parent = child;              // 父亲往下走
            child = parent * 2 + 1;      // 重新计算新的左孩子
        }
        else
        {
            // 如果孩子比父亲大，说明已经符合小堆要求，不用调了
            break;
        }
    }
}

void CreateNDate() { 
    // 造数据⼀堆随机数据⽂件中，⽅便测试
    int n = 100000; 
    srand(time(0)); 
    const char* file = "data.txt";     
    FILE* fin = fopen(file, "w");     
    if (fin == NULL) { 
        perror("fopen error"); 
        return; 
    } 
 
    for (int i = 0; i < n; ++i) { 
        int x = (rand() + i) % 1000000; 
        fprintf(fin, "%d\n", x); 
    } 
 
    fclose(fin); 
} 


void topk() {
    // 1. 获取用户想要找的前 K 个数
    printf("请输入k：>");
    int k = 0;
    scanf("%d", &k);

    // 2. 打开刚才造好的文件
    const char* file = "data.txt";
    FILE* fout = fopen(file, "r"); // 以“读”模式打开（"r"）
    if (fout == NULL) {
        perror("fopen error");
        return;
    }

    // 3. 在内存中申请一个大小为 K 的数组（这就是那个“漏斗”）
    int val = 0;
    int* minheap = (int*)malloc(sizeof(int) * k);
    if (minheap == NULL) {
        perror("malloc error");
        return;
    }

    // 4. 从文件里读取【前 K 个数】，放进数组
    for (int i = 0; i < k; i++) {
        fscanf(fout, "%d", &minheap[i]);
    }

    // 5. 把这前 K 个数，建造成一个【小根堆】
    // 因为此时数组长度为 k，所以从最后一个非叶子节点 (k-1-1)/2 开始向下调整
    for (int i = (k - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(minheap, k, i);
    }

    // 6. 核心逻辑：遍历文件里【剩余的 10万 - K 个数据】
    int x = 0;
    while (fscanf(fout, "%d", &x) != EOF) { // 只要没读到文件末尾，就一直读
        // 如果当前读到的数字 x，比堆顶（也就是这 K 个数里最小的那个）还要大
        if (x > minheap[0]) {
            // 直接把堆顶干掉，让 x 上位
            minheap[0] = x;
            // 然后对堆顶进行向下调整，重新选出这 K 个数里的最小值，放到堆顶
            AdjustDown(minheap, k, 0);
        }
    }

    // 7. 遍历结束后，堆里剩下的 K 个数，就是全场最大的前 K 个数（虽然不一定是按顺序排的）
    for (int i = 0; i < k; i++) {
        printf("%d ", minheap[i]);
    }

    // 8. 打扫战场
    free(minheap);
    fclose(fout);
}
