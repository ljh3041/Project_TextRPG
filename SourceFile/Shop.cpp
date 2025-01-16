#include "../headerFile/Shop.h"
#include "../headerFile/EquipmentItem.h"
#include "../headerFile/ConsumableItem.h"
#include <windows.h>
#include "../headerFile/MyMath.h"

Shop::Shop()
{
    InitializeShop();
}

void Shop::InitializeShop()
{
    all_items.clear(); // 기존 아이템 제거

    all_items.push_back(new Sword10());
    all_items.push_back(new Sword20());
    all_items.push_back(new Sword30());
    all_items.push_back(new Sword40());
    all_items.push_back(new Sword50());

    all_items.push_back(new ScalingSword10());
    all_items.push_back(new ScalingSword20());
    all_items.push_back(new ScalingSword30());
    all_items.push_back(new ScalingSword40());
    all_items.push_back(new ScalingSword50());

    all_items.push_back(new VampiricDagger10());
    all_items.push_back(new VampiricDagger20());
    all_items.push_back(new VampiricDagger30());
    all_items.push_back(new VampiricDagger40());
    all_items.push_back(new VampiricDagger50());

    all_items.push_back(new HP_Blade1());
    all_items.push_back(new HP_Blade2());
    all_items.push_back(new HP_Blade3());
    all_items.push_back(new HP_Blade4());
    all_items.push_back(new HP_Blade5());

    all_items.push_back(new Armor10());
    all_items.push_back(new Armor20());
    all_items.push_back(new Armor30());
    all_items.push_back(new Armor40());
    all_items.push_back(new Armor50());
    all_items.push_back(new Armor50());

    all_items.push_back(new ScalingArmor10());
    all_items.push_back(new ScalingArmor20());
    all_items.push_back(new ScalingArmor30());
    all_items.push_back(new ScalingArmor40());
    all_items.push_back(new ScalingArmor50());

    all_items.push_back(new HealingArmor2());
    all_items.push_back(new HealingArmor4());
    all_items.push_back(new HealingArmor6());
    all_items.push_back(new HealingArmor8());
    all_items.push_back(new HealingArmor10());

    all_items.push_back(new potion50());
    all_items.push_back(new potion100());
    all_items.push_back(new potion300());
    all_items.push_back(new potion600());

    all_items.push_back(new potionQuarter());
    all_items.push_back(new potionHalf());
    all_items.push_back(new potionFull());

    items_for_sale = RandomItem(); // 아이템 재랜덤화
}


// 랜덤으로 아이템 뽑기 함수
vector<Item*> Shop::RandomItem()
{
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 설정

    random_shuffle(all_items.begin(), all_items.end()); // 배열 섞기

    return vector<Item*>(all_items.begin(), all_items.begin() + 3); // 3개 선택해서 반환
}

// 현재 보유 골드, 인벤토리 상태 표시 함수
void Shop::EnterShop() {}

// 상점 선택
void Shop::ShopSelection()
{
    while (true)
    {
        system("cls");
        printstore();

        int choice = GetValidNumber();

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
            system("cls");
            Character::GetInstance()->DisplayStatus();
            PressAnyKey();
            break;
        case 4:
            cout << "갈림길로 이동합니다!" << endl; // 전장 이동
            Sleep(500);
            //나중에 전장이동 생기면 넣기
            return;
        default:
            cout << "잘못된 선택입니다." << endl; // 잘못된 선택 처리
            Sleep(500);
        }
    }
}

