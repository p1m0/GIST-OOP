#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <memory>

#include "tool.cpp"
#include "guard.cpp"
#include "player.cpp"
#include "saveHistory.cpp"

using namespace std;


int main()
{
    Player player ( "Archer" );
    SaveHistory saveHistory;

    shared_ptr <Observer> logger = make_shared <Logger> ();
    shared_ptr <Observer> soundManager = make_shared <SoundManager> ();
    
    player.addObserver ( logger );
    player.addObserver ( soundManager );
    
    // ================================================================

    player.gainExperience ( 50 );
    player.takeDamage ( 30 );

    saveHistory.save ( player.getState () );

    unique_ptr <Tool> sword = make_unique <Sword> ( "Big sword", 1.5, 
        "sounds/sword_eq.mp3", "sounds/sword_uneq.mp3" );
    player.equipTool ( std::move ( sword ) );
    
    unique_ptr <Guard> basicGuard = make_unique <WoodenGuard> ( "Basic guard", 1.5,
        "sounds/wooden_shield_eq.mp3", "sounds/wooden_shield_uneq.mp3" );
    player.equipGuard ( std::move ( basicGuard ) );
    
    saveHistory.save ( player.getState () );

    player.gainExperience ( 50 );
    player.takeDamage ( 30 );

    unique_ptr <Tool> bow = make_unique <Bow> ( "Basic Bow", 2, 0.5,
        "sounds/bow_eq.mp3", "sounds/bow_uneq.mp3" );

    basicGuard = player.unequipGuard ();

    unique_ptr <Guard> steelGuard = make_unique <SteelGuard> ( "Better guard", 2.0,
        "sounds/shield_eq.mp3", "sounds/shield_uneq.mp3" );
    player.equipGuard ( std::move ( steelGuard ) );

    sword = player.unequipTool ();
    player.equipTool ( std::move ( bow ) );
    
    try
    {
        saveHistory.load ( 2 );
    }
    catch ( const out_of_range& e )
    {
        cout << "Accessing non-existent save state: " << e.what() << endl;
    }

    player.set_state ( saveHistory.load ( 0 ) );

    player.set_state ( saveHistory.load ( 1 ) );
    
    return 0;
}