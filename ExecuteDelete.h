#ifndef DELETE
#define DELETE

# include "header.h"
# include "ProcessCommand.h"



void deleteFile(string filename){
    const char *file = filename.c_str();
    if(remove(file)!=0){
        cout << "Can't remove the file";
    }
}


void deleteDirectory(string filename){
    const char *source = filename.c_str();
    DIR *di;
    struct dirent *dir;
    if ((di = opendir (source)) != NULL) 
    {
        while ((dir = readdir(di)) != NULL) 
        {	                 
            if( (string(dir->d_name) == "..") || (string(dir->d_name) == ".") )	
            {  		
            }
            else{
                string from=filename + "/" +string(dir->d_name);
                const char* f = from.c_str();
                struct stat st;
                if (stat(f,&st)==0) {                 
                    if((S_ISDIR(st.st_mode)))
                    {
                        // cout << from << endl;
                        deleteDirectory(from);
                        const char *file = from.c_str();
                        if(remove(file)!=0){
                            // cout << "Can't remove the file";
                        }
                    }
                    else
                    {
                        // cout << from << endl;
                        deleteFile(from);
                    }
                }
                    
            }
        }
        closedir(di);
    }
    else{
        cout << "Directory not found";
    }
    return;
}

void executeDelete(){
    unsigned int len = tokens.size();
	if(len < 1)
	{
		printf("Less number of Argument");
        return;
	}
    for(int i=0;i<len;i++)
    {
        if(isDirectory(tokens[i].c_str()))
        {
            deleteDirectory(tokens[i]);
            const char *file = tokens[i].c_str();
            if(remove(file)!=0){
                // cout << "Can't remove the file";
            }
        }
        else
        {
            deleteFile(tokens[i]);
        }
        // cout << tokens[i] << endl;
    }
}


#endif