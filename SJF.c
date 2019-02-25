#include<stdio.h>	//Hello

struct process{
    int id, at, bt, ct, wt, tat;
};

int main()
{
    int n, i, j;
    printf("Enter number of processess : ");
    scanf("%d", &n);
    struct process p[n];
    int complete[n];
    printf("Enter arrival times and burst times");
    for(i = 0; i < n; i++){
        p[i].id = i;
        scanf("%d %d", &p[i].at, &p[i].bt);
        complete[i] = 0;
    }

    int completed = 0, T = 0;
    while(completed != n){
        int sj = -1, st = 1000000;
        for(i = 0; i < n; i++){
            if(p[i].at <= T && p[i].bt < st && !complete[i]){
                sj = i;
                st = p[i].bt;
            }
        }
        if(sj == -1){
            T++;
            continue;
        }
        completed++;
        complete[sj]++;
        T += st;
        p[sj].ct = T;
    }
        for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++){
            if(p[j].ct > p[j + 1].ct){
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    for(i = 0; i < n; i++){
        printf("%d %d %d %d\n", p[i].id, p[i].at, p[i].bt, p[i].ct);
    }
}
