#include "stdafx.h"
#include<iostream>
using namespace std;
/*Node Struct Declaration*/
struct Node {
	int nodeData;
	struct Node* next;
};
struct Node* Head = NULL;

/*Function Prototypes*/
void insertListData(struct Node**, int data);
void displayListData(struct Node*,int level=1);
struct Node* createNode();
void deleteListData(struct Node* Head,int level=1);

/*Main Function*/

int main()
{
	char rec_data='0';
	std::cout << "Program started \n";
	while (rec_data != 'e')
	{
		cout << "Enter \n 'a' to add Data\n 'd' to display entered data \n 'e' to end program\n";
		cin >> rec_data;

		switch (rec_data)
		{
		case 'a':
			int data;
			cout << "Enter the Data \n";
			cin >> data;
			cin.clear();
			insertListData(&Head, data);
			cout << "Inserting of Data " <<data<< " Done \n";
			break;

		case 'd':
			cout << "The Entered Data are as Follows: \n";
			displayListData(Head);
			break;
		case 'e':
			cout << "The entire list of entered Data are: \n";
			displayListData(Head);
			cout << "Deletion of list started" << endl;
			deleteListData(Head);
			break;
		default:
			cout << "Wrong option chosen, Please select the correct one" << endl;
			break;
		}
	}
	cout << "End of program\n";
	return 0;
}

/* Function Definations*/

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
		cout << "The element in Node " << level << " is " << nodePtr->nodeData << "\n";
		displayListData(nodePtr->next, level + 1);
	}
	else
	{
		if (level == 1)
		{
			cout << "List is Empty" << endl;
		}
		
		else
		{
			cout << " Reached Null Node\n";
		}
	}
}

void deleteListData(struct Node* Head,int level)
{
	if (Head == NULL)
	{ if(level==1)
		cout << "The List is empty"<<endl;
	else
		cout << "Complete List Deleted"<<endl;
	}
	else
	{
		cout << "Deleted data " << level <<" "<< Head->nodeData<<endl;
		deleteListData(Head->next, level + 1);
		free(Head);
	}
}