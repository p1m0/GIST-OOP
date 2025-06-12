#include "eventData.h"

using namespace std;
    
bool EventData::has ( const string& key ) const { return data.find ( key ) != data.end (); }
    
string EventData::getEventType () const { return get <string> ( "eventType" ); }