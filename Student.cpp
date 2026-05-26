#include "Student.h"
#include <iostream>

using namespace std;

// Οι constructors φωνάζουν την Person και φροντίζουν ΜΟΝΟ το semester!
Student::Student(const char* num, string name) : Person(num, name) {
    semester = 1;
}

Student::Student(const char* num, string name, char g, unsigned int s) : Person(num, name, g) {
    semester = s;
}

Student::~Student() {
    // Μένει άδειος, καθαρίζει η Person
}

unsigned int Student::getSemester() const { return semester; }
void Student::setSemester(unsigned int s) { semester = s; }

void Student::print(ostream& os) const {
    os << "Ονοματεπώνυμο: " << onep << " (" << onep.length() << "), " 
       << "AM: " << code << ", " 
       << "Φύλο: " << gen << ", " 
       << "Εξάμηνο: " << semester << endl;
}

// --- Operators ---
Student& Student::operator++() {
    semester += 1;
    return *this;
}

Student& Student::operator--() {
    if (semester > 1) {
        semester -= 1;
    }
    return *this;
}

Student& Student::operator+=(unsigned int val) {
    semester += val;
    return *this;
}

Student& Student::operator-() {
    // Μπορούμε να πειράξουμε το gen κανονικά επειδή είναι protected στην Person
    if(gen == 'A') {
        gen = 'K';
    } else if(gen == 'K'){
        gen = 'A';
    }
    return *this;
}