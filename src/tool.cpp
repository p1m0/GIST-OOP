#pragma once

#include <iostream>
#include <string>

using namespace std;


class Tool
{
public:
    Tool ( string name, float attackBonus ) : m_name ( name ), m_attackBonus ( attackBonus )
    {
        m_eqSound = "sounds/default_sound.mp3";
        m_unEqSound = "sounds/default_sound.mp3";
    }

    Tool ( string name, float attackBonus, string eqSound, string unEqSound ) :
        m_name ( name ), m_attackBonus ( attackBonus ), m_eqSound ( eqSound ), m_unEqSound ( unEqSound ) {}

    virtual ~Tool () = default;

    virtual unique_ptr <Tool> clone () const = 0;

    virtual float getAttackBonus () const = 0;
    virtual void setAttackBonus ( float attackBonus ) { m_attackBonus = attackBonus; };

    string getName () const { return m_name; }
    void setName ( string name ) { m_name = name; }

    string getEqSound () const { return m_eqSound; }
    string getUnEqSound () const { return m_unEqSound; }

    virtual ostream& print ( ostream& os ) const = 0;

    friend ostream& operator<< ( ostream& os, const Tool& t );

protected:
    string m_name;
    float m_attackBonus;
    string m_eqSound;
    string m_unEqSound;
};

ostream& operator<< ( ostream& os, const Tool& t )
{
    return t.print ( os );
}


class NoTool : public Tool
{
public:
    NoTool ( string name = "NoTool", float attackBonus = 1 ) :  Tool ( name, attackBonus ) {}
    
    virtual unique_ptr <Tool> clone () const override { return make_unique <NoTool> (); };

    float getAttackBonus () const override { return m_attackBonus; }

    ostream& print ( ostream& os ) const override
    {
        return os << "No tool, attack bonus: " << m_attackBonus;
    }
};


class Bow : public Tool
{
public:
    Bow ( string name, float attackBonus, float criticalHitProb ) :  Tool ( name, attackBonus ), 
        m_criticalHitProb ( criticalHitProb ), m_randomDist ( 0.0f, 1.0f ) {}
    
    Bow ( string name, float attackBonus, float criticalHitProb, string eqSound, string unEqSound ) :
        Tool ( name, attackBonus, eqSound, unEqSound ), m_criticalHitProb ( criticalHitProb ),
        m_randomDist ( 0.0f, 1.0f ) {}
    
    Bow ( const Bow& other ) : Tool ( other.m_name, other.m_attackBonus, other.m_eqSound, other.m_unEqSound ),
        m_criticalHitProb ( other.m_criticalHitProb ), m_randomDist ( 0.0f, 1.0f ) {}
    
    virtual unique_ptr <Tool> clone () const override { return make_unique <Bow> ( *this ); };

    float getAttackBonus () const override
    {
        float randomValue = m_randomDist ( m_randomEngine );
        if ( randomValue < m_criticalHitProb )
            return m_attackBonus * 2;
        return m_attackBonus;
    }

    ostream& print ( ostream& os ) const override
    {
        return os << "Tool type: Bow, name: " << m_name << ", attack bonus: " << m_attackBonus
            << ", critical hit probability: " << m_criticalHitProb;
    }

private:
    float m_criticalHitProb;
    mutable random_device m_randomDevice;
    mutable mt19937 m_randomEngine { m_randomDevice() };
    mutable uniform_real_distribution<float> m_randomDist;
};


class Sword : public Tool
{
public:
    Sword ( string name, float attackBonus ) : Tool ( name, attackBonus ) {}

    Sword ( string name, float attackBonus, string eqSound, string unEqSound ) :
        Tool ( name, attackBonus, eqSound, unEqSound ) {}

    Sword ( const Sword& other ) : Tool ( other.m_name, other.m_attackBonus, other.m_eqSound, other.m_unEqSound ) {}
    
    virtual unique_ptr <Tool> clone () const override { return make_unique <Sword> ( *this ); };

    float getAttackBonus () const override { return m_attackBonus; }

    ostream& print ( ostream& os ) const override
    {
        return os << "Tool type: Sword, name: " << m_name << ", attack bonus: " << m_attackBonus;
    }
};