#pragma once

#include <iostream>
#include <string>

using namespace std;


class Guard
{
public:
    Guard ( string name, float defenceBonus ) : m_name ( name ), m_defenceBonus ( defenceBonus )
    {
        m_eqSound = "sounds/default_sound.mp3";
        m_unEqSound = "sounds/default_sound.mp3";
    }

    Guard ( string name, float defenceBonus, string eqSound, string unEqSound ) :
        m_name ( name ), m_defenceBonus ( defenceBonus ), m_eqSound ( eqSound ), m_unEqSound ( unEqSound ) {}
    
    virtual ~Guard () = default;

    virtual unique_ptr <Guard> clone () const = 0;

    virtual float getDefenceBonus () = 0;
    virtual void setDefenceBonus ( float defenceBonus ) { m_defenceBonus = defenceBonus; };

    string getName () const { return m_name; }
    void setName ( string name ) { m_name = name; }

    string getEqSound () const { return m_eqSound; }
    string getUnEqSound () const { return m_unEqSound; }

    virtual ostream& print ( ostream& os ) const = 0;

    friend ostream& operator<< ( ostream& os, const Guard& t );

protected:
    string m_name;
    float m_defenceBonus;
    string m_eqSound;
    string m_unEqSound;
};

ostream& operator<< ( ostream& os, const Guard& g )
{
    return g.print ( os );
}

class NoGuard : public Guard
{
public:
    NoGuard ( string name = "NoGuard", float defenceBonus = 1 ) :  Guard ( name, defenceBonus ) {}

    virtual unique_ptr <Guard> clone () const override { return make_unique <NoGuard> (); };

    float getDefenceBonus () override { return m_defenceBonus; }

    ostream& print ( ostream& os ) const override
    {
        return os << "No guard, attack bonus: " << m_defenceBonus;
    }
};

class WoodenGuard : public Guard
{
public:
    WoodenGuard ( string name, float defenceBonus, int durability = 100, int durabilityLoss = 10 ) :
        Guard ( name, defenceBonus ), m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}
    
    WoodenGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
        int durability = 100, int durabilityLoss = 10 ) :
        Guard ( name, defenceBonus, eqSound, unEqSound ),
        m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}
    
    WoodenGuard ( const WoodenGuard& other ) :
        Guard ( other.m_name, other.m_defenceBonus, other.m_eqSound, other.m_unEqSound )
    {
        m_durability = other.m_durability;
        m_durabilityLoss = other.m_durabilityLoss;
    }

    virtual unique_ptr <Guard> clone () const override { return make_unique <WoodenGuard> ( *this ); };

    float getDefenceBonus () override
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

    ostream& print ( ostream& os ) const override
    {
        return os << "Wooden guard, name: " << m_name << ", defence bonus: "
            << m_defenceBonus << ", durability: " << m_durability;
    }

private:
    int m_durability;
    int m_durabilityLoss;
};

class SteelGuard : public Guard
{
public:
    SteelGuard ( string name, float defenceBonus, int durability = 200, int durabilityLoss = 5 ) :
        Guard ( name, defenceBonus ), m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}
    
    SteelGuard ( string name, float defenceBonus, string eqSound, string unEqSound,
        int durability = 200, int durabilityLoss = 5 ) :
        Guard ( name, defenceBonus, eqSound, unEqSound ),
        m_durability ( durability ), m_durabilityLoss ( durabilityLoss ) {}

    SteelGuard ( const SteelGuard& other ) : Guard ( other.m_name, other.m_defenceBonus )
    {
        m_durability = other.m_durability;
        m_durabilityLoss = other.m_durabilityLoss;
    }

    virtual unique_ptr <Guard> clone () const override { return make_unique <SteelGuard> ( *this ); };

    float getDefenceBonus () override
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

    ostream& print ( ostream& os ) const override
    {
        return os << "Steel guard, name: " << m_name << ", defence bonus: "
            << m_defenceBonus << ", durability: " << m_durability;
    }

private:
    int m_durability;
    int m_durabilityLoss;
};