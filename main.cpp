#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>
#include "./headers/zombie.h"
#include "./headers/server.h"
#include "./headers/exec.h"
using namespace std;

int main() {
    while(true) {
        cout<<"Który program chcesz uruchomić?\n1. Symulacja serwera (fork, wait, drzewo procesów)\n2. Stworzenie procesu zombie\n3. Użycie funkcji exec()\n4. Zakończenie programu\n";
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1:
            server_simulation(5);
            break;
            case 2:
            create_zombie();
            break;
            case 3:
            create_exec();
            break;
            case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
