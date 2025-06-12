#pragma once

#include <iostream>
#include <string>

#include "guard.h"

using namespace std;


class SteelGuard : public Guard
{
public:
    SteelGuard ( string name, float defenceBonus, int durability = 200, int durabilityLoss = 5 );
    
    SteelGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
        int durability = 200, int durabilityLoss = 5 );

    SteelGuard ( const SteelGuard& other );

    unique_ptr <Guard> clone () const override;

    float getDefenceBonus () override;
    
    ostream& print ( ostream& os ) const override;

private:
    int m_durability;
    int m_durabilityLoss;
};