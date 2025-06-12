#include "soundManager.h"

using namespace std;


void SoundManager::update ( const GameEvent& event )
{
    visit ( []( const auto& e ) { e.playSound (); }, event );
}