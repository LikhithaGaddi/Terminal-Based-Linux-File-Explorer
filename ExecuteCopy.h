#ifndef COPY
#define COPY

# include "header.h"
# include "ProcessCommand.h"

void copyFile(string filename, string destdir){
    const char *source = filename.c_str();
    const char *destination = destdir.c_str();
    char content[8000];
    int from,to,fread;
    from = open(source, O_RDONLY);
    to = open(destination,O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while((fread = read(from , content, sizeof(content)))>0){
        write(to,content,fread);
    }
    struct stat fromstat, tostat;
    if(stat(source,&fromstat)!=-1 && stat(destination,&tostat)!=-1){
        int ownStatus = chown(destination,fromstat.st_uid,fromstat.st_gid);
        int modeStatus = chmod(destination, fromstat.st_mode);
        if(ownStatus!=0){
            cout << "Error setting file ownership";
        }
        if(modeStatus!=0){
            cout << "Error setting file permisson";
        }
    }
}

void copyDirectory(string filename, string destdir){
    const char *source = filename.c_str();
    const char *destination = destdir.c_str();
    int s = mkdir(destination,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if(s==0){
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
                    string to=destdir + "/" +string(dir->d_name);
                    const char* f = from.c_str();
                    struct stat st;
                    if (stat(f,&st)==0) {                 
                        if((S_ISDIR(st.st_mode)))
                        {
                            copyDirectory(from,to);
                        }
                        else
                        {
                            copyFile(from,to);
                        }
                    }
                        
                }
            }
        }
        else{
            cout << "Directory not found";
        }
    }
    else{
        cout << "Can't make the directory ";
    }
    return;
}

void executeCopy(){
    unsigned int len = tokens.size();
	if(len < 2)
	{
		printf("Less number of Argument");
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
            }
            else
            {
                copyFile(filename,destdir);
            }
        }
    }
    else{
        printf("Destination directory doesn't exists");
        return;
    }
}

#endif