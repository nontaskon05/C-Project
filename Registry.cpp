#include "Registry.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include <iostream>
#include <cstring>

using namespace std;

//Destructor
    Registry::~Registry() {
        for(Student* s : my_student) {
            delete s;
        }
        for(Professor* p : my_prof) {
            delete p;
        }
        for(Course* c : my_course) {
            delete c;
        }
    }

//Προσθήκες
    void Registry::addStudent(Student* s) {
        my_student.push_back(s);
    }

    void Registry::addProfessor(Professor* p) {
        my_prof.push_back(p);
    }

    void Registry::addCourse(Course* c) {
        my_course.push_back(c);
    }


//Αναζητήσεις
    Student* Registry::findStudent(const char* id) {
        for(Student* s : my_student) {
            if (strcmp(s->getCode(), id) == 0) {
                return s;
            }
        }
        return nullptr;
    }

        Professor* Registry::findProfessor(const char* id) {
        for(Professor* p : my_prof) {
            if (strcmp(p->getCode(), id) == 0) {
                return p;
            }
        }
        return nullptr;
    }

    Course* Registry::findCourse(string id) {
        for(Course* c : my_course){
            if(c->getID() == id){
                return c;
            }
        }
        return nullptr;
    }

//Assign course to Student / Professor
    void Registry::assignCoursetoStudent(const char* id, string code) {
        Student* target_s = findStudent(id);
        Course* target_c = findCourse(code);
        if (target_s != nullptr && target_c != nullptr)
            target_s->addCourse(target_c);
    }

    void Registry::assignCoursetoProfessor(const char* id, string code) {
        Professor* target_p = findProfessor(id);
        Course* target_c = findCourse(code);
        if (target_p != nullptr && target_c != nullptr) {
            target_p->addCourse(target_c);
        }
    }