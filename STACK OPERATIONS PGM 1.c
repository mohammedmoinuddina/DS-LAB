#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int stack[SIZE];
int top=-1;

void push(int value)
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("%d Pushed into stack\n",value);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from the stack\n",stack[top]);
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("stack elements are \n");
        for(int i=top; i>=0; i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("Stack Operation\n");
        printf("1.Push 2.Pop 3.Display 4.Exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("enter the element to push:");
                scanf("%d",&value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program");
                exit(0);

            default:
                printf("invalid choice");
        }
    }
}
