#include "Harl.hpp"

void Harl::debug(void) {
    std::cout <<  "DEBUG: I love having extra bacon for my ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout <<  "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void){
    std::cout <<  "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::complain(std::string level){

    void (Harl::*functions[])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            index = i;
        }
    }
    switch (index) {
        case 0:
            (this->*functions[0])();
             // fall through
        case 1:
            (this->*functions[1])();
             // fall through
        case 2:
            (this->*functions[2])();
             // fall through
        case 3:
            (this->*functions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
}