#include "../headerFile/Character.h"
#include "../headerFile/MyMath.h"
#include "../headerFile/TextColor.h"
#include "../headerFile/Sounds.h"

Character* Character::instance = nullptr;

Character::Character()
{
    level = 1;
    health = 200;
    maxHealth = 200;
    basicAttack = 30;
    extraAttack = 0;
    totalAttack = basicAttack + extraAttack;
    experience = 0;
    expForLevelUp = 0;
    gold = 10;
    maxLevel = 10;
    inventoryWeight = 0;
    maxInventoryWeight = 6;
    textSpeed = 300;
}

Character::~Character()
{
    for (Item* item : inventory)
    {
        delete item;
    }
    inventory.clear();
}


Character* Character::GetInstance()
{

    if (instance == nullptr)
    {
        instance = new Character();
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

void Character::NameValidation() // 이름 검증
{
    locale::global(locale("ko_KR.UTF-8"));// 로케일을 한국어로 설정
    wcin.imbue(locale("ko_KR.UTF-8"));
    wcout.imbue(locale("ko_KR.UTF-8"));
    wstring_convert<codecvt_utf8<wchar_t>> converter;// 와이드 문자열 -> UTF-8 변환기
    wstring inputName;
    string characterName = "";
    NamePlease();

    while (true)
    {
        cout << "\n\n\n\n\n                         신중하게 지은 이름: ";
        getline(wcin, inputName);
        characterName = converter.to_bytes(inputName);
        system("cls");

        if (characterName.size() < 1) //한글자 허용
        {
            LeastOneChar();
            continue;
        }

        if (characterName.size() >= 30)
        {
            LessThan30();
            continue;
        }

        bool isValid = true;
        for (char v : characterName)
        {
            if (!isalnum(v)) // 영어, 숫자만 가려내는 함수
            {
                OnlyAlNum();
                isValid = false;
                break;
            }
        }
        if (isValid) { break; }
    }

    name = characterName;
    CorrectName();
    return;
}

void Character::DisplayStatus()
{
    int Speed = 50;
    Sleep(Speed);
    cout << "- " << yellow << name << white << "님의 현재 상태에 대해 말씀드리자면, " << endl;
    Sleep(Speed);
    cout << "레벨: " << red << level << white << endl;
    Sleep(Speed);
    cout << "체력: " << darkred << health << white << "/" << maxHealth << endl;
    Sleep(Speed);
    cout << "공격력: " << blue << basicAttack << white << "(+" << blue << GetItemAttack() << white << ")" << endl;
    Sleep(Speed);
    cout << "경험치: " << green << experience << white << endl;
    Sleep(Speed);
    cout << "레벨업까지: " << green << expForLevelUp << white << "/ 100" << endl;
    Sleep(Speed);
    cout << "골드: " << darkyellow << gold << white << endl;
    Sleep(Speed);
    cout << "인벤토리 공간: " << puple << inventoryWeight << white << " / " << maxInventoryWeight << endl;
    Sleep(Speed);
    cout << "보유중인 아이템" << endl;
    Sleep(Speed);
    if(inventory.size() == 0)
    {
        cout << "- 아무것도 없어요. 상점 한번 털고 오시죠." << endl;
        Sleep(Speed);
    }
    else
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            int num = i + 1;
            cout << num << " - " << inventory[i]->GetName() << endl;
            Sleep(Speed);
        }
    }
    cout << "이정도네요. 화이팅!" << endl;
}

