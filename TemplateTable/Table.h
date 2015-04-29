#include<iostream>

#define TYP template<typename T>

TYP
class Table
{
public:
	//constructors
	Table();
	Table(int m, int n); //empty table m*n
	Table(int m, int n, const T& value);

	//destructor
	~Table();
	
	void Print();
	void Resize(int cols, int raws);

	//operators overloading
	Table<T> operator=(const Table<T>& rhs);
	Table<T> operator+(const Table<T>& rhs);
private:
	void Destroy();
private:
	T** mData;
	int numRows;
	int numCols;
};

TYP
Table<T>::Table<T>()
{
	cout << "Enter number of columns" << endl;
	cin >> numCols;
	cout << "Enter number of lines" << endl;
	cin >> numRows;
	mData = new T*[numCols];
	
	for (int i = 0; i < numCols; i++)
	{
		mData[i] = new T[numRows];
	}
	
	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			cout << "Enter element for column " << i << ", row " << j << "..." << endl;
			cin >> mData[i][j];
		}
	}
}

TYP
Table<T>::Table<T>(int n, int m)
{
	numCols = n;
	numRows = m;
	mData = new T*[numCols];
	for (int i = 0; i < numCols; i++)
	{
		mData[i] = new T[numRows];
	}
}

TYP
Table<T>::Table<T>(int n, int m, const T& rhs)
{
	numCols = n;
	numRows = m;
	mData = new T*[numCols];
	for (int i = 0; i < numCols; i++)
	{
		mData[i] = new T[numRows];
		for (int j = 0; j < numRows; i++)
			mData[i][j] = rhs;
	}
}

TYP
void Table<T>::Destroy()
{
	if (mData)
	{
		for (int i = 0; i < numCols; i++)
		if (mData[i])
		{
			{
				delete[] mData[i];
				mData = NULL;
			}
		}
		delete[] mData;
		mData = NULL;
		numCols = 0;
		numRows = 0;
	}
}
	
TYP
Table<T>::~Table<T>()
{
	void Destroy();
}

TYP
Table<T> Table<T>::operator=(const Table<T>& rhs)
{
	Destroy();
	numCols = rhs.numCols;
	numRows = rhs.numRows;
	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			mData[i][j] = rhs.mData[i][j];
		}
	}
	return *this;
}

TYP
Table<T> Table<T>::operator+(const Table<T>& rhs)
{
	Table<T> tbl(numCols, numRows);
	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			tbl.mData[i][j] = mData[i][j] + rhs.mData[i][j];
		}
	}
	return tbl;
}

TYP
void Table<T>::Print()
{
	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			cout << mData[j][i] << " ";
		}
		cout << endl;
	}
}

TYP
void Table<T>::Resize(int cols, int raws)
{
	Destroy();
	numCols = cols;
	numRows = raws;
	mData = new T*[numCols];
	for (int i = 0; i < numCols; i++)
	{
		mData[i] = new T[numRows];
	}
}

