#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ToDo {
public:
    int num;
    string work;
    bool done;    

    ToDo(int n, string w) {
        num = n;
        work = w;
        done = false;
    }
};

vector<ToDo> add_task(vector<ToDo> tasks) {
    printf("Enter task number: ");
    int n;
    cin >> n;
    printf("Enter task: ");
    cin.ignore();  // Clear the newline character from the input buffer
    string w;
    getline(cin, w);  // Read the entire line including spaces
    ToDo t(n, w);
    tasks.push_back(t);
    printf("Task added successfully.\n");
    return tasks;
}

void display_tasks(vector<ToDo> &tasks) {
    if (tasks.empty()) {
        printf("No tasks found.\n");
        return;
    }
    printf("Tasks:\n");
    for (auto t : tasks) {
        printf("Task %d: %s\t Status: %s\n", t.num, t.work.c_str(), t.done ? "Done" : "Not Done");
    }
}

vector<ToDo> delete_task(vector<ToDo> &tasks) {
    if (tasks.empty()) {
        printf("No tasks found.\n");
        return tasks;
    }
    printf("Enter task number to delete: ");
    int n;
    cin >> n;
    auto it = tasks.begin();
    while (it != tasks.end()) {
        if (it->num == n) {
            tasks.erase(it);
            printf("Task deleted successfully.\n");
            return tasks;
        }
        it++;
    }
    printf("Task not found.\n");
    return tasks;
}

vector<ToDo> mark_task_done(vector<ToDo> &tasks) {
    if (tasks.empty()) {
        printf("No tasks found.\n");
        return tasks;
    }
    printf("Enter task number to mark as done: ");
    int n;
    cin >> n;
    auto it = tasks.begin();
    while (it != tasks.end()) {
        if (it->num == n) {
            it->done = true;
            printf("Task marked as done successfully.\n");
            return tasks;
        }
        it++;
    }
    printf("Task not found.\n");
    return tasks;
}

int main() {
    bool flag = true;
    vector<ToDo> tasks;
    while (flag) {
        printf("\n________TO DO Application________\n");
        printf("1. Add a Task.\n");
        printf("2. Delete a Task.\n");
        printf("3. Mark a Task as Done.\n");
        printf("4. View all Tasks.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: 
                tasks = add_task(tasks);
                break;
            case 2: 
                tasks = delete_task(tasks);
                break;
            case 3: 
                tasks = mark_task_done(tasks); 
                break;
            case 4: 
                display_tasks(tasks);
                break;
            case 5: 
                flag = false;
                printf("Exiting...Thank You!!!!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }           
    return 0;
}