#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "tool.h"
#include "noTool.h"
#include "guard.h"
#include "noGuard.h"

using namespace std;


class PlayerState
{
public:
    PlayerState ( int h, int e, int l );

    PlayerState ( int health, int experience, int level,
        const unique_ptr <Tool>& tool, const unique_ptr <Guard>& guard );

    int getHealth () const;
    void setHealth ( int health );
    
    int getExperience () const;
    void setExperience ( int experience );
    
    int getLevel () const;
    void setLevel ( int level );

    const unique_ptr <Tool>& getTool () const;
    void setTool ( unique_ptr <Tool> tool );
    
    const unique_ptr <Guard>& getGuard () const;
    void setGuard ( unique_ptr <Guard> guard );

    void print () const;

private:
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
};