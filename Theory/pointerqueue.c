#include<malloc.h>
#include<stdio.h>


struct node
{
	int info;
	struct node *ptr;
};
struct node * insertQueue(struct node *rear, struct node **front, int data)
{
	struct node *newNode;
	
newNode=(struct node *) malloc(sizeof(struct node));
	newNode->info = data;
	newNode->ptr = NULL;
		
	if( rear == NULL && *front == NULL)
		*front = newNode;
	else
		rear->ptr = newNode;
	
	rear = newNode;
	return rear; 
}

struct node * deleteQueue(struct node **rear, struct node *front)
{
	struct node *curNode;
	curNode = front;
	
	if(front == NULL)
	{
		printf("list is Empty");
		return front;
	}

	if(curNode->ptr != NULL)
		front = front->ptr;
	else
		*rear =front = NULL;
     printf("%d",curNode->info);
	free(curNode);

	return front;
		
}

main()
{	int data=1;
	struct node *rear, *front;
	front = rear = NULL;
	rear = insertQueue(rear, &front, data);
	front = deleteQueue(&rear,front);
	//printf("the content=%d",(*front)->info);
}


