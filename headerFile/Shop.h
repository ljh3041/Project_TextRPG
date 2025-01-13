#pragma once
#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Character.h" 
#include "Item.h" 

using namespace std;

class Shop
{
private:
    Character& character;
    vector<Item> items_for_sale;

    vector<Item> RandomItem();

public:
    Shop(Character& c);
    void EnterShop();
    void ShopSelection();
    void BuyItem();
    void SellItem();
};

#endif//SHOP_H
