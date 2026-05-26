#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Course; 

class Person {
protected: 
    char* code; 
    std::string onep;
    char gen;
    std::vector<Course*> my_courses;

public:
    Person(const char* num, std::string name);
    Person(const char* num, std::string name, char g);
    Person(const Person& other); 
    ~Person();

    char* getCode() const;
    std::string getOnep() const;
    char getGen() const;
    std::vector<Course*> getCourses() const;

    void setCode(const char* newCode);
    void setOnep(std::string name);
    void setGen(char g);

    void addCourse(Course* c);
    void remCourse(Course* c);
};

#endif