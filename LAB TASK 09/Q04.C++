#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) override {
        double rate = 0;

        if (status == "undergraduate") {
            rate = 200;
        } else if (status == "graduate") {
            rate = 300;
        } else if (status == "doctoral") {
            rate = 400;
        } else {
            cout << "Invalid status provided!\n";
            return 0;
        }

        return creditHours * rate;
    }
};

int main() {
    GraduateStudent grad;

    string topic;
    cout << "Enter research topic: ";
    getline(cin, topic);
    grad.setResearchTopic(topic);

    string status;
    int credits;

    cout << "Enter student status (undergraduate/graduate/doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> credits;

    double tuition = grad.getTuition(status, credits);

    cout << "\n--- Student Info ---\n";
    cout << "Research Topic: " << grad.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << tuition << endl;

    return 0;
}
