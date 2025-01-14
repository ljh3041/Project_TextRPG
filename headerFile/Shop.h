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

//생성자
Shop::Shop()
{

}


// 랜덤으로 아이템 뽑기 함수
vector<Item> Shop::RandomItem()
{
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    vector<Item> shuffled_items;// = all_items; // 원본 복사 (나중에 함수 명 변경)
    random_shuffle(shuffled_items.begin(), shuffled_items.end()); // 배열 섞기

    return vector<Item>(shuffled_items.begin(), shuffled_items.begin() + 3); // 3개 선택해서 반환
}

// 현재 보유 골드, 인벤토리 상태 표시 함수
void Shop::EnterShop()
{
    /*
    cout << "현재 보유 골드 : " << character.GetGold() << endl;
    cout << "인벤토리 무게 : " << character.inventoryweight << "/" << character.maxinventoryweight << endl;
    */
}



// 상점 선택
void Shop::ShopSelection()
{
    while (true)
    {
        cout << "1.아이템 구매" << endl;
        cout << "2.아이템 판매" << endl;
        cout << "3.전장으로 이동" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (items_for_sale.empty())
            {
                cout << "모든 아이템이 매진되었습니다." << endl;
            }
            else
            {
                BuyItem(); // 아이템 구매
            }
            break;
        case 2:
            SellItem(); // 아이템 판매
            break;
        case 3:
            cout << "전장으로 이동합니다." << endl; // 전장 이동
            //나중에 전장이동 생기면 넣기
            return;
        default:
            cout << "잘못된 선택입니다." << endl; // 잘못된 선택 처리
        }
    }
}

// 아이템 구매 함수
void Shop::BuyItem()
{
    cout << "구매 가능한 아이템 : " << endl;
    for (size_t i = 0; i < items_for_sale.size(); i++)
    {
        cout << i + 1 << "." << items_for_sale[i].getName()
            << ": 가격 " << items_for_sale[i].getPrice()
            << ", 무게 " << items_for_sale[i].getWeight() << endl;
    }

    cout << "4.뒤로가기" << endl;
    cout << "구매할 아이템을 선택하세요 : " << endl;
    int choice;
    cin >> choice;

    if (choice == 4) return;

    Item selected_item = items_for_sale[choice - 1];
    /*
    if (character.getGold() < selected_item.getPrice())
    {
        cout << "골드가 부족합니다. 보유 골드 : " << character.getGold() << endl;
        return;
    }
    if (character.inventoryweight + selected_item.getWeight() > character.maxinventoryweight)
    {
        cout << "인벤토리 최대치를 초과합니다. 현재 무게 : "
            << character.inventoryweight << " "
            << selected_item.GetName() << " 무게 : "
            << selected_item.GetWeight() << endl;
        return;
    }

    character.SetGold = character.GetGold - selected_item.GetPrice();
    character.add_to_inventory(selected_item);
    items_for_sale.erase(items_for_sale.begin() + (choice - 1));
    cout << "구매 성공! 남은 골드 : " << character.GetGold() << endl;
    */
}

// 아이템 판매 로직
void Shop::SellItem()
{
    /*
    cout << "보유 중인 아이템:" << endl;
    for (size_t i = 0; i < character.GetInventory().size(); i++)
    {
        cout << i + 1 << ". " << character.GetInventory()[i].GetName()
            << ": 판매 가격 " << character.GetInventory()[i].GetPrice() / 2 << endl; // 판매 가격을 일단 절반으로 가정
    }

    cout << "뒤로가기: " << character.GetInventory().size() + 1 << endl;
    cout << "판매할 아이템을 선택하세요 : " << endl;

    int choice;
    cin >> choice;

    if (choice == character.GetInventory().size() + 1) return; // 뒤로가기 처리

    Item selected_item = character.GetInventory()[choice - 1]; // 선택한 아이템
    character.remove_from_inventory(selected_item); // 인벤토리에서 제거
    character.SetGold(character.GetGold() + selected_item.GetPrice() / 2);
    cout << "판매 성공! 현재 보유 골드: " << character.GetGold() << endl;
    */
}



#endif//SHOP_H