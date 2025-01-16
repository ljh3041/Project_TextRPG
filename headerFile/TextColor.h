#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

static HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

ostream& blue(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

ostream& red(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

ostream& green(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return s;
}

ostream& yellow(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    return s;
}

ostream& white(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return s;
}

ostream& puple(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return s;
}

ostream& darkred(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
    return s;
}

ostream& darkyellow(ostream& s)
{
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN);
    return s;
}

struct color {
    color(WORD attribute) :m_color(attribute) {};
    WORD m_color;
};

template <class _Elem, class _Traits>basic_ostream<_Elem, _Traits>& operator<<(basic_ostream<_Elem, _Traits>& i, color& c)
{
    SetConsoleTextAttribute(hStdout, c.m_color);
    return i;
}

