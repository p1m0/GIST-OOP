#pragma once

#include <iostream>
#include <string>

#include "guard.h"

using namespace std;


class WoodenGuard : public Guard
{
public:
    WoodenGuard ( string name, float defenceBonus, int durability = 100, int durabilityLoss = 10 );
    
    WoodenGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
        int durability = 100, int durabilityLoss = 10 );
    
    WoodenGuard ( const WoodenGuard& other );

    unique_ptr <Guard> clone () const override;

    float getDefenceBonus () override;

    ostream& print ( ostream& os ) const override;

private:
    int m_durability;
    int m_durabilityLoss;
};