#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>
#include <string>

class Student;
class Professor;
class Course;

class Registry {

    private:
        std::vector<Student*> my_student;
        std::vector<Professor*> my_prof;
        std::vector<Course*> my_course;

    public:
       //Προσθήκες 
        void addStudent(Student* s);
        void addProfessor (Professor* p);
        void addCourse (Course* c);


       //Αναζήτηση
        Student* findStudent(const char* id);
        Professor* findProfessor(const char* id);
        Course* findCourse(std::string id);

       //Εισαγώγη μαθήματος σε κατάλογο φοιτητή
        void assignCoursetoStudent(const char* id, std::string code);
        void assignCoursetoProfessor(const char* id, std::string code);
       
        //Εκτύπωση Φοιτητών 
        void printStudents() const;
        void printProfessors() const;
        void printCourses() const;

       //Destructor
        ~Registry(); 
        

};


#endif