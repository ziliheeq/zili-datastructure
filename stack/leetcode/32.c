/* 
https://leetcode.cn/problems/longest-valid-parentheses/
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/
#include <stdio.h>

typedef struct {
    int data[30000];
    int top;
} stack;

void ppush(stack* s, char c) {
    s->data[s->top] = c;
    s->top++;
}

void ppop(stack* s, int* length) {
    *length = s->top;
    s->top = 0;
}

int longestValidParentheses(char* s){
    int MaxValidSubStrLen = 0;
    while (*s != '(')
        s++;
    stack st;
    st.top = 0;
    while(*s != '\0') {
        if(*s == '(' && *(s+1) == ')') {
            ppush(&st, '(');
            ppush(&st, ')');
            s++;
            s++;
        } else {
            int tempLen;
            ppop(&st, &tempLen);
            if (tempLen > MaxValidSubStrLen) 
                MaxValidSubStrLen = tempLen;
        }
    }

    return MaxValidSubStrLen;
}



int main() {
    char tar[] = ")()())";
    printf(")()()) --> %d\n", longestValidParentheses(tar));
    return 0;
}