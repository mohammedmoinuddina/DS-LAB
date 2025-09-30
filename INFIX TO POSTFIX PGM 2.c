#include<stdio.h>
#define MAX 10

char stack[MAX];
int top=-1;

void push(char c)
{
if(top<MAX-1)
{
stack[++top]=c;
}
}

char pop()
{
if(top>=0)
{
return stack[top--];
}
return 0;
}

char peek()
{
if(top>=0)
return stack[top];
return 0;
}

int precedence(char c)
{
    switch(c)
    {

    case '^':return 3;
    case'*':
    case'/': return 2;
    case'+':
    case'-': return 1;
    default: return 0;
    }

}

int isOperand(char c)
{
    if((c>='A'&& c<='Z')|| (c>='a'&& c<'z')||(c>='0'&&c<='9'))
       {
           return 1;
       }
       return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, k = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        switch (c) {
            case '(':
                push(c);
                break;

            case ')':
                while (top != -1 && peek() != '(')
                        {
                    postfix[k++] = pop();
                }
                pop();
                break;

            case '+': case '-': case '*': case '/':
                while (top != -1 && precedence(peek()) >= precedence(c))
                    {
                    postfix[k++] = pop();
                }
                push(c);
                break;

            case '^':
                while (top != -1 && precedence(peek()) > precedence(c))
                    {
                    postfix[k++] = pop();
                }
                push(c);
                break;

            default:
                if (isOperand(c))
                    {
                    postfix[k++] = c;
                }
                break;
        }
        i++;
    }

    while (top != -1)
        {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s",infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}




