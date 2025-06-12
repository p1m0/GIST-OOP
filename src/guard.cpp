#include "guard.h"

using namespace std;


Guard::Guard ( string name, float defenceBonus ) : m_name ( name ), m_defenceBonus ( defenceBonus )
{
    m_eqSound = "sounds/default_sound.mp3";
    m_unEqSound = "sounds/default_sound.mp3";
}

Guard::Guard ( string name, float defenceBonus, string eqSound, string unEqSound ) :
    m_name ( name ), m_defenceBonus ( defenceBonus ), m_eqSound ( eqSound ), m_unEqSound ( unEqSound ) {}

string Guard::getName () const { return m_name; }
void Guard::setName ( string name ) { m_name = name; }

string Guard::getEqSound () const { return m_eqSound; }
string Guard::getUnEqSound () const { return m_unEqSound; }

ostream& operator<< ( ostream& os, const Guard& g )
{
    return g.print ( os );
}