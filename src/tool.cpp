#include "tool.h"

using namespace std;


Tool::Tool ( string name, float attackBonus ) : m_name ( name ), m_attackBonus ( attackBonus )
{
    m_eqSound = "sounds/default_sound.mp3";
    m_unEqSound = "sounds/default_sound.mp3";
}

Tool::Tool ( string name, float attackBonus, string eqSound, string unEqSound ) :
    m_name ( name ), m_attackBonus ( attackBonus ), m_eqSound ( eqSound ), m_unEqSound ( unEqSound ) {}

void Tool::setAttackBonus ( float attackBonus ) { m_attackBonus = attackBonus; };

string Tool::getName () const { return m_name; }
void Tool::setName ( string name ) { m_name = name; }

string Tool::getEqSound () const { return m_eqSound; }
string Tool::getUnEqSound () const { return m_unEqSound; }

ostream& operator<< ( ostream& os, const Tool& t )
{
    return t.print ( os );
}