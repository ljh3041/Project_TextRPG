#include "../headerFile/Shop.h"
#include "../headerFile/EquipmentItem.h"
#include <windows.h>

Shop::Shop()
{
    all_items.push_back(new Sword40());
    all_items.push_back(new HP_Blade4());
    all_items.push_back(new HP_Blade4());
    all_items.push_back(new HP_Blade4());

    items_for_sale = RandomItem();
}


// 랜덤으로 아이템 뽑기 함수
vector<Item*> Shop::RandomItem()
{
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    random_shuffle(all_items.begin(), all_items.end()); // 배열 섞기

    return vector<Item*>(all_items.begin(), all_items.begin() + 3); // 3개 선택해서 반환
}

// 현재 보유 골드, 인벤토리 상태 표시 함수
void Shop::EnterShop()
{
    cout << "현재 보유 골드 : " << Character::GetInstance()->GetGold() << endl;
    cout << "인벤토리 무게 : " << Character::GetInstance()->GetInventoryWeight()
        << "/" << Character::GetInstance()->GetMaxInventoryWeight() << endl;
}



// 상점 선택
void Shop::ShopSelection()
{
    while (true)
    {
        cout << "1.아이템 구매" << endl;
        cout << "2.아이템 판매" << endl;
        cout << "3.갈림길로 이동" << endl;
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
            cout << "갈림길로 이동합니다!" << endl; // 전장 이동
            Sleep(500);
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
    size_t i = 0;
    cout << "구매 가능한 아이템 : " << endl;
    for (i = 0; i < items_for_sale.size(); i++)
    {
        cout << i + 1 << "." << items_for_sale[i]->GetName()
            << ": 가격 " << items_for_sale[i]->GetPrice()
            << ", 무게 " << items_for_sale[i]->GetWeight() << endl;
    }

    cout <<  ++i << ".뒤로가기" << endl;
    cout << "구매할 아이템을 선택하세요 : " << endl;
    int choice;
    cin >> choice;

    if (choice == i) return;

    Item* selected_item = items_for_sale[choice - 1];
    
    if (Character::GetInstance()->GetGold() < selected_item->GetPrice())
    {
        cout << "골드가 부족합니다. 보유 골드 : " << Character::GetInstance()->GetGold() << endl;
        return;
    }
    if (Character::GetInstance()->GetInventoryWeight() + selected_item->GetWeight() >
        Character::GetInstance()->GetMaxInventoryWeight())
    {
        cout << "인벤토리 최대치를 초과합니다. 현재 무게 : "
            << Character::GetInstance()->GetInventoryWeight() << " "
            << selected_item->GetName() << " 무게 : "
            << selected_item->GetWeight() << endl;
        return;
    }

    Character::GetInstance()->SetGold(Character::GetInstance()->GetGold() - selected_item->GetPrice());
    Character::GetInstance()->AddToInventory(selected_item);
    items_for_sale.erase(items_for_sale.begin() + (choice - 1));
    cout << "구매 성공! 남은 골드 : " << Character::GetInstance()->GetGold() << endl;
    
}

// 아이템 판매 로직
void Shop::SellItem()
{
    
    cout << "보유 중인 아이템:" << endl;
    for (size_t i = 0; i < Character::GetInstance()->GetInventory().size(); i++)
    {
        cout << i + 1 << ". " << (Character::GetInstance()->GetInventory())[i]->GetName()
            << ": 판매 가격 " << (Character::GetInstance()->GetInventory())[i]->GetPrice() / 2 << endl; // 판매 가격을 일단 절반으로 가정
    }

    cout << "뒤로가기: " << Character::GetInstance()->GetInventory().size() + 1 << endl;
    cout << "판매할 아이템을 선택하세요 : " << endl;

    int choice;
    cin >> choice;

    if (choice == Character::GetInstance()->GetInventory().size() + 1) return; // 뒤로가기 처리

    Item* selected_item = Character::GetInstance()->GetInventory()[choice - 1]; // 선택한 아이템
    Character::GetInstance()->remove_from_inventory(selected_item); // 인벤토리에서 제거
    Character::GetInstance()->SetGold(Character::GetInstance()->GetGold() + selected_item->GetPrice() / 2);
    cout << "판매 성공! 현재 보유 골드: " << Character::GetInstance()->GetGold() << endl;
    
}

