#include "setting.h"

using namespace ai;

int main(int argc, char **argv)
{   
    //Read entries
    if( !Setting::readArgs(argc, argv) )
        return 1;
    
    //Check entries
    if( !Setting::parseEntries() )
        return 1;

    return 0;
}


