#include "../headerFile/Monster.h"

Monster::Monster(string _name)
{
	//몬스터 데이터에 등록된 몬스터인지 판별
	const std::unordered_map<std::string, Stats>::const_iterator it = monsterDatas.find(_name);
	if (it != monsterDatas.end())
	{
		DecoWord::getInstance().nickname(this->name);							//몬스터 데이터에 있으면 별명 먼저 넣어주기

		this->health =  GetRandomHealthStat(_name);	//그 몬스터의 체력계수와 레벨, 랜덤값을 계산한 최종 체력
		this->attack =  GetRandomAttackStat(_name);;	//그 몬스터의 공격계수와 레벨, 랜덤값을 계산한 최종 공격력
		health;
		attack;
	}
	else
	{
		cout << "몬스터데이터에 등록되지 않은 몬스터 입니다." << endl;
	}
}

string Monster::GetName()
{
	return name;
}

int Monster::GetHealth()
{
	return health;
}

int Monster::GetAttack()
{
	return attack;
}

int Monster::GetRandomHealthStat(string _name)
{
	int final = (monsterDatas.at(_name).health * Character::GetInstance()->GetLevel()) + (Character::GetInstance()->GetLevel() * GetRandom(20, 30));
	return final;
}

int Monster::GetRandomAttackStat(string _name)
{
	int final = (monsterDatas.at(_name).attack * Character::GetInstance()->GetLevel()) + (Character::GetInstance()->GetLevel() * GetRandom(5, 10));
	return final;
}

void Monster::TakeDamage(int damage)
{
	health = health - damage;
}

Item* Monster::DropItem()
{
	Item* item = nullptr;
	return item;
}
