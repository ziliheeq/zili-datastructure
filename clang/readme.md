[转义字符](https://www.ibm.com/docs/en/zos/2.3.0?topic=set-escape-sequences)

主要用在非可打印字符，如换行，tab等，可以转义十六进制对应字
```c
printf("\x56"); /* V */
```

c语言中字符串其实就是字符数组，每个字符串数组的长度要比字符串实际长度多加一个，用作存储结尾的空字符。示例：最多存储 80 个字符的字符串，分配空间需要有 81 个。

通常使用一个宏来定义数组长度，预处理时候会将此宏的值自动替换到代码位置。 `#define MAXSIZE 81`

字符数组和字符指针声明方式如下代码，字符指针声明之后可以指向其他字符指针和字符数组，但是两者不可以互换。可以使用`printf`函数写字符串, `%.ps`其中`p`是要显示的字符数量，可以使用`puts`函数输出字符串，它总会添加一个额外的换行符。

读取字符串

1. scanf 函数，`scanf("%s", str);`str是数组名称，函数调用时编译器会将其作为指针处理。特点：`从第一个非空白字符开始读取，遇到空白字符就结束读取，其中读取到的字符串存入字符数组。`

2. gets 函数，`gets(str);`直接读取输入，回车结束，保留所有空白符。

上述两种方式都会存在不知道何时填满预定数组空间的问题。一旦越界可能产生未定义的问题。
```c
char str[12] = "hello world"; /* 字符数组 */
char *p; /* 字符指针 */
p = str;
printf("%s\n", p); 
puts(str);
```

自己定义读取字符串的函数，需要注意在字符串最后加入空字符'\0`
```c
int readLine(char str[], int n) {
    int ch, i = 0;
    while((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
```
> 字符串

条件*s != '\0'与*s != 0是一样的，因为空字符的整数值就是0。

长度的计算方法，通过空字符所在的指针位置，减去首只针对位置，得到长度。
```c
size_t strlen(const char* s) {
    size_t n = 0;
    /*for (; *s != '\0'; s++)*/
    /*for (; *s; s++)*/
    /*for (; *s++;)*/
    const char* p = s;
    while(*s)
        s++;
    return s-p;
}
```
字符串连接函数，注意一定要保证 s1 的长度够存储两个字符串的长度，否则会出错--segmentation falut。
```
A segmentation fault occurs when a program attempts to access a memory location that it is not allowed to access, 
or attempts to access a memory location in a way that is not allowed (for example, attempting to write to 
a read-only location, or to overwrite part of the operating system).
```s
```c
/*字符串连接*/
char* strcat(char* s1, const char* s2) {
    char* p = s1;
    while(*p)
        p++;
    
    /*
    while(*s2) {
        *p = *s2;
        p++;
        s2++;
    }
    */
    /* 
      先赋值，判断 s2 的值是否是空字符
      while语句会测试赋值表达式的值，也就是测试复制的字符。除空字符以外的所有字符的测试结果都为真
      循环只有在复制空字符后才会终止
      由于循环是在赋值之后结束的，所以不用在最后补充空字符。
    */
    while(*p++ = *s2++)
        ;
    return s1;
}
```
