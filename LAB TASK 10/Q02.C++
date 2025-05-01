#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100; 

struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;
};

void writeDummyData(const string& filename) {
    ofstream file(filename);
    file << "1,Ali,manager,3\n";
    file << "2,Talha,developer,1\n";
    file << "3,Ahmed,manager,1\n";
    file << "4,Affan,designer,4\n";
    file << "5,Raza,manager,5\n";
    file.close();
}

Employee parseLine(const string& line) {
    Employee e;
    size_t pos = 0, start = 0;
    string temp[4];
    int index = 0;

    while ((pos = line.find(',', start)) != string::npos && index < 3) {
        temp[index++] = line.substr(start, pos - start);
        start = pos + 1;
    }
    temp[3] = line.substr(start);

    e.id = stoi(temp[0]);
    e.name = temp[1];
    e.designation = temp[2];
    e.yearsOfService = stoi(temp[3]);
    return e;
}

string toLine(const Employee& e) {
    return to_string(e.id) + "," + e.name + "," + e.designation + "," + to_string(e.yearsOfService);
}

int queryManagers(const string& filename, Employee result[]) {
    ifstream file(filename);
    string line;
    int count = 0;

    while (getline(file, line)) {
        Employee e = parseLine(line);
        if (e.designation == "manager" && e.yearsOfService >= 2) {
            result[count++] = e;
        }
    }
    file.close();
    return count;
}

void writeToFile(const string& filename, Employee data[], int size) {
    ofstream file(filename);
    for (int i = 0; i < size; i++) {
        file << toLine(data[i]) << endl;
    }
    file.close();
}

void writeIncrementedData(const string& filename, Employee data[], int size) {
    ofstream file(filename);
    for (int i = 0; i < size; i++) {
        Employee e = data[i];
        e.id += 100;
        e.yearsOfService += 1;
        file << toLine(e) << endl;
    }
    file.close();
}

int main() {
    const string filename = "data.txt";
    Employee result[MAX];
    int count;

    writeDummyData(filename);

    count = queryManagers(filename, result);
    cout << "Query (a): Managers with >= 2 years\n";
    for (int i = 0; i < count; i++) {
        cout << toLine(result[i]) << endl;
    }

    writeToFile(filename, result, count);
    cout << "\nQuery (b): File updated with only above records.\n";

    writeIncrementedData("updated_data.txt", result, count);
    cout << "Query (c): New file 'updated_data.txt' written with incremented data.\n";

    return 0;
}
