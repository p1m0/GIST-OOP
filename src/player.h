#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "tool.h"
#include "noTool.h"
#include "guard.h"
#include "noGuard.h"
#include "observer.h"
#include "playerState.h"

using namespace std;


class Player
{
public:
    Player ( const string& playerName );
    
    void gainExperience ( int points );
    
    void takeDamage ( int points );

    unique_ptr <Tool> unequipTool ();

    void equipTool ( unique_ptr <Tool> tool );
    
    unique_ptr <Guard> unequipGuard ();

    void equipGuard ( unique_ptr <Guard> guard );

    shared_ptr <PlayerState> getState ();

    void set_state ( shared_ptr <PlayerState> state );

    void addObserver ( shared_ptr <Observer> observer );
     
    void show_status () const;

private:
    void notifyObservers ( const GameEvent& event );

    string m_name;
    int m_health;
    int m_experience;
    int m_level;  
    unique_ptr <Tool> m_tool;
    unique_ptr <Guard> m_guard;
    vector <shared_ptr <Observer>> m_observers;
};