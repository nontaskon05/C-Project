#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h" 
#include <iostream>

class Student : public Person { 
private:
    unsigned int semester; 

public:
    // Constructors
    Student(const char* num, std::string name);
    Student(const char* num, std::string name, char g, unsigned int s);

    // Destructor
    ~Student();
    
    // Getters & Setters
    unsigned int getSemester() const;
    void setSemester(unsigned int s);

    void print(std::ostream& os) const;

    // Operators
    Student& operator++();
    Student& operator--();
    Student& operator+=(unsigned int val);
    Student& operator-();
};

#endif