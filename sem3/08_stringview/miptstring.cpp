#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include "miptstring.h"
#include "miptstringview.h"
using std::cout, std::cin, std::endl, std::size_t;

namespace mipt{

char* errorCheckedMalloc(size_t newCapacity)
{
    char* result = static_cast<char*>(std::malloc(newCapacity * sizeof(char)));
    if (result == NULL)
    {
        cout << "Error! Out of memory" << endl;
        std::exit(1);
    }
    return result;
}

String::String(const char* str) 
{
    size_t strSize = std::strlen(str);
    resize(strSize);
    std::memcpy(mpData, str, mSize);
}

String::String() : String("") {}
String::String(const String& s) : String(s.cStr()) {}
String::String(const StringView& sv) {
        mSize = sv.size();
        (*this).reserve(mSize);
        for(int i = 0; i < mSize; ++i)
            mpData[i] = sv[i];
        mpData[mSize] = '\0';
        
}

String::String(size_t n, char a)
{
    resize(n);

    for (size_t i = 0; i < mSize; ++i)
        mpData[i] = a;
}

String::~String()
{
    std::free(mpData);
}

void String::reserve(size_t capacity)
{
    if (capacity <= mCapacity)
        return;

    mCapacity = std::max(2 * mCapacity, capacity);
    char* newData = errorCheckedMalloc(mCapacity);

    if (mpData)
        std::memcpy(newData, mpData, mSize + 1);

    std::free(mpData);
    mpData = newData;
}


void String::resize(size_t size)
{
    reserve(size + 1);
    mSize = size;
    mpData[mSize] = '\0';
}


String& String::operator=(const String& right)
{
    if (this == &right)
        return *this;

    mSize = right.mSize;
    resize(mSize);

    std::memcpy(mpData, right.mpData, mSize + 1);

    return *this;
}


String String::operator+(const String& b)
{
    String result;
    result.resize(mSize + b.mSize);

    std::memcpy(result.mpData, mpData, mSize);
    std::memcpy(result.mpData + mSize, b.mpData, b.mSize);
    result.mpData[result.mSize] = '\0';

    return result;
}

String& String::operator+=(const String& right)
{
    *this = *this + right;
    return *this;
}

bool String::operator==(const String& right) const
{
    if (mSize != right.mSize)
        return false;

    size_t i = 0;
    while (i < mSize && mpData[i] == right.mpData[i])
        i++;

    return i == mSize;
}

bool String::operator<(const String& right) const
{
    size_t i = 0;
    while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
        i++;

    return mpData[i] < right.mpData[i];
}

bool String::operator<=(const String& right) const
{
    size_t i = 0;
    while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
        i++;

    return mpData[i] <= right.mpData[i];
}

bool String::operator!=(const String& right) const
{
    return !(*this == right);
}

bool String::operator>(const String& right) const
{
    return !(*this <= right);
}

bool String::operator>=(const String& right) const
{
    return !(*this < right);
}

char& String::operator[](size_t i)
{
    return mpData[i];
}

const char& String::operator[](size_t i) const
{
    return mpData[i];
}

char& String::at(size_t i)
{
    if (i >= mSize)
    {
        cout << "Error! Index is out of bounds." << endl;
    }
    return mpData[i];
}

void String::clear()
{
    std::free(mpData);

    mSize = 0;
    mCapacity = 1;
    mpData = errorCheckedMalloc(mCapacity);
    mpData[0] = '\0';
}

void String::addCharacter(char c)
{
    if (mSize + 1 == mCapacity)
        reserve(2 * mCapacity);

    mpData[mSize] = c;
    resize(mSize + 1);
}


size_t String::getSize()        const   {return mSize;}
size_t String::getCapacity()    const   {return mCapacity;}
const char* String::cStr()      const   {return mpData;}



std::ostream& operator<<(std::ostream& out, const String& s) 
{
    out << s.cStr();
    return out;
}

std::istream& operator>>(std::istream& in, String& s) 
{
    s.clear();
    while (true)
    {
        char x = in.get();
        if (x == ' ' || x == '\n' || x == '\t')
            break;
        s.addCharacter(x);
    }
    return in;
}

}
