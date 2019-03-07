#include "stdafx.h"
#include<iostream>
using namespace std;
/*
struct Node {
	int data; 
	struct Node* Next;
} Node;
*/

typedef struct {
	int data;
	struct Node* Next;
};
typedef struct Node* NodePtr;

int main()
{
	char enteredData[25];
	 
	while (1)
	{
		cout << "Entered Data is before " << enteredData;
		cout << "Enter a Number to be stored or type end to exit \n";
		cin >> enteredData;
		try {
			if (enteredData == "end")
				throw enteredData;
			else
			{
				insertData(enteredData);
			}
		}
		catch (char*)
		{
			cout<<"The Entered list of Data are as follows\n"
			DisplayData
		}
		cout << "Entered Data is " << enteredData;
	}
	
	return 0;
}