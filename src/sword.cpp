#include "sword.h"

using namespace std;


Sword::Sword ( string name, float attackBonus ) : Tool ( name, attackBonus ) {}

Sword::Sword ( string name, float attackBonus, string eqSound, string unEqSound ) :
    Tool ( name, attackBonus, eqSound, unEqSound ) {}

Sword::Sword ( const Sword& other ) : Tool ( other.m_name, other.m_attackBonus, other.m_eqSound, other.m_unEqSound ) {}

unique_ptr <Tool> Sword::clone () const { return make_unique <Sword> ( *this ); }

float Sword::getAttackBonus () const { return m_attackBonus; }

ostream& Sword::print ( ostream& os ) const
{
    return os << "Tool type: Sword, name: " << m_name << ", attack bonus: " << m_attackBonus;
}