#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "events.h"

using namespace std;


class Observer
{
public:
    virtual ~Observer () = default;

    virtual void update ( const GameEvent& event ) = 0;  
};