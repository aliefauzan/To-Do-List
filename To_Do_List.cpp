#include "To_Do_List.h"

void createListTask(list &LT){
    LT.first = NULL;
}

adr_Task createElementTask(infoTask CE){
    adr_Task T;
    T = new elementTask;
    T->info = CE;
    T->next = NULL;
    return T;
}

void insertFirstTask(list &LT, adr_Task T){
        T->next = LT.first;
        LT.first = T;
}

void showList(list LT, adr_Task T){
        cout << "Task Name: " << T->info.title << "\n";
        cout << "Deadline: " << T->info.deadline << "\n";
        cout << "-------------------------------------------\n";
}

void showTask(list LT){
    adr_Task T = LT.first;
    cout << "----====[ Task ]====----" << "\n";
    if(T == NULL){
        cout << "No Task avaible" << endl;
    }else{
        while(T != NULL){
            showList(LT, T);
            T = T->next;
        }
    }
}

adr_Task searchT(list &LT, string title, int deadline){
    adr_Task T = LT.first;
    while (T != NULL){
        if(T->info.title == title && T->info.deadline == deadline){
            return T;
        }
        T = T->next;
    }
    cout << "Task " << title << ", Deadline " << deadline << " Not Found" << endl;
    return NULL;
}

void searchTask(list &LT, string title, int deadline){
    adr_Task T = searchT(LT, title, deadline);
    if(T != NULL){
        showList(LT, T);
    }
}

void deleteTask(list &LT, string title, int deadline){
    adr_Task T = searchT(LT, title, deadline);
    if(T != NULL){
        if(T == LT.first){
            LT.first = LT.first->next;
            delete T;
            cout << "Task " << title << ", Deadline " << deadline << " Deleted" << endl;
        }else{
            adr_Task temp = LT.first;
            while(temp->next != T){
                temp = temp->next;
            }
            temp->next = T->next;
            delete T;
            cout << "Task " << title << ", Deadline " << deadline << " Deleted" << endl;
        }
    }else{
        cout << "Task " << title << ", Deadline " << deadline << " Not Found" << endl;       
    }
}

void completeTask(list &LT, string title, int deadline) {
    adr_Task T = searchT(LT, title, deadline);
    if (T != NULL) {
        T->info.completed = true;
        cout << "Task " << title << ", Deadline " << deadline << " marked as completed." << endl;
    } else {
        cout << "Task " << title << ", Deadline " << deadline << " not found." << endl;
    }
}

void sortByDeadline(list &LT) {
    if (LT.first == NULL || LT.first->next == NULL) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        adr_Task current = LT.first;
        adr_Task prev = NULL;

        while (current->next != NULL) {
            if (current->info.deadline > current->next->info.deadline) {
                adr_Task temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (prev != NULL) {
                    prev->next = temp;
                } else {
                    LT.first = temp;
                }
                prev = temp;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}