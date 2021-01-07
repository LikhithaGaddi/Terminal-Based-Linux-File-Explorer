#ifndef UTILITY
#define UTILITY

# include "header.h"

void tokenize(string const &str, const char* delim,vector<string> &out)
{
	char *token = strtok(const_cast<char*>(str.c_str()), delim);
	while (token != nullptr)
	{
		out.push_back(std::string(token));
		token = strtok(nullptr, delim);
	}
}

int isDirectory(const char* file){
	struct stat sb;
	if (stat(file,&sb) == -1) {
        // perror("lstat");
		// cout << "No such directory exists";
		return -1;
    }
    else
    {
    	if((S_ISDIR(sb.st_mode)))
	    {
	    	return 1;
	    }
	    else
	    {
	    	return 0;
	    }
    }

    return -1;
}

string getFileName(string s){
	vector<string> out;
    const char* delim = "/";
    tokenize(s, delim, out);
	return out[out.size()-1];
}

#endif
