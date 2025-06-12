#include "bow.h"

using namespace std;


Bow::Bow ( string name, float attackBonus, float criticalHitProb ) : Tool ( name, attackBonus ), 
    m_criticalHitProb ( criticalHitProb ), m_randomDist ( 0.0f, 1.0f ) {}

Bow::Bow ( string name, float attackBonus, float criticalHitProb, string eqSound, string unEqSound ) :
    Tool ( name, attackBonus, eqSound, unEqSound ), m_criticalHitProb ( criticalHitProb ),
    m_randomDist ( 0.0f, 1.0f ) {}

Bow::Bow ( const Bow& other ) : Tool ( other.m_name, other.m_attackBonus, other.m_eqSound, other.m_unEqSound ),
    m_criticalHitProb ( other.m_criticalHitProb ), m_randomDist ( 0.0f, 1.0f ) {}

unique_ptr <Tool> Bow::clone () const { return make_unique <Bow> ( *this ); };

float Bow::getAttackBonus () const
{
    float randomValue = m_randomDist ( m_randomEngine );
    if ( randomValue < m_criticalHitProb )
        return m_attackBonus * 2;
    return m_attackBonus;
}

ostream& Bow::print ( ostream& os ) const
{
    return os << "Tool type: Bow, name: " << m_name << ", attack bonus: " << m_attackBonus
        << ", critical hit probability: " << m_criticalHitProb;
}
