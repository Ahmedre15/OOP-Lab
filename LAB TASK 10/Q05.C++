#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string TODO_FILE = "todo.txt";
const int MAX_TASKS = 100;

struct Task {
    bool done;
    std::string description;
};

int load_tasks(Task tasks[], int max_tasks) {
    std::ifstream file(TODO_FILE.c_str());
    std::string line;
    int count = 0;

    while (std::getline(file, line) && count < max_tasks) {
        std::istringstream iss(line);
        std::string status_str, desc;
        if (std::getline(iss, status_str, '|') && std::getline(iss, desc)) {
            tasks[count].done = (status_str == "1");
            tasks[count].description = desc;
            count++;
        }
    }

    return count;
}

void save_tasks(Task tasks[], int count) {
    std::ofstream file(TODO_FILE.c_str());
    for (int i = 0; i < count; ++i) {
        file << (tasks[i].done ? "1" : "0") << "|" << tasks[i].description << std::endl;
    }
}

void add_task() {
    std::cin.ignore();
    std::string desc;
    std::cout << "Enter task description: ";
    std::getline(std::cin, desc);

    std::ofstream file(TODO_FILE.c_str(), std::ios::app);
    file << "0|" << desc << std::endl;
    std::cout << "Task added.\n";
}

void view_tasks() {
    Task tasks[MAX_TASKS];
    int count = load_tasks(tasks, MAX_TASKS);

    std::cout << "\n--- To-Do List ---\n";
    for (int i = 0; i < count; ++i) {
        std::cout << (i + 1) << ". [" << (tasks[i].done ? 'x' : ' ') << "] " << tasks[i].description << std::endl;
    }

    if (count == 0) {
        std::cout << "(No tasks found.)\n";
    }
}

void mark_task_done() {
    Task tasks[MAX_TASKS];
    int count = load_tasks(tasks, MAX_TASKS);
    view_tasks();

    std::cout << "Enter task number to mark as done: ";
    int index;
    std::cin >> index;

    if (index >= 1 && index <= count) {
        tasks[index - 1].done = true;
        save_tasks(tasks, count);
        std::cout << "Task marked as done.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void show_menu() {
    std::cout << "\n--- To-Do List Menu ---\n"
              << "1. Add Task\n"
              << "2. View Tasks\n"
              << "3. Mark Task as Done\n"
              << "4. Exit\n"
              << "Choose an option: ";
}

int main() {
    int choice;
    do {
        show_menu();
        std::cin >> choice;
        switch (choice) {
            case 1: add_task(); break;
            case 2: view_tasks(); break;
            case 3: mark_task_done(); break;
            case 4: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid option.\n"; break;
        }
    } while (choice != 4);

    return 0;
}
