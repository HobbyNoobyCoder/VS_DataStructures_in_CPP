#include "stdafx.h"
#include<iostream>
#include"myStackClass_using_linked_List.cpp"
int main()
{
	myStack erenStack; int data;
	cout << "Prog Started" << endl;
	cout << "Pushing 10" << endl;
	erenStack.push(10);
	cout << "Pushed 10" << endl;

	cout << "Pushing 670" << endl;
	erenStack.push(670);
	cout << "Pushed 670" << endl;
	cout << "Pushing 999" << endl;
	erenStack.push(999);
	cout << "Pushed 999" << endl;

	cout << "Popping 999" << endl;
	cout << erenStack.pop() << endl;
	cout << "Popped 999" << endl;

	cout << "Popping 670" << endl;
	cout << erenStack.pop() << endl;
	cout << "Popped 670" << endl;

	cout << "Pushing 567" << endl;
	erenStack.push(567);
	cout << "Pushed 567" << endl;

	cout << "Poppong 567" << endl;
	cout << erenStack.pop() << endl;
	cout << "Popped 567" << endl;

	cout << "Peeking 10" << endl;
	cout << erenStack.Peek() << endl;
	cout << "Peeked 10" << endl;

	cout << "Poppong 10" << endl;
	cout << erenStack.pop()<<endl;
	cout << "Popped 10" << endl;

	cout << "Peeking Empty" << endl;
	cout << erenStack.Peek() << endl;
	cout << "Peeked Empty" << endl;

	cout << "Popping Empty Will Be error" << endl;
	cout << erenStack.pop();
	cout << "You shouldnt See this" << endl;




}
