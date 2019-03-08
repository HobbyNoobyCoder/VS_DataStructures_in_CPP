#include "stdafx.h"
#include<iostream>
using namespace std;
/*
struct Node {
	int data; 
	struct Node* Next;
} Node;
*/

struct Node {
	int data;
	struct Node* Next=NULL;
};
typedef struct Node* NodePtr;

void createNode(NodePtr*);
void insertData(NodePtr, char[]);
void DisplayDataAsQueue(NodePtr, int);

void insertData(NodePtr nodePtr, char data[])
{
	if (nodePtr == NULL)
	{
		createNode(&nodePtr);
		nodePtr->data = (int)(*data);
		nodePtr->Next = NULL;
	}
	else
	{
		insertData(nodePtr->Next, data);
	}

}

void DisplayDataAsQueue(NodePtr nodePtr, int level=1)
{
	if (nodePtr != NULL) {
		cout << "Element No " << level << "is" << nodePtr->data;
		DisplayDataAsQueue(nodePtr->Next, ++level);
	}
}

void createNode(NodePtr* node)
{
	*node = (NodePtr)malloc(1 * sizeof(struct Node));
	if (*node == NULL)
	{
		cout << "\n Memory Error , Exiting";
		exit(1);
	}

}


int main()
{
	char enteredData[25] = {};
	Node NodeLinkedList;
	int record;
	cout << "Enter the number of records to be stored\n";
	cin >> record;
	for(int i=0;i<record;i++)
	{
		cout << "Entered Data is before " << enteredData;
		cout << "Enter a Number to be stored or type end to exit \n";
		cin >> enteredData;
		try {
			if (enteredData == "end")
				throw enteredData;
			else
			{
				insertData(&NodeLinkedList,enteredData);
			}
		}
		catch (char*)
		{
			cout << "The Entered list of Data are as follows\n";
				DisplayDataAsQueue(&NodeLinkedList);
			return 0;
		}
		
	}
	cout << "The Entered list of Data are as follows\n";
	DisplayDataAsQueue(&NodeLinkedList);
	return 0;
}