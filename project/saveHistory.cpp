#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "player.cpp"

using namespace std;


class SaveHistory
{
public:
    SaveHistory () = default;

    void save ( shared_ptr <PlayerState> playerState ) { saves.push_back ( playerState ); }
    
    shared_ptr <PlayerState> load ( int saveId ) const { return saves.at ( saveId ); }

private:
    vector <shared_ptr <PlayerState>> saves;
};