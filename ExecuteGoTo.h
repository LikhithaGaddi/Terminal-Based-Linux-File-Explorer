#ifndef GOTO
#define GOTO

# include "header.h"
#include "printFiles.h"

void gotoFolder(){
    int len = tokens.size();
    if(len>1){
        cout << "more aruguments";
        return;
    }
    string path = tokens[0];
    backStack.push(curr_root);
    curr_root = path.c_str();
    if(!forwardStack.empty()){
        while(!forwardStack.empty())
            forwardStack.pop();
    }
    printFiles(curr_root);
}

#endif