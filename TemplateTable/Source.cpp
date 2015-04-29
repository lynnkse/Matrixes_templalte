#include<iostream>
#include"Table.h"

using namespace std;

int main()
{
	cout << "Creating fisrt matrix..." << endl;
	Table<int> mtr1;
	cout << "Creating second matrix..." << endl;
	Table<int> mtr2;
	Table<int> mtr3 = mtr1 + mtr2;
	cout << "Printing the sum..." << endl;
	mtr3.Print();
}