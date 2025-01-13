#include "../headerFile/Character.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

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

    cout << "ĳ���Ͱ� �����Ǿ����ϴ�. " << name << "��! �غ��� �ϼ̳���? �غ��� �߿伺�� ���� �ƽó���? �غ��� � �� �λ������� ȹ�������� �ٿ��� �� �ֽ��ϴ�." << endl;
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
    if (characterName.size() < 1)
    {
        cout << "ĳ���� �̸��� �� ���� �̻� �Է����ּ���. �̸��̶���, ���� �θ������� �̸��� �� ����̶�� �� ������ �ΰ����� �̸��̶� �߿��� ���̶�� �ðŵ��. " << endl;
        return false;
    }

    if (characterName.size() >= 30)
    {
        cout << "������ �ϼ���. 30���ڴ� �����ݾƿ�. ���밡�� �������� �����ϰھ��." << endl;
        return false;
    }

    for (char v : characterName)
    {
        if (isalnum(v) == false)
        {
            cout << "����� ���ڸ� �Է� �����մϴ�. �ֳĸ� C++ ���� ���� �̱�ȸ��� ��� �⺻�̱⵵�ϰ� �ѱ۵� ��� �ϸ� ������ �ϴٴµ� �ʹ� ���������� ������ �����ΰŰ��ƿ�." << endl;
            return false;
        }
    }
    return true;
}

void Character::DisplayStatus()
{
    cout << "-���� ���¿� ���� �����帮�ڸ�, " << endl;
    cout << "������ " << level << endl;
    cout << "ü��: " << health << "/" << maxHealth << endl;
    cout << "���ݷ�: " << attack << endl;
    cout << "����ġ: " << experience << "/100" << endl;
    cout << "���: " << gold << endl;
    cout << "�������׿�. ȭ����!" << endl;
}

void Character::LevelUp()
{
    experience += 20;

    if (experience < 100)
    {
        cout << "����ġ�� 20 ȹ���߾��. ���������� �ʿ��� ����ġ�� " << 100 - experience << "�Դϴ�." << endl;
        return;
    }

    level++;
    maxHealth += (level * 20);
    attack += (level * 5);
    health = maxHealth;
    experience = 0;
    cout << "������ �ö��µ� �� �ö��ĸ� ����ġ�� 100�� ���̸� ������ �����µ� ��� ������ �ʿ����ġ 100�� �����Ǽ̾��." <<
        "\n�׷��� ���� ������ " << level << "�Դϴ�." << "\n�׸��� �ִ� ü���� " << maxHealth << "�̰� ���ݷ��� " << attack << "�Դϴ�." << endl;
    
    if (level == 10)
    {
        cout << "�������� �� �ִ� ����ġ�� ������ �ߴµ� ���� �ְ������̶� ���� �� �÷���. �׷��� ��� ���ư������� ���ھ��. ������ �Ƹ����ݾƿ�. ü���� ä���帱�Կ�." << endl;
        health = maxHealth;
        cout << "���� ü��: " << health << endl;
        return;
    }
}
void Character::UseItem(int index)
{
    Item* item = inventory[index];
    item->Use(this);
    cout << item->GetName() << "��(��) ����߽��ϴ�." << endl;

    delete item;
    inventory.erase(inventory.begin() + index);
}

/*void Character::VisitShop()
{
    cout << "������ �����߽��ϴ�. ���� ����� �Ƶ��� �����ε� �����̰� �۳⿡ �����ߴٰ� �̵� ���ذ����� ����Ե� ������ ��¦ �ö��־��.." << endl;
    GameManager::GetInstance()->VisitShop(this);
}*/


//✨ update  
void Character::TakeDamage(int damage)
{
	health -= damage;
}

