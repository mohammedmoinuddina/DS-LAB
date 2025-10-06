#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int queue[SIZE];
int front=-1,rear=-1;

void insert()
{
int value;
if((front==0 && rear==SIZE-1)|| (rear+1)%SIZE==front)
{
    printf("Queue Overflow!\n");
}

else
{
if(front==-1 )
front=0;

printf("Enter element to insert\n");
scanf("%d",&value);
rear=(rear+1)%SIZE;
queue[rear]=value;
printf("%d inserted into the queue\n",value);
}
}
void delete()
{
    if(front==-1)
    printf("Queue Underflow\n");
else
{
    printf("%d deleted from the queue\n",queue[front]);
    front++;

    if(front==rear)
    front=rear=-1;
    else
    front=(front+1)%SIZE;
}

}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue element:\n");
        int i=front;
        while(1)
        {
        printf("%d ",queue[i]);
        if(i==rear)
        break;
        i=(i+1)%SIZE;
        }



    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Queue Operations:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:
            printf("Exiting program\n");
            exit(0);
            default:
            printf("Invalid choice\n");
                }
    }
}
