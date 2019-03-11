#include<stdio.h>

int main()
{
	int p, r, i, j;
	printf("Enter number of processes and resources : ");
	scanf("%d %d", &p, &r);
	int max_need[p][r], current_alloc[p][r], current_alloc1[p][r], rem_need[p][r], rem_need1[p][r], available[r], available1[r];
	printf("Enter max_need values : \n");
	for(i = 0; i < p; i++)
	{
		printf("Process %d : \n", i);
		for(j = 0; j < r; j++)
			scanf("%d", &max_need[i][j]);
	}
	printf("Enter current_alloc values : \n");
        for(i = 0; i < p; i++)
        {
                printf("Process %d : \n", i);
                for(j = 0; j < r; j++)
		{
                        scanf("%d", &current_alloc[i][j]);
			current_alloc1[i][j] = current_alloc[i][j];
			rem_need[i][j] = max_need[i][j] - current_alloc[i][j];
			//rem_need[i][j] = rem_need[i][j] > 0 ? rem_need[i][j] : 0;
			if(rem_need[i][j] < 0)
				rem_need[i][j] = 0;
		}
        }
	printf("Enter available values : \n");
        for(i = 0; i < r; i++)
        {
                scanf("%d", &available[i]);
		available1[i] = available[i];
        }
	printf("Remaining need : \n");
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
			printf("%d ", rem_need[i][j]);
		printf("\n");
	}
	int k, flag = 0, sequence[p], next = 0, finish[p], finished = 0, prev_finished = 0;
	for(i = 0; i < p; i++)
		finish[i] = 0;
	int t = 0;
	while(finished != p && t < p * p)
	{
		t++;
		flag = 0;
		for(i = 0; i < p; i++)
		{
			if(finish[i])
				continue;
			for(j = 0; j < r; j++)
				if(rem_need[i][j] > available[j])
					break;
			if(j == r)
			{
				//prev_finished = finished;
				finished++;
				flag++;
				finish[i]++;
				sequence[next++] = i;
				printf("%d  %d\n", i, finished);
				for(k = 0; k < r; k++)
				{
					available[k] += current_alloc[i][k];
					printf("%d ", available[k]);
				}
				i = 0;
			}
/*			else
				for(k = 0; k < r; k++)
                        	{
					available[k] += current_alloc[i][k];
					current_alloc[i][k] = 0;
					rem_need[i][k] = max_need[i][k];
				}*/
		}
		prev_finished = finished;
	}
	if(finished != p)
		printf("Not safe!!\n");
	else
	{
		printf("Safe!!\n");
		for(i = 0; i < next; i++)
			printf("%d ", sequence[i]);
	}
	printf("Enter process number for request : ");
	int req;
	scanf("%d", &req);
	int new_req;
	printf("Enter request array : ");
	for(j = 0; j < r; j++)
	{
		scanf("%d", &new_req);
		max_need[req][j] = new_req;
	}
	printf("current alloc  : \n");
	for(i = 0; i < p; i++)
        {
                for(j = 0; j < r; j++)
                        printf("%d ", current_alloc1[i][j]);
                printf("\n");
        }
	for(i = 0; i < p; i++)
	for(j = 0; j < r; j++)
                {
                       	//scanf("%d", &current_alloc[i][j]);
                        rem_need1[i][j] = max_need[i][j] - current_alloc1[i][j];
                        //rem_need[i][j] = rem_need[i][j] > 0 ? rem_need[i][j] : 0;
                        if(rem_need1[i][j] < 0)
                                rem_need1[i][j] = 0;
        	}
	printf("Remaining need : \n");
        for(i = 0; i < p; i++)
        {
                for(j = 0; j < r; j++)
                        printf("%d ", rem_need1[i][j]);
                printf("\n");
        }
	flag = 0;
	next = 0;
	finished = 0;
	prev_finished = 0;
        for(i = 0; i < p; i++)
                finish[i] = 0;
	t = 0;
        while(finished != p && t < p * p)
        {
		t++;
                flag = 0;
                for(i = 0; i < p; i++)
                {
                        if(finish[i])
                                continue;
                        for(j = 0; j < r; j++)
                                if(rem_need1[i][j] > available1[j])
                                        break;
                        if(j == r)
                        {
                                //prev_finished = finished;
                                finished++;
                                flag++;
                                finish[i]++;
                                sequence[next++] = i;
                                printf("%d  %d\n", i, finished);
                                for(k = 0; k < r; k++)
                                        available1[k] += current_alloc1[i][k];
                                i = 0;
                        }
	//		else
//                                for(k = 0; k < r; k++)
 //                               {
 //                                       available1[k] += current_alloc[i][k];
  //                                      current_alloc1[i][k] = 0;
    //                                    rem_need1[i][k] = max_need[i][k];
      //                          }

                }
                prev_finished = finished;
        }
        if(!flag && finished != p)
	        printf("Not safe!!\n");
        else
        {
                printf("Safe!!\n");
                for(i = 0; i < next; i++)
                        printf("%d ", sequence[i]);
        }
}
