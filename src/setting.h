#ifndef _SETTING_H_
#define _SETTING_H_

#include <iostream>

namespace ai
{

class Setting
{
public:
    static Setting* get(){
        if( !_instance ) {
            _instance = new Setting;
        }
        return _instance;
    }

    static const int& missionaries () { return get()->_missionaries; }
    static const int& cannibals    () { return get()->_missionaries; }
    static const int& boatCapacity () { return get()->_missionaries; }

    static void missionaries (int miss) { get()->_missionaries = miss; }
    static void cannibals    (int cann) { get()->_cannibals    = cann; }
    static void boatCapacity (int bCap) { get()->_boatCapacity = bCap; }

    //static void tat( const std::string &tat ) { try{ get()->_tat = std::stoi(tat);} catch(std::exception& e) {get()->_tat = -2;} }

    static bool readArgs(int argc, char **argv)
    {   
        //All entries
        for( int i = 1; i < argc; ) {
            //Get an argument.
            std::string arg(argv[i++]);

            //Numer of missionaries
            if( arg == "-h") {
                Setting::setHelp();

            //Numer of cannibals
            } else if( arg == "-m" && i < argc ) {
                Setting::missionaries(std::atoi(argv[i++]));

            //Numer of cannibals
            } else if( arg == "-c" && i < argc ) {
                Setting::cannibals(std::atoi(argv[i++]));

            //Boat capacity
            } else if( arg == "-bc" && i < argc ) {
                Setting::boatCapacity(std::atoi(argv[i++]));

            } else {
                std::cerr<<"Unknown option: "<<arg<<std::endl;
                return false;
            }
        }
        return true;
    }


    //Parse the entries.
    static bool parseEntries(){
        bool valid;

        if( Setting::getHelp() ){
            std::cout<<"    Program Argumments  "<<std::endl
                     <<"-m  [INT] : number of missionaries"<<std::endl
                     <<"-c  [INT] : number of cannibals"<<std::endl
                     <<"-bc [INT] : capacity of the boat"<<std::endl
                     <<"-h        : show this text"<<std::endl;
            return false;
        }

        //Check arguments values
        if( get()->_missionaries < 1 ){
            std::cout<<"Must to have at least 1 missionary."<<std::endl; valid = false;
        }

        if( get()->_cannibals < 1 ){
            std::cout<<"Must to have at least 1 cannibal."<<std::endl; valid = false;
        }

        if( get()->_boatCapacity < 2 ){
            std::cout<<"The boat capacity must to be at least 2."<<std::endl; valid = false;
        }

        //Must not have more cannibals than missionaries.
        if( get()->_cannibals > get()->_missionaries ){
             std::cout<<"The number of missionaries must to be equal or greater the number of cannibals."<<std::endl; valid = false;
        }

        return valid;
    }

private:
    static Setting *_instance;
    Setting() {
    }
    ~Setting(){}

    static void setHelp    () { get()->_help = true; }
    static bool getHelp    () { return get()->_help; }

    int  _missionaries = -1;
    int  _cannibals    = -1;
    int  _boatCapacity = -1;
    bool _help         =  false;
};

Setting *Setting::_instance = 0;

}

#endif