void Character::LevelUp()
{
    Sleep(textSpeed);
    if (level < maxLevel)
    {
        experience += 20;
        expForLevelUp += 20;

        if (expForLevelUp < 100)
        {
           
            cout << "\n경험치를 " << green << "20" << white << "획득했어요." << endl;
            Sleep(textSpeed/2);
            cout << "누적 경험치 " << green << experience << white << ", 다음 레벨까지 필요한 경험치는 " << green << 100 - expForLevelUp << white << "입니다." << endl;
            return;
        }

        level++;
        maxHealth += (level * 20);
        basicAttack += (level * 5);
        health = maxHealth;
        expForLevelUp = 0;

        cout << "\n레벨이 올랐는데 왜 올랐냐면 경험치가 " << green << "100" << white << "이 쌓이면 레벨이 오르는데 방금 전투로 필요경험치" << green << "100" << white << "이 누적되셨어요." << endl;
        Sleep(textSpeed/2);
        cout << "그래서 현재 레벨은 " << red << level << white << "입니다." << endl;
        Sleep(textSpeed / 2);
        cout << "그리고 최대 체력은 " << darkred << maxHealth << white << "이고 공격력은 " << blue << GetTotalAttack() << white << "입니다." << endl;
        Sleep(textSpeed / 2);
        cout << "체력도 완전 회복됐습니다. 쩔죠?" << endl;
        Sleep(textSpeed);
    }

    if (level == maxLevel)
    {
        cout << red << "\n최고레벨" << white << "에 도달했어요!이제 " << yellow << name << white << "님을 능가할 용사는 없어요!마지막 테스트만 통과하면요.. " << endl;
    }
}

void Character::AddGold(int AddGold)
{    
    gold += AddGold;
    GetGoldMessage(AddGold);
}

void Character::SetGold(int settleGold)
{
    gold = settleGold;      
}

void Character::SetInventoryWeight(int weight)
{
    if (weight < 0)
    {
        inventoryWeight = 0;
    }

    else
    {
        inventoryWeight = min(weight, maxInventoryWeight);
    }
}

void Character::SetMaxHealth(int adjustMaxHealth)
{
    maxHealth += adjustMaxHealth;
    if (health > maxHealth)
    {
        health = maxHealth;
    }
    else {}
}

void Character::TakeDamage(int damage)
{
    health = max((health - damage) , 0);
}

void Character::Healing(int heal)
{
    health = min((health + heal), GetTotalHealth());
}

//아이템 관련 함수
int Character::GetItemAttack()
{
    int itemAttack = 0;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        itemAttack += inventory[i]->GetAttack();
    }
    return itemAttack;
}

int Character::GetItemHealth()
{
    int itemHealth = 0;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        itemHealth += inventory[i]->GetHealth();
    }
    return itemHealth;
}

void Character::UseItem()
{
    for (size_t i = 0; i < inventory.size(); i++)
    { 
        inventory[i]->UseItem();
        if (inventory[i]->IsUsed() == true)
        {
            inventory.erase(inventory.begin() + i);
        }
    }
}

void Character::StartFight()
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        inventory[i]->StartFight();
    }
}

void Character::EndFight()
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        inventory[i]->EndFight();
    }
}

int Character::GetTotalAttack()
{
    totalAttack = GetItemAttack() + basicAttack;
    return totalAttack;
}

int Character::GetRandTotalAttack()
{
    return GetTotalAttack() + (rand() % 6 - 2);
}

int Character::GetTotalHealth()
{
    return maxHealth + GetItemHealth();
}


//인벤토리 관련 함수
int Character::GetInventoryWeight()
{
    return inventoryWeight;
}

int Character::GetMaxInventoryWeight()
{
    return maxInventoryWeight;
}


void Character::AddToInventory(Item* item)
{
    inventory.push_back(item);
}

vector<Item*> Character::GetInventory()
{
    return inventory;
}

void Character::remove_from_inventory(Item* item)
{
    auto it = find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it); // 선택된 아이템만 제거
    }
}

void Character::NamePlease()
{
    cout << blue << "                                          !--------!  !---   ---!  !--------!" << endl;
    cout << "                                          !--+  +--!  !   ; ;   !  !--+  +--!" << endl;
    cout << "                                             !  !     !    *    !     !  !   " << endl;
    cout << "                                             !  !     !  !'*'!  !  .__!  !__." << endl;
    cout << "                                             !__!     !__!   !__!  !________!" << white; Sleep(textSpeed * 3); cout << " RPG \n\n" << endl;
    Sleep(textSpeed);
    cout << "                            캐릭터의 이름을 2세 이름짓듯 설레고도 신중한 마음으로 입력해주세요." << endl;
    Sleep(textSpeed);
    cout << "                        너무 짧아도 안되고 너무 길어도 안돼요. 그리고 영어와 숫자로만 입력해주세요." << endl;
    Sleep(textSpeed);
    cout << "                                                 그래야 사주가 좋대요. " << endl;
    Sleep(textSpeed * 3);
    cout << "                                                        진짜로.\n\n" << endl;
    Sleep(textSpeed * 3);
}

void Character::LeastOneChar()
{
    Sleep(textSpeed);
    cout << "\n\n\n\n\n\n\n                                       캐릭터 이름은 한 글자 이상 입력해주세요. " << endl;
    Sleep(textSpeed);
    cout << "                             이름이란게, 고대 로마에서는 이름이 곧 운명이라고 할 정도로" << endl;
    Sleep(textSpeed);
    cout << "                                     인간에게 이름이란 중요한 것이라고 봤거든요.\n\n\n" << endl;
    Sleep(textSpeed);
}

void Character::OnlyAlNum()
{
    Sleep(textSpeed);
    cout << "\n\n\n\n\n\n\n                                             영어랑 숫자만 입력 가능합니다." << endl;
    Sleep(textSpeed);
    cout << "                                 왜냐면 C++ 만든 곳이 미국회사라서 영어가 기본이기도하고" << endl;
    Sleep(textSpeed);
    cout << "                                          한글도 어떻게 하면 가능은 하다는데" << endl;
    Sleep(textSpeed);
    cout << "                                         너무 복잡해져서 아직은 무리인거같아요." << endl;
    Sleep(textSpeed);
    cout << "                                                   아니면 한글이어도" << endl;
    Sleep(textSpeed);
    cout << "                                           혹시 제 마음에 들면 허락해드릴게요." << endl;
    Sleep(textSpeed);
}

void Character::LessThan30()
{
    Sleep(textSpeed);
    cout << "\n\n\n\n\n\n\n                                                     적당히 하세요.." << endl;
    Sleep(textSpeed * 5);
    cout << "                                                   30자는 심해요 좀.." << endl;
    Sleep(textSpeed * 5);
    cout << "                                          군대가면 관등성명대다 전역하겠어요..\n\n\n" << endl;
    Sleep(textSpeed * 5);
}

void Character::CorrectName()
{    
    string s = "                                                           ";
    s.erase(0, name.size() / 2 + 1);

    Sleep(textSpeed);
    cout << "\n\n\n\n\n\n\n                                                    좋은 이름입니다." << endl;
    Sleep(textSpeed);
    cout << "                                                   장수할 이름이에요." << endl;
    Sleep(textSpeed);
    cout << "\n\n                                                캐릭터가 생성되었습니다." << endl;
    Sleep(textSpeed);
    cout << s << yellow << name << white << "님!" << endl;
    Sleep(textSpeed);
    cout << "                                                  준비운동은 하셨나요? " << endl;
    Sleep(textSpeed);
    cout << "                                           준비운동의 중요성에 대해 아시나요?" << endl;
    Sleep(textSpeed);
    cout << "                                준비운동은 운동 중 부상위험을 획기적으로 줄여줄 수 있습니다." << endl;
    Sleep(textSpeed);
    cout << "                                                  그럼, 시작해볼까요?" << endl;
    Sleep(textSpeed * 3);
}

void Character::GetGoldMessage(int AddGold)
{    
    int messageCall = GetRandom(0, 2);

    vector<string>goldMessage =
    {
        "\n몬스터가 두부 심부름값으로 들고가던 ",
        "\n몬스터가 어머니 생일선물 사려고 모았던 ",
        "\n몬스터의 할머니가 용돈으로 주셨던 "
    };

    Sleep(textSpeed);
    cout << goldMessage[messageCall] << darkyellow << AddGold << white << "G를 획득했습니다! " << endl;
    Sleep(textSpeed / 2);
    cout << "현재 보유 골드 " << darkyellow << gold << white << "G 입니다." << endl;
    Sleep(textSpeed);
    PlayWavFile("gold.wav");
}