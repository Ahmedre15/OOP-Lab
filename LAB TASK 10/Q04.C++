#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

const std::string LOG_FILE = "log.txt";
const size_t MAX_LOG_SIZE = 1 * 1024 * 1024; // 1MB
const int MAX_BACKUPS = 5;

void rotate_logs() {
    std::string oldest = "log" + std::to_string(MAX_BACKUPS) + ".txt";
    if (fs::exists(oldest)) {
        fs::remove(oldest);
    }

    for (int i = MAX_BACKUPS - 1; i >= 1; --i) {
        std::string old_name = "log" + std::to_string(i) + ".txt";
        std::string new_name = "log" + std::to_string(i + 1) + ".txt";
        if (fs::exists(old_name)) {
            fs::rename(old_name, new_name);
        }
    }

    if (fs::exists(LOG_FILE)) {
        fs::rename(LOG_FILE, "log1.txt");
    }
}

void log_message(const std::string& message) {
    if (fs::exists(LOG_FILE) && fs::file_size(LOG_FILE) > MAX_LOG_SIZE) {
        rotate_logs();
    }

    std::ofstream log(LOG_FILE, std::ios::app);
    if (log) {
        log << message << std::endl;
    } else {
        std::cerr << "Error: Unable to open log file." << std::endl;
    }
}

int main() {
    for (int i = 0; i < 100000; ++i) {
        log_message("Log entry number: " + std::to_string(i));
    }
    return 0;
}
