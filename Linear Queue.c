#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int queue[SIZE];
int front=-1,rear=-1;
void insert()
{
if(rear==SIZE-1)
{
    printf("Queue Overflow!");
}

else
{
    if(front==-1 )
    front=0;
int value;
printf("Enter element to insert\n");
scanf("%d",&value);
rear++;
queue[rear]=value;
printf("%d inserted into the queue\n",value);
}
}
void delete()
{
    if(front==-1 || front>rear)
    printf("Queue Underflow");
else
{
    printf("%d deleted from the queue",queue[front]);
    front++;
}

}

void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue element:\n");
        for(int i =front;i<=rear;i++)
        {
            printf("%d",queue[i]);
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
