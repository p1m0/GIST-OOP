#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "observer.h"

using namespace std;


class SoundManager : public Observer
{
public:
    void update ( const GameEvent& event ) override;
};