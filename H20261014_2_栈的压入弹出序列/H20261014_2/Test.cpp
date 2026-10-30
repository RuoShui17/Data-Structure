#define _CRT_SECURE_NO_WARNINGS 1

//给定 pushed 和 popped 两个序列，每个序列中的值都不重复，
//只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，
//返回 true；否则，返回 false

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int stackArr[1000];
    int top = 0;
    int j = 0;
    for (int i = 0; i < pushedSize; i++)
    {
        //入栈一个数据
        stackArr[top] = pushed[i];
        //尝试持续匹配出栈序列
        while (top != 0 && stackArr[top - 1] == popped[j])
        {
            top--;//出栈
            j++;//出栈序列取下一个
        }
    }
    return top == 0;//如果栈内都出完了就是匹配
}