#include "steelGuard.h"

using namespace std;


SteelGuard::SteelGuard ( string name, float defenceBonus, int durability, int durabilityLoss ) :
    Guard ( name, defenceBonus ), m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}

SteelGuard::SteelGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
    int durability, int durabilityLoss ) : Guard ( name, defenceBonus, eqSound, unEqSound ),
    m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}

SteelGuard::SteelGuard ( const SteelGuard& other ) : Guard ( other.m_name, other.m_defenceBonus )
{
    m_durability = other.m_durability;
    m_durabilityLoss = other.m_durabilityLoss;
}

unique_ptr <Guard> SteelGuard::clone () const { return make_unique <SteelGuard> ( *this ); }

float SteelGuard::getDefenceBonus ()
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

ostream& SteelGuard::print ( ostream& os ) const
{
    return os << "Steel guard, name: " << m_name << ", defence bonus: "
        << m_defenceBonus << ", durability: " << m_durability;
}