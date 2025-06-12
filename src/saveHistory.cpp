#include "saveHistory.h"

using namespace std;


void SaveHistory::save ( shared_ptr <PlayerState> playerState ) { saves.push_back ( playerState ); }

shared_ptr <PlayerState> SaveHistory::load ( int saveId ) const { return saves.at ( saveId ); }