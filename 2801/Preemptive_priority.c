#include<stdio.h>

struct process{
    int id, at, bt, rt, pty, ct, wt, tat;
};

int main()
{
    int n, i, j;
    printf("Enter number of processess : ");
    scanf("%d", &n);
    struct process p[n];
    int complete[n];
    printf("Enter arrival times, burst times and priorities");
    for(i = 0; i < n; i++){
        p[i].id = i;
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pty);
        complete[i] = 0;
        p[i].rt = p[i].bt;
    }

    int completed = 0, T = 0;
    while(completed != n){
        int sj = -1, sp = 1000000;
        for(i = 0; i < n; i++){
            if(p[i].at <= T && p[i].pty < sp && !complete[i]){
                sj = i;
                sp = p[i].pty;
            }
        }
        if(sj == -1){
            printf("Idle ");
            T++;
            continue;
        }
        if(p[sj].rt == 1){
            completed++;
            complete[sj]++;
            T++;
            p[sj].rt--;
            p[sj].ct = T;
        }
        else{
            T++;
            p[sj].rt--;
        }
        printf("%d ", sj);
    }
    printf("\n");
    // for(i = 0; i < n - 1; i++)
    //     for(j = 0; j < n - i - 1; j++){
    //         if(p[j].ct > p[j + 1].ct){
    //             struct process temp = p[j];
    //             p[j] = p[j + 1];
    //             p[j + 1] = temp;
    //         }
    //     }
    for(i = 0; i < n; i++){
        printf("%d %d %d %d\n", p[i].id, p[i].at, p[i].bt, p[i].ct);
    }
}