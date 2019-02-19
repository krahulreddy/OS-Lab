#include<stdio.h>

struct process{
    int id, at, bt;
};

int main()
{
    int n, i, j;
    printf("Enter number of processess : ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter arrival times and burst times");
    for(i = 0; i < n; i++){
        p[i].id = i;
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++){
            if(p[j].at > p[j + 1].at){
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    for(i = 0; i < n; i++){
        printf("%d %d %d\n", p[i].id, p[i].at, p[i].bt);
    }
}