#pragma once 
#include<iostream> 
using namespace std;
class MyString
{
	char* str;
	int length;
	static int count;
	friend ostream& operator<<(ostream& os, MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
public:
	static int GetCount();
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	MyString(MyString&& obj);
	MyString(initializer_list <char>obj);

	void Input();
	void Output();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& obj);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	MyString& operator=(const MyString& obj);
	MyString& operator= (MyString&& obj);
	MyString& operator +=(const char* string);

	char operator[] (int index);
	void operator() ();

	int GetSize() const;
	const char* GetStr() const;

	void Save(const char* filename) const;
	~MyString();
};