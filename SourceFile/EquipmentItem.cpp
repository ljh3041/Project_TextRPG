#include "../headerFile/EquipmentItem.h"
#include "../headerFile/Character.h"

Character* c;

//레벨 비례 검
int ScalingSword3::GetAttack()
{
	return c->GetLevel() * 3;
}


//흡혈 단검
void VampiricDagger::UseItem()
{
	c->Healing(c->GetAttack() * 3 / 10);
	cout << "데미지의 30%만큼 흡혈하는 무게 1, 공격력 10 단검의 효과: 체력" << c->GetAttack() * 3 / 10 << "회복" << endl;
}


//체력 도
int HP_Blade4::GetAttack()
{
	if (count < 4)
	{
		return 0;
	}
	else
	{
		count = 0;
		return c->GetHealth() * 5 / 100;  //아이템에 추가 공격력을 통해 추가 데미지 구현
		cout << "4번째 공격에 나의 현재체력의 5%의 추가 피해를 주는 무게2, 체력 50의 도의 효과: " << c->GetMaxHealth() * 5 / 100 << "의 추가 데미지" << endl;
	}
}

void HP_Blade4::UseItem()
{
	count += 1;
}


//체력회복 방어구
void HealingArmor::EndFight()
{
	c->Healing(c->GetMaxHealth() / 10);
}