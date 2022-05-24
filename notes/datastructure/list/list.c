#include <stdlib.h> /* size_t */
#include "datastructure.h"


/*
线性表顺序存储结构
*/


/* 获取元素 i 从 1 到 length */
Status GetElem(SqList L, size_t i, ElemType* e) {
    if (L.length == 0)
        return LIST_IS_EMPTY;
    if (i < 1 || i > L.length)
        return OUT_OF_INDEX;
    *e = L.data[i-1];
    return RUN_SUCCESS;
}

/* 插入元素 */
Status InsertElem(SqList* L, size_t i, ElemType e) {
    size_t j;
    /* 预分配限行空间已经满 */
    if (L->length == MAXSIZE)
        return LIST_IS_FULL;
    /* 1 <= i <= length */
    if ( i < 1 || i > L->length + 1)
        return OUT_OF_INDEX;
    
    /* 插入数据位置不在表尾 */
    if (i <= L->length) {
        for (j = L->length; j > i - 1; j--) {
            L->data[j] = L->data[j-1];
        }
    }


    L->data[i-1] = e;
    L->length++;
    return RUN_SUCCESS;
}

/* 删除元素 */
Status DeleteElem(SqList* L, size_t i, ElemType* e) {
    size_t j;
    /* 空列表，不允许执行删除 */
    if (L->length == 0)
        return LIST_IS_EMPTY;
    /* 删除范围 1 <= i <= length */
    if (i < 1 || i > L->length)
        return OUT_OF_INDEX;
    /* 不删除最后一个元素 */
    *e = L->data[i-1];
    if (i < L->length ) {
        for (j = i - 1; j < L->length; ++j)
            L->data[j] = L->data[j+1];
    }
    
    L->length--;
    return RUN_SUCCESS;
}

/* 打印序列 */
void PrintList(const SqList* L) {
    size_t i;
    printf("[ ");
    for (i = 0; i < L->length; ++i) 
        printf(" %d ", L->data[i]);
    printf("]\n");
}


/*
线性表——链表
*/
Status GetListLinkElem(LinkList L, size_t i, ElemType* e) {
    size_t j;
    LinkList p = L->next;
    j = 1;

    while(p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ELEMENT_IS_NOT_EXIST;
    
    *e = p->data;
    return RUN_SUCCESS;
}


/* 初始化链表 */
Status LinkListInit(LinkList L, size_t length) {
    if (length < 1) return LENGTH_IS_NEGATIVE;

}
void PrintLinkList(const LinkList L) {
    LinkList T = L;
    while(L) {
        printf(" %d ", L->data);
        T = T->next;
    }
}