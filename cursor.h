#ifndef CURSOR_H
#define CURSOR_H

#include "header.h"
#include "printFiles.h"
#include "openFile.h"
#include "nonCanonicalMode.h"
#include "ToCommandMode.h"

void cursor(vector<string> contents){
    while (1) {
        char c;
        toNonCanonicalMode();
        c=cin.get();
        backToCanonical();
        if(int(c)==27){
            char a,b;
            toNonCanonicalMode();
            a=cin.get();
            b=cin.get();
            backToCanonical();
            if(int(b) == 65){
                if(upCount>0){
                    upCount--;
                    printf("\033[1A");
                }
            }
            if(int(b) == 66){
                // if(upCount<top && upCount<contents.size()){
                if(upCount<bottom-15 && upCount<contents.size()-1){
                    upCount++;
                    printf("\033[1B");
                }
            }     
            if(int(b) == 67){
                if(!forwardStack.empty()){
                    string dir = forwardStack.top();
                    backStack.push(contents[0]);
                    forwardStack.pop();
                    curr_root = dir.c_str();
                    printFiles(dir.c_str());
                }
            }
            if(int(b) == 68){
                if(!backStack.empty()){
                    string dir = backStack.top();
                    forwardStack.push(contents[0]);
                    backStack.pop();
                    curr_root = dir.c_str();
                    printFiles(dir.c_str());
                }
            }
            continue;
        }
        if(int(c)==58){
            isNormalMode = false;
            printf("\033[%d;%dH",modePlace,0);
            if(isNormalMode){
                cout << "-----------NORMAL MODE-----------";
            }
            else{
                cout << "----------COMMAND MODE------------";
            }
            toCommandMode();
        }
        if(int(c)==127){
            printFiles(contents[1].c_str());
        }
        if(c == 'k'){ //k
            if(upCount>0){
                upCount--;
                top--;
                display(contents);
            }
        }
        if(c == 'l'){ //l
            if(contents.size()>top){
                upCount++;
                top++;
                display(contents);
            }
        }
        if(int(c)==10){
            struct stat sta;
            if(upCount<top && stat(contents[upCount].c_str(), &sta) == 0){
                if(S_ISDIR(sta.st_mode)){
                    backStack.push(contents[0]);
                    if(!forwardStack.empty()){
                        while(!forwardStack.empty())
                            forwardStack.pop();
                    }
                    string s = contents[upCount];
                    upCount = 0;
                    curr_root = s.c_str();
                    printFiles(s.c_str());
                }
                else{
                    openFile(contents[upCount].c_str());
                }
            }
            else{
                // cout <<"status" << stat(contents[upCount].c_str(), &sta) ;
            }            
        }
        if(int(c)==104){
            printFiles(root);
        }
        if (c == 'q') break;               
    }
}

#endif