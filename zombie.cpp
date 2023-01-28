#include "./headers/zombie.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>
using namespace std;

void create_zombie() {
    pid_t pid = fork();
    if (pid == 0) {
        cout << "Proces potomny: " << getpid() << endl;
        exit(0);
    } else {
        cout << "Proces macierzysty: " << getpid() << endl;
        // brak wywołania wait() lub waitpid()
    }
    system("ps -A | grep -e 'Z'");
}