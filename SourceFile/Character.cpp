#include "../headerFile/Character.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <windows.h>

#include "../headerFile/MyMath.h"

Character* Character::instance = nullptr;

Character::Character()
{
    level = 1;
    health = 200;
    maxHealth = 200;
    attack = 30;
    experience = 0;
    gold = 1000;
    inventoryWeight = 0;
    maxInventoryWeight = 3;
}

Character::~Character()
{
    for (Item* item : inventory)
    {
        delete item;
    }
    inventory.clear();
}


Character* Character::GetInstance()
{

    if (instance == nullptr)
    {
        instance = new Character();
    }
    return instance;
}

void Character::ReleaseInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

string Character::NameValidation() // 이름 검증
{
    string characterName;

    cout << "캐릭터의 이름을 2세 이름짓듯 설레고도 신중한 마음으로 입력해주세요. 너무 짧아도 안되고 너무 길어도 안돼요. 그리고 영어와 숫자로만 입력해주세요. 그래야 사주가 좋대요. " << endl;

    while (true)
    {
        
        cout << "신중하게 지은 이름: ";
        getline(cin, characterName);
        system("cls");

        if (characterName.size() < 2) //2여야지 1이면 여기로 들어옴.
        {
            cout << "캐릭터 이름은 한 글자 이상 입력해주세요. 이름이란게, 고대 로마에서는 이름이 곧 운명이라고 할 정도로 인간에게 이름이란 중요한 것이라고 봤거든요." << endl;
            continue;
        }

        if (characterName.size() >= 30)
        {
            cout << "적당히 하세요. 30자는 심하잖아요. 군대가면 관등성명대다 전역하겠어요." << endl;
            continue;
        }

        bool isValid = true;
        for (char v : characterName)
        {
            if (isalnum(v) == false) // 영어랑 숫자만 가려내는 함수
            {
                cout << "영어랑 숫자만 입력 가능합니다. 왜냐면 C++ 만든 곳이 미국회사라서 영어가 기본이기도하고 한글도 어떻게 하면 가능은 하다는데 너무 복잡해져서 아직은 무리인거같아요." << endl;
                isValid = false;
                break;
            }
        }
        if (isValid) { break; }
    }
    cout << "좋은 이름입니다. 장수할 이름이에요." << endl;
    return characterName;
}

void Character::SetName(const string& characterName)
{
    name = characterName;    
    cout << "\n캐릭터가 생성되었습니다. " << name << "님! 준비운동은 하셨나요? 준비운동의 중요성에 대해 아시나요? 준비운동은 운동 중 부상위험을 획기적으로 줄여줄 수 있습니다." << endl;
}

void Character::DisplayStatus()
{
    cout << "-현재 상태에 대해 말씀드리자면, " << endl;
    cout << "레벨: " << level << endl;
    cout << "체력: " << health << "/" << maxHealth << endl;
    cout << "공격력: " << attack << endl;
    cout << "경험치: " << experience << "/100" << endl;
    cout << "골드: " << gold << endl;
    cout << "이정도네요. 화이팅!" << endl;
}

void Character::LevelUp()
{
    experience += 20;

    if (experience < 100)
    {
        cout << "경험치를 20 획득했어요. 레벨업까지 필요한 경험치는 " << 100 - experience << "입니다." << endl;
        return;
    }

    level++;
    maxHealth += (level * 20);
    attack += (level * 5);
    health = maxHealth;
    experience = 0;
    cout << "레벨이 올랐는데 왜 올랐냐면 경험치가 100이 쌓이면 레벨이 오르는데 방금 전투로 필요경험치 100이 누적되셨어요." <<
        "\n그래서 현재 레벨은 " << level << "입니다." << "\n그리고 최대 체력은 " << maxHealth << "이고 공격력은 " << attack << "입니다." << endl;

    if (level == 10)
    {
        cout << "최고레벨에 도달했어요! 이제 " << name << "님을 능가할 용사는 없어요! 마지막 테스트만 통과하면요.. 마지막으로 체력을 채워드릴게요." << endl;
        health = maxHealth;
        cout << "현재 체력: " << health << endl;
    }
}
/*void Character::UseItem(int index)
{
    Item* item = inventory[index];
    item->Use(this);
    cout << item->getName() << "을(를) 사용했습니다." << endl;

    delete item;
    inventory.erase(inventory.begin() + index);
}

/*void Character::VisitShop()
{
    cout << "상점에 입장했습니다. 여기 사장님 아들이 만득인데 만득이가 작년에 코인했다가 쫄딱 망해가지고 사장님도 돈독이 바짝 올라있어요.." << endl;
    GameManager::GetInstance()->VisitShop(this);
}*/

void Character::SetGold(int settleGold)
{
    gold = settleGold;
    cout << "\n현재 보유 골드 " << gold << "G 입니다." << endl;
    /*int messageCall = GetRandom(0, 2); // 상점수입과 혼동될 수 있어 보류

    vector<string>goldMessageA =
    {
        "몬스터가 두부 심부름값으로 들고가던 ",
        "몬스터가 어머니 생일선물 사려고 모았던 ",
        "몬스터의 할머니가 용돈으로 주셨던 "
    };

    vector<string>goldMessageB =
    {
        "몬스터의 어머니는 오늘 두부도 잃고 자식도 잃었네요.",
        "몬스터의 어머니는 올해 생일선물 받긴 글렀네요.",
        "맛있는거 사먹으라고 꼬깃한 쌈짓돈 쥐어주시는 모습이 아른거려요.."
    };

    if (settleGold > 0)
    {
        cout << goldMessageA[messageCall] << settleGold << "G를 획득했습니다!" << goldMessageB[messageCall] << endl;
        cout << "\n현재 보유 골드 " << gold << "G 입니다." << endl;
        return;
    }
    else if (settleGold < 0)
    {
        cout << "시원하게 지르셨네요. 총 구매비용 " << settleGold * -1 << ", 현재 보유 골드 " << gold << "입니다. 좀 아껴쓰시는게 좋겠어요. 요즘같은 고물가시대에.. 포션따위보단 현금입니다." << endl;
        return;
    }
    else { return; } // 0원일 시 통과*/
}

//✨ update  
void Character::TakeDamage(int damage)
{
    health -= damage;
}

void Character::Healing(int heal)
{
    health -= heal;
}

//아이템 관련 함수
int Character::GetItemAttack()
{
    int itemAttack = 0;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        itemAttack += inventory[i]->GetAttack();
    }
    return itemAttack;
}

int Character::GetItemHealth()
{
    int itemHealth = 0;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        itemHealth += inventory[i]->GetHealth();
    }
    return itemHealth;
}

void Character::UseItem()
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        inventory[i]->UseItem();
        if (inventory[i]->IsUsed() == true)
        {
            inventory.erase(inventory.begin() + i);
        }
    }
}

void Character::StartFight()
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        inventory[i]->StartFight();
    }
}

void Character::EndFight()
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        inventory[i]->EndFight();
    }
}

int Character::GetTotalAttack()
{
    return attack + GetItemAttack();
}

int Character::GetTotalHealth()
{
    return health + GetTotalHealth();
}


//인벤토리 관련 함수
int Character::GetInventoryWeight()
{
    return inventoryWeight;
}

int Character::GetMaxInventoryWeight()
{
    return maxInventoryWeight;
}


void Character::AddToInventory(Item* item)
{
    inventory.push_back(item);
}

vector<Item*> Character::GetInventory()
{
    return inventory;
}

void Character::remove_from_inventory(Item* item)
{
    //find item and remove item
}