#include "./headers/server.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

void handle_client(int client_id) {
    cout<<"Serwer obsługuje klienta o ID: "<<client_id<<endl;
    sleep(5);
    cout<<"Serwer zakończył obsługę klienta o ID: "<<client_id<<endl;
    exit(0);
}

void server_simulation(int num_clients){
    cout<<getpid()<<" Serwer rozpoczął działanie!\n";
    for(int i = 0; i < num_clients; i++) {
        pid_t pid = fork();
        if(pid == 0) {
            handle_client(i);
        }
    }
    for(int i = 0; i < num_clients; i++) {
        wait(NULL);
    }
}