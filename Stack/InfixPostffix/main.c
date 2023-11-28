#include "stack.c"
#include "string.h"
int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 5;
    case '*':
    case '/':
    case '%':
        return 4;
    case '+':
    case '-':
        return 3;

    default:
        return -1;
    }
}
char *infixToPostfix(char s[100])   
{
    stack st;
    init(&st, 100);
    char *res = (char *)malloc(sizeof(char) * 100);
    int m = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] >= '0' && s[i] <= '9')
        {
            *(res + m) = s[i];
            m++;
        }
        else if (s[i] == '(')
        {
            push(&st, s[i]);
        }
        else if (s[i] == ')')
        {
            while (!isEmpty(st) && peek(&st) != '(')
            {
                *(res + m) = pop(&st);
                m++;
            }
            if (!isEmpty(st))
            {
                pop(&st);
            }
        }
        else
        {
            while (!isEmpty(st) && precedence(peek(&st)) > precedence(s[i]))
            {
                *(res + m) = pop(&st);
                m++;
            }
            push(&st, s[i]);
        }
    }
    while (!isEmpty(st))
    {
        *(res + m) = pop(&st);
        m++;
    }
    *(res + m) = '\0';
    return res;
}

char *toPrefix(char u[100]){
    int length = 0;
    char *s = (char *)malloc(sizeof(char)* 100);
    strcpy(s, u);

    for(int i=0;s[i]!='\0';i++){
        if(s[i] == '(')
        s[i] = ')';
        else if(s[i] == ')')
        s[i] = '(';
        length++;
    }
    int start = 0;
    int end = length - 1;
    int temp;
    while(start < end){
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    printf("%s",s);
    return infixToPostfix(s);
}
char *toPostFix(char s[100])
{
    char *result = (char *)malloc(sizeof(char) * 100);
    stack st;
    char c;
    int j = 0;
    init(&st, 100);
    for (int i = 0; s[i] != '\0'; i++)
    {
        c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            *(result + j++) = c;
        }
        else if (c == '(')
        {
            push(&st, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(st) && peek(&st) != '(')
            {
                *(result + j++) = pop(&st);
            }
            if (!isEmpty(st))
            {
                pop(&st);
            }
        }
        else
        {
            while (!isEmpty(st) && precedence(peek(&st)) > precedence(c))
            {
                *(result + j++) = pop(&st);
            }
            push(&st, c);
        }
    }
        while (!isEmpty(st))
        {
            *(result + j++) = pop(&st);
        }
    *(result + j++) = '\0';

    return result;
}
int main()
{
    char *exp = "(a-b/c)*(a/k-l)";
    char *result = toPostFix(exp);
    printf("%s\n", result);
    result = toPrefix(exp);
    printf("%s", result);
    return 0;
}