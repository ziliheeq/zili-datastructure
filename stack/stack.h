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
    SHARED_STACK_NUMBER_WRONG
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