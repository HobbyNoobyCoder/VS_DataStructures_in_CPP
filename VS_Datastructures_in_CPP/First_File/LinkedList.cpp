#include "stdafx.h"
#include<iostream>
using namespace std;
struct Node {
	int nodeData;
	struct Node* next;
};
struct Node* Head = NULL;
void insertListData(struct Node**, int data);
void displayListData(struct Node*,int level=1);
struct Node* createNode();

int main()
{
	std::cout << "Program started \n";
	insertListData(&Head, 1);
	insertListData(&Head, 2);
	insertListData(&Head, 3);
	insertListData(&Head, 4);
	cout << "Inserting of Data Done \n";

	displayListData(Head);

	cout << "End of program\n";
	return 0;
}

void insertListData(struct Node** head, int data)
{
	if (*head == NULL)
	{
		*head = createNode();
		(*head)->nodeData = data;
		(*head)->next = NULL;
	}
	else
	{
		insertListData(&((*head)->next), data);
	}

}

struct Node* createNode()
{
	struct Node* new_node = (struct Node*)malloc(1 * sizeof(struct Node));
	if (new_node == NULL)
	{
		cout << "Memory Error, Exiting application\n";
		exit (1);
	}
	return new_node;
}

void displayListData(struct Node* nodePtr, int level)
{
	if (nodePtr != NULL)
	{
		displayListData(nodePtr->next, level+1);
		cout << "The element in Node " << level << " is " << nodePtr->nodeData<<"\n";
	}
	else
	{
		cout << "\n Reached Null Node\n";
	}
}
