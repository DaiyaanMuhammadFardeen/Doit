#include <exception>
#include <filesystem>
#include <string>
#include <string.h>
#include <iostream>

class ArgumentException : public std::exception {
public:
    const char *what()
    {
        return "Invalid Argument: Bad command\n";
    }
};

class Flags{
private:
    int edit_mode = 0;
    std::string saveLocation = std::string(getenv("HOME"))+std::string("/.doit");
public:
    std::string getDefaultLocation()
    {
        return saveLocation;
    }
    int isinEditMode()
    {
        return edit_mode;
    }
    void parseArgs(int argc, char ** argv)
    {
        for(int i=1; i<argc; i++)
        {
            if(strcmp(argv[i], "-e") == 0)
            {
                edit_mode = 1;
            }
            if(strcmp(argv[i], "--setloc") == 0)
            {
                if (i+1 >= argc || !std::filesystem::directory_entry(argv[i+1]).exists())
                {
                    /* std::cout << "Not Cool\n"; */
                    throw ArgumentException();
                }
                else
            {
                    saveLocation = argv[i+1];
                }
            }
            if(strcmp(argv[i], "--loadloc") == 0)
            {
                if (i+1 >= argc || !std::filesystem::directory_entry(argv[i+1]).exists())
                {
                    /* std::cout << "Not Cool\n"; */
                    throw ArgumentException();
                }
                else
            {
                    saveLocation = argv[i+1];
                }
            }
            // edit_mode = !(strcmp(argv[i], "-e"));
        }
    }
};
