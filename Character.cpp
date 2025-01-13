#include "Character.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

Character* Character::instance = nullptr;

Character::Character(const string& characterName) : level(1), health(200), maxHealth(200), attack(30), experience(0), gold(0)
{
    name = characterName;
    cout << "ĳ���Ͱ� �����Ǿ����ϴ�." << name << "��! �ѹ� �����Ǳ��?" << endl;
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
    if (IsValidName(characterName) == false) 
    {
        return nullptr;
                    
    }
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

bool Character::IsValidName(const string& characterName) // �̸� ����
{
    if(characterName.size() < 1)
    {
        cout << "ĳ���� �̸��� �� ���� �̻� �Է����ּ���. �̸��̶���, ��� �θ������� �̸��� �� ����̶�� �� ������ �ΰ����� �̸��̶� �߿��� ���̶�� �ðŵ��. " << endl;
        return false;
    }

    if (characterName.size() >= 30) 
    {
        cout << "������ �ϼ���. 30���ڴ� �����ݾƿ�. ���밡�� ������� �����ϰھ��." << endl;
        return false;
    }

    for (char v : characterName) 
    {
        if(isalnum(v) == false)
        {
            cout << "����� ���ڸ� �Է� �����մϴ�. �ֳĸ� C++ ���� ���� �̱�ȸ��� ��� �⺻�̱⵵�ϰ� �ѱ۵� ��� �ϸ� ������ �ϴٴµ� �ʹ� ���������� ������ �����ΰŰ��ƿ�." << endl;
            return false;
        }
    }
    return true;
}

void Character::DisplayStatus()
{

}


void Character::LevelUp()
{
    int expForLevel = 0;
    experience += 20;   
    expForLevel += 20;

    if (expForLevel == 100)
    {
        if (level == 10)
        {
            cout << "�������� �� �ִ� ����ġ�� ������ �ߴµ� ���� �ְ����̶� ���� �� �÷���. �׷��� ��� ���ư������� ���ھ��. ������ �Ƹ����ݾƿ�. �׷��� ü���� ä���帱�Կ�." << endl;
            health = maxHealth;
        }
        else
        {
            level++;
            maxHealth += (level * 20);
            attack += (level * 5);
            health = maxHealth;
            expForLevel = 0;
            cout << "������ �ö��µ� �� �ö��ĸ� ����ġ�� 100�� ���̸� ������ �����µ� ��� ������ �ʿ����ġ 100�� �����Ǽ̾��." << "\n�׷��� ���� ������ " << level << "�Դϴ�." << endl;
        }
    }
}
void Character::UseItem(int index)
{

}
void Character::VisitShop()
{
    cout << "������ �����߽��ϴ�. ���� ����� �Ƶ��� �����ε� �����̰� �۳⿡ �����ߴٰ� �̵� ���ذ����� ����Ե� ������ ��¦ �ö��־��.." << endl;
    GameManager::GetInstance()->VisitShop(this); 
}

