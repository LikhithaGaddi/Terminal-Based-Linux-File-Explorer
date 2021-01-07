#ifndef NONCANONICALMODE_H
#define NONCANONICALMODE_H

#include"header.h"

//prints and error message and exits
void die(const char *s) {
  perror(s);
  exit(1);
}

void toNonCanonicalMode(){
    tcgetattr(0, &original);
	newval = original;
	newval.c_lflag &= ~ (ICANON | ECHO);
    if(tcsetattr(fileno(stdin), TCSAFLUSH, &newval)!=0) {
        cout<<"Could not set attributes for termios"<<endl;
    }
}

void backToCanonical(){
    tcsetattr(fileno(stdin), TCSANOW, &original);
}

#endif