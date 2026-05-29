#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

//Constructors
    Course::Course(string num, std:: string des, unsigned int s, Professor* yp){
        ID = num;
        description = des;
        semester = s;
        ypefthinos = yp;
    }
//Destructor
    Course::~Course(){}


//Getters
    string Course::getID() {return ID;}
    string Course::getdescription() {return description;}
    unsigned int Course::getsemester() {return semester;}
    Professor* Course::getypefthinos() {return ypefthinos;}

//Setters
    void Course::setID(string num) {ID = num;}

    void Course::setDescription(string des) {description = des;}
    
    void Course::setSemester(unsigned int s) {semester = s;}

    void Course::setYpefthinos(Professor* yp) {ypefthinos = yp;}

    void Course::print(ostream& os) const {
    os << "Κωδικός: " << ID 
       << ", Περιγραφή: " << description 
       << ", Εξάμηνο: " << semester;
    
    //Έλεγχος αν υπάρχει υπεύθυνος καθηγητής
    if (ypefthinos != nullptr) {
        os << ", Υπεύθυνος: " << ypefthinos->getOnep(); 
    } else {
        os << ", Υπεύθυνος: Κανένας";
    }
    
    os << endl;
}
