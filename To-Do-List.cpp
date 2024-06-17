#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string &description) : description(description), completed(false) {}
    
    std::string getDescription() const {
        return description;
    }
    
    bool isCompleted() const {
        return completed;
    }
    
    void markCompleted() {
        completed = true;
    }

private:
    std::string description;
    bool completed;
};

class ToDoListManager {
public:
    void addTask(const std::string &description) {
        tasks.push_back(Task(description));
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription()
                      << (tasks[i].isCompleted() ? " [Completed]" : "") << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks[index - 1].markCompleted();
        std::cout << "Task " << index << " marked as completed." << std::endl;
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task " << index << " removed." << std::endl;
    }

private:
    std::vector<Task> tasks;
};

void displayMenu() {
    std::cout << "To-Do List Manager" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ToDoListManager manager;
    int choice;
    std::string description;
    size_t index;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                manager.addTask(description);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                manager.markTaskCompleted(index);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                manager.removeTask(index);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}