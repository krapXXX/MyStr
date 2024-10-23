#include <iostream>   
#include <fstream>
#include "MyString.h" 
using namespace std;

int MyString::GetCount()//статична пам'€ть
{
    return count;
}
MyString::MyString()
{
    str = nullptr;
    length = 0;
    count++;
}
MyString::MyString(const char* string)
{
    str = new char[strlen(string) + 1];
    strcpy_s(str, strlen(string) + 1, string);
    length = strlen(string + 1);
    count++;
}
MyString::MyString(const MyString& string)//конструктор коп≥юванн€
{
    str = new char[strlen(string.str) + 1];
    strcpy_s(str, strlen(string.str) + 1, string.str);
    length = strlen(string.str + 1);
}
MyString::MyString(MyString&& obj)
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;

    cout << "Move constr" << endl;
}

MyString::MyString(initializer_list<char> arr)
{
    cout << "initializer list" << endl;
    cout << arr.size() << endl;
    length = arr.size();
    str = new char[length + 1];
    for (auto x = arr.begin(); x != arr.end(); x++)
    {
        *str = *x;
        str++;
    }
    str -= length;
}

void MyString::Input()
{
    char string[225];
    cout << "Enter text: ";
    cin.getline(string, 225);
    str = new char[strlen(string) + 1];
    strcpy_s(str, strlen(string) + 1, string);
}
void MyString::Output()
{
    cout << str;
}

void MyString::MyStrcpy(MyString& obj)//копирование строк   
{
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    length = obj.length;
}
bool MyString::MyStrStr(const char* string)//поиск подстроки в строке   
{
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (string[i] == str[j])
            {
                return true;
                cout << "Found!";
                break;
            }
            else
            {
                return false;
                cout << "Not found";
            }

        }
    }
}
int MyString::MyChr(char c)//поиск символа в строке(индекс найденного символа, либо -1)   
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            return i + 1;
        }
    }
}
int MyString::MyStrLen()//возвращает длину строки   
{
    return strlen(str);
}
void MyString::MyStrCat(MyString& obj)//объединение строк   
{
    str = new char[strlen(str) + strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    for (int i = 0; i < strlen(obj.str); i++)
    {
        str[i] = obj.str[i];
    }
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = obj.str[i];
    }
    str[strlen(obj.str) + strlen(str)] = '\0';
}
void MyString::MyDelChr(char c)// удал€ет указанный символ    
{

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            length--;
            str[i] = str[i + 1];
        }
    }
}
int MyString::MyStrCmp(MyString& obj)/*сравнение строк
- 1 Ц перва€ строка меньше чем втора€
1 Ц перва€ больше чем втора€
0 Ц строки равны!*/
{
    if (strlen(str) == strlen(obj.str))
    {
        return 0;
    }
    if (strlen(str) > strlen(obj.str))
    {
        return  -1;
    }
    if (strlen(str) < strlen(obj.str))
    {
        return 1;
    }
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    if (str != nullptr)
    {
        delete[] str;
    }
    length = obj.length;

    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);

    return*this;
}
MyString& MyString::operator=(MyString&& obj)
{
    if (str != nullptr)
    {
        delete[] str;
    }
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;

    cout << "Move =" << endl;
    return *this;
}

MyString& MyString::operator+=(const char* string)
{
    MyString temp = *this;
    char* temp1 = new char[length + strlen(string) + 1];
    for (int i
        = 0; i < length; i++)
    {
        temp1[i] = str[i];
    }
    for (int i = 0; i < strlen(string); i++)
    {
        temp1[length] = string[i];
        length++;
    }
    delete[] str;
    *str = *temp1;
    length += strlen(string);
    return temp;
}

char MyString::operator[](int index)
{
    return str[index];
}
void MyString::operator()()
{
    cout << str << endl;
}

int MyString::GetSize() const
{
    return length;
}
const char* MyString::GetStr() const
{
    return str;
}


void MyString::Save(const char* filename) const
{
    ofstream out(filename);
    out.open("Test.txt", ios::out | ios::trunc);
    out << str;
    out.close();
}


MyString::~MyString()
{
    delete[]str;
    length = 0;
    count--;
}