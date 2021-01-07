#ifndef ToCommandMode
#define ToCommandMode

#include"header.h"
#include "nonCanonicalMode.h"
# include "ProcessCommand.h"

vector<string> args;

void removeLine(){
    printf("%c[%d;%dH",27,bottom,1);
    printf(":");
}

void toCommandMode(){
    printf("\033[%d;%dH",bottom,0);
    printf(":");
    char c;
    toNonCanonicalMode();
    c=cin.get();
    backToCanonical();
    while(int(c)!=27 && int(c)!=10){
        if(int(c)==127){
            if(!command.empty())
            {
                command.pop_back();
                printf("%c[2K", 27);
                printf("\033[%d;%dH",bottom,0);
                printf(":");
                // printf("%s",command);
                cout << command;
            }            
        }
        else{
            printf("%c",c);
            command.push_back(c);
        }
        toNonCanonicalMode();
        c=cin.get();
        backToCanonical();
    }
    if(int(c)==10){
        processEnter();  
        // tokens.clear();
        command = "";      
        // toCommandMode();
        // processCommand(command);
    }
    else if(int(c)==27){        
        upCount = 0;
        printf("\033[%d;%dH",0,0);
        isNormalMode = true;
        // tokens.clear();
        command = "";
        printFiles(curr_root);
    }
}

#endif
