#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <string>

class Professor : public Person {
private:    
    std::string speciality;
        
public:
    Professor(const char* num, std::string name);
    Professor(const char* num, std::string name, char g, std::string s);
    ~Professor();

    std::string getSpeciality() const;
    void setSpeciality(std::string s);
};

#endif