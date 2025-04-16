#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const int BarLen = 50;
const int TotalTasks = 5;

typedef struct
{
    int id;
    int progress;
    int step;
} Task;

void progressBar(Task task)
{
    int completed = (task.progress * BarLen) / 100;
    printf("Task %d: [", task.id);
    for (int i = 0; i < BarLen; i++)
    {
        if (i < completed)
        {
            printf("=");
        }
        else
        {
            printf(" ");
        }
    }

    printf("] %d%%\n", task.progress);
}

int main()
{
    srand(time(0));

    Task tasks[TotalTasks];
    for (int i = 0; i < TotalTasks; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 10 + 5;
    }

    int tasksCompleted;
    while (1)
    {
        tasksCompleted = 0;
        for (int i = 0; i < TotalTasks; i++)
        {
            if (tasks[i].progress < 100)
            {
                tasks[i].progress += tasks[i].step;
                if (tasks[i].progress > 100)
                {
                    tasks[i].progress = 100;
                }
            }
            progressBar(tasks[i]);
            if (tasks[i].progress == 100)
            {
                tasksCompleted++;
            }
        }

        if (tasksCompleted == TotalTasks)
        {
            break;
        }

        sleep(1);
        system("cls");
    }
    printf("All Tasks Completed!!\n");
    
    
    return 0;
}