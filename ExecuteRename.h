#ifndef RENAME
#define RENAME

#include"header.h"

void executeRename(){
    string name_one = tokens[0];
    string name_two = tokens[1];
    string filename = getFileName(name_two);
    auto pos = name_one.rfind('/');
    if (pos != std::string::npos) {
        name_one.erase(pos);
    }
    string dest =  name_one+"/"+filename ;
    int val = rename(tokens[0].c_str(),dest.c_str());
    if(val!=0){
        cout << "error renaming";
    }
}

#endif