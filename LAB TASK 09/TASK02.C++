#include <iostream>
#include <string>

using namespace std;

class Logger {
private:
    string logs[1000];
    int count = 0;
    const int maxLogs = 1000;

    string formatMessage(const string& severity, const string& source, const string& message) {
        return "[" + severity + "] From " + source + ": " + message;
    }

    void storeLog(const string& formattedMessage) {
        if (count >= maxLogs) {
            for (int i = 1; i < maxLogs; i++) {
                logs[i - 1] = logs[i]; // shift left to remove oldest
            }
            logs[maxLogs - 1] = formattedMessage;
        } else {
            logs[count++] = formattedMessage;
        }
    }

public:
    void log(const string& severity, const string& source, const string& message) {
        string formatted = formatMessage(severity, source, message);
        storeLog(formatted);
    }

    friend class Auditor;
};

class Auditor {
private:
    string password;

public:
    Auditor(string pw) : password(pw) {}

    void retrieveLogs(const Logger& logger) {
        if (password == "admin123") {
            cout << "\n--- Retrieved Logs ---\n";
            for (int i = 0; i < logger.count; i++) {
                cout << logger.logs[i] << endl;
            }
        } else {
            cout << "Access Denied: Invalid password.\n";
        }
    }
};

int main() {
    Logger logger;

    logger.log("INFO", "Network", "Connected to server");
    logger.log("WARN", "Auth", "Weak password detected");
    logger.log("ERROR", "Database", "Failed to write to DB");

    Auditor auditor("admin123"); 
    auditor.retrieveLogs(logger);

    Auditor wrongAuditor("guest");
    wrongAuditor.retrieveLogs(logger);

    return 0;
}
