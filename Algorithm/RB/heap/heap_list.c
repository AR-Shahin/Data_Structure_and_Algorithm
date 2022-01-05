#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int priority;
    int data;
    struct node *link;
} NODE;
NODE *front = NULL;
void insert(int item, int priority)
{
    NODE *newnode, *temp;

    newnode = malloc(sizeof(NODE));
    newnode->data = item;
    newnode->priority = priority;
    if (front == NULL || priority < front->priority)
    {
        newnode->link = front;
        front = newnode;
    }
    else
    {
        temp = front;
        while (temp->link != NULL && temp->link->priority <= priority)
            temp = temp->link;
        newnode->link = temp->link;
        temp->link = newnode;
    }
}
void delet()
{
    NODE *temp;
    if (front == NULL)
        printf("empty queue\n");
    else
    {
        temp = front;
        printf("Deleted item is %d\n", temp->data);
        front = front->link;
        free(temp);
    }
}
void display()
{
    NODE *dis;
    dis = front;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("data  priority\n");
        while (dis != NULL)
        {
            printf("%5d   %5d\n", dis->data, dis->priority);
            dis = dis->link;
        }
    }
}
int main()
{
    int choice, item, priority;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the value of data : ");
            scanf("%d", &item);
            printf("Enter its priority : ");
            scanf("%d", &priority);
            insert(item, priority);
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}
