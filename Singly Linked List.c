#include <stdio.h>
#include <stdlib.h>

// Structure of a LL Node
typedef struct Node
{
	int data;
	struct Node* next;
} Node;

/********************************* Insertion *********************************/

// Adds a new node at the begining of a LL
// Note : This function works even if the LL is empty ( i.e; HEAD is NULL)
// Time Complexity = O(1), Space Complexity = O(1)
void addNodeAtBegining(Node** head, int d)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = d;
	new_node->next = *head;
	*head		   = new_node;
	return;
}

// Adds a new node after a given position/ given node in the LL
// Note : A check has to be made to see if the given previous node is NULL.
// Time Complexity = O(1), Space Complexity = O(1)
void addNodeAfterPosition(Node* prev_node, int d)
{
	if (prev_node == NULL)
	{
		printf("The previous node cannot be NULL.");
		return;
	}
	Node* new_node	= (Node*)malloc(sizeof(Node));
	new_node->data	= d;
	new_node->next	= prev_node->next;
	prev_node->next = new_node;
	return;
}

/*  Adds a new node at the end of the LL.
	Note : A check is made to see if the given HEAD is NULL. In this case, we
	make the new node as HEAD
	Time Complexity = O(N) where N = no. of nodes in LL, Space Complexity = O(1)
	Optimizations : We can further optimize addNodeAtEnd to work in O(1) by
	maintaining a pointer to the end of LL.
 */
void addNodeAtEnd(Node** head, int d)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = d;
	new_node	   = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	Node* temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	return;
}

/********************************** Deletion **********************************/

// Deletion from the begining of LL gives us Segmentation Fault(core dumped) if
// LL is already empty (i.e; HEAD is NULL)

// Deletes a node from the begining of LL.
// Note : A check is made to see if HEAD is NULL & also if LL contains 1 node
// Time Complexity = O(1), Space Complexity = O(1)
void deleteNodeFromBegining(Node** head)
{
	if (*head == NULL)
	{
		return;
	}

	if (*head->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	Node* temp = *head;
	*head	   = *head->next;
	free(temp);
	temp = NULL;
	return;
}

// Deletes a node from the end of the LL.
// Note : A check is made to see if HEAD is NULL & also if LL contains 1 node
// Time Complexity = O(N) where N = no. of nodes in LL, Space Complexity = O(1)
void deleteNodeFromEnd(Node** head)
{
	if (*head == NULL)
		return;

	if (*head->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	Node* temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	return;
}

// Deletes a node at a given position in LL.
// Assumptions made : 1.) If position = 0, we have to delete HEAD, if position =
// N, then we have to reach the N-1th node so that we can delete the Nth node.
// 2.) There is always at least 1 node in the LL.
// Time Complexity = O(N), Space Complexity = O(1)
void deleteNodeAtPosition(int position)
{
	Node* temp = head;

	if (position = 0)
	{
		head = head->next;
		free(temp);
		temp = NULL;
		return;
	}

	int i = 0;
	while (i < position - 1)
	{
		temp = temp->next;
		i++;
	}
	Node* deleteNodePtr = temp->next;
	temp->next			= deleteNodePtr->next;
	free(deleteNodePtr);
	deleteNodePtr = NULL;
	return;
}