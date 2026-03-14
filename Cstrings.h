#ifndef CSTRING_H
#define CSTRING_H

#include <iostream>
class Cstring
{
private:
    char *str;
    int size;

public:
    Cstring();
    Cstring(char);
    Cstring(const char *);
    Cstring(const Cstring &);
    ~Cstring();

    int get_length(const char *) const;
    int getLength() const;
    void display() const;
    int find(const char *, int start = 0) const;
    int find(char, int start = 0) const;
    int insert(int,const char *);
    int insert(int, char);
    Cstring left(int) const;
    Cstring right(int) const;
    int remove(int, int count = 1);
    int remove(char);
    void replace(char);
    int replace(char, char);
    int replace(const char *,const char *);
    void trim();
    void trimLeft();
    void trimRight();
    void makeUpper();
    void makeLower();
    void reverse();
    void resize(int);
    Cstring concat(const Cstring &) const;
    void concatEqual(const Cstring &);
    void concatEqual(const char *);
    int isEqual(const Cstring &) const;
    int isEqual(const char *) const;
    void input();
    char &at(int);
    int isEmpty() const;
    void clear();
    Cstring substring(int, int);
    int CountChar(char) const;
    Cstring &operator=(const Cstring &);
    Cstring operator+(const Cstring &) const;
    bool operator==(const Cstring &) const;
    friend std::ostream &operator<<(std::ostream &, const Cstring &);
};

#endif