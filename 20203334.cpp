#include <iostream>
#include <vector>
#include <string>

struct Task {
    int id;
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;
    int nextId;

public:
    ToDoList() : nextId(1) {}

    void addTask(const std::string& description) {
        tasks.push_back({nextId++, description, false});
        std::cout << "Task added successfully.\n";
    }

    void listTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        for (const auto& task : tasks) {
            std::cout << "[" << (task.completed ? "X" : " ") << "] "
                      << task.id << ": " << task.description << "\n";
        }
    }

    void markComplete(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                std::cout << "Task marked as complete.\n";
                return;
            }
        }
        std::cout << "Task ID not found.\n";
    }

    void deleteTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                std::cout << "Task deleted successfully.\n";
                return;
            }
        }
        std::cout << "Task ID not found.\n";
    }
};

int main() {
    ToDoList todo;
    int choice;

    do {
        std::cout << "\n--- To-Do List Manager ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. List Tasks\n";
        std::cout << "3. Mark Task as Complete\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear input buffer
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todo.addTask(description);
                break;
            }
            case 2:
                todo.listTasks();
                break;
            case 3: {
                int id;
                std::cout << "Enter task ID to mark complete: ";
                std::cin >> id;
                todo.markComplete(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter task ID to delete: ";
                std::cin >> id;
                todo.deleteTask(id);
                break;
            }
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}