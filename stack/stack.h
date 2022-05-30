#ifndef STACK_H__
#define STACK_H__

#include <stdlib.h>

typedef int SElemType;

#define MAXSIZE 1000

typedef int Status;

typedef struct {
    SElemType data[MAXSIZE];
    int top;  /* 栈顶指针 */
} SqStack;

enum {
    RUN_SUCCESS = 0,
    STACK_IS_FULL = 1,
    STACK_IS_EMPTY,
    SHARED_STACK_NUMBER_WRONG,
    QUEUE_IS_FULL,
    QUEUE_IS_EMPTY,
    MEM_OVERFLOW
};

Status Push(SqStack* s, SElemType e);
Status Pop(SqStack* s, SElemType* e);

/* 两个栈共享空间结构 */
typedef struct {
    SElemType data[MAXSIZE];
    int top1;  /* 栈 1 --栈顶指针 */
    int top2;  /* 栈 2 --栈顶指针 */
} SqDoubleStack;

Status DPush(SqDoubleStack* s, SElemType e, size_t stackNum);
Status DPop(SqDoubleStack* s, SElemType* e, size_t stackNum);

/* 链表 */
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

/* 链表栈 */
typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

Status LPush(LinkStack* s, SElemType e);
Status LPop(LinkStack* s, SElemType* e);

enum {
    FALSE,
    TRUE
};

int isStackEmpty(const LinkStack* s);

/*斐波那契数列递归函数*/
int Fbi(int i);

/*循环队列*/
typedef int QElemType;
typedef struct {
    QElemType data[MAXSIZE];
    int front; /*头指针*/
    int rear; /*尾指针，如果队列不空，指向队列下一个元素*/
} SqQueue;

Status InitQueue(SqQueue* q);
size_t QueueLength(const SqQueue* q);
/* 若队列未满，则插入元素 e 为 Q 新的队尾元素 */
Status EnQueue(SqQueue* q, QElemType e);
/* 若队列不空，则删除 Q 中对头元素，使用 e 返回其值 */
Status DeQueue(SqQueue* q, QElemType* e);

/* 链栈 */
/* 节点 */
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

/* 队列的链表结构 */
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

/* 插入队列 */
Status LEnQueue(LinkQueue* q, QElemType e);
/* 出队列 */
Status LDeQueue(LinkQueue* q, QElemType* e);
#endif