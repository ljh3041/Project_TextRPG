#pragma once
#include "Item.h"
#include "Character.h"
using namespace std;

//Singleton Pattern
class Shop
{
private:
	static Shop* instance;

	Shop();
	~Shop();

	Shop(const Shop&) = delete;
	Shop& operator=(const Shop&) = delete;

public:
	static Shop* GetInstance() {
		if (instance == nullptr) {
			instance = new Shop();
		}
		return instance;
	}

	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
};