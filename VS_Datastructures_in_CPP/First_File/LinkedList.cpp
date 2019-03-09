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
	int rec_num;
	std::cout << "Program started \n";
	cout << "Enter the number of Datas to be Stored\n";
	cin >> rec_num;
	for (int i = 0,data; i < rec_num; i++)
	{
		cout << "Enter the record no " << i<<"\n";
		cin >> data;
		//data -= 48;
		insertListData(&Head,((int)data));
	}
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
		cout << "The element in Node " << level << " is " << nodePtr->nodeData<<"\n";
		displayListData(nodePtr->next, level + 1);
	}
	else
	{
		cout << " Reached Null Node\n";

	}
}
