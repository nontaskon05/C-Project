#include "Person.h"
#include <cstring>

using namespace std;

// --- Constructors ---
Person::Person(const char* num, string name) {
    code = new char [strlen(num) + 1];
    strcpy(code, num);
    onep = name;
    gen = '-';
}

Person::Person(const char* num, string name, char g) {
    code = new char[strlen(num) + 1];
    strcpy(code, num);
    onep = name;
    gen = g;
}

// Copy Constructor
Person::Person(const Person& other) {
    code = new char[strlen(other.code) + 1];
    strcpy(code, other.code);
    onep = other.onep;
    gen = other.gen;
    // Το vector my_courses αντιγράφεται αυτόματα (ρηχό αντίγραφο)
}

// --- Destructor ---
Person::~Person() {
    delete[] code;
}

// --- Getters ---
char* Person::getCode() const { return code; }
string Person::getOnep() const { return onep; }
char Person::getGen() const { return gen; }
vector<Course*> Person::getCourses() const { return my_courses; }

// --- Setters ---
void Person::setCode(const char* newCode) {
    if(code != nullptr) {
        delete[] code;
    }
    code = new char[strlen(newCode) + 1];
    strcpy(code, newCode);
}

void Person::setOnep(string name) { onep = name; }
void Person::setGen(char g) { gen = g; }

// --- Λειτουργίες Vector ---
void Person::addCourse(Course* c) {
    my_courses.push_back(c);
}

void Person::remCourse(Course* c) {
    // Αυτό θέλει λίγο ψάξιμο με iterators, το αφήνουμε για το τέλος αν χρειαστεί!
}