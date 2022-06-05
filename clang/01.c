#include <stdio.h>


int readLine(char str[], int n) {
    int ch, i = 0;
    while((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}


int main() {
    printf("\x56\n"); /* V */

    char str[12] = "hello world"; /* 字符数组 */
    char *p; /* 字符指针 */
    p = str;

    printf("%.3s\n", p); 

    puts(str);


    char str1[20] ;
    /*
    scanf("%s", str1);
    puts(str1);
    char str2[20];
    gets(str2);
    puts(str2);
*/
    readLine(str1, 8);
    puts(str1);


    return 0;
}