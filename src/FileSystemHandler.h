#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

class FileSystemHandler{
private:
    
public:
    std::vector<std::string> listFilesin(std::string directory)
    {
        std::vector<std::string> fileList;
        try
        {
            for(const auto &file: std::filesystem::directory_iterator(directory))
            {
                fileList.push_back(file.path());
            }
        } 
        catch (const std::filesystem::filesystem_error &e)
        {
            std::cerr << "Something went wrong when managing files and folders\n" << e.what() << std::endl;
        }
        return fileList;
    }
    void prepareDirectory(std::string directory)
    {
        std::filesystem::path p = directory;
        std::filesystem::directory_entry entry(p);
        try
        {
            if (!entry.exists()){
                std::filesystem::create_directory(std::filesystem::absolute(p));
            }
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
};
