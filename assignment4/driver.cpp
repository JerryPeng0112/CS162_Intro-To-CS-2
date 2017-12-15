#include "Game.h"
#include <cstring>

void command_line_error();
bool valid_argv(char* []);
bool valid_num(char* second_par);


int main(int argc, char* argv[]){
    srand(time(NULL));
    int side;
    if(argc != 3){
        command_line_error();
        return 0;
    }
    if(!valid_argv(argv)){
        command_line_error();
        return 0;
    }
    side = atoi(argv[2]);
    Game hunt_the_wumpus(side);
    return 0;
}

void command_line_error(){
    std::cout << "Usage: a.out -s #" << std::endl
              << "#: min 4, max 12" << std::endl;
}

bool valid_argv(char* argv[]){
    if(strcmp(argv[1], "-s") != 0 || !valid_num(argv[2])){
        return false;
    }
    return true;
}

bool valid_num(char* second_par){
    int side;
    if(strlen(second_par) > 2){
        return false;
    }
    for(int i = 0; i < strlen(second_par); i++){
        if(second_par[i] < '0' || second_par[i] > '9'){
            return false;
        }
    }
    side = atoi(second_par);
    if(side > 12 || side < 4){
        return false;
    }
    return true;
}
