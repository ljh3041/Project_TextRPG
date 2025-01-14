#pragma once
#include <string>
#include <unordered_map>

struct Stats	//몬스터 개체값들
{
	int health;
	int attack;
};

extern const std::unordered_map<std::string, Stats> monsterDatas;	//몬스터데이터들

const std::unordered_map<std::string, Stats> monsterDatas =
{
    //이름/    체력 / 공격력 
    {"Goblin", {20, 5}},
    {"Troll", {30, 3}},
    {"Orc", {25, 7}},
    {"Dragon", {40, 15}}
};