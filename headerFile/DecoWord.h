#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "MyMath.h"

using namespace std;

class DecoWord
{
public:
	vector<string> DecoWordList1;
	vector<string> DecoWordList2;

	string nickname(string& _name);

	
	static DecoWord& getInstance() {
		static DecoWord instance; // 유일한 객체 생성
		return instance;	
	}
	
private:
	DecoWord();
	DecoWord(const DecoWord&) = delete;
	DecoWord& operator=(const DecoWord&) = delete;
};

