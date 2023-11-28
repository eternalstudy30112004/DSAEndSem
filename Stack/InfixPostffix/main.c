#include "stack.c"

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
char *infixToPostfix(char s[100]){
    stack s;
    init(&s, 100);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]>='0' && s[i]<='9'){

        }
    }
    
}
int main()
{

    return 0;
}