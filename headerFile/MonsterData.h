#pragma once
#include <string>
#include <unordered_map>

struct Stats	//몬스터 스텟들
{
	int health;
	int attack;
};

extern const std::unordered_map<std::string, Stats> monsterDatas;	//몬스터데이터들