#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int stackpre(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 4;
        case '$':
        case '^':
        return 5;
        case '(':
        return 0;
        case '#':
        return -1;
        default:
        return 8;
    }
}

int infixpre(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 3;
        case '$':
        case '^':
        return 6;
        case '(':
        return 9;
        case ')':
        return 0;
        default : 
        return 7;
    }
}

void infix_postfix(char infix[],char postfix[])
{
    char s[30],symbol;
    int i,j,top;
    top=-1;
    s[++top]='#';
    j=0;

    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        while(stackpre(s[top])>infixpre(symbol))
        postfix[j++]=s[top--];
        if(stackpre(s[top])!=infixpre(symbol))
        s[++top]=symbol;
        else
        top--;
    }
    while(s[top]!='#')
    {
        postfix[j++]=s[top--];
    }
    postfix[j]='\0';
}


int main()
{
    char infix[30],postfix[30];
    printf("\n Enter infix expression : ");
    scanf("%s",infix);
    printf("\n Equivalent postfix expression is : \n");
    infix_postfix(infix,postfix);
    printf(" %s",postfix);
    return 0;
}