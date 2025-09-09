#include "Brain.hpp"

Brain::Brain(){
    std::cout<< "Brain constructed!"<<std::endl;
    for (int i = 0; i<100; i++ )
        ideas[i] = "Empty idea";
}

Brain::Brain(Brain &other){
    std::cout<< "Brain copy constructed!"<<std::endl;
    for (int i = 0; i<100; i++ )
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(Brain& other){
    std::cout<< "Brain asigned!"<<std::endl;
    if (this != &other)
    {
        for (int i = 0; i<100; i++ )
            ideas[i] = other.ideas[i];
    } 
    return(*this);
}

Brain::~Brain(){
    std::cout<< "Brain destructed!"<<std::endl;
}

const std::string& Brain::getIdea(int index) const{
    if(index >= 0 && index<100)
        return ideas[index];
    static std::string empty = "";
    return empty;
}

void Brain::setIdea(int index, const std::string& idea){
    if(index >= 0 && index<100)
        ideas[index] = idea;
}