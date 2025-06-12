#include "player.h"

using namespace std;


Player::Player ( const string& playerName ) : m_name ( playerName ),
    m_health ( 100 ), m_experience ( 0 ), m_level ( 1 ),
    m_tool ( make_unique <NoTool> () ), m_guard ( make_unique <NoGuard> () ) {}

void Player::gainExperience ( int points )
{
    m_experience += points * m_tool->getAttackBonus ();
    m_level = 1 + m_experience / 100;
}

void Player::takeDamage ( int points )
{
    m_health -= points * m_guard->getDefenceBonus ();
    if ( m_health < 0 )
    m_health = 0;
}

unique_ptr <Tool> Player::unequipTool ()
{
    notifyObservers ( ToolChangeEvent { m_tool->getName (), "unequipped", m_tool->getUnEqSound () } );
    unique_ptr <Tool> temp = make_unique <NoTool> ();
    m_tool.swap ( temp );
    return temp;
}

void Player::equipTool ( unique_ptr <Tool> tool )
{
    m_tool = std::move ( tool );
    notifyObservers ( ToolChangeEvent { m_tool->getName (), "equipped", m_tool->getEqSound () } );
}

unique_ptr <Guard> Player::unequipGuard ()
{
    notifyObservers ( GuardChangeEvent { m_guard->getName (), "unequipped", m_guard->getUnEqSound () } );
    unique_ptr <Guard> temp = make_unique <NoGuard> ();
    m_guard.swap ( temp );
    return temp;
}

void Player::equipGuard ( unique_ptr <Guard> guard )
{
    m_guard = std::move ( guard );
    notifyObservers ( GuardChangeEvent { m_guard->getName (), "equipped", m_guard->getEqSound () } );
}

shared_ptr <PlayerState> Player::getState ()
{
    return make_shared <PlayerState> ( m_health, m_experience, m_level, m_tool, m_guard );
}

void Player::set_state ( shared_ptr <PlayerState> state )
{
    m_health = state->getHealth ();
    m_experience = state->getExperience ();
    m_level = state->getLevel ();
    m_tool = state->getTool ()->clone ();
    m_guard = state->getGuard ()->clone ();
    notifyObservers ( GameStateLoadedEvent { state } );
}

void Player::addObserver ( shared_ptr <Observer> observer ) { m_observers.push_back ( observer ); }
    
void Player::show_status () const
{
    cout << "========================" << endl;
    cout << "| Player: " << m_name << endl;
    cout << "| Health: " << m_health << endl;
    cout << "| Experience: " << m_experience << endl;
    cout << "| Level: " << m_level << endl;
    cout << "| Tool: " << *m_tool << endl;
    cout << "| Guard: " << *m_guard << endl;
    cout << "========================" << endl;
}

void Player::notifyObservers ( const GameEvent& event )
{
    for ( const auto& observer : m_observers )
        observer->update ( event );
}