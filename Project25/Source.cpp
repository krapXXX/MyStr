#include <iostream> 
#include "MyString.h" 
using namespace std;
ostream& operator<<(ostream& os, MyString& str)
{
    for (int i = 0; i < str.length; i++)
    {
        os << str.str[i] << "\t";
    }
    return os;
}
istream& operator>>(istream& is, MyString& str)
{
    for (int i = 0; i < str.length; i++)
    {
        cout << i << ": ";
        is >> str.str[i];
    }
    return is;
}
/*MyString b ;
     b = "Hello" + a ; // перегрузка через функцию!!*/

MyString operator+(const char* string, const MyString& a) // int+ Point 
{
    char* temp = new char[strlen(string) + 1 + a.GetSize()];
    for (int i = 0; i < strlen(string); i++)
    {
        temp[i] = string[i];
    }
    for (int i = strlen(string); i < a.GetSize(); i++)
    {
        int b = 0;
        temp[i] = a.GetStr()[i];
        b++;
    }
    return temp;
}
int main()
{
    /*MyString str1("I love world");
    MyString str2("I love you");
    MyString str3 = str1;
    MyString str4;
    str4.Input();
    str1.Output();
    str2.Output();
    str3.Output();
    str4.Output();

    MyString str5{ 'I', 'L', 'U' };
    str5.Output();
    MyString str6 = move(str5);
    str6 += ("Hello world");
    MyString str7;
    MyString str8{ 'I', 'L', 'U' };
    str7 = "Hello" + str8;*/
    MyString str9("Hello world!");
    str9.Save("Test.txt");
}