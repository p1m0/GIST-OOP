#include "woodenGuard.h"

using namespace std;


WoodenGuard::WoodenGuard ( string name, float defenceBonus, int durability, int durabilityLoss ) :
    Guard ( name, defenceBonus ), m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}

WoodenGuard::WoodenGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
    int durability, int durabilityLoss ) :
    Guard ( name, defenceBonus, eqSound, unEqSound ),
    m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}

WoodenGuard::WoodenGuard ( const WoodenGuard& other ) :
    Guard ( other.m_name, other.m_defenceBonus, other.m_eqSound, other.m_unEqSound )
{
    m_durability = other.m_durability;
    m_durabilityLoss = other.m_durabilityLoss;
}

unique_ptr <Guard> WoodenGuard::clone () const { return make_unique <WoodenGuard> ( *this ); }

float WoodenGuard::getDefenceBonus ()
{
    if ( m_durability > 0 )
    {
        m_durability -= m_durabilityLoss;
        if ( m_durability < 0 )
            m_durability = 0;
    }

    if ( m_durability > 0 )
        return m_defenceBonus;
    return 1;
}

ostream& WoodenGuard::print ( ostream& os ) const
{
    return os << "Wooden guard, name: " << m_name << ", defence bonus: "
        << m_defenceBonus << ", durability: " << m_durability;
}