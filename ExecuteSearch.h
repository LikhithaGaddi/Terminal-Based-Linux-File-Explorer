#ifndef SEARCH
#define SEARCH

# include "header.h"

string destination;
bool result=false;

void searchHelper(string source){
    string file = getFileName(source);
    if(file == destination){
        result = true;
        return;
    }
    if(isDirectory(source.c_str())==1){
        DIR *di;
        struct dirent *dir;
        if ((di = opendir (source.c_str())) != NULL) 
        {
            while ((dir = readdir(di)) != NULL) 
            {	                 
                if( (string(dir->d_name) == "..") || (string(dir->d_name) == ".") )	
                {  		
                }
                else{
                    string from=source + "/" +string(dir->d_name);
                    const char* f = from.c_str();
                    struct stat st;
                    if (stat(f,&st)==0) {                 
                        if((S_ISDIR(st.st_mode)))
                        {
                            searchHelper(from);
                        }
                        else{
                            string file1 = getFileName(from);
                            if(file1 == destination){
                                // cout << file1 << endl;
                                result = true;
                                return;
                            }
                        }
                    }
                        
                }
            }
        }
    }
}

bool search(){
    int len = tokens.size();
    if(len >1){
        cout<< "can't search more than one file";
        return result;
    }
    string name_one = tokens[0];
    auto pos = name_one.rfind('/');
    if (pos != std::string::npos) {
        name_one.erase(pos);
    }
    destination = getFileName(tokens[0]);
    searchHelper(name_one);
    return result;
}

#endif