#include "stdafx.h"
#include<iostream>
using namespace std;
/*=====Start of Node Structure Defination=====*/

struct Node
{
	int nodeData;
	struct Node* nextNodePtr;
};

typedef struct Node* NodePtr;
/*=====End of Node Structure Defination=====*/

/*=====Start of myStack Structure =====*/
struct myStack
{
	NodePtr stackNode=NULL;
	int stackSize = 0;
};

myStack stack;
/*=====End of myStack Structure =====*/

/*=====Start of function Prototypes=====*/
int  pop();
void push(int data);
int  peek();
bool isEmpty();
void deleteStack();
void displayStack(NodePtr nodePtr=stack.stackNode);
/*=====End of function Prototypes=====*/

/*=====Start of Main =====*/
int main()
{
	int option = 0;
	
	while (option != 4) {
		cout << "Enter \n '1' to Push \n '2' to Pop\n '3' to Check for peek element\n ";
		cout << "'4' to end the program\n";
		cin >> option;
		switch (option)
		{
		case 1:
			int enteredData;
			cout << "Enter the data to be pushed" << endl;
			cin >> enteredData;
			push(enteredData);
			break;
		case 2:
			cout << "The poped out Element is :" << endl << pop();
			break;

		case 3:
			cout << "The Last pushed element is :" << endl << peek();
			break;
		case 4:
			cout << "The elements present in the Stacks are:" << endl;
			displayStack();
			cout << "Now deleting the Stack " << endl;
			deleteStack();
			cout << "End of program"<<endl;
		}
	}
	return 0;
}
/*=====End of Main =====*/

/*=====Start of function definations =====*/
int  pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty, No item to pop" << endl;
		return -1;
	}
	else
	{
		stack.stackSize--;
		return(stack.stackNode->nodeData);
		
	}
}

void push(int data)
{
	if (isEmpty())
	{
		stack.stackNode = (NodePtr)malloc(1 * (sizeof(struct Node)));
	}
	else
	{
		NodePtr new_node= (NodePtr)malloc(1 * (sizeof(struct Node)));
		new_node->nextNodePtr = stack.stackNode;
		stack.stackNode->nextNodePtr = new_node;
	}
	stack.stackNode->nodeData = data;
	stack.stackSize++;

}
int  peek()
{
	if (isEmpty())
	{
		cout << "The Stack is empty"<<endl;
		return -1;
	}
	else
	{
		return(stack.stackNode->nodeData);
	}
}

bool isEmpty()
{
	return ((stack.stackSize==0) ? true : false);
}

void deleteStack()
{
	if ( !isEmpty()/*stack.stackNode != NULL*/)
	{
		NodePtr temp = stack.stackNode;
		stack.stackNode = stack.stackNode->nextNodePtr;
		stack.stackSize--;
		cout << "Deleting data " << temp->nodeData;
		free(temp);
		deleteStack();
	}
}
void displayStack(NodePtr nodePtr)
{
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		cout << " " << stack.stackNode->nodeData << endl;
		displayStack(stack.stackNode->nextNodePtr);
	}
}


/*=====End of function definations =====*/
