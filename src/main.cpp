#include <ostream>
#include <iostream>
#include <bits/stdc++.h>
#include "./flags.h"
#include "FileSystemHandler.h"


int main(int argc, char ** argv)
{
    Flags flags;
    FileSystemHandler fileSystemHandler;
    try
    {
        flags.parseArgs(argc, argv);
    } 
    catch (ArgumentException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    fileSystemHandler.prepareDirectory(flags.getDefaultLocation());
    std::cout<<"Edit mode: "<<flags.isinEditMode()<<std::endl<<"Save Location: "<<flags.getDefaultLocation()<<std::endl;
    //TODO: Configure program piping
    /* std::string programInput; */
    /* std::cin >> programInput; */
    /* std::cout << programInput << std::endl; */
    for(auto filePath: fileSystemHandler.listFilesin(flags.getDefaultLocation()))
    {
        std::cout << filePath << std::endl;
    }
    return 0;
}
