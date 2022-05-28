enum {
    RUN_SUCCESS = 0,
    OUT_OF_INDEX,
    LIST_IS_FULL,
    LIST_IS_EMPTY,
    ELEMENT_IS_NOT_EXIST,
    LENGTH_IS_NEGATIVE,
    STATIC_MEMORY_IS_NOT_ENOUGH,
    FASLE = 0,
    TRUE = 1
};

#define MAXSIZE 30

typedef int Status;
typedef int ElemType;


/* 线性表——顺序存储结构 */
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

/* 线性表——链表 */
typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

/* 定义链表 */
typedef struct Node* LinkList;

Status GetElem(SqList L, size_t i, ElemType* e);
Status InsertElem(SqList* L, size_t i, ElemType e);
Status DeleteElem(SqList* L, size_t i, ElemType* e);
void PrintList(const SqList* L);

Status GetListLinkElem(LinkList L, size_t i, ElemType *e);
Status LinkListInit(size_t length);
Status LinkListInsert(LinkList* L, size_t i, ElemType e);
Status LinkListDelete(LinkList* L, size_t i, ElemType* e);
void LinkListCreateHead(LinkList* L, size_t n);
void LinkListCreateTail(LinkList* L, size_t n);
void PrintLinkList(const LinkList L);

/* 静态链表 */
#define SMAXSIZE 1000
typedef struct {
    ElemType data;
    int cur;  /* 相当于单链表中的 next 指针，存放下一个节点的数组下标 */
} Component, StaticLinkList[SMAXSIZE];

Status InitStaticLinkList(StaticLinkList space);

int Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur;

    if (space[0].cur)
        space[0].cur = space[i].cur;
    
    return i;
}

void Free_SLL(StaticLinkList space, size_t i) {
    space[0].cur = i;

}

Status StaticListInsert(StaticLinkList L, size_t i, ElemType e);
size_t StaticLinkListLength(StaticLinkList L);
Status StaticLinkDelete(StaticLinkList L, size_t i);

