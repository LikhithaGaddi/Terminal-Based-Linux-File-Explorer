#ifndef CREATE
#define CREATE

# include "header.h"
# include "ProcessCommand.h"

void createFile(){
    string filename = getFileName(tokens[0]);
    string path = tokens[1] +"/"+ filename;
    // cout << path;
    int status=open(path.c_str(),O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);; 	
    if (status == -1)
    {
        printf("error creating file");	       
    }    
}

void createDirectory(){
    string filename = getFileName(tokens[0]);
    string path = tokens[1] +"/"+ filename;
    int s = mkdir(path.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if(s==-1){
        printf("error creating directory");
    }
}

#endif