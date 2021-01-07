#ifndef PROCESSCOMMAND
#define PROCESSCOMMAND

# include "header.h"
# include "ToCommandMode.h"
# include "ExecuteCopy.h"
#include "ExecuteMove.h"
#include "ExecuteDelete.h"
#include "ExecuteCreate.h"
# include "ExecuteRename.h"
#include "ExecuteGoTo.h"
#include "ExecuteSearch.h"


string processTokens(string command){
    if(command == ""){
        return "";
    }
    vector<string> out;
    const char* delim = " ";
    string s = command;
    tokenize(s, delim, out);
    // cout << out.size()<<" ";
    // tokens.clear();
    for(int i=1;i<out.size();i++){
        if(out[i][0] == '~'){            
            string temp = string(root)+out[i].replace(0,1,"");
            tokens.push_back(temp);
        }
        else if(out[i][0] == '.' || out[i][0] == '/'){
            string temp = string(curr_root)+out[i].replace(0,1,"");
            tokens.push_back(temp);
        }
        else{
            // cout << "curr_root: " << curr_root << " ";
            string temp = string(curr_root)+"/"+out[i].replace(0,0,"");
            tokens.push_back(temp);
        }
    }
    return out[0];
}

void processCommand(string command){
    tokens.clear();
    string cmd = processTokens(command);
    if(cmd=="copy"){
        // cout << "copying" << " ";
        executeCopy();
    }
    else if(cmd=="move"){
        executeMove();
    }
    else if(cmd=="rename"){
        executeRename();
    }
    else if(cmd=="create_file"){
        createFile();
    }
    else if(cmd=="create_dir"){
        createDirectory();
    }
    else if(cmd=="delete_file"){
        executeDelete();
    }
    else if(cmd=="delete_dir"){
        executeDelete();
    }
    else if(cmd=="goto"){
        gotoFolder();
    }
    else if(cmd=="search"){
        if(search()==true){
            cout << "True";
        }
        else{
            cout << "False";
        }
    }
    // tokens.clear();
}

void processEnter(){
    printf("%c[2K", 27);
    printf("\033[%d;%dH",bottom,0);
    printf(":");
    // printf(":tokens are => ");
    // cout << command;
    // tokens.clear();
    processCommand(command);
    // tokens.clear();
    // printf("%c[2K", 27);
    toCommandMode();
}


#endif