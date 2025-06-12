#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <variant>

#include "playerState.h"

using namespace std;


struct ToolChangeEvent
{
    string toolName;
    string action; // "equipped", "unequipped"  
    string soundFile;

    void playSound () const;
    void log () const;
};

struct GuardChangeEvent
{
    string guardName;
    string action; // "equipped", "unequipped"
    string soundFile;

    void playSound () const;
    void log () const;
};

struct GameStateLoadedEvent
{
    shared_ptr <PlayerState> state;
    string soundFile = "sounds/save_load.mp3";
    
    void playSound () const;
    void log () const;
};

using GameEvent = variant <ToolChangeEvent, GuardChangeEvent, GameStateLoadedEvent>;