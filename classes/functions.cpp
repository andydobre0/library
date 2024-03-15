#include"../header_files/functions.h"

#ifdef _WIN32
    #include <windows.h>
#endif

void clearConsole(){
    #ifdef _WIN32
        system("cls");
    #elif
        system("clear");
    #endif
}

std::string& ltrim(std::string& str){
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return str;
}

std::string& rtrim(std::string& str){
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
    return str;
}

std::string& trim(std::string& str){
    return ltrim(rtrim(str));
}


std::string toLower(const std::string& str){
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) {return std::tolower(c);});
    return trim(lowerStr);
}
