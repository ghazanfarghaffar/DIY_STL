#ifndef MYSTRING_H
#define MYSTRING_H
/**
 * This is the implementation for my personal standard string library and all its functions using class STRING.
 */

#include <iostream>

class STRING
{
private:
    char *str;
    int len;

public:
    // ******************************************************* constructors and destructor ************************************************************
    STRING() // default constructor
    {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }
    STRING(const char *str) // constructor that takes a c-string
    {
        len = 0;
        while (str[len] != '\0') // count the length of the string
            len++;

        this->str = new char[len + 1]; // allocate memory for the string
        for (int i = 0; i < len; i++)  // copy the string
            this->str[i] = str[i];
        this->str[len] = '\0'; // terminate the string
    }
    STRING(const STRING &other) // copy constructor
    {
        len = other.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)
            str[i] = other.str[i];
        str[len] = '\0';
    }
    ~STRING() { delete[] str; }
    // *************************************************************** Getter and Setter ***************************************************************
    char *getStr() const { return str; } // Get the c-string representation of the string
    void setStr(const char *str)
    {
        len = 0;
        while (str[len] != '\0') // count the length of the string
            len++;
        this->str = new char[len + 1]; // allocate memory for the string
        for (int i = 0; i < len; i++)  // copy the string
            this->str[i] = str[i];
        this->str[len] = '\0'; // terminate the string
    }

    // *************************************************************** member functions ***************************************************************
    int length() const { return len; }                        // Get the length of the string
    char &at(int index) const { return str[index]; }          // Access the character at a given index
    void append(const STRING &other);                         // Append a string to another
    STRING substr(int start, int length) const;               // Get a substring
    int find(const STRING &other, int start = 0) const;       // Find the index of a substring
    void replace(int start, int length, const STRING &other); // Replace a substring with another
    void insert(int start, const STRING &other);              // Insert a substring at a given index
    void erase(int start, int length);                        // Erase a substring

    // **************************************************************** operators *******************************************************
    STRING &operator=(const STRING &other);     // Assign one string to another
    STRING operator+(const STRING &other);      // Concatenate two strings
    bool operator==(const STRING &other) const; // Compare two strings
    char &operator[](int index);                // Access the character
};

// ************************************************implementation of member functions*******************************************************

// append a string to another
void STRING::append(const STRING &other)
{
    int newlen = len + other.len;
    char *newstr = new char[newlen + 1];
    for (int i = 0; i < len; i++)
        newstr[i] = str[i];
    for (int i = 0; i < other.len; i++)
        newstr[len + i] = other.str[i];
    newstr[newlen] = '\0';
    delete[] str;
    str = newstr;
    len = newlen;
}

// get a substring
STRING STRING::substr(int start, int length) const
{
    STRING substr;
    for (int i = 0; i < length; i++)
        substr.str[i] = str[start + i];
    substr.str[length] = '\0';
    substr.len = length;
    return substr;
}

// find the index of a substring
int STRING::find(const STRING &other, int start) const
{
    for (int i = 0; i < len; i++)
    {
    }
    return 0;
}

// replace a substring with another
void STRING::replace(int start, int length, const STRING &other)
{
}

// insert a substring at a given index
void STRING::insert(int start, const STRING &other)
{
}

// erase a substring
void STRING::erase(int start, int length)
{
}

// assign one string to another
STRING &STRING::operator=(const STRING &other)
{
    if (this != &other)
    {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)
            str[i] = other.str[i];
        str[len] = '\0';
    }
    return *this;
}

// concatenate two strings
STRING STRING::operator+(const STRING &other)
{
    STRING s;

    s.append(*this);
    s.append(other);
    return s;
}

// compare two strings
bool STRING::operator==(const STRING &other) const
{
    return (this->str == other.str && this->len == other.len);
}

// access the character
char &STRING::operator[](int index)
{
    return str[index];
}

//********************************implementation of non-member functions********************************************************
// Print the string to the output stream
std::ostream &operator<<(std::ostream &os, STRING &str)
{
    return os << str.getStr();
}
// Read a string from the input stream
std::istream &operator>>(std::istream &is, STRING &str)
{
    char buffer[100];
    is.getline(buffer, 100);
    str.setStr(buffer);
    return is;
}

#endif