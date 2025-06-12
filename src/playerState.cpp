#include "playerState.h"

using namespace std;


PlayerState::PlayerState ( int h, int e, int l ) : m_health ( h ), m_experience ( e ), m_level ( l ),
    m_tool ( make_unique <NoTool> () ), m_guard ( make_unique <NoGuard> () ) {}

PlayerState::PlayerState ( int health, int experience, int level,
    const unique_ptr <Tool>& tool, const unique_ptr <Guard>& guard ) : m_health ( health ),
    m_experience ( experience ), m_level ( level )
{
    m_tool = tool->clone ();
    m_guard = guard->clone ();
}

int PlayerState::getHealth () const { return m_health; }
void PlayerState::setHealth ( int health ) { m_health = health; }

int PlayerState::getExperience () const { return m_experience; }
void PlayerState::setExperience ( int experience ) { m_experience = experience; }

int PlayerState::getLevel () const { return m_level; }
void PlayerState::setLevel ( int level ) { m_level = level; }

const unique_ptr <Tool>& PlayerState::getTool () const { return m_tool; }
void PlayerState::setTool ( unique_ptr <Tool> tool ) { m_tool = std::move ( tool ); }

const unique_ptr <Guard>& PlayerState::getGuard () const { return m_guard; }
void PlayerState::setGuard ( unique_ptr <Guard> guard ) { m_guard = std::move ( guard ); }

void PlayerState::print () const
{
    cout << "+-----------------------" << endl;
    cout << "| Health: " << m_health << endl;
    cout << "| Experience: " << m_experience << endl;
    cout << "| Level: " << m_level << endl;
    cout << "| Tool: " << *m_tool << endl;
    cout << "| Guard: " << *m_guard << endl;
    cout << "+-----------------------" << endl;
}