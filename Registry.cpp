#include "Registry.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

//Destructor
    Registry::~Registry() {
        for(Person* p : my_members) {
            delete p;
        }
        for(Course* c : my_course) {
            delete c;
        }
    }

//Προσθήκες
    void Registry::addMember(Person* p) {
        my_members.push_back(p);
    }

    void Registry::addCourse(Course* c) {
        my_course.push_back(c);
    }


//Αναζητήσεις
    Person* Registry::findMember(const char* id) {
    for (Person* p : my_members) {
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

// ================= ΔΙΟΡΘΩΣΗ ΔΕΔΟΜΕΝΩΝ =================

// Διόρθωση Ονόματος (Αφορά τη Person)
    void Registry::updateMemberName(const char* id, string newName) {
        Person* p = findMember(id); 
        if (p != nullptr) {
            p->setOnep(newName); 
            cout << "Το όνομα ενημερώθηκε επιτυχώς!" << endl;
        }
    }

// Διόρθωση Φύλου (Αφορά τη Person)
    void Registry::updateMemberGender(const char* id, char newGender) {
        Person* p = findMember(id);
        if (p != nullptr) {
            p->setGen(newGender);
            cout << "Το φύλο ενημερώθηκε επιτυχώς!" << endl;
        }
    }

// Διόρθωση Εξαμήνου (Αφορά Φοιτητή)
    void Registry::updateStudentSemester(const char* id, unsigned int newSem) {
        Person* p = findMember(id);
        if (p != nullptr) {
            // Έλγχουμε αν αυτός ο Person είναι όντως Student
            Student* s = dynamic_cast<Student*>(p);
            if (s != nullptr) {
                s->setSemester(newSem);
                cout << "Το εξάμηνο ενημερώθηκε επιτυχώς!" << endl;
            } else {
                cout << "Σφάλμα: Το μέλος με ID " << id << " δεν είναι Φοιτητής." << endl;
            }
        }
    }

// Διόρθωση Ειδικότητας (Αφορά Καθηγητή)
    void Registry::updateProfSpeciality(const char* id, string newSpec) {
        Person* p = findMember(id);
        if (p != nullptr) {
            // Ελέγχουμε αν αυτός ο Person είναι όντως Professor
            Professor* prof = dynamic_cast<Professor*>(p);
            if (prof != nullptr) {
                prof->setSpeciality(newSpec);
                cout << "Η ειδικότητα ενημερώθηκε επιτυχώς!" << endl;
            } else {
                cout << "Σφάλμα: Το μέλος με ID " << id << " δεν είναι Καθηγητής." << endl;
            }
        }
    }


// ================= ΔΙΑΓΡΑΦΗ ΜΕΛΟΥΣ =================
    void Registry::removeMember(const char* id) {
        for (auto it = my_members.begin(); it != my_members.end(); ++it) {
            if (strcmp((*it)->getCode(), id) == 0) {
                delete *it;          
                my_members.erase(it); 
                cout << "Το μέλος με ID " << id << " διαγράφηκε επιτυχώς!" << endl;
                return;
            }
        }
        cout << "Το μέλος με ID " << id << " δεν βρέθηκε για να διαγραφεί." << endl;
    }

//Assign course
    void Registry::assignCourse(const char* id, string code) {
        // 1. Βρίσκουμε το μέλος με τη νέα σου συνάρτηση (δεν μας νοιάζει η ιδιότητά του)
        Person* target_p = findMember(id); 
        
        // 2. Βρίσκουμε το μάθημα, ακριβώς όπως το είχες γράψει
        Course* target_c = findCourse(code);
        
        // 3. Ελέγχουμε αν όντως βρέθηκαν και τα δύο
        if (target_p == nullptr) {
            throw invalid_argument(string("Σφάλμα: Το μέλος με ID ") + id + " δεν βρέθηκε στο σύστημα!");
         }
        if (target_c == nullptr) {
            throw invalid_argument(string("Σφάλμα: Το μάθημα με κωδικό ") + code + " δεν βρέθηκε!");
        }
        target_p->addCourse(target_c); 
        cout << "Το μάθημα ανατέθηκε επιτυχώς!" << endl;
    }


//Εκτύπωση 
    void Registry::printMembers() const {
    cout << "=== ΕΝΙΑΙΟΣ ΚΑΤΑΛΟΓΟΣ ΜΕΛΩΝ ΠΑΝΕΠΙΣΤΗΜΙΟΥ ===" << endl;
    for (Person* p : my_members) {
        p->print(cout); 
    }
    cout << "---------------------------------------------" << endl;
}

    void Registry::printCourses() const {
        cout << "=== ΛΙΣΤΑ ΜΑΘΗΜΑΤΩΝ ===" << endl;
        for(Course* c : my_course) {
            c->print(cout);
        }
        cout << "------------------------" << endl;
    }

// ============== ΑΠΟΣΤΟΛΗ EMAILS ==============

    void Registry::sendEmailToStudents(string message) const {
        cout << "\n=== ΜΑΖΙΚΟ EMAIL ΣΕ ΦΟΙΤΗΤΕΣ ===" << endl;
        int count = 0; // Πόσα mails στείλαμε
        
        for (Person* p : my_members) {
            // Έλεγχος ταυτότητας
            Student* s = dynamic_cast<Student*>(p);
        
            if (s != nullptr) {
                cout << "Προς AM " << s->getCode() << " (" << s->getOnep() << "): " << message << endl;
                count++;
            }
        }
        cout << "[Στάλθηκαν συνολικά " << count << " emails σε φοιτητές]\n" << endl;
    }

    void Registry::sendEmailToProfessors(string message) const {
        cout << "\n=== ΜΑΖΙΚΟ EMAIL ΣΕ ΚΑΘΗΓΗΤΕΣ ===" << endl;
        int count = 0;
        
        for (Person* p : my_members) {
            // Έλεγχος ταυτότητας
            Professor* prof = dynamic_cast<Professor*>(p);
            
            if (prof != nullptr) {
                cout << "Προς Καθηγητή/τρια " << prof->getOnep() << ": " << message << endl;
                count++;
            }
        }
        cout << "[Στάλθηκαν συνολικά " << count << " emails σε καθηγητές]\n" << endl;
    }


// ================= ΑΡΧΕΙΑ CSV =================

    void Registry::saveData(string filename) const {
        //(Output File Stream)
        ofstream file(filename); 
        
        // Έλεγχος ασφαλείας: Άνοιξε σωστά το αρχείο;
        if (!file.is_open()) {
            cout << "Σφάλμα: Δεν μπόρεσε να ανοίξει το αρχείο για γράψιμο!" << endl;
            return;
        }

        // Διατρέχουμε όλους τους ανθρώπους της Γραμματείας
        for (Person* p : my_members) {
            
            //Φοιτητής;
            Student* s = dynamic_cast<Student*>(p);
            if (s != nullptr) {
                // Γράφουμε με κόμματα: ΤΑΜΠΕΛΑ, ΚΩΔΙΚΟΣ, ΟΝΟΜΑ, ΦΥΛΟ, ΕΞΑΜΗΝΟ
                file << "STUDENT," << s->getCode() << "," 
                    << s->getOnep() << "," << s->getGen() << "," 
                    << s->getSemester() << "\n";
            } 
            else {
                // Δεν είναι Φοιτητής, άρα είναι Καθηγητής;
                Professor* prof = dynamic_cast<Professor*>(p);
                if (prof != nullptr) {
                    // Γράφουμε με κόμματα: ΤΑΜΠΕΛΑ, ΚΩΔΙΚΟΣ, ΟΝΟΜΑ, ΦΥΛΟ, ΕΙΔΙΚΟΤΗΤΑ
                    file << "PROFESSOR," << prof->getCode() << "," 
                        << prof->getOnep() << "," << prof->getGen() << "," 
                        << prof->getSpeciality() << "\n";
                }
            }
        }
        
        file.close(); // Κλείνουμε το αρχείο
        cout << "Τα δεδομένα αποθηκεύτηκαν επιτυχώς στο " << filename << "!" << endl;
    }

    void Registry::loadData(string filename) {
    // (Input File Stream) - Ανοίγουμε το αρχείο για διάβασμα
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Το αρχείο " << filename << " δεν βρέθηκε. Θα δημιουργηθεί νέο κατά την αποθήκευση." << endl;
        return;
    }

    string line;
    // Η getline διαβάζει το αρχείο γραμμή-γραμμή μέχρι να τελειώσει
    while (getline(file, line)) {
        
        // Φτιάχνουμε το stringstream για την τρέχουσα γραμμή
        stringstream ss(line); 
        
        string type, id, name, genderStr, extra;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, genderStr, ',');
        getline(ss, extra, ','); // Το extra είναι είτε εξάμηνο είτε ειδικότητα

        // Επειδή το φύλο διαβάζεται ως string, παίρνουμε τον πρώτο του χαρακτήρα
        char gender = genderStr[0];

        // Ελέγχουμε την ταμπέλα και φτιάχνουμε τον αντίστοιχο άνθρωπο
        if (type == "STUDENT") {
            // Η string to integer μετατρέπει το κείμενο σε αριθμό
            unsigned int semester = stoi(extra);

            addMember(new Student(id.c_str(), name, gender, semester));
        } 
        else if (type == "PROFESSOR") {
            // Αντίστοιχα, φτιάχνουμε νέο καθηγητή
            addMember(new Professor(id.c_str(), name, gender, extra));
        }
    }
    
    file.close();
    cout << "Τα δεδομένα φορτώθηκαν επιτυχώς από το " << filename << "!" << endl;
}
