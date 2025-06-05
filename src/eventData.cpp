#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <any>

using namespace std;

class EventData
{
public:
    template<typename T>
    void set ( const string& key, const T& value ) { data [ key ] = value; }
    
    template<typename T>
    T get ( const string& key ) const
    {
        auto it = data.find ( key );
        if ( it != data.end () )
            return any_cast <T> ( it->second );
        throw runtime_error ( "Key not found: " + key );
    }
    
    bool has ( const string& key ) const { return data.find ( key ) != data.end ();
    }
    
    string getEventType () const { return get <string> ( "eventType" ); }

private:
    unordered_map <string, any> data;
};