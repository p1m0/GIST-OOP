#pragma once

#include <iostream>
#include <string>

#include "guard.h"

using namespace std;


class NoGuard : public Guard
{
public:
    NoGuard ( string name = "NoGuard", float defenceBonus = 1 );

    unique_ptr <Guard> clone () const override;

    float getDefenceBonus () override;

    ostream& print ( ostream& os ) const override;
};