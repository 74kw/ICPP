#include "Monster.h"

int Monster::GetHP() const
{
    return this->hp;
}

void Monster::SetHP(int hp)
{
    this->hp = hp;
}

int Monster::GetMaxHP() const
{
    return this->maxhp;
}

void Monster::SetMaxHP(int maxhp)
{
    this->maxhp = maxhp;
}

