# 1. [python tutorial](https://docs.python.org/3/tutorial/index.html)

python 是动态类型(dynamic typing)解释型语言.

- 动态类型：运行时检查变量类型
- 解释型：不需要编译，直接运行时解释执行

python 是抽象程度较高的编程语言，这样对用户使用越友好。

使用缩进来分组代码块，而不是通过`{}`

也不需要事先声明变量。
## 注释
1. 单行注释使用`#`
2. 多行注释使用三个单引号或三个双引号
```python
'''
多行注释一
多行注释
'''

"""
多行注释二
多行注释
"""
```
## 字符串使用说明

1. 单引号和双引号配对使用标识字符串，但是其间不能包含相同的类型，如""", '''
2. 可以交叉使用，如"'", '"'
3. 联结字符串 
```python
a = "hello"
b = "world"
print(a + " " + b) # hello world
```
4. 可通过数组索引使用，a = "hello"
```python
# 正序访问
a[0] #'h'
a[1] #'e'
# ....
# 逆序访问
a[-1] # 'o'
a[-2] # 'l'
#.....
```
5. 字符串长度使用`len()`函数

6. 切片——批量获取字符段

语法：字符串变量[开始位置索引(包括):结束位置索引(不包括):步进(间隔)]

索引支持倒序
```python
a = "hello world"
print(a[:]) # hello world
print(a[1:]) # ello world
print(a[::2]) # hlowrd
```
7. 字符串是不可以更改的，给字符串中某个字符重新赋值是错误的`a[0] = 'Q'`，这是错误的；而实际使用中需要‘修改’字符串是创建了一个新的字符串

python 的 [string 内存](https://rushter.com/blog/python-strings-and-memory/)

**python 根据不同的字符类型，使用不同的编码方式[长度不同1，2，4个字节]**

每个python字符串会占用额外的`49-80`个字节的内存空间，用来存储附加信息，如`hash`，`长度`,`字节长度`,`编码类型`,`字符串标志`，所以空字符串也会有`49`个字节大小`sys.getsizeof("")`。



## 列表——lists
1. 空列表：a = []
2. 联合：b = [1], a + b --> `[1]`
3. 切片(slice)：列表的切片是[浅拷贝(shallow copy)](https://docs.python.org/3/library/copy.html#shallow-vs-deep-copy)

浅拷贝或者深拷贝只是对组合对象来考虑。

> 浅拷贝——shallow copy
```
A shallow copy constructs a new compound object and then (to the extent possible) inserts references into it to the objects found in the original.

浅拷贝构造一个新的组合类型，并且将指向原先组合对象的引用放进去。【所以并不是新构建的对象拥有原先的一个副本，只是一个索引而已】
```
> 深拷贝——deep copy
```
A deep copy constructs a new compound object and then, recursively, inserts copies into it of the objects found in the original.

深拷贝构造一个新的组合类型，并且将原先对象拥有的元素完全的逐一拷贝到新对象中。
```
深拷贝和浅拷贝的区别示例
```python
# ----------浅拷贝-------------
# list 切片，赋值都是浅拷贝
a = [1, 2, 3, 5]
b = a
# b = [1, 2, 3, 5]
# 赋值
b[2] = 333
# b = [1, 2, 333, 5]
# a = [1, 2, 333, 5] ---> a 也跟着改变

# ----------深拷贝-------------
import copy
c = copy.deepcopy(a)
# c = [1, 2, 333, 5]
c[1] = 222
# c = [1, 222, 333, 5]
# a = [1, 2, 333, 5] ---> a 未改变

# copy.copy() 方法仍是浅拷贝
```
类用户要定义自己的拷贝实现方式，需要定义浅拷贝方法`__copy__()`和深拷贝方法`__deepcopy__()`

## 转换
数字-->字符串：`str(34)`

