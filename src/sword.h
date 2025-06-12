#pragma once

#include <iostream>
#include <string>

#include "tool.h"

using namespace std;


class Sword : public Tool
{
public:
    Sword ( string name, float attackBonus );

    Sword ( string name, float attackBonus, string eqSound, string unEqSound );

    Sword ( const Sword& other );
    
    unique_ptr <Tool> clone () const override;

    float getAttackBonus () const override;

    ostream& print ( ostream& os ) const override;
};