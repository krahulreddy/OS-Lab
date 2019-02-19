#include<stdio.h>

struct process{
    int id, at, bt, rt, ct, wt, tat;
};

int queue[100], front = -1, rear = -1, ptr = -1;

void enqueue(int i){
    if(front == -1){
        front = rear = 0;
        queue[rear] = i;
        return;
    }
    if(rear == 99){
        printf("Error");
        return;
    }
    queue[++rear] = i;
}

int dequeue(int i){
    int j, temp;
    if(front == rear){
        if(queue[front] == i)
        {
            front = rear = -1;
            return i;
        }
        else
        {
            printf("Error!!");
            return i;
        }
    }
    for(j = front; queue[j] != i; j++){
        ;
    }
    temp = queue[j];
    for(; j > front; j--)
    {
        queue[j] = queue[j - 1];
    }
    front++;
    return temp;
}

int main()
{
    int n, i, j, q;
    printf("Enter number of processess : ");
    scanf("%d", &n);
    struct process p[n];
    int complete[n];
    printf("Enter arrival times and burst times");
    for(i = 0; i < n; i++){
        p[i].id = i;
        scanf("%d %d", &p[i].at, &p[i].bt);
        complete[i] = 0;
        p[i].rt = p[i].bt;
    }
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++){
            if(p[j].at > p[j + 1].at){
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    
    printf("Enter quantum value : ");
    scanf("%d", &q);
    int completed = 0, pT = -1, T = 0;
    while(completed != n){
        for(i = n - 1; i >= 0; i--)
            if(p[i].at <= T && p[i].at > pT){
                enqueue(i);
            }
        if((ptr < front || ptr < 0) && rear != -1){
            ptr = rear;
        }

        if(front == -1){
            ptr = -1;
            T++;
            continue;
        }
        
        pT = T;
        
        if(p[queue[ptr]].rt <= q){
            T += p[queue[ptr]].rt;
            complete[queue[ptr]]++;
            completed++;
            p[queue[ptr]].ct = T;
            p[queue[ptr]].rt = 0;
            dequeue(queue[ptr]);
            printf("comp : %d %d %d\n", T, p[queue[ptr]].id, p[queue[ptr]].rt);
            ptr--;
            continue;
        }
        T += q;
        p[queue[ptr]].rt -= q;
        printf("%d %d %d\n", T, p[queue[ptr]].id, p[queue[ptr]].rt);
        ptr--;
    }
}