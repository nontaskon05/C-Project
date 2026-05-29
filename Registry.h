#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>
#include <string>

class Person;   
class Student;
class Professor;
class Course;

class Registry {

    private:
        std::vector<Person*> my_members;
        std::vector<Course*> my_course;

    public:
       //Προσθήκες 
        void addMember(Person* p);
        void addCourse (Course* c);


       //Αναζήτηση
        Person* findMember(const char* id);
        Course* findCourse(std::string id);
       
       // Διόρθωση Δεδομένων
        void updateMemberName(const char* id, std::string newName);
        void updateMemberGender(const char* id, char newGender);
        void updateStudentSemester(const char* id, unsigned int newSem);
        void updateProfSpeciality(const char* id, std::string newSpec);

        // Διαγραφή
        void removeMember(const char* id);

        // Εισαγωγή μαθήματος σε κατάλογο
        void assignCourse(const char* id, std::string code);
       
        // Εκτύπωση 
        void printMembers() const;
        void printCourses() const;

        // Αποστολή Emails
        void sendEmailToStudents(std::string message) const;
        void sendEmailToProfessors(std::string message) const;


        // Αποθήκευση και ανάκτηση πληροφοριών σε .csv
        void saveData(std::string filename) const;
        void loadData(std::string filename);

        // Destructor
        ~Registry();
        

};


#endif