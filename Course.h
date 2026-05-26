#include <cstring>
#include "Professor.h"
#include <iostream>


class Course {
    private:
        std::string ID;
        std::string description;
        unsigned int semester;
        Professor* ypefthinos;
    
    public:
        
    //Constructor
        Course(std:: string num, std:: string des, unsigned int s, Professor* yp);

    //Destructor
        ~Course();

    //Getters
        std::string getID();
        std::string getdescription();
        unsigned int getsemester();
        Professor* getypefthinos();

    //Setters
        void setID(std::string num);

        void setDescription(std::string des);
        
        void setSemester(unsigned int s);
        
        void setYpefthinos(Professor* yp);

        void print(std::ostream& os) const;
        

};