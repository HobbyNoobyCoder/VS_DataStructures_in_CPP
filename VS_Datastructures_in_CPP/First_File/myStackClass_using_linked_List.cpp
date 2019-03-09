#include "stdafx.h"

#include<iostream>
using namespace std;
class myStack {
	struct Node {
		int nodeData;
		struct Node* nextNodePtr;
	};
typedef struct Node* NodePtr;
NodePtr Top=NULL;
public:
	int pop()
	{
		if (isEmpty())
		{
			cout << "Error the Stack is Empty, exiting Program" << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			int tempData = Top->nodeData;
			NodePtr tempPtr = Top;
			Top = Top->nextNodePtr;
			free(tempPtr);
			return (tempData);
		}
	}

	void push(int Data)
	{
		if (isEmpty())
		{
			Top = createNode();
		}
		else
		{
			NodePtr new_node = createNode();
			new_node->nextNodePtr = Top;
			Top = new_node;
		}
		Top->nodeData = Data;
	}

	int Peek()
	{
		if (isEmpty())
		{
			cout << "The Stack is Empty, -1 will be returned " << endl;
			return - 1;
		}
		else
		{
			return(Top->nodeData);
		}
	}
bool isEmpty()
	{
		return(Top == NULL);
	}
NodePtr createNode()
 {
	NodePtr new_node = (NodePtr)malloc(1 * (sizeof(struct Node)));
	if (new_node == NULL)
	{
		cout << "Error in Memory in Malloc, exiting Program" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		new_node->nextNodePtr = NULL;
		return new_node;
	}

 }
};



