#include "../headerFile/ConsumableItem.h"
#include "../headerFile/Character.h"


//고정값 포션
void potion50::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= 100)
	{
		Character::GetInstance()->Healing(50);
		cout << "체력을 50 회복하는 물약의 효과: 체력 50 회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

void potion100::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= 100)
	{
		Character::GetInstance()->Healing(100);
		cout << "체력을 100 회복하는 물약의 효과: 체력 100 회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

void potion300::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= 100)
	{
		Character::GetInstance()->Healing(150);
		cout << "체력을 150 회복하는 물약의 효과: 체력 150 회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

void potion600::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= 100)
	{
		Character::GetInstance()->Healing(200);
		cout << "체력을 200 회복하는 물약의 효과: 체력 200 회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

//비율포션
void potionQuarter::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= Character::GetInstance()->GetMaxHealth() / 4)
	{
		Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() / 4);
		cout << "체력이 25% 이하일 때 체력 25%를 회복하는 포션의 효과: " << Character::GetInstance()->GetMaxHealth() / 4 << "회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

void potionHalf::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= Character::GetInstance()->GetMaxHealth() / 2)
	{
		Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() / 2);
		cout << "체력이 50% 이하일 때 체력 50%를 회복하는 포션의 효과: " << Character::GetInstance()->GetMaxHealth() / 2 << "회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}

void potionFull::UseItem()
{
	if (Character::GetInstance()->GetHealth() <= Character::GetInstance()->GetMaxHealth() / 10)
	{
		Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth());
		cout << "체력이 10% 이하일 때 체력 100%를 회복하는 포션의 효과: " << Character::GetInstance()->GetMaxHealth() << "회복" << endl;
		isUsed = true;
	}
	else isUsed = false;
}