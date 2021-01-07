#ifndef PRINTFILES_H
#define PRINTFILES_H

#include "header.h"
#include "cursor.h"
#include "utility.h"
# include "ToCommandMode.h"

void display(vector<string> fileContents){
    // write(STDOUT_FILENO, "\x1b[2J", 4);
    // write(STDOUT_FILENO, "\x1b[H", 3);
    // printf("")
    printf("\033c");
    // cout << "resize" << res << " ";
	// printf("\033[H\033[J");
    // printf("\033[0;0H");
	// printf("%c[%d;%dH", 27, 1, 1);
    int size=fileContents.size();    
    int left,right;  
    left = upCount;
    right = min(size,max(top,bottom-15));  
    // if(size>top){
    //     // right = top;
    //     if(bottom-15 >= top)
    //         right = bottom-15;
    //     else
    //         right = top;
    // }
    for(int i=left;i<right;i++){
        struct stat sta;
        if(stat(fileContents[i].c_str(), &sta) == 0){
            mode_t perm = sta.st_mode;
            printf("%c",(perm & S_IRUSR) ? 'r' : '-');
            printf("%c",(perm & S_IWUSR) ? 'w' : '-');
            printf("%c",(perm & S_IXUSR) ? 'x' : '-');
            printf("%c",(perm & S_IRGRP) ? 'r' : '-');
            printf("%c",(perm & S_IWGRP) ? 'w' : '-');
            printf("%c",(perm & S_IXGRP) ? 'x' : '-');
            printf("%c",(perm & S_IROTH) ? 'r' : '-');
            printf("%c",(perm & S_IWOTH) ? 'w' : '-');
            printf("%c",(perm & S_IXOTH) ? 'x' : '-');
            struct passwd *pw = getpwuid(sta.st_uid);
            struct group  *gr = getgrgid(sta.st_gid);
            printf("   %s ",pw->pw_name);
            printf("%s ",gr->gr_name);

            long long size=sta.st_size;
            char unit='B';
            if(size>1024){
                size/=1024;
                unit='K';
            }
            if(size>1024){
                size/=1024;
                unit='M';
            }
            if(size>1024){
                size/=1024;
                unit='G';
            }
            printf("   %lld%c \t", size, unit);
            char *c=ctime(&sta.st_mtime);
            cout << "  ";
            for(int i=0;i<=15;i++)
                printf("%c",c[i]);
            printf("   ");
            const char* delim = "/";

            vector<string> out;
            string s = fileContents[i];
            tokenize(s, delim, out);
            if(S_ISDIR(sta.st_mode)){
                printf("\033[1;31m");
                printf("    %s",out[out.size()-1].c_str());
                printf("\033[0m");
            }
            else{
                printf("    %s",out[out.size()-1].c_str());
            }
        }
        cout<<endl;
    }
    modePlace = right+2-left;
    printf("\033[%d;%dH",modePlace,0);
    if(isNormalMode){
        cout << "-----------NORMAL MODE-----------";
    }
    else{
        cout << "----------COMMAND MODE------------";
    }
    printf("\033[0;0H");
    upCount=left;
    if(isNormalMode){
        cursor(fileContents);
    }
    else
    {
        toCommandMode();
    }
    
}

void printFiles(const char* root){
    // *curr_path = *root;
    vector<string> fileContents;
    DIR *dir;
    if ((dir = opendir (root)) != NULL) {
        // creating a reference to direct to get the filename
        struct dirent *ent;
        // reading the directory
        string path = root;
        while ((ent = readdir (dir)) != NULL) {
            string s=ent->d_name;
            fileContents.push_back(path+'/'+s);
        }
        sort(fileContents.begin(),fileContents.end());
        display(fileContents);
        // int size=fileContents.size();    
        // left = upCount;
        // right = size;  
        // if(size>top){
        //     right = top;
        // }
        // for(int i=left;i<right;i++){
        //     struct stat sta;
        //     if(stat(fileContents[i].c_str(), &sta) == 0){
        //         mode_t perm = sta.st_mode;
        //         printf("%c",(perm & S_IRUSR) ? 'r' : '-');
        //         printf("%c",(perm & S_IWUSR) ? 'w' : '-');
        //         printf("%c",(perm & S_IXUSR) ? 'x' : '-');
        //         printf("%c",(perm & S_IRGRP) ? 'r' : '-');
        //         printf("%c",(perm & S_IWGRP) ? 'w' : '-');
        //         printf("%c",(perm & S_IXGRP) ? 'x' : '-');
        //         printf("%c",(perm & S_IROTH) ? 'r' : '-');
        //         printf("%c",(perm & S_IWOTH) ? 'w' : '-');
        //         printf("%c",(perm & S_IXOTH) ? 'x' : '-');
        //         struct passwd *pw = getpwuid(sta.st_uid);
        //         struct group  *gr = getgrgid(sta.st_gid);
        //         printf("   %s ",pw->pw_name);
        //         printf("%s ",gr->gr_name);

        //         long long size=sta.st_size;
        //         char unit='B';
        //         if(size>1024){
        //             size/=1024;
        //             unit='K';
        //         }
        //         if(size>1024){
        //             size/=1024;
        //             unit='M';
        //         }
        //         if(size>1024){
        //             size/=1024;
        //             unit='G';
        //         }
        //         printf("   %lld%c \t", size, unit);
        //         char *c=ctime(&sta.st_mtime);
        //         cout << "  ";
        //         for(int i=0;i<=15;i++)
        //             printf("%c",c[i]);
        //         printf("   ");
        //         const char* delim = "/";

        //         vector<string> out;
        //         string s = fileContents[i];
        //         tokenize(s, delim, out);
        //         if(S_ISDIR(sta.st_mode)){
        //             printf("\033[1;31m");
        //             printf("    %s",out[out.size()-1].c_str());
        //             printf("\033[0m");
        //         }
        //         else{
        //             printf("    %s",out[out.size()-1].c_str());
        //         }
        //     }
        //     cout<<endl;
        // }
        // closing the directory
        closedir (dir);
    } 
    else {
        perror ("");
        cout << "Couldn't open the director";
    }
}






#endif