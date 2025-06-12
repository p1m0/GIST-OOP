#pragma once

#include <iostream>
#include <string>

using namespace std;


class Tool
{
public:
    Tool ( string name, float attackBonus );

    Tool ( string name, float attackBonus, string eqSound, string unEqSound );

    virtual ~Tool () = default;

    virtual unique_ptr <Tool> clone () const = 0;

    virtual float getAttackBonus () const = 0;
    virtual void setAttackBonus ( float attackBonus );

    string getName () const;
    void setName ( string name );

    string getEqSound () const;
    string getUnEqSound () const;

    virtual ostream& print ( ostream& os ) const = 0;

    friend ostream& operator<< ( ostream& os, const Tool& t );

protected:
    string m_name;
    float m_attackBonus;
    string m_eqSound;
    string m_unEqSound;
};