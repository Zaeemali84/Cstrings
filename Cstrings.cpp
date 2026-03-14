#include "Cstrings.h"
#include <iostream>
using namespace std;

Cstring::Cstring()
{
    size = 1;
    str = new char[size];
    str[0] = '\0';
}
Cstring::Cstring(char c)
{
    size = 2;
    str = new char[size];
    str[0] = c;
    str[1] = '\0';
}
Cstring::Cstring(const char *c)
{
    int length = get_length(c);
    str = new char[length + 1];
    size = length;
    for (int i = 0; i <= length; i++)
    {
        str[i] = c[i];
    }
}
Cstring::Cstring(const Cstring &ref)
{
    size = ref.size;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = ref.str[i];
    }
    str[size] = '\0';
}
Cstring::~Cstring()
{
    delete[] str;
    str = nullptr;
}
int Cstring::getLength() const
{
    return size;
}
void Cstring::display() const
{
    cout << str;
}
int Cstring::find(const char *substr, int start) const
{
    int sub_length = get_length(substr);
    if (sub_length == 0)
    {
        return start;
    }
    int k;
    for (int i = start; i <= size - sub_length; i++)
    {
        k = 0;
        if (str[i] == substr[k])
        {
            for (int j = i; k < sub_length; j++)
            {
                if (str[j] != substr[k])
                {
                    break;
                }
                k++;
                if (k == sub_length)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
int Cstring::find(char ch, int start) const
{
    for (int i = start; i < size; i++)
    {
        if (str[i] == ch)
        {
            return i;
        }
    }
    return -1;
}
int Cstring::insert(int index,const char *substr)
{
    if (index > size)
    {
        return -1;
    }
    int str_len = get_length(substr);
    char *new_str = new char[size + str_len + 1];
    for (int i = 0; i < index; i++)
    {
        new_str[i] = str[i];
    }
    for (int i = 0; i < str_len; i++)
    {
        new_str[index + i] = substr[i];
    }
    for (int i = index; i < size; i++)
    {
        new_str[i + str_len] = str[i];
    }
    new_str[size + str_len] = '\0';
    delete[] str;
    str = new_str;
    size = size + str_len;
    return size;
}
int Cstring::insert(int index, char ch)
{
    if (index > size)
    {
        return -1;
    }
    char temp;
    char *new_str = new char[size + 2];

    for (int i = 0; i < size + 1; i++)
    {
        if (i < index)
        {
            new_str[i] = str[i];
        }
        else if (i == index)
        {
            new_str[i] = ch;
        }
        else
        {
            new_str[i] = str[i - 1];
        }
    }
    new_str[size + 1] = '\0';

    delete[] str;
    str = new_str;
    size += 1;
    return size;
}
Cstring Cstring::left(int count) const
{
    if (count > size)
    {
        count = size;
    }
    if (count <= 0)
        return Cstring();

    Cstring left;
    left.str = new char[count + 1];
    for (int i = 0; i < count; i++)
    {
        left.str[i] = str[i];
    }
    left.str[count] = '\0';
    left.size = count;
    return left;
}
Cstring Cstring::right(int count) const
{
    if (count > size)
        count = size;

    if (count <= 0)
        return Cstring();

    Cstring right;
    delete[] right.str;
    right.str = new char[count + 1];
    int ind = size - count;
    for (int i = 0; i < count; i++)
    {
        right.str[i] = str[ind + i];
    }
    right.str[count] = '\0';
    right.size = count;
    return right;
}
int Cstring::remove(int index, int count)
{
    if (index < 0 || index > size)
        return size;
    if (index + count > size)
        count = size - index;
    char *new_str = new char[size - count + 1];
    for (int i = 0; i < size - count; i++)
    {
        if (i < index)
        {
            new_str[i] = str[i];
        }
        else if (i >= index)
            new_str[i] = str[i + count];
    }
    new_str[size - count] = '\0';
    delete[] str;
    str = new_str;
    size -= (count);
    return size;
}
int Cstring::remove(char ch)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ch)
        {
            remove(i, 1);
            count++;
            i--;
        }
    }
    return count;
}
void Cstring::replace(char new_char)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = new_char;
    }
    str[size] = '\0';
}
int Cstring::replace(char old_char, char new_char)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == old_char)
        {
            str[i] = new_char;
            count++;
        }
    }
    return count;
}
int Cstring::replace(const char *old_char,const char *new_char)
{
    int old_len = get_length(old_char);
    int new_len = get_length(new_char);
    int count = 0;
    int i = 0;
    while ((i = find(old_char, i)) != -1)
    {
        count++;
        i += old_len;
    }
    if (count == 0)
    {
        return 0;
    }
    int index = 0;
    i = 0;
    int new_size = size + (count * (new_len - old_len));
    char *new_str = new char[new_size + 1];
    while (str[i] != '\0')
    {
        if ((find(old_char, i)) == i)
        {
            for (int j = 0; j < new_len; j++)
            {
                new_str[index++] = new_char[j];
            }
            i += old_len;
        }
        else
        {
            new_str[index++] = str[i++];
        }
    }
    new_str[index] = '\0';
    size = index;
    delete[] str;
    str = new_str;
    return count;
}
void Cstring::trim()
{
    trimLeft();
    trimRight();
}
void Cstring::trimLeft()
{
    int first_character = 0;
    while (first_character < size && str[first_character] == ' ')
    {
        first_character++;
    }
    int new_len = size - first_character;
    char *new_str = new char[new_len + 1];
    for (int i = 0; i < new_len; i++)
    {
        new_str[i] = str[i + first_character];
    }
    new_str[new_len] = '\0';
    size = new_len;
    delete[] str;
    str = new_str;
}
void Cstring::trimRight()
{
    int index_last_ch = -1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            index_last_ch = i;
            break;
        }
    }
    if (index_last_ch == size - 1)
    {
        return;
    }
    size = index_last_ch + 1;
    char *new_str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_str[i] = str[i];
    }
    new_str[size] = '\0';
    delete[] str;
    str = new_str;
}
void Cstring::makeUpper()
{
    for (int i = 0; i < size; i++)
    {
        if (int(str[i]) >= 97 && int(str[i]) <= 122)
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}
void Cstring::makeLower()
{
    for (int i = 0; i < size; i++)
    {
        if (int(str[i]) >= 65 && int(str[i]) <= 90)
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}
void Cstring::reverse()
{
    char temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}
void Cstring::resize(int add)
{
    if (add <= 0)
    {
        add = 0;
    }
    char *new_str = new char[size + add + 1];
    for (int i = 0; i < size; i++)
    {
        new_str[i] = str[i];
    }
    for (int i = size; i < size + add; i++)
    {
        new_str[i] = ' ';
    }
    size += add;
    new_str[size] = '\0';
    delete[] str;
    str = new_str;
}
Cstring Cstring::concat(const Cstring &s2) const
{
    Cstring concat;
    concat.str = new char[size + s2.size + 1];
    concat.size = size + s2.size;
    int i = 0;
    for (i; i < size; i++)
    {
        concat.str[i] = str[i];
    }
    for (int j = 0; j < s2.size; j++)
    {
        concat.str[i++] = s2.str[j];
    }
    concat.str[i] = '\0';
    return concat;
}
void Cstring::concatEqual(const Cstring &s2)
{
    char *new_str = new char[size + s2.size + 1];
    int i = 0;
    for (i; i < size; i++)
    {
        new_str[i] = str[i];
    }
    for (int j = 0; j < s2.size; j++)
    {
        new_str[i++] = s2.str[j];
    }
    new_str[i] = '\0';
    delete[] str;
    str = new_str;
    size += s2.size;
}
void Cstring::concatEqual(const char *s2)
{
    if (s2 == nullptr)
    {
        return;
    }
    int str_len = get_length(s2);
    char *new_str = new char[size + str_len + 1];
    for (int i = 0; i < size - 1; i++)
    {
        new_str[i] = str[i];
    }
    for (int j = 0; j < str_len; j++)
    {
        new_str[size - 1 + j] = s2[j];
    }
    new_str[size + str_len] = '\0';
    delete[] str;
    str = new_str;
    size += str_len;
}
int Cstring::isEqual(const Cstring &s2) const
{
    int index = size < s2.size ? size : s2.size;
    for (int i = 0; i < index + 1; i++)
    {
        if (str[i] != s2.str[i])
        {
            return str[i] - s2.str[i];
        }
    }
    return 0;
}
int Cstring::isEqual(const char *s2) const
{
    int str_len = get_length(s2);
    int index = size < str_len ? size : str_len;
    for (int i = 0; i < index + 1; i++)
    {
        if (str[i] != s2[i])
        {
            return str[i] - s2[i];
        }
    }
    return 0;
}
void Cstring::input()
{
    char buffer[1000];
    cin.getline(buffer, 1000);
    int length = get_length(buffer);
    delete[] str;
    size = length;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = buffer[i];
    }
    str[size] = '\0';
}
char &Cstring::at(int index)
{
    if (index < 0 || index >= size)
    {
        return str[0];
    }
    return str[index];
}
int Cstring::isEmpty() const
{
    return str[0];
}
int Cstring::get_length(const char *str) const
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void Cstring::clear()
{
    delete[] str;
    str = new char[1];
    str[0] = '\0';
    size = 1;
}
Cstring Cstring::substring(int start, int length)
{
    if (start < 0 || start >= size || length <= 0)
    {
        return Cstring();
    }
    Cstring sub_str;
    delete[] sub_str.str;
    sub_str.size = length;
    sub_str.str = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        sub_str.str[i] = str[start + i];
    }
    sub_str.str[length] = '\0';
    return sub_str;
}
int Cstring::CountChar(char ch) const
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }
    return count;
}
Cstring &Cstring::operator=(const Cstring &ref)
{
    if (this != &ref)
    {
        delete[] str;

        size = ref.size;
        str = new char[size + 1];
        for (int i = 0; i <= size; i++)
        {
            str[i] = ref.str[i];
        }
    }
    return *this;
}
Cstring Cstring::operator+(const Cstring &ref) const
{
    Cstring temp;
    delete[] temp.str;

    temp.size = this->size + ref.size;
    temp.str = new char[temp.size + 1];
    int i = 0;
    for (; i < this->size; i++)
    {
        temp.str[i] = this->str[i];
    }
    for (int j = 0; j < ref.size; j++)
    {
        temp.str[i++] = ref.str[j];
    }
    temp.str[temp.size] = '\0';
    return temp;
}
bool Cstring::operator==(const Cstring &ref) const
{
    if (this->size != ref.size)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (this->str[i] != ref.str[i])
        {
            return false;
        }
    }
    return true;
}
ostream &operator<<(ostream &out, const Cstring &obj)
{
    out << obj.str;
    return out;
}