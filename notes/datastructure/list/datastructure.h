enum {
    RUN_SUCCESS = 0,
    OUT_OF_INDEX,
    LIST_IS_FULL,
    LIST_IS_EMPTY,
    FASLE = 0,
    TRUE = 1
};

#define MAXSIZE 30

typedef int Status;
typedef int ElemType;


typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;


Status GetElem(SqList L, size_t i, ElemType* e);
Status InsertElem(SqList* L, size_t i, ElemType e);
Status DeleteElem(SqList* L, size_t i, ElemType* e);
void PrintList(const SqList* L);