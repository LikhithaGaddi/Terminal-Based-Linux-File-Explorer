#ifndef OPENFILE_H
#define OPENFILE_H

#include "header.h"

void openFile(const char *file){
    // if (fork() == 0) {
	// 	// execl("/usr/bin/xdg-open", "xdg-open", file, (char *)0);	
	// 	execv(file,"vi");							
	// 	exit(1);
	// }
	// int fileOpen=open("/dev/null",O_WRONLY);
	// dup2(fileOpen,2);
	// close(fileOpen);
	// pid_t processID = fork();
	// if(processID == 0)
	// {
	// 	// execlp("xdg-open","xdg-open",file,NULL);
	// 	execlp("vi","vi",file,NULL);
	// 	exit(0);
	// } 
	// wait(processID);
	pid_t pid = fork();
	if (pid == 0) {
		// close(2);
		execlp("vi", "vi", file, NULL);
		exit(0);
	}
	int status;
	waitpid(pid, &status, 0);
	while(!WIFEXITED(status))
		continue;
}

#endif