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


/* 初始化链表
Status LinkListInit(LinkList L, size_t length) {
    if (length < 1) return LENGTH_IS_NEGATIVE;

} */
void PrintLinkList(const LinkList L) {
    LinkList ptr;
    LinkList p;

    while(L) {
        printf(" %d ", L->data);
        T = T->next;
    }
}

/* 1 < i < ListLength(L) */
/* 在 L 中底 i 位置之前插入新的数据元素 e， L 的长度加 1 */
Status LinkListInsert(LinkList* L, size_t i, ElemType e) {
    size_t j;
    LinkList p, s;

    p = *L;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }

    if (!p || j > i)
        return ELEMENT_IS_NOT_EXIST;
    s = (LinkList)malloc(sizeof(Node)); /* 生成新节点 */
    s->data = e;
    s->next = p->next;
    p->next = s;
    return RUN_SUCCESS;
}

/* 链表删除元素 */
Status LinkListDelete(LinkList* L, size_t i, ElemType* e) {
    size_t j;
    LinkList p, q;

    p = *L;
    j = 1;
    /* 因为有一个头指针，没有数据 */
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ELEMENT_IS_NOT_EXIST;
    q = p->next;
    p = p->next;
    *e = p->data;
    free(q);
    return RUN_SUCCESS;
}


/* 头插法 */
void LinkListCreateHead(LinkList* L, size_t n) {
    LinkList p;
    size_t i;

    srand(time(0));
    /* 建立一个带头结点的单链表 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (i = 0; i < n; ++i) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; /* 随机生成100以内的数字 */
        p->next = (*L)->next;
        (*L)->next = p->next; /* 插入到表头 */
    }
}

/* 尾插法 */
void LinkListCreateTail(LinkList* L, size_t n) {
    LinkList p, r;
    size_t i;

    srand(time(0));
    *L = (LinkList) malloc(sizeof(Node));
    r = *L;

    for (i = 0; i < n; ++i) {
        p = (Node*)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

Status InitStaticLinkList(StaticLinkList space){
    size_t i;
    for (i = 0; i < SMAXSIZE - 1; ++i) 
        space[i].cur = i + 1;
    space[SMAXSIZE-1].cur = 0;

    return RUN_SUCCESS;
}

Status StaticListInsert(StaticLinkList L, size_t i, ElemType e) {
    int j, k, l;
    k = SMAXSIZE - 1;
    if (i < 1 || i > ListLen)
}