#include "stdafx.h"
#include<iostream>
using namespace std;
#include"First_File.cpp"

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

