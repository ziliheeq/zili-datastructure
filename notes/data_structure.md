<[大话数据结构](https://book.douban.com/subject/6424904/)>
---
顺序存储结构：数据元素存储在连续地址的存储单元，逻辑关系和物理关系一致。

抽象数据类型（Abstract Data Type -- ADT）：一个数据模型及定义在该模型上面的一组操作。

逻辑结构：集合、线性、树形、图形

物理结构：顺序、链式

---

算法：解决特定问题求解步骤的描述，在计算机中表现为指令的有限序列，并且每条指令表示为一个或多个操作。

算法时间复杂度：

常数：`O(1)`

线性：`O(n)`
```c
int i;
for (i = 0; i < n; ++i) {
    /* 时间复杂度为常数(O(1))的程序序列 */
}
```

对数：`O(logn)`
```c
int count = 1;
while(count < n) {
    count *= 2; /* 步进为 2 */
    /* 时间复杂度为常数(O(1))的程序序列 */
}
```

平方阶：O(n<sup>2</sup>)

嵌套循环
```c
int i, j;
for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
            /* 时间复杂度为常数(O(1))的程序序列 */
    }
}
```
---
线性表：**零个或多个数据元素的有限序列**

常见操作：
- InitList(\*L): 初始化，建立一个空表
- ListEmpty(L): 线性表为空返回`true`
- ClearList(\*L): 清空线性表
- GetElem(L, i, \*e): 将线性表中第 i 个元素返回给 e
- LocateElem(L, e): 在线性表 L 中，查找与给定值 e 相等的元素，查找成功——序号；否则返回失败
- ListInsert(\*L, i, e): 在线性表中第 i 个位置插入新元素 e
- ListDelete(\*L, i, \*e): 删除线性表中第 i 个位置元素，并用 e 作为其返回值
- ListLength(L): 返回线性表 L 的元素个数

线性表顺序存储结构适合元素个数不大变化的，更多是存取数据的应用。

链式存储：用一组任意的存储单元存储线性表的数据元素，存储单元可以是连续的，也可以是不连续的。

链表定义:

[struct 的自引用](https://stackoverflow.com/questions/588623/self-referential-struct-definition)
```c
/* 线性表——链表 */
typedef struct Node {
    ElemType data;
    /* 不能包含 Node 的常量，这样会是不会结束的递归调用，可以包含 Node 的指针 */
    struct Node* next;
} Node;
```