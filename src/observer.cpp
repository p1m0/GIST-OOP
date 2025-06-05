#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <variant>

#include <SFML/Audio.hpp>

#include "playerState.cpp"

using namespace std;


void playSoundSFML ( const std::string& filename )
{
    sf::SoundBuffer buffer;
    if ( ! buffer.loadFromFile ( filename ))
    {
        std::cout << "Error loading sound file" << std::endl;
        return;
    }
    
    sf::Sound sound ( buffer );
    sound.play ();
    
    while ( sound.getStatus () == sf::Sound::Status::Playing )
        sf::sleep ( sf::milliseconds ( 10 ) );
}

struct ToolChangeEvent
{
    string toolName;
    string action; // "equipped", "unequipped"
    string soundFile; // Optional sound file for the event

    void playSound () const
    {
        if ( ! soundFile.empty () )
        {
            cout << "Playing sound: " << soundFile << endl;
            playSoundSFML ( soundFile );
        }
    }

    void log () const
    {
        cout << "Tool Change: " << toolName << ", Action: " << action << endl;
    }
};

struct GuardChangeEvent
{
    string guardName;
    string action; // "equipped", "unequipped"
    string soundFile; // Optional sound file for the event

    void playSound () const
    {
        if ( ! soundFile.empty () )
        {
            cout << "Playing sound: " << soundFile << endl;
            playSoundSFML ( soundFile );
        }
    }

    void log () const
    {
        cout << "Guard Change: " << guardName << ", Action: " << action << endl;
    }
};

struct GameStateLoadedEvent
{
    shared_ptr <PlayerState> state;
    string soundFile = "sounds/save_load.mp3"; // Optional sound file for the event
    
    void playSound () const
    {
        if ( ! soundFile.empty () )
        {
            cout << "Playing sound: " << soundFile << endl;
            playSoundSFML ( soundFile );
        }
    }

    void log () const
    {
        cout << "Game State Loaded: " << endl;
        if ( state )
            state->print ();
        else
            cout << "No state available." << endl;
    }
};

// Event variant that can hold any event type
using GameEvent = variant <ToolChangeEvent, GuardChangeEvent, GameStateLoadedEvent>;


class Observer
{
public:
    virtual ~Observer () = default;

    virtual unique_ptr <Observer> clone () const = 0;

    virtual void update ( const GameEvent& event ) = 0;  
};

class Logger : public Observer
{
public:
    unique_ptr <Observer> clone () const override { return make_unique <Logger> (); }

    void update ( const GameEvent& event ) override
    {
        // cout << "--------Logger--------" << endl;
        visit ( []( const auto& e ) { e.log (); }, event );
        // cout << "--------EndLogger--------" << endl;
    }
};

class SoundManager : public Observer
{
public:
    unique_ptr <Observer> clone () const override { return make_unique <SoundManager> (); }

    void update ( const GameEvent& event ) override
    {
        visit ( []( const auto& e ) { e.playSound (); }, event );
    }
};