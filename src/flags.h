#include <exception>
#include <string>
#include <string.h>
#include <iostream>

class ArgumentException : public std::exception {
public:
    const char *what(){
        return "Invalid Argument: Maybe you didn't specify your argument after a flag";
    }
};

class Flags{
public:
    int edit_mode = 0;
    std::string default_saveLocation = "~/.doit";
    void parseArgs(int argc, char ** argv){
        for(int i=1; i<argc; i++){
            if(strcmp(argv[i], "-e") == 0){
                edit_mode = 1;
            }
            if(strcmp(argv[i], "-l") == 0){
                if (i+1 >= argc){
                    /* std::cout << "Not Cool\n"; */
                    throw ArgumentException();
                }
                else{
                    default_saveLocation = argv[i+1];
                }
            }
            // edit_mode = !(strcmp(argv[i], "-e"));
        }
    }
};
