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
    static Shop* instance;

    vector<Item*> all_items;//모든 아이템 저장 백터
    vector<Item*> items_for_sale;//판매할 아이템

    vector<Item*> RandomItem();// 아이템을 랜덤으로 선택

public:
    Shop();
    ~Shop();
    void EnterShop();
    void ShopSelection();
    void BuyItem();
    void SellItem();
    void InitializeShop();
    void printstore();
    void printstore_dot();

    static Shop* GetInstance() {
        if (instance == nullptr) {
            instance = new Shop();
        }
        return instance;
    }
};


#endif//SHOP_H