// 아이템 구매 함수
void Shop::BuyItem()
{
    system("cls");
    cout << "================================" << endl;
    cout << "상점" << endl;
    cout << "아이템 목록" << endl;
    cout << "================================" << endl;
    cout << "현재 보유 골드 : " << Character::GetInstance()->GetGold() << endl;
    cout << "인벤토리 무게 : " << Character::GetInstance()->GetInventoryWeight()
        << "/" << Character::GetInstance()->GetMaxInventoryWeight() << endl;


    size_t i = 0;
    cout << "구매 가능한 아이템 : " << endl;
    for (i = 0; i < items_for_sale.size(); i++)
    {
        cout << i + 1 << ". " << items_for_sale[i]->GetName()
            << endl << ": 가격 " << items_for_sale[i]->GetPrice()
            << ", 무게 " << items_for_sale[i]->GetWeight() << endl << endl;
    }

    cout << ++i << ".뒤로가기" << endl;
    cout << "구매할 아이템을 선택하세요 : " << endl;

    int choice = GetValidNumber();

    if (choice == i) return;
    if (choice > i || choice <= 0)

    {
        cout << "잘못된 선택입니다." << endl;
        return;
    }

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
    //골드 차감 및 인벤토리 아이템 추가
    Character::GetInstance()->SetGold(Character::GetInstance()->GetGold() - selected_item->GetPrice());
    Character::GetInstance()->AddToInventory(selected_item);

    //캐릭터 정보 업데이트
    Character::GetInstance()->SetInventoryWeight(Character::GetInstance()->GetInventoryWeight() + selected_item->GetWeight());//무게
    Character::GetInstance()->SetMaxHealth(selected_item->GetHealth());//최대체력
    Character::GetInstance()->Character::Healing(selected_item->GetHealth());//현재체력 회복

    items_for_sale.erase(items_for_sale.begin() + (choice - 1));
    cout << "구매 성공! 남은 골드 : " << Character::GetInstance()->GetGold() << endl;

}

// 아이템 판매 로직
void Shop::SellItem()
{
    system("cls");
    cout << "================================" << endl;
    cout << "상점" << endl;
    cout << "인벤토리" << endl;
    cout << "================================" << endl;
    cout << "현재 보유 골드 : " << Character::GetInstance()->GetGold() << endl;
    cout << "인벤토리 무게 : " << Character::GetInstance()->GetInventoryWeight()
        << "/" << Character::GetInstance()->GetMaxInventoryWeight() << endl;


    cout << "보유 중인 아이템:" << endl << endl;
    for (size_t i = 0; i < Character::GetInstance()->GetInventory().size(); i++)
    {
        cout << i + 1 << ". " << (Character::GetInstance()->GetInventory())[i]->GetName()
            << endl << "판매 가격 : " << (Character::GetInstance()->GetInventory())[i]->GetPrice() / 2 << endl; // 판매 가격을 일단 절반으로 가정
    }

    cout << "뒤로가기: " << Character::GetInstance()->GetInventory().size() + 1 << endl;
    cout << "판매할 아이템을 선택하세요 : " << endl;

    int choice = GetValidNumber();


    if (choice == Character::GetInstance()->GetInventory().size() + 1) return; // 뒤로가기 처리

    Item* selected_item = Character::GetInstance()->GetInventory()[choice - 1]; // 선택한 아이템

    //캐릭터 정보 업데이트
    Character::GetInstance()->remove_from_inventory(selected_item); // 인벤토리에서 제거
    Character::GetInstance()->SetGold(Character::GetInstance()->GetGold() + selected_item->GetPrice() / 2);//골드획득
    Character::GetInstance()->Character::TakeDamage(selected_item->GetHealth());//현재체력감소
    Character::GetInstance()->SetMaxHealth(-1 * selected_item->GetHealth());//최대체력감소
    Character::GetInstance()->SetInventoryWeight(Character::GetInstance()->GetInventoryWeight()-selected_item->GetWeight());//인벤토리 무게감소

    cout << "판매 성공! 현재 보유 골드: " << Character::GetInstance()->GetGold() << endl;
}

void Shop::printstore() {
    const char* asciiArt = R"(                                       
                                   
                                   
                                                                                         $$$$$$           
                                                                                       $*-----~!          
                                                                                      $!, .,,,,-$         
                                                                                     $!-,,.,,,,,:$        
                                                                                    $!-,,,.,,,,-*$        
                                                                                     *==*,.,;=*~==$       
                                                                                     $!!!~.-!!;-*;$       
                  .----------------------------.                                    $;,,=====,,-!~$       
                 /     1.아이템 구매            \                                   $;~~$=*==:---;$       
                |      2.아이템 판매             |                                  $;;*=*~!==;-,!        
                |      3.상태보기                |                                  =:,~~-,,~:~,,::-*     
                 \     4.갈림길로 이동          /                                 ;-~-,,-,,,,,,,~~~,-=   
                  '---------------------------'                                   ~..~:-,-,,,,,,-:;:-,,   
                                                                               $!. ,,,--~----~::~~~-~-,-  
                                                                               ;. ,,,~~~~:::::~~::,,,~,,  
                                                                              $;~:~~,..,~~---,,~,~..,,,,  
                                                                             $;-,-~~~,,,,,----~:,-...,,,  
                                                                            $;,,..-~~~,-,,,,,,,,:,...,,   
                                                                            !,......~~~~-,,,,,,,,--..,,   
                                                                            =:......-~~~~~,,,,,,,,--.,;   
                                                                             =:,....,~~~~~~~,,,,,,,~.,*   
                                                                              $;~----~~~::~~~-,,,,~-,~    
                                                                               $$*:::::::::::~::::;-~     
                                                                               $ *~~--~~::::::~~~~::;@    
                                                                               $ =::::~~~~:::~~~~::;;@   
                                                                            ====$=;;;;;;;;;;;;;;;!;!!$=$$=

)";
    cout << asciiArt;
}
/*
                                                                                        $$$$$$ 
                                                                                      $!///////-$         
                                                                                     $!-/////// :$        
                                                                                    $!-        -*$        
                                                                                    <*==*,.,;=*~==$_       
                                                                                    $ !!! | !!!  ;$ }       
                  .----------------------------.                                   $;   (== )     ~$]       
                 /     1.아이템 구매            \                                  $;  $=*===:    ;$       
                |      2.아이템 판매             |                                  $;           ,!        
                |      3.상태보기                |                                  =:,~~-,,~:~,,::-*     
                 \     4.갈림길로 이동          /                                 ;-~-,,      ,,~    -=   
                  '---------------------------'                                   ~  ::       ,,     -,,   
                                                                               $!.  ,,-       ::      -,-  
                                                                               ;.  ,~~~~:::::~~::    ~,,  
                                                                              $;  ~          ,,~,~     ,,  
                                                                             $; ,-~~ ,,,,,--- ~:,-     ,,  
                                                                            $;   .-  ~,-,     ' ,:,   ,,   
                                                                            !,    ..~   -,      ,--  ,,   
                                                                             =:,      ,~  ~',,,,'~.,*   
                                                                              $;~----~~~`'~~~-----~-,~    
                                                                               $$*:                ;-~     
                                                                               $ *                 :;@    
                                                                               $ =                  ;@   
                                                                            ====$=;;;;;;;;;;;;;;;!;!!$=$$=
 */


//                                                                                            $$  $$$             
//                                                                                          $=~~:::~:!            
//                                                                                         $*~ .,,,,,-=           
//                                                                                        $*~,,..,,,,,~$          
//                                                                                       $*~,,,,,,,,,,-=          
//                                                                                       =:---,..,----!$$         
//                                                                                       $*==*,..-*==:!=$         
//                                                                                       #=!!!:.,:!!!~!:*$        
//                                                                                       $:--*=!!=*--,;-;$        
//                                                                                       $~,-===$$=,,,--!$        
//                                                                                       =;:!$=!!==*::,:=#        
//                                                                                       =:;**!~-!**;-,-*==$      
//                                                                                       :-----,,--~-,,,;~-:!     
//                                                                                     ;~.~-,,~-,,,,,,,,:~~,,;    
//                                                                                   $;...:~,,~,,,,,,,,::;:-,,;   
//                                                                                  !.....,-~~,,,,,~:::~~~~:,,,!  
//                                                                                $!...-~~,--~~:::::::~:~-,-~,,!  
//                                                                                =~----,,---~~~~~~~~-~~~.,,-,,!  
//                                                                               $!--~~~-...,,--~~~.,~-,:...,,,!  
//                                                                              $!-,,,-~~~,,,,,,,,,~~:-~....,,,!  
//                                                                             $!-,,..-~~~~--,,,,,,,,,~:....,,:   
//                                                                             *-.......~~~~~,,,,,,,,,,,~,..,,:   
//                                                                             =:,......-~~~~~--,,,,,,,,,~,.,,*   
//                                                                              =:,......~~~~~~~~,,,,,,,,--.,-    
//                                                                               =:,.....,~~~~~~~~~,,,,,,--,,$    
//                                                                               $=;::~~~~~~::::~~~~,,,,,~,,-     
//                                                                                  $!~~~~~~::::::::::::::-~$     
//1.아이템 구매                                                                     $*~~~~~~~::::::~~~~:~::;      
//2.아이템 판매                                                                      =:::~~~~~~:::~~~~~~::;;      
//3.상태보기                                                                         =;;;;;;;;;;;;;;;;;;;;;;      
//4.갈림길로 이동                                                              -~-,~************************~-~;~~