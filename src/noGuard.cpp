#include "noGuard.h"

using namespace std;


NoGuard::NoGuard ( string name, float defenceBonus ) : Guard ( name, defenceBonus ) {}

unique_ptr <Guard> NoGuard::clone () const { return make_unique <NoGuard> (); };

float NoGuard::getDefenceBonus () { return m_defenceBonus; }

ostream& NoGuard::print ( ostream& os ) const
{
    return os << "No guard, attack bonus: " << m_defenceBonus;
}