#include <iostream>
using namespace std;

const int MAX = 50;
string tasks[MAX];
bool done[MAX];
int count = 0;

void showMenu() {
    cout << "\n1. Add Task\n2. View Tasks\n3. Mark Completed\n4. Remove Task\n5. Exit\nChoose: ";
}

void addTask() {
    if (count >= MAX) {
        cout << "Task list full!" << endl;
        return;
    }
    cout << "Enter task: ";
    cin.ignore(); // to clear buffer
    getline(cin, tasks[count]);
    done[count] = false;
    count++;
    cout << "Task added." << endl;
}

void viewTasks() {
    if (count == 0) {
        cout << "No tasks added yet." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i] << " [" << (done[i] ? "Done" : "Pending") << "]\n";
    }
}

void markDone() {
    int num;
    viewTasks();
    if (count == 0) return;
    cout << "Enter task number to mark as done: ";
    cin >> num;
    if (num >= 1 && num <= count) {
        done[num - 1] = true;
        cout << "Marked as completed." << endl;
    } else {
        cout << "Invalid number." << endl;
    }
}

void removeTask() {
    int num;
    viewTasks();
    if (count == 0) return;
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num >= 1 && num <= count) {
        for (int i = num - 1; i < count - 1; i++) {
            tasks[i] = tasks[i + 1];
            done[i] = done[i + 1];
        }
        count--;
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid number." << endl;
    }
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        if (choice == 1) addTask();
        else if (choice == 2) viewTasks();
        else if (choice == 3) markDone();
        else if (choice == 4) removeTask();
        else if (choice == 5) cout << "Goodbye!" << endl;
        else cout << "Invalid choice." << endl;
    } while (choice != 5);
    
    return 0;
}