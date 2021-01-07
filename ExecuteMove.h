#ifndef MOVE
#define MOVE

# include "header.h"
# include "ProcessCommand.h"
# include "ExecuteCopy.h"
#include "ExecuteDelete.h"

void executeMove(){
    unsigned int len = tokens.size();
	if(len < 2)
	{
		printf("less number of Argument");
        return;
	}
    if(isDirectory(tokens[len-1].c_str())==1){
        for(int i=0;i<len-1;i++)
        {
            string filename = getFileName(tokens[i]);
            string destdir= tokens[len-1];
            destdir =destdir + "/" + filename;
            filename = tokens[i];
            if(isDirectory(filename.c_str()))
            {
                copyDirectory(filename,destdir);
                deleteDirectory(filename);
                const char *file = filename.c_str();
                if(remove(file)!=0){
                    // cout << "Can't remove the file";
                }
            }
            else
            {
                copyFile(filename,destdir);
                deleteFile(filename);
            }
        }
    }
    else{
        printf("directory doesn't exists");
        return;
    }
}


#endif