#pragma once

#include <iostream>
#include <string>

using namespace std;


class Guard
{
public:
    Guard ( string name, float defenceBonus );

    Guard ( string name, float defenceBonus, string eqSound, string unEqSound );
    
    virtual ~Guard () = default;

    virtual unique_ptr <Guard> clone () const = 0;

    virtual float getDefenceBonus () = 0;
    virtual void setDefenceBonus ( float defenceBonus ) { m_defenceBonus = defenceBonus; };

    string getName () const;
    void setName ( string name );

    string getEqSound () const;
    string getUnEqSound () const;

    virtual ostream& print ( ostream& os ) const = 0;

    friend ostream& operator<< ( ostream& os, const Guard& t );

protected:
    string m_name;
    float m_defenceBonus;
    string m_eqSound;
    string m_unEqSound;
};