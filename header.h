#ifndef HEADER_H
#define HEADER_H


#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
using namespace std;
// #include "utility.h"
// # include "ExecuteCopy.h"

const char* root;
const char* curr_root;
struct termios original, newval;
stack<string> backStack;
stack<string> forwardStack;
struct winsize terminal;
int upCount;
int top,bottom;
static int res = 1;
int modePlace;
vector<string> tokens;
string command;
bool isNormalMode = true;

void printFiles(const char* root);
void openFile(const char *file);
void cursor(vector<string> contents);
void processCommand(string command);
int isDirectory(const char *file);
void display(vector<string> fileContents);
void toCommandMode();
void processCommand();
void tokenize(string const &str, const char* delim,vector<string> &out);
string getFileName(string s);
void executeCopy();


#endif