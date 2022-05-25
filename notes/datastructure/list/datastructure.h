enum {
    RUN_SUCCESS = 0,
    OUT_OF_INDEX,
    LIST_IS_FULL,
    LIST_IS_EMPTY,
    ELEMENT_IS_NOT_EXIST,
    LENGTH_IS_NEGATIVE,
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
Status ClearList(LinkList* L);
void PrintLinkList(const LinkList L);

/* 静态链表 */
#define MAXSIZLINKLIST 1000
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZLINKLIST];