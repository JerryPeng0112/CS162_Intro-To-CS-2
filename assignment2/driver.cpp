#include "./Game.h"
int main(){
    srand(time(NULL));
    for(int i = 0; i < 100; i++) std::cout << std::endl;
    std::string response;
    std::cout << "-----------| Welcome to Blackjack ! |-----------" << std::endl;
    while(1){
        Game g;
        while(1){
            std::cout << "Do you want another round of blackjack? ('y' for yes, 'n' for no): ";
            getline(std::cin, response);
            if(!response.empty() && (response == "y" || response == "n")){
                break;
            }else{
                std::cout << std::endl << std::endl << "Please enter 'y' for yes and 'n' for no !" << std::endl;
            }
        }
        if(response == "y"){
            for(int i = 0; i < 100; i++) std::cout << std::endl;
            std::cout << "-----------| Welcome to Blackjack ! |-----------" << std::endl;
        }else if(response == "n"){
            std::cout << "Play again next time !" << std::endl;
            return 0;
        }
    }
    return 0;
}
