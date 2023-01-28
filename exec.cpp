#include <iostream>
#include <cstdlib>
#include <sys/wait.h>
#include "./headers/exec.h"
using namespace std;

void create_exec() {
    pid_t pid = fork();
    if(pid == 0) {
        for(int i = 0; i < 10; i++) {
            if(i == 8) {
                char* argument_list[] = {"ls", "-l", NULL};
                execvp("ls", argument_list);
            }
            cout<<"Processing...\n";
        }
    }
    else {
        wait(NULL);
    }
}