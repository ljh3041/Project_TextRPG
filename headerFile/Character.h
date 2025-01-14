#pragma once
#include <iostream>

#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include "Item.h"
using namespace std;

//Singleton Pattern
class Character
{
private:
	static Character* instance;
	Character(const string& characterName);
	~Character();

    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;

    vector<Item*> inventory;


	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

public:
    static Character* GetInstance(const string& characterName);
    static void ReleaseInstance();
    
    string NameValidation(); // 이름 검증
    void DisplayStatus();
    void LevelUp();
    void UseItem(int index);
    void VisitShop(); 

//✨ update  
    int getlevel() const 
    {

        return level;
    }
    int gethealth() const 
    {
        return health;
    }
    int getattack() const 
    {
        return attack;
    }
    string getname() const 
    {
        return name;
    }

    int getgold() const
    {
        return gold;    
    }

    void setgold(int settleGold);

    //✨ update  

    void TakeDamage(int damage);
};



Character* Character::instance = nullptr;

Character::Character(const string& characterName)
{
    name = characterName;
    level = 1;
    health = 200;
    maxHealth = 200;
    attack = 30;
    experience = 0;
    gold = 0;

    cout << "캐릭터가 생성되었습니다. " << name << "님! 준비운동은 하셨나요? 준비운동의 중요성에 대해 아시나요? 준비운동은 운동 중 부상위험을 획기적으로 줄여줄 수 있습니다." << endl;
}

Character::~Character()
{
    for (Item* item : inventory)
    {
        delete item;
    }
    inventory.clear();
}

Character* Character::GetInstance(const string& characterName)
{

    if (instance == nullptr)
    {
        instance = new Character(characterName);
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
        cout << "신중하게 지은 이름: " << endl;
        cin >> characterName;

        if (characterName.size() < 1)
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
    return characterName;
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
        cout << "레벨업할 수 있는 경험치에 도달은 했는데 지금 최고레벨이라 이제 못 올려요. 그래도 계속 나아가셨으면 좋겠어요. 도전은 아름답잖아요. 체력은 채워드릴게요." << endl;
        health = maxHealth;
        cout << "현재 체력: " << health << endl;
    }
}
void Character::UseItem(int index)
{
    Item* item = inventory[index];
    //item->Use(this);
    cout << item->getName() << "을(를) 사용했습니다." << endl;

    delete item;
    inventory.erase(inventory.begin() + index);
}

void Character::VisitShop()
{
    cout << "상점에 입장했습니다. 여기 사장님 아들이 만득인데 만득이가 작년에 코인했다가 쫄딱 망해가지고 사장님도 돈독이 바짝 올라있어요.." << endl;
    //GameManager::GetInstance()->VisitShop(this);
}

void Character::setgold(int settleGold) // +값이 들어오면 몬스터 사냥보상으로 인식, -값이 들어오면 상점 소모비용으로 인식
{
    gold += settleGold;

    if (settleGold > 0)
    {
        cout << "몬스터가 두부 심부름값으로 들고가던 " << settleGold << "G를 획득했습니다! 몬스터의 어머니는 오늘 두부도 잃고 자식도 잃었네요. \n현재 보유 골드 " << gold << "G 입니다." << endl;
        return;
    }
    else if (settleGold < 0)
    {
        cout << "시원하게 지르셨네요. 총 구매비용 " << settleGold * -1 << ", 현재 보유 골드 " << gold << "입니다. 아껴쓰시는게 좋겠어요. 요즘같은 고물가시대에.. 포션같은거보단 현금입니다." << endl;
        return;
    }
    else { return; } // 0원일 시 통과
}

//✨ update  
void Character::TakeDamage(int damage)
{
    health -= damage;
}

