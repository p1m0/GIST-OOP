#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "tool.cpp"
#include "guard.cpp"

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

    /*
    unique_ptr <Tool> takeTool ()
    {
        unique_ptr <Tool> temp = make_unique <NoTool> ();
        m_tool.swap ( temp );
        return temp;
    }

    unique_ptr <Guard> takeGuard ()
    {
        unique_ptr <Guard> temp = make_unique <NoGuard> ();
        m_guard.swap ( temp );
        return temp;
    }
    */

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

private:
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
};

/*
class Player
{
public:
    Player ( const string& playerName ) : m_name ( playerName ),
        m_state ( make_shared <PlayerState> ( 100, 0, 1 ) ) {}
    
    void gainExperience ( int points )
    {
        m_state->setExperience ( m_state->getExperience () + points * m_state->getTool()->getAttackBonus () );
        m_state->setLevel ( 1 + m_state->getExperience () / 100 );
    }
    
    void takeDamage ( int points )
    {
        int newHealth = m_state->getHealth () - points * m_state->getGuard ()->getDefenceBonus ();
        if ( newHealth < 0 )
            newHealth = 0;
        m_state->setHealth ( newHealth );
    }

    unique_ptr <Tool> unequipTool () { return m_state->takeTool (); }
    void equipTool ( unique_ptr <Tool> tool ) { m_state->setTool ( std::move ( tool ) ); }
    
    unique_ptr <Tool> unequipGuard () { return m_state->takeTool (); }
    void equipGuard ( unique_ptr <Guard> guard ) { m_state->setGuard ( std::move ( guard ) ); }

    shared_ptr <PlayerState> get_state () { return m_state; }
    void set_state ( shared_ptr<PlayerState> state ) { m_state = state; }
     
    void show_status () const
    {
        cout << "------------------------" << endl;
        cout << "Player: " << m_name << endl;
        cout << "Health: " << m_state->getHealth () << endl;
        cout << "Experience: " << m_state->getExperience () << endl;
        cout << "Level: " << m_state->getLevel () << endl;
        cout << "Tool: " << *m_state->getTool ();
        cout << "Guard: " << *m_state->getGuard ();
        cout << "------------------------" << endl;
    }

private:
    string m_name;
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
    shared_ptr <PlayerState> m_state;
};
*/

class Player
{
public:
    Player ( const string& playerName ) : m_name ( playerName ),
        m_health ( 100 ), m_experience ( 0 ), m_level ( 1 ),
        m_tool ( make_unique <NoTool> () ), m_guard ( make_unique <NoGuard> () ) {}
    
    void gainExperience ( int points )
    {
        m_experience += points * m_tool->getAttackBonus ();
        m_level = 1 + m_experience / 100;
    }
    
    void takeDamage ( int points )
    {
        m_health -= points * m_guard->getDefenceBonus ();
        if ( m_health < 0 )
        m_health = 0;
    }

    unique_ptr <Tool> unequipTool ()
    {
        unique_ptr <Tool> temp = make_unique <NoTool> ();
        m_tool.swap ( temp );
        return temp;
    }
    void equipTool ( unique_ptr <Tool> tool ) { m_tool = std::move ( tool ); }
    
    unique_ptr <Guard> unequipGuard ()
    {
        unique_ptr <Guard> temp = make_unique <NoGuard> ();
        m_guard.swap ( temp );
        return temp;
    }
    void equipGuard ( unique_ptr <Guard> guard ) { m_guard = std::move ( guard ); }

    shared_ptr <PlayerState> get_state ()
    {
        return make_shared <PlayerState> ( m_health, m_experience, m_level, m_tool, m_guard );
    }
    void set_state ( shared_ptr <PlayerState> state )
    {
        m_health = state->getHealth ();
        m_experience = state->getExperience ();
        m_level = state->getLevel ();
        m_tool = state->getTool ()->clone ();
        m_guard = state->getGuard ()->clone ();
    }
     
    void show_status () const
    {
        cout << "------------------------" << endl;
        cout << "Player: " << m_name << endl;
        cout << "Health: " << m_health << endl;
        cout << "Experience: " << m_experience << endl;
        cout << "Level: " << m_level << endl;
        cout << "Tool: " << *m_tool << endl;
        cout << "Guard: " << *m_guard << endl;
        cout << "------------------------" << endl;
    }

private:
    string m_name;
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
};