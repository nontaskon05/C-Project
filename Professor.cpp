#include "Professor.h"

using namespace std;

// Οι constructors φωνάζουν την Person και φροντίζουν ΜΟΝΟ το speciality!
Professor::Professor(const char* num, string name) : Person(num, name) {
    speciality = "-";
}

Professor::Professor(const char* num, string name, char g, string s) : Person(num, name, g) {
    speciality = s;
}

Professor::~Professor() {
    // Μένει άδειος, καθαρίζει η Person
}

string Professor::getSpeciality() const { return speciality; }
void Professor::setSpeciality(string s) { speciality = s; }