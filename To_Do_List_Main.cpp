#include "To_Do_List.cpp"

int main() {
    list LT;
    createListTask(LT);

    //insertFirstTask(LT, createElementTask({"Task 1", 3, false}));
    //insertFirstTask(LT, createElementTask({"Task 2", 5, false}));
    //insertFirstTask(LT, createElementTask({"Task 3", 2, false}));
    //insertFirstTask(LT, createElementTask({"Task 4", 1, false}));
    //insertFirstTask(LT, createElementTask({"Task 5", 4, false}));

    int choice;
    string title;
    int deadline;

    do {
        cout << "----====[ To-Do List Menu ]====----" << endl;
        cout << "1. Show Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Complete Task" << endl;
        cout << "5. Sort Tasks by Deadline" << endl;
        cout << "6. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showTask(LT);
                break;
            case 2:
                cout << "----====[ Add Task ]====----" << endl;
                cout << "Enter Task Title: ";
                cin >> title;
                cout << "Enter Deadline (YYMMDD): ";
                cin >> deadline;
                insertFirstTask(LT, createElementTask({title, deadline, false}));
                cout << "Task added successfully." << endl;
                break;
            case 3:
                cout << "----====[ Delete Task ]====----" << endl;
                cout << "Enter Task Title: ";
                cin >> title;
                cout << "Enter Deadline: ";
                cin >> deadline;
                deleteTask(LT, title, deadline);
                break;
            case 4:
                cout << "----====[ Complete Task ]====----" << endl;
                cout << "Enter Task Title: ";
                cin >> title;
                cout << "Enter Deadline: ";
                cin >> deadline;
                completeTask(LT, title, deadline);
                break;
            case 5:
                cout << "----====[ Sort Tasks by Deadline ]====----" << endl;
                sortByDeadline(LT);
                cout << "Tasks sorted successfully." << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }

        cout << endl;

    } while (choice != 6);

    return 0;
}
