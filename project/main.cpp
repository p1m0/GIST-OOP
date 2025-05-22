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
    
    player.gainExperience ( 50 );
    player.takeDamage ( 30 );

    player.show_status ();
    
    saveHistory.save ( player.get_state () );
    cout << "Saved state above" << endl;

    unique_ptr <Tool> sword = make_unique <Sword> ( "Big sword", 1.5 );
    player.equipTool ( std::move ( sword ) );
    
    unique_ptr <Guard> basicGuard = make_unique <WoodenGuard> ( "Basic guard", 1.5 );
    player.equipGuard ( std::move ( basicGuard ) );
    
    player.show_status ();

    saveHistory.save ( player.get_state () );
    cout << "Saved state above" << endl;

    player.gainExperience ( 50 );
    player.takeDamage ( 30 );

    player.show_status ();

    unique_ptr <Tool> bow = make_unique <Bow> ( "Basic Bow", 2, 0.5 );

    sword = player.unequipTool ();
    player.equipTool ( std::move ( bow ) );
    
    player.show_status ();

    try
    {
        saveHistory.load ( 2 );
    }
    catch ( const out_of_range& e )
    {
        cout << "Accessing non-existent save state: " << e.what() << endl;
    }


    player.set_state ( saveHistory.load ( 0 ) );
    
    player.show_status ();
    cout << "Loaded save 0 above" << endl;

    player.set_state ( saveHistory.load ( 1 ) );
    
    player.show_status ();
    cout << "Loaded save 1 above" << endl;
    
    return 0;
}