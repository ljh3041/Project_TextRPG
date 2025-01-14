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
    vector<Item> items_for_sale;

    vector<Item> RandomItem();

public:
    Shop();
    void EnterShop();
    void ShopSelection();
    void BuyItem();
    void SellItem();
    static Shop& getInstance() {
        static Shop shopinstance; // 유일한 객체 생성
        return shopinstance;
    }
};


#endif//SHOP_H