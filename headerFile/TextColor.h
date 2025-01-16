#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

static HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

ostream& blue(ostream& s);

ostream& red(ostream& s);

ostream& green(ostream& s);

ostream& yellow(ostream& s);

ostream& white(ostream& s);

ostream& puple(ostream& s);

ostream& darkred(ostream& s);

ostream& darkyellow(ostream& s);

struct color {
    color(WORD attribute) :m_color(attribute) {};
    WORD m_color;
};

template <class _Elem, class _Traits>basic_ostream<_Elem, _Traits>& operator<<(basic_ostream<_Elem, _Traits>& i, color& c)
{
    SetConsoleTextAttribute(hStdout, c.m_color);
    return i;
}

