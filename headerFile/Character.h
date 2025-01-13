#pragma once
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

//Singleton Pattern
class Character
{
private:
	static Character* instance;
	Character();
	~Character();

    string name;
    int level;
    int health;
    int maxHealth;
    int attack;
    int experience;
    int gold;

    vector<Item*> inventory;


	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

public:
    static Character* GetInstance() {
        if (instance == nullptr) {
            instance = new Character();
        }
        return instance;
    }

    void displayStatus();
    void levelUp();
    void useItem(int index);
    void visitShop();

//✨ update  
        int getlevel() const {
        return level;
    }
    int gethealth() const {
        return health;
    }
    int getattack() const {
        return attack;
    }
    string getname() const {
        return name;
    }
    //✨ update  
    void TakeDamage(int damage);
};