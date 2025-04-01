#include <ostream>
#include <iostream>
#include <bits/stdc++.h>
#include "./flags.h"


int main(int argc, char ** argv){
    Flags flags;
    try{
        flags.parseArgs(argc, argv);
    } catch (ArgumentException &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout<<"Edit mode: "<<flags.edit_mode<<std::endl<<"Save Location: "<<flags.default_saveLocation<<std::endl;
    return 0;
}
