#include "noTool.h"

using namespace std;


NoTool::NoTool ( string name, float attackBonus ) : Tool ( name, attackBonus ) {}

unique_ptr <Tool> NoTool::clone () const { return make_unique <NoTool> (); };

float NoTool::getAttackBonus () const { return m_attackBonus; }

ostream& NoTool::print ( ostream& os ) const
{
    return os << "No tool, attack bonus: " << m_attackBonus;
}