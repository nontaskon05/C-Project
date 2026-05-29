#include "Professor.h"

using namespace std;


Professor::Professor(const char* num, string name) : Person(num, name) {
    speciality = "-";
}

Professor::Professor(const char* num, string name, char g, string s) : Person(num, name, g) {
    speciality = s;
}

Professor::~Professor(){}

string Professor::getSpeciality() const { return speciality; }
void Professor::setSpeciality(string s) { speciality = s; }

void Professor::print(ostream& os) const {
    os << "[Καθηγητής] Κωδικός: " << getCode() 
       << " | Όνομα: " << getOnep() 
       << " | Ειδικότητα: " << speciality << endl;
}