#include <vector>


class Registry {

    private:
        std::vector<Student*> my_student;
        std::vector<Professor*> my_prof;
        std::vector<Course*> my_course;

    public:

        void addStudent(Student* s);
        void addProfessor (Professor* p);
        void addCourse (Course* c);

        

}