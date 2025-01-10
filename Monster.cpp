#include "Monster.h"


Monster::Monster()
{
	//만약 스테이지가 보스 스테이지면 보스를 소환해야겠지?

	species = static_cast<MonstetrKind>(GetRandom(0,2));	//랜덤한 종으로 넣기
	name += SpeciesToString(species);						//뒤에 몬스터 이름 붙이기
	SettingStateInit(species);								//종에따른 종족값 세팅

	
}

string Monster::GetName()
{
	return name;
}

int Monster::GetHealth()
{
	return health;
}

int Monster::GetRandom(int _min, int _max)
{
	// 난수 엔진 초기화
	std::random_device rd;  // 하드웨어 기반 난수 생성기 (시드용)
	std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화

	// 범위 내 난수 생성기 (최소, 최대)
	std::uniform_int_distribution<> dist(_min, _max);

	return dist(gen);
}

float Monster::GetRandomf(float _min, float _max)
{
	// 난수 엔진 초기화
	std::random_device rd;  // 하드웨어 기반 난수 생성기 (시드용)
	std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화

	// 범위 내 난수 생성기 (최소, 최대)
	std::uniform_real_distribution<> dist(_min, _max);

	return dist(gen);
}

void Monster::SettingStateInit(MonstetrKind _monsterkind)
{
	switch (_monsterkind)	//종에 따른 각 능력치 계수별로 출력
	{
	case Monster::Goblin:
		health = 20;
		attack = 5;
		break;
	case Monster::Troll:
		health = 30;
		attack = 3;
		break;
	case Monster::Orc:
		health = 25;
		attack = 7;
		break;
	case Monster::Dragon:
		health = 40;
		attack = 15;
		break;
	default:
		break;
	}

	//여기다 레벨 당 올라가는 수치 더해주면 될듯.
	health *= GetRandomf(1.0f, 1.5f);
	attack *= GetRandomf(1.0f, 1.5f);
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

string Monster::SpeciesToString(MonstetrKind _monsterkind)
{
	switch (_monsterkind)
	{
	case Monster::Goblin:
		return "Goblin";
	case Monster::Troll:
		return "Troll";
	case Monster::Orc:
		return "Orc";
	case Monster::Dragon:
		return "Dragon";
	default:
		return "Error";
	}
}
