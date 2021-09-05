#pragma once
#include "IngameObject.h"
#include "Enemy.h"

class Lizard :
    public Enemy
{
    int appear_x;
public:
    Lizard();
    void Appear(int tornev_x, int appear_x);
};
