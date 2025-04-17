#include <iostream>
#include <string>
using namespace std;

class PatientRecord;

class Doctor {
public:
    void updateMedicalHistory(PatientRecord& patient, const string& history);
    void viewMedicalData(PatientRecord& patient);
};

class Billing {
public:
    void addBillingDetails(PatientRecord& patient, double amount);
    void viewBillingInfo(PatientRecord& patient);
};

class PatientRecord {
private:
    string name;
    string ID;
    string dateOfBirth;
    string medicalHistory;
    string currentTreatment;
    double billingAmount;

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord(string n, string id, string dob)
        : name(n), ID(id), dateOfBirth(dob), billingAmount(0) {}

    string getPublicData() {
        return "Name: " + name + ", ID: " + ID + ", DOB: " + dateOfBirth;
    }

    string getMedicalData() {
        return "Medical History: " + medicalHistory + ", Treatment: " + currentTreatment;
    }

    double getBillingAmount() {
        return billingAmount;
    }
};

void Doctor::updateMedicalHistory(PatientRecord& patient, const string& history) {
    patient.medicalHistory = history;
    patient.currentTreatment = "Under observation";
}

void Doctor::viewMedicalData(PatientRecord& patient) {
    cout << patient.getMedicalData() << endl;
}

void Billing::addBillingDetails(PatientRecord& patient, double amount) {
    patient.billingAmount += amount;
}

void Billing::viewBillingInfo(PatientRecord& patient) {
    cout << "Total Billing: $" << patient.billingAmount << endl;
}

class Receptionist {
public:
    void tryToAccess(PatientRecord& patient) {
        cout << "Receptionist sees -> " << patient.getPublicData() << endl;
    }
};

int main() {
    PatientRecord p1("Talha Mirza", "P123", "12-08-1990");

    Doctor doc;
    Billing bill;
    Receptionist rec;

    doc.updateMedicalHistory(p1, "High Blood Pressure");
    doc.viewMedicalData(p1);

    bill.addBillingDetails(p1, 5000);
    bill.viewBillingInfo(p1);

    rec.tryToAccess(p1);
}
