#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<string>
#include<iostream>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain &other);
        Brain &operator=(Brain &other);
        ~Brain();

        //getter and setter
        const std::string &getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};





#endif