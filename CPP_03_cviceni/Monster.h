#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include "MoveableObject.h"

class Monster : MoveableObject {
private:
	int hp;
	int maxhp;

public:
	int GetHP() const;
	void SetHP(int hp);
	int GetMaxHP() const;
	void SetMaxHP(int maxhp);

};

#endif // !MONSTER_H

