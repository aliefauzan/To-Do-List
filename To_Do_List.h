#ifndef TO_DO_LIST_H_INCLUDED
#define TO_DO_LIST_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elementTask *adr_Task;
typedef struct task infoTask;

struct task{
    string title;
    int deadline;
    bool completed;
};

struct elementTask{
    infoTask info;
    adr_Task next;
};

struct list{
    adr_Task first;
};


#endif