#include "logger.h"

using namespace std;


void Logger::update ( const GameEvent& event )
{
    // cout << "--------Logger--------" << endl;
    visit ( []( const auto& e ) { e.log (); }, event );
    // cout << "--------EndLogger--------" << endl;
}