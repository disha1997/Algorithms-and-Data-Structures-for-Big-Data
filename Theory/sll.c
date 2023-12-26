/********************************************************
*                                                   	*
*	Single linked list implementation		*
*							*
********************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node			/* data structure for single linked list   */
{
	int info;
	struct node *ptr;
};


struct node * insert_element (struct node*, int);	/* function to insert an element into sll  */

struct node * delete_element (struct node*, int);	/* function to delete an element from sll  */

void display_list (struct node *);			/* function to traverse (print) list 	*/

main()
{
	struct node *head = NULL;
	int choice, value;

	do
	{
		printf ("\n\nEnter the choice\n");
		printf ("1. Add to list\n2. Delete from list\n3. Display list\n4. Quit\n");

		scanf ("%d",&choice);
	
		switch (choice)
		{
			case 1:
				printf ("Enter the data to be added\n");
				scanf ("%d",&value);
				head = insert_element (head, value);		

				break;

			case 2:
				printf ("Enter the data to be deleted\n");
				scanf ("%d",&value);
				head = delete_element (head, value);
				break;

			case 3:
				display_list(head);
				break;

			case 4:
				break;
		}

	}while (choice!=4);
}


struct node * insert_element (struct node * start , int data)
{
	struct node* new_node, *cur_node;
	int pos, ele;

	new_node = (struct node*) malloc (sizeof(struct node));
	new_node->info = data;
	new_node->ptr  = NULL;
	
	printf ("Do you want to insert the node at the beggining? if yes eneter 1\n");
	scanf ("%d",&pos);

	if ( pos == 1 || start == NULL )
	{
		new_node->ptr = start;
		start = new_node;
		printf ("Data %d enetered into list\n",data);
	}
	else
	{
		cur_node = start;		

		printf ("Enter the data after which you want to insert new node\n");
		scanf ("%d",&ele);

		while ( cur_node != NULL && cur_node->info != ele)
			cur_node = cur_node->ptr;

		if (cur_node == NULL)
			printf ("Entered node is wrong!!  Data not found\n");
		else
		{
			new_node->ptr = cur_node->ptr;
			cur_node->ptr = new_node;
			printf ("Data %d enetered into list\n",data);
		}

	}
	return start;
}


struct node * delete_element (struct node * start, int data)
{
	struct node *cur_node, *pre_node;

	if (start == NULL)
	{
		printf("List is empty\n");
		return start;
	}

	cur_node = start;

	while(cur_node != NULL)
	{
		if (cur_node->info == data)
		{
			if (cur_node == start)
				start = start->ptr;
			else
				pre_node->ptr = cur_node->ptr;

			free(cur_node);
			printf ("Element %d is deleted from list\n",data);
			return start;
		}
		else
		{
			pre_node = cur_node;			
			cur_node = cur_node->ptr;
		}
	}

	printf("Entered data %d is not present in the list\n",data);
	return start;

}

void display_list (struct node *start)
{
	if (start == NULL)
	{
		printf(" empty list? \n");
		return;
	}
	printf ("Elements in the list\n");
	while (start!=NULL)
	{
		printf ("%d\t",start->info);
		start = start->ptr;
	}
	printf("\n");
}
