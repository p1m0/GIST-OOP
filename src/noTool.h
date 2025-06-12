#pragma once

#include <iostream>
#include <string>

#include "tool.h"

using namespace std;


class NoTool : public Tool
{
public:
    NoTool ( string name = "NoTool", float attackBonus = 1 );
    
    unique_ptr <Tool> clone () const override;

    float getAttackBonus () const override;

    ostream& print ( ostream& os ) const override;
};