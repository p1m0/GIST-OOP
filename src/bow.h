#pragma once

#include <iostream>
#include <random>
#include <string>

#include "tool.h"

using namespace std;


class Bow : public Tool
{
public:
    Bow ( string name, float attackBonus, float criticalHitProb );
    
    Bow ( string name, float attackBonus, float criticalHitProb, string eqSound, string unEqSound );
    
    Bow ( const Bow& other );
    
    unique_ptr <Tool> clone () const override;

    float getAttackBonus () const override;

    ostream& print ( ostream& os ) const override;

private:
    float m_criticalHitProb;
    mutable random_device m_randomDevice;
    mutable mt19937 m_randomEngine { m_randomDevice() };
    mutable uniform_real_distribution<float> m_randomDist;
};