#include "stdafx.h"
#include<iostream>
using namespace std;

class myStack {
/* Structure for Linked List Node*/
	struct Node
	{
		int nodeData;
		struct Node* nextNodePtr=NULL;
	};
	typedef struct Node* NodePtr;

public:
/*Function Prototypes*/
//	int pop();
//	void push(int data);
//	int peek();
//	bool isEmpty();
//	NodePtr createNode();

/* Declarations */

	NodePtr Top = NULL;
/*Functions Definations*/

/*Funtions to pop the top element from the stack*/
	int pop()
	{
		if (!isEmpty())
		{
			int data;
			NodePtr temp = Top;
			Top = Top->nextNodePtr;
			data = temp->nodeData;
			free(temp);
			return data;
		}
		else
		{
			cout << "Stack underflow, exiting program" << endl;
			exit(1);
		}
	}
/*Function to push the Data to the Stack*/
	void push(int data)
	{
		if (isEmpty())
		{
			Top = createNode();
			Top->nodeData = data;
		}
		else
		{
			NodePtr new_node = createNode();
			new_node->nodeData = data;
			new_node->nextNodePtr = Top;
			Top = new_node;
		}

	}

/*Function to check whether the stack is empty or not*/
	bool isEmpty()
	{
		return(Top == NULL);
	}
/*Function to get the Top element without deleting it */
	int peek()
 {
	 if (isEmpty())
		{
		 cout << "Empty Stack, No element is pushed" << endl;
		 return -1;
		}
	 else
		 {
		 return (Top->nodeData);
		 }
 }
/*Function to Create new Node */
	NodePtr createNode()
	{
		NodePtr new_node = (NodePtr)malloc(1 * (sizeof(struct Node)));
		if (new_node == NULL)
		{
			cout << "Memory Error in Malloc" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			new_node->nextNodePtr = NULL;
			return new_node;
		}
	}
};
 char instructionString[] = "Choose \n '1' to Push \n '2' to Pop \n '3' to Peek \n '4' to exit \n";
int main()
{
	myStack stack;
	int option = 0;
	while (option != 4)
	{
		cout << instructionString << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			int data;
			cout << "Enter the number to be pushed" << endl;
			cin>> data;
			stack.push(data);
			cout << data << " was pushed" << endl;
			break;

		case 2:
			cout << "The popped out Number is:" << endl;
			cout << stack.pop()<<endl;
			break;

		case 3:
			cout << "The top element is :" << endl;
			cout << stack.peek() << endl;
			break;

		case 4:
			cout << "Exiting the program" << endl;
			break;
		default:
			cout << "Wrong option chosen, please select the correct option"<<endl;
			break;
		}
	}


}