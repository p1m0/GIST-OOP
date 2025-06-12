#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "observer.h"

using namespace std;

class Logger : public Observer
{
public:
    void update ( const GameEvent& event ) override;
};