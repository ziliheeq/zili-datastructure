#include "stack.h"

Status Push(SqStack* s, SElemType e) {
    if (s->top == MAXSIZE - 1)
        return STACK_IS_FULL;
    
    s->top++; /* 栈顶指针加 1 */
    s->data[s->top] = e;
    return RUN_SUCCESS;
}

Status Pop(SqStack* s, SElemType* e) {
    if (s->top == -1)
        return STACK_IS_EMPTY;
    
    *e = s->data[s->top];
    s->top--;
    return RUN_SUCCESS;
}

/* 栈共享空间 */

Status DPush(SqDoubleStack* s, SElemType e, size_t stackNum) {
    /* 栈满了 */
    if(s->top1 + 1 == s->top2)
        return STACK_IS_FULL;
    if (stackNum == 1)
        s->data[++s->top1] == e;
    else if (stackNum == 2)
        s->data[--s->top2] == e;
    else
        return SHARED_STACK_NUMBER_WRONG;
    return RUN_SUCCESS;
}

Status DPop(SqDoubleStack* s, SElemType* e, size_t stackNum) {
    if (stackNum == 1) {
        if (s->top1 == -1)
            return STACK_IS_EMPTY;
        *e = s->data[s->top1--];
    }
    else if (stackNum == 2) {
        if (s->top2 == MAXSIZE)
            return STACK_IS_EMPTY;
        *e = s->data[s->top2++];
    }
    else
        return SHARED_STACK_NUMBER_WRONG;
    return RUN_SUCCESS;
}

Status LPush(LinkStack* s, SElemType e) {
    /*链表栈不会满*/
    LinkStackPtr node = (LinkStackPtr) malloc(sizeof(StackNode));
    node->data = e;
    node->next = s->top;
    s->top = node;
    s->count++;
    return RUN_SUCCESS;
}

int isStackEmpty(const LinkStack* s) {
    if (s->top == NULL)
        return TRUE;
    else
        return FALSE;
}

Status LPop(LinkStack* s, SElemType* e) {
    LinkStackPtr p = s->top;
    
    if (isStackEmpty(s))
        return STACK_IS_EMPTY;
    *e = p->data;
    free(p);
    s->count--;

    return RUN_SUCCESS;
}

int Fbi(int i) {
    if (i < 2)
        return i == 0? 0 : 1;
    else
        return Fbi(i-1) + Fbi(i - 2);
}


