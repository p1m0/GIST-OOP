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
        cout << "Playing sound: " << soundFile << endl << endl;
        playSoundSFML ( soundFile );
    }
}

void ToolChangeEvent::log () const
{
    cout << "-------- ToolChangeEvent BEGIN --------" << endl;
    cout << "Tool Change: " << toolName << ", Action: " << action << endl;
    cout << "-------- ToolChangeEvent END --------" << endl << endl;
}

void GuardChangeEvent::playSound () const
{
    if ( ! soundFile.empty () )
    {
        cout << "Playing sound: " << soundFile << endl << endl;
        playSoundSFML ( soundFile );
    }
}

void GuardChangeEvent::log () const
{
    cout << "-------- GuardChangeEvent BEGIN --------" << endl;
    cout << "Guard Change: " << guardName << ", Action: " << action << endl;
    cout << "-------- GuardChangeEvent END --------" << endl << endl;
}

void GameStateLoadedEvent::playSound () const
{
    if ( ! soundFile.empty () )
    {
        cout << "Playing sound: " << soundFile << endl << endl;
        playSoundSFML ( soundFile );
    }
}

void GameStateLoadedEvent::log () const
{
    cout << "-------- GameStateLoadedEvent BEGIN --------" << endl;
    cout << "Game State Loaded: " << endl;
    if ( state )
        state->print ();
    else
        cout << "No state available." << endl;
    cout << "-------- GameStateLoadedEvent END --------" << endl << endl;
}