#include <iostream>
#include "Registry.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "   ΣΥΣΤΗΜΑ ΓΡΑΜΜΑΤΕΙΑΣ (ΦΟΙΤΗΤΟΛΟΓΙΟ)   " << endl;
    cout << "========================================\n" << endl;

    // 1. Δημιουργία της Γραμματείας
    Registry reg;

    // 2. Ανάκτηση δεδομένων από προηγούμενες εκτελέσεις (αν υπάρχουν)
    cout << "--- Φόρτωση Δεδομένων ---" << endl;
    reg.loadData("data.csv");
    cout << endl;

    // 3. Εισαγωγή νέων δεδομένων για επίδειξη
    cout << "--- Εισαγωγή Νέων Μελών & Μαθημάτων ---" << endl;
    //reg.addMember(new Student("101", "Γιάννης Παπαδόπουλος", 'A', 3));
    //reg.addMember(new Professor("205", "Μαρία Αντωνίου", 'K', "Τεχνολογία Λογισμικού"));
    
    Course* c1 = new Course("CS101", "Αντικειμενοστρεφής Προγραμματισμός", 2, nullptr);
    reg.addCourse(c1);
    cout << "Τα νέα μέλη και μαθήματα προστέθηκαν." << endl;

    // 4. Επίδειξη Εξαιρέσεων (try / catch)
    cout << "\n--- Δοκιμή Ανάθεσης Μαθήματος (Exceptions) ---" << endl;
    try {
        cout << "[Δοκιμή 1]: Σωστή ανάθεση..." << endl;
        reg.assignCourse("101", "CS101"); // Θα πετύχει

        cout << "[Δοκιμή 2]: Λάθος ανάθεση (ανύπαρκτο ID)..." << endl;
        reg.assignCourse("999", "CS101"); // Θα πετάξει throw!
        
    } catch (const exception& e) {
        // Εδώ "πιάνουμε" το throw της Γραμματείας για να μην κρασάρει το πρόγραμμα!
        cout << ">>> EXCEPTION CAUGHT: " << e.what() << endl;
    }

    // 5. Επίδειξη Διόρθωσης και Διαγραφής
    cout << "\n--- Δοκιμή Διόρθωσης / Διαγραφής ---" << endl;
    reg.updateMemberName("101", "Γιάννης Παπαδόπουλος (Ενημερωμένο)");
    reg.updateStudentSemester("101", 4);
    
    // Προσθέτουμε έναν προσωρινό για να δείξουμε τη διαγραφή
    reg.addMember(new Student("999", "Προσωρινός Φοιτητής", 'A', 1));
    reg.removeMember("999");

    // 6. Εκτύπωση Καταλόγων
    cout << "\n--- Τελικές Εκτυπώσεις ---" << endl;
    reg.printMembers();
    reg.printCourses();

    // 7. Επίδειξη Μαζικών Emails
    cout << "\n--- Αποστολή Ενημερώσεων (Emails) ---" << endl;
    reg.sendEmailToStudents("Υπενθύμιση: Η δήλωση μαθημάτων λήγει την Παρασκευή!");
    reg.sendEmailToProfessors("Παρακαλώ καταχωρήστε τις βαθμολογίες του εξαμήνου.");

    // 8. Αποθήκευση στο CSV
    cout << "--- Αποθήκευση Δεδομένων ---" << endl;
    reg.saveData("data.csv");

    cout << "\n========================================" << endl;
    cout << "       ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ         " << endl;
    cout << "========================================" << endl;

    return 0;
}