#include "../headerFile/EquipmentItem.h"
#include "../headerFile/Character.h"



//레벨 비례 검
int ScalingSword10::GetAttack()
{
	return Character::GetInstance()->GetLevel() * 5;
}

int ScalingSword20::GetAttack()
{
	return Character::GetInstance()->GetLevel() * 10;
}

int ScalingSword30::GetAttack()
{
	return Character::GetInstance()->GetLevel() * 15;
}

int ScalingSword40::GetAttack()
{
	return Character::GetInstance()->GetLevel() * 20;
}

int ScalingSword50::GetAttack()
{
	return Character::GetInstance()->GetLevel() * 25;
}



//흡혈 단검
void VampiricDagger10::UseItem()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetAttack() * 1 / 10);
	cout << "데미지의 10%만큼 흡혈하는 무게 1, 공격력 2 단검의 효과: 체력" << Character::GetInstance()->GetAttack() * 1 / 10 << "회복" << endl;
}

void VampiricDagger20::UseItem()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetAttack() * 2 / 10);
	cout << "데미지의 20%만큼 흡혈하는 무게 1, 공격력 4 단검의 효과: 체력" << Character::GetInstance()->GetAttack() * 2 / 10 << "회복" << endl;
}

void VampiricDagger30::UseItem()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetAttack() * 3 / 10);
	cout << "데미지의 30%만큼 흡혈하는 무게 2, 공격력 6 단검의 효과: 체력" << Character::GetInstance()->GetAttack() * 3 / 10 << "회복" << endl;
}

void VampiricDagger40::UseItem()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetAttack() * 4 / 10);
	cout << "데미지의 40%만큼 흡혈하는 무게 2, 공격력 8 단검의 효과: 체력" << Character::GetInstance()->GetAttack() * 4 / 10 << "회복" << endl;
}

void VampiricDagger50::UseItem()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetAttack() * 5 / 10);
	cout << "데미지의 50%만큼 흡혈하는 무게 2, 공격력 10 단검의 효과: 체력" << Character::GetInstance()->GetAttack() * 5 / 10 << "회복" << endl;
}


//체력 도
int HP_Blade1::GetAttack()
{
	count += 1;
	if (count >= 3)
	{
		return Character::GetInstance()->GetHealth() * 10 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
	}
	else {
		return 0;
	}
}

void HP_Blade1::UseItem()
{
	if (count >= 3)
	{
		count = 0;
		cout << "3번째 공격에 나의 현재체력의 10%의 추가 피해를 주는 무게 1, 체력 10의 도의 효과: " << Character::GetInstance()->GetHealth() * 10 / 100 << "의 추가 데미지" << endl;
	}
}

int HP_Blade2::GetAttack()
{
	count += 1;
	if (count >= 3)
	{
		return Character::GetInstance()->GetHealth() * 20 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
	}
	else {
		return 0;
	}
}

void HP_Blade2::UseItem()
{
	if (count >= 3)
	{
		count = 0;
		cout << "3번째 공격에 나의 현재체력의 20%의 추가 피해를 주는 무게 1, 체력 20의 도의 효과: " << Character::GetInstance()->GetHealth() * 20 / 100 << "의 추가 데미지" << endl;
	}
}

int HP_Blade3::GetAttack()
{
	count += 1;
	if (count >= 3)
	{
		return Character::GetInstance()->GetHealth() * 30 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
	}
	else {
		return 0;
	}
}

void HP_Blade3::UseItem()
{
	if (count >= 3)
	{
		count = 0;
		cout << "3번째 공격에 나의 현재체력의 30%의 추가 피해를 주는 무게 2, 체력 30의 도의 효과: " << Character::GetInstance()->GetHealth() * 30 / 100 << "의 추가 데미지" << endl;
	}
}

int HP_Blade4::GetAttack()
{
	count += 1;
	if (count >= 3)
	{
		count = 0;
		return Character::GetInstance()->GetHealth() * 40 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
	}
	else {
		return 0;
	}
}

void HP_Blade4::UseItem()
{
	if (count >= 3)
	{
		count = 0;
		cout << "3번째 공격에 나의 현재체력의 40%의 추가 피해를 주는 무게2, 체력 40의 도의 효과: " << Character::GetInstance()->GetHealth() * 40 / 100 << "의 추가 데미지" << endl;
	}
}

int HP_Blade5::GetAttack()
{

	count += 1;
	if (count >= 2)
	{
		count = 0;
		return Character::GetInstance()->GetHealth() * 50 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
	}
	else {
		return 0;
	}
}

void HP_Blade5::UseItem()
{
	if (count >= 2)
	{
		count = 0;
		cout << "2번째 공격에 나의 현재체력의 50%의 추가 피해를 주는 무게2, 체력 50의 도의 효과: " << Character::GetInstance()->GetHealth() * 50 / 100 << "의 추가 데미지" << endl;
	}
}




//체력회복 방어구
void HealingArmor2::EndFight()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() * 2 / 100);
	cout << "전투종료시 전체 체력의 2%를 회복하는 체력 20 방어구의 효과: " << Character::GetInstance()->GetMaxHealth() * 2 / 100 << "회복" << endl;
}
void HealingArmor4::EndFight()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() * 4 / 100);
	cout << "전투종료시 전체 체력의 4%를 회복하는 체력 40 방어구의 효과: " << Character::GetInstance()->GetMaxHealth() * 4 / 100 << "회복" << endl;
}
void HealingArmor6::EndFight()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() * 6 / 100);
	cout << "전투종료시 전체 체력의 6%를 회복하는 체력 60 방어구의 효과: " << Character::GetInstance()->GetMaxHealth() * 6 / 100 << "회복" << endl;
}
void HealingArmor8::EndFight()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() * 8 / 100);
	cout << "전투종료시 전체 체력의 8%를 회복하는 체력 80 방어구의 효과: " << Character::GetInstance()->GetMaxHealth() * 8 / 100 << "회복" << endl;
}
void HealingArmor10::EndFight()
{
	Character::GetInstance()->Healing(Character::GetInstance()->GetMaxHealth() * 10 / 100);
	cout << "전투종료시 전체 체력의 10%를 회복하는 체력 100 방어구의 효과: " << Character::GetInstance()->GetMaxHealth() * 10 / 100 << "회복" << endl;
}