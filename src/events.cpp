// #include <SFML/Audio.hpp>
#include "events.h"

using namespace std;


void playSoundSFML ( const std::string& filename )
{
    /*
    If you want to use SFML for sound playback, make sure to link against the SFML Audio library.
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
    */
}

void ToolChangeEvent::playSound () const
{
    if ( ! soundFile.empty () )
    {
        cout << "Playing sound: " << soundFile << endl;
        playSoundSFML ( soundFile );
    }
}

void ToolChangeEvent::log () const
{
    cout << "Tool Change: " << toolName << ", Action: " << action << endl;
}

void GuardChangeEvent::playSound () const
{
    if ( ! soundFile.empty () )
    {
        cout << "Playing sound: " << soundFile << endl;
        playSoundSFML ( soundFile );
    }
}

void GuardChangeEvent::log () const
{
    cout << "Guard Change: " << guardName << ", Action: " << action << endl;
}

void GameStateLoadedEvent::playSound () const
{
    if ( ! soundFile.empty () )
    {
        cout << "Playing sound: " << soundFile << endl;
        playSoundSFML ( soundFile );
    }
}

void GameStateLoadedEvent::log () const
{
    cout << "Game State Loaded: " << endl;
    if ( state )
        state->print ();
    else
        cout << "No state available." << endl;
}