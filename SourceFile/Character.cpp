#include "../headerFile/Character.h"
Character::Character()
{
    name = "";
    level = 1;
    health = 100;
    maxHealth = 100;
    attack = 10;
    experience = 0;
    gold = 0;
}

Character::~Character()
{

}



void Character::displayStatus()
{

}
void Character::levelUp()
{

}
void Character::useItem(int index)
{

}
void Character::visitShop()
{

}
//✨ update  
void Character::TakeDamage(int damage)
{
	health -= damage;
}
