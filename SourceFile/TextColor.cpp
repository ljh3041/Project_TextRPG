#pragma once
#include "../headerFile/TextColor.h"

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
