#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "player.h"

using namespace std;


class SaveHistory
{
public:
    SaveHistory () = default;

    void save ( shared_ptr <PlayerState> playerState );
    
    shared_ptr <PlayerState> load ( int saveId ) const;

private:
    vector <shared_ptr <PlayerState>> saves;
};