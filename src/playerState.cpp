#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "tool.cpp"
#include "guard.cpp"
#include "observer.cpp"

using namespace std;


class PlayerState
{
public:
    PlayerState ( int h, int e, int l ) : m_health ( h ), m_experience ( e ), m_level ( l ),
        m_tool ( make_unique <NoTool> () ), m_guard ( make_unique <NoGuard> () ) {}

    PlayerState ( int health, int experience, int level,
        const unique_ptr <Tool>& tool, const unique_ptr <Guard>& guard ) : m_health ( health ),
        m_experience ( experience ), m_level ( level )
    {
        m_tool = tool->clone ();
        m_guard = guard->clone ();
    }

    int getHealth () const { return m_health; }
    void setHealth ( int health ) { m_health = health; }
    
    int getExperience () const { return m_experience; }
    void setExperience ( int experience ) { m_experience = experience; }
    
    int getLevel () const { return m_level; }
    void setLevel ( int level ) { m_level = level; }

    const unique_ptr <Tool>& getTool () const { return m_tool; }
    void setTool ( unique_ptr <Tool> tool ) { m_tool = std::move ( tool ); }
    
    const unique_ptr <Guard>& getGuard () const { return m_guard; }
    void setGuard ( unique_ptr <Guard> guard ) { m_guard = std::move ( guard ); }

    void print () const
    {
        cout << "+-----------------------" << endl;
        cout << "| Health: " << m_health << endl;
        cout << "| Experience: " << m_experience << endl;
        cout << "| Level: " << m_level << endl;
        cout << "| Tool: " << *m_tool << endl;
        cout << "| Guard: " << *m_guard << endl;
        cout << "+-----------------------" << endl;
    }

private:
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
};