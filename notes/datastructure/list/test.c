#include <stdio.h>
#include "datastructure.h"

static int test_count = 0;
static int test_pass = 0;
#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if(equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual); \
        } \
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static SqList generator(int length) {
    if (length > MAXSIZE) return;
    SqList a;
    size_t i;
    a.length = length;
    for (i = 0; i < length; ++i) 
        a.data[i] = i * i + 11;
    return a;       
}

static void LinkListGen(LinkList L, int length) {
    size_t i;
    LinkList head;
    head->next = L;
    for (i = 0; i < length; ++i) {
        L->data = i * i + 2;
    LinkList head = L;
    size_t i;
    for (i = 0; i < length; ++i) {
        LinkList T;
        T->data = 12 * i + 2;
        L->next = T;
        L = L->next;
    }
    L->next = NULL;
    L = head;
}

void test_get_elements(){
    SqList a  = generator(10);
    int res;
    GetElem(a, 1, &res);
    EXPECT_EQ_INT(res, 11);
    GetElem(a, 2, &res);
    EXPECT_EQ_INT(res, 12);

    InsertElem(&a, 2, 222);
    GetElem(a, 2, &res);
    EXPECT_EQ_INT(res, 222);
}

void test_del_elements(){
    SqList a = generator(10);
    int res;
    GetElem(a, 3, &res);
    EXPECT_EQ_INT(res, 15);

    DeleteElem(&a, 3, &res);
    EXPECT_EQ_INT(res, 15);

    GetElem(a, 3, &res);
    EXPECT_EQ_INT(res, 20);
    EXPECT_EQ_INT(a.length, 9);

    EXPECT_EQ_INT(0, DeleteElem(&a, 9, &res));
    EXPECT_EQ_INT(res, 92);
    EXPECT_EQ_INT(a.length, 8);
}

/*
test_link_list_get_element() {
    LinkList L;
    LinkListGen(L, 10);
    PrintLinkList(L);

}
*/


int main() {
    test_get_elements();
    test_del_elements();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return 0;
}