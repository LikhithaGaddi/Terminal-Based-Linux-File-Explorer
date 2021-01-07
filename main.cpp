#include "header.h"
#include "printFiles.h"


void handleResize(int sigwinchID)
{
    if (sigwinchID == 28)
    {
        // terminalRows = getTerminalSize();
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal);
        top = terminal.ws_row - 15;
        bottom = terminal.ws_row;
        printFiles(curr_root);
        // doNotInsertInStack = 1;
        // listFiles(0, filePaths.size());
    }
}

int main (int argc, char **argv)
{      
    DIR *dir;
    char buff[FILENAME_MAX]; 
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal);
    top = terminal.ws_row - 15;
    bottom = terminal.ws_row;
    // bottom = terminal.ws_col;
    vector<string> contents;
    root = getcwd( buff, FILENAME_MAX );
    curr_root = root;
    printFiles(root);    
    signal(28, handleResize);
    exit(0);
}