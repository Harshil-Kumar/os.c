CPU SCHEDULING ALGOS[FirstComeFirstServe]
#include <stdio.h>


int main() {
                int n, at[20], bt[20], ct[20], wt[20], tat[20], avwt = 0, avtat = 0, avct = 0,ind[20];
                int i, j;


                printf("FIRST COME FIRST SERVE\n");
                printf("Enter Total Number of Processes: ");
                scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                        ind[i]=i+1;
        }
                printf("Enter Process Arrival Time, Burst Time: \n");


                for (i = 0; i < n; i++) {
                                printf("P[%d]:", ind[i]);
                                scanf("%d", &at[i]);
                                scanf("%d", &bt[i]);
                }


        for(int i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                                {
                                        if(at[i]>at[j])
                                        {
                                                int temp=at[i];
                                                at[i]=at[j];
                                                at[j]=temp;
                                                temp=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=temp;
                                                temp=ind[i];
                                                ind[i]=ind[j];
                                                ind[j]=temp;
                                        }
                                }
                }


                ct[0] = bt[0]+at[0];
                tat[0] = ct[0] - at[0];
                wt[0] = tat[0] - bt[0];
                avwt += wt[0];
                avtat += tat[0];
                avct += ct[0];


        


                printf("\nProcess\tAT\t\tBT\t\tCT\t\tTAT\t\tWT");


                for (i = 0; i < n; i++) {
                                if (i > 0) {
                                        if(ct[i-1]>=at[i]){
                                                ct[i] = ct[i - 1] + bt[i];
                                        }
                                        else{
                                        ct[i] = ct[i - 1] + bt[i]+(at[i]-ct[i-1]);
                                        }
                                        tat[i] = ct[i] - at[i];
                                        wt[i] = tat[i] - bt[i];
                                        avwt += wt[i];
                                        avtat += tat[i];
                                        avct += ct[i];
                                                
                                }


                                printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d", ind[i], at[i], bt[i], ct[i], tat[i], wt[i]);
                }


                avwt /= n;
                avtat /= n;
                avct /= n;


                printf("\nAverage Waiting Time: %d", avwt);
                printf("\nAverage Turnaround Time: %d", avtat);
                printf("\nAverage Completion Time: %d\n", avct);


                return 0;
}










































CPU SCHEDULING ALGOS[ShortestJobFirst]
#include <stdio.h>


int main() {
                int n, at[20], bt[20], ct[20], wt[20], tat[20], avwt = 0, avtat = 0, avct = 0,ind[20];
                int i, j;


                printf("SHORTEST JOB FIRST\n");
                printf("Enter Total Number of Processes: ");
                scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                        ind[i]=i+1;
        }
                printf("Enter Process Arrival Time, Burst Time: \n");


                for (i = 0; i < n; i++) {
                                printf("P[%d]:", ind[i]);
                                scanf("%d", &at[i]);
                                scanf("%d", &bt[i]);
                }


        for(int i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                                {
                                        if(at[i]>at[j])
                                        {
                                                int temp=at[i];
                                                at[i]=at[j];
                                                at[j]=temp;
                                                temp=bt[i];
                                                bt[i]=bt[j];
                                                bt[j]=temp;
                                                temp=ind[i];
                                                ind[i]=ind[j];
                                                ind[j]=temp;
                                        }
                                }
                }


                ct[0] = bt[0]+at[0];
                tat[0] = ct[0] - at[0];
                wt[0] = tat[0] - bt[0];
                avwt += wt[0];
                avtat += tat[0];
                avct += ct[0];


        for(int i=1;i<n;i++)
        {
                for(int j=i+1;j<n;j++)
                        {
                                if(bt[i]>bt[j])
                                {
                                        int temp=at[i];
                                        at[i]=at[j];
                                        at[j]=temp;
                                        temp=bt[i];
                                        bt[i]=bt[j];
                                        bt[j]=temp;
                                        temp=ind[i];
                                        ind[i]=ind[j];
                                        ind[j]=temp;
                                }
                        }
        }


                printf("\nProcess\tAT\t\tBT\t\tCT\t\tTAT\t\tWT");


                for (i = 0; i < n; i++) {
                                if (i > 0) {
                                        if(ct[i-1]>=at[i]){
                                                ct[i] = ct[i - 1] + bt[i];
                                        }
                                        else{
                                        ct[i] = ct[i - 1] + bt[i]+(at[i]-ct[i-1]);
                                        }
                                        tat[i] = ct[i] - at[i];
                                        wt[i] = tat[i] - bt[i];
                                        avwt += wt[i];
                                        avtat += tat[i];
                                        avct += ct[i];
                                                
                                }


                                printf("\nP[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d", ind[i], at[i], bt[i], ct[i], tat[i], wt[i]);
                }


                avwt /= n;
                avtat /= n;
                avct /= n;


                printf("\nAverage Waiting Time: %d", avwt);
                printf("\nAverage Turnaround Time: %d", avtat);
                printf("\nAverage Completion Time: %d\n", avct);


                return 0;
}










CPU SCHEDULING ALGOS[ShortestTimeRemainingFirst]
#include <stdio.h>


int main() {
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;


    printf("SHORTEST REMAINING TIME FIRST\n");
    printf("Enter the Total Number of Processes: ");
    scanf("%d", &limit);


    printf("\nEnter Details of %d Processes:\n", limit);
    for (i = 0; i < limit; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }


    burst_time[9] = 9999;


    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");


    for (time = 0; count != limit; time++) {
        smallest = 9;
        for (i = 0; i < limit; i++) {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;


        if (burst_time[smallest] == 0) {
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }


        printf("P%d\t%d\t\t%d\t\t%.2f\t\t%.2f\n", smallest + 1, arrival_time[smallest], temp[smallest], wait_time, turnaround_time);
    }


    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;


    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);


    return 0;}




















CPU SCHEDULING ALGOS[PriorityScheduling]
#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);


    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }


    for (int i = 0; i < n; i++) {
        int a = p[i], m = i;


        for (int j = i; j < n; j++) {
            if (p[j] > a) {
                a = p[j];
                m = j;
            }
        }


        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }


    int t = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;


    printf("Order of process Execution is\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        total_turnaround_time += t + b[i];
        total_waiting_time += t;
        t += b[i];
    }


    printf("\n");
    printf("Process Id     Burst Time   Wait Time    Turnaround Time\n");
    int wait_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d          %d          %d          %d\n", index[i], b[i], wait_time, wait_time + b[i]);
        wait_time += b[i];
    }


    float avg_turnaround_time = (float)total_turnaround_time / n;
    float avg_waiting_time = (float)total_waiting_time / n;


    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);


    return 0;
}








CPU SCHEDULING ALGOS[RoundRobin]
#include<stdio.h>
int main()
{
  int  n;
  printf("Enter Total Number of Processes:");
  scanf("%d", &n);
  int wait_time = 0, ta_time = 0, arr_time[n], burst_time[n], temp_burst_time[n];
  int x = n;
  for(int i = 0; i < n; i++)
  {
      printf("Enter Details of Process %d \n", i + 1);
      printf("Arrival Time:  ");
      scanf("%d", &arr_time[i]);
      printf("Burst Time:   ");
      scanf("%d", &burst_time[i]);
      temp_burst_time[i] = burst_time[i];
  }
  int time_slot;
  printf("Enter Time Quantum:");
  scanf("%d", &time_slot);
  int total = 0,  counter = 0,i;
  printf("Process ID           Burst Time           Turnaround Time          Waiting Time\n");
  for(total=0, i = 0; x!=0; )  
  {  
      if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)    
      {  
          total = total + temp_burst_time[i];  
          temp_burst_time[i] = 0;  
          counter=1;  
      }         
      else if(temp_burst_time[i] > 0)  
      {  
          temp_burst_time[i] = temp_burst_time[i] - time_slot;  
          total  += time_slot;    
      }  
      if(temp_burst_time[i]==0 && counter==1)  
      {  
          x--;
          printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, burst_time[i],total-arr_time[i], total-arr_time[i]-burst_time[i]);  
          wait_time = wait_time+total-arr_time[i]-burst_time[i];  
          ta_time += total -arr_time[i];  
          counter =0;         
      }  
      if(i==n-1)  
      {  
          i=0;  
      }  
      else if(arr_time[i+1]<=total)  
      {  
          i++;  
      }  
      else  
      {  
          i=0;  
      }  
  }  
  float average_wait_time = wait_time * 1.0 / n;
  float average_turnaround_time = ta_time * 1.0 / n;
  printf("\nAverage Waiting Time:%f", average_wait_time);
  printf("\nAvg Turnaround Time:%f", average_turnaround_time);
  return 0;
}






THREAD CREATION


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5
void *thread_function(void *arg) {
int thread_id = *(int *)arg;
printf("Thread %d is running\n", thread_id);
pthread_exit(NULL);
}
int main() {
pthread_t threads[NUM_THREADS];
int thread_args[NUM_THREADS];
for (int i = 0; i< NUM_THREADS; ++i) {
thread_args[i] = i;
int result = pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
if (result) {
printf("Error creating thread %d; return code: %d\n", i, result);
exit(-1);
}
}
printf("All threads are created.\n");
for (int i = 0; i< NUM_THREADS; ++i) {
pthread_join(threads[i], NULL);
printf("Thread %d has finished.\n", i);
}
printf("Main thread exiting.\n");
pthread_exit(NULL);
}






PRODUCER-CONSUMER PROBLEM
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>


#define BUFFER_SIZE 10


sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int buffer_index = 0;
int produced_items = 0;
int consumed_items = 0;
int total_items = 5;


void *producer(void *arg)
{
  while (produced_items < total_items)
  {
      sem_wait(&empty);
      sem_wait(&mutex);


      buffer[buffer_index] = produced_items + 1;
      printf("Producer produces item %d\n", buffer[buffer_index]);
      buffer_index = (buffer_index + 1) % BUFFER_SIZE;
      produced_items++;


      sem_post(&mutex);
      sem_post(&full);
  }
  pthread_exit(NULL);
}


void *consumer(void *arg)
{
  while (consumed_items < total_items)
  {
      sem_wait(&full);
      sem_wait(&mutex);


      int item = buffer[(buffer_index - 1 + BUFFER_SIZE) % BUFFER_SIZE];
      printf("Consumer consumes item %d\n", item);
      buffer_index = (buffer_index - 1 + BUFFER_SIZE) % BUFFER_SIZE;
      consumed_items++;


      sem_post(&mutex);
      sem_post(&empty);
  }
  pthread_exit(NULL);
}


int main()
{
  sem_init(&mutex, 0, 1);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);


  pthread_t producer_thread, consumer_thread;
  pthread_create(&producer_thread, NULL, producer, NULL);
  pthread_create(&consumer_thread, NULL, consumer, NULL);
  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);


  sem_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);


  return 0;
}
DINING PHILOSOPHERS PROBLEM
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>


#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N


int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };
sem_t mutex;
sem_t S[N];


void test(int phnum)
{
    if (state[phnum] == HUNGRY
     && state[LEFT] != EATING
     && state[RIGHT] != EATING) {
     state[phnum] = EATING;
     sleep(2);
     printf("Philosopher %d takes fork %d and %d\n",
           phnum + 1, LEFT + 1, phnum + 1);
     printf("Philosopher %d is Eating\n", phnum + 1);
     sem_post(&S[phnum]);
    }
}


void take_fork(int phnum)
{
    sem_wait(&mutex);
    state[phnum] = HUNGRY;
    printf("Philosopher %d is Hungry\n", phnum + 1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);
    sleep(1);
}


void put_fork(int phnum)
{
    sem_wait(&mutex);
    state[phnum] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n",    phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is thinking\n", phnum + 1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}


void* philosopher(void* num)
{
    while (1) {
     int* i = num;
     sleep(1);
     take_fork(*i);
     sleep(0);
     put_fork(*i);
    }
}


int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
     sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++) {
     pthread_create(&thread_id[i], NULL,
           philosopher, &phil[i]);
     printf("Philosopher %d is thinking\n", i + 1);
    }
    for (i = 0; i < N; i++)
     pthread_join(thread_id[i], NULL);
}
















































DEADLOCK DETECTION MECHANISM
#include <stdio.h>
#include <stdbool.h>


int processes, resources;
int allocated[10][10], max[10][10], need[10][10];
int available[10], work[10];
bool finish[10];


void input() {
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);


    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }


    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }


    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
}


void display() {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", allocated[i][j]);
        }
        printf("\n");
    }


    printf("Maximum Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }


    printf("Need Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


    printf("Available Resources:\n");
    for (int i = 0; i < resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}


bool isSafe() {
    for (int i = 0; i < processes; i++) {
        finish[i] = false;
    }


    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }


    int count = 0;
    int sequence[10];


    while (count < processes) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocated[i][j];
                    }
                    finish[i] = true;
                    sequence[count] = i;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is in a deadlock state!\n");
            return false;
        }
    }


    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", sequence[i]);
    }
    printf("\n");


    return true;
}


int main() {
    input();
    display();
    isSafe();


    return 0;
}






























PAGE REPLACEMENT ALGORITHMS
#include<stdio.h>


int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pcnt=0;


void getData()
{
  printf("\nEnter length of page reference sequence:");
  scanf("%d",&n);
  printf("\nEnter the page reference sequence:");
  for(i=0; i<n; i++)
      scanf("%d",&in[i]);
  printf("\nEnter no of frames:");
  scanf("%d",&nf);
}


void initialize()
{
  pcnt=0;
  for(i=0; i<nf; i++)
      p[i]=9999;
}


int isHit(int data)
{
  hit=0;
  for(j=0; j<nf; j++)
  {
      if(p[j]==data)
      {
          hit=1;
          break;
      }
  }
  return hit;
}


int getHitIndex(int data)
{
  int hitnd;
  for(k=0; k<nf; k++)
  {
      if(p[k]==data)
      {
          hitnd=k;
          break;
      }
  }
  return hitnd;
}


void dispPages()
{
  for (k=0; k<nf; k++)
  {
      if(p[k]!=9999)
          printf(" %d",p[k]);
  }
}


void dispPgfcount()
{
  printf("\nTotal no of page faults:%d",pcnt);
}


void fifo()
{
  initialize();
  for(i=0; i<n; i++)
  {
      printf("\nFor %d :",in[i]);
      if(isHit(in[i])==0)
      {
          for(k=0; k<nf-1; k++)
              p[k]=p[k+1];
          p[k]=in[i];
          pcnt++;
          dispPages();
      }
      else
          printf("No page fault");
  }
  dispPgfcount();
}


void optimal()
{
  initialize();
  int near[50];
  for(i=0; i<n; i++)
  {
      printf("\nFor %d :",in[i]);
      if(isHit(in[i])==0)
      {
          for(j=0; j<nf; j++)
          {
              int pg=p[j];
              int found=0;
              for(k=i; k<n; k++)
              {
                  if(pg==in[k])
                  {
                      near[j]=k;
                      found=1;
                      break;
                  }
                  else
                      found=0;
              }
              if(!found)
                  near[j]=9999;
          }
          int max=-9999;
          int repindex;
          for(j=0; j<nf; j++)
          {
              if(near[j]>max)
              {
                  max=near[j];
                  repindex=j;
              }
          }
          p[repindex]=in[i];
          pcnt++;
          dispPages();
      }
      else
          printf("No page fault");
  }
  dispPgfcount();
}


void lru()
{
  initialize();
  int least[50];
  for(i=0; i<n; i++)
  {
      printf("\nFor %d :",in[i]);
      if(isHit(in[i])==0)
      {
          for(j=0; j<nf; j++)
          {
              int pg=p[j];
              int found=0;
              for(k=i-1; k>=0; k--)
              {
                  if(pg==in[k])
                  {
                      least[j]=k;
                      found=1;
                      break;
                  }
                  else
                      found=0;
              }
              if(!found)
                  least[j]=-9999;
          }
          int min=9999;
          int repindex;
          for(j=0; j<nf; j++)
          {
              if(least[j]<min)
              {
                  min=least[j];
                  repindex=j;
              }
          }
          p[repindex]=in[i];
          pcnt++;
          dispPages();
      }
      else
          printf("No page fault!");
  }
  dispPgfcount();
}


void lfu()
{
  int usedcnt[100];
  int least,repuin,sofarcnt=0,bn;
  initialize();
  for(i=0; i<nf; i++)
      usedcnt[i]=0;
  for(i=0; i<n; i++)
  {
      printf("\n For %d :",in[i]);
      if(isHit(in[i]))
      {
          int hitnd=getHitIndex(in[i]);
          usedcnt[hitnd]++;
          printf("No page fault!");
      }
      else
      {
          pcnt++;
          if(bn<nf)
          {
              p[bn]=in[i];
              usedcnt[bn]=usedcnt[bn]+1;
              bn++;
          }
          else
          {
              least=9999;
              for(k=0; k<nf; k++)
                  if(usedcnt[k]<least)
                  {
                      least=usedcnt[k];
                      repin=k;
                  }
              p[repin]=in[i];
              sofarcnt=0;
              for(k=0; k<=i; k++)
                  if(in[i]==in[k])
                      sofarcnt=sofarcnt+1;
              usedcnt[repin]=sofarcnt;
          }
          dispPages();
      }
  }
  dispPgfcount();
}
int main()
{
  int choice;
  while(1)
  {
      printf("\nPage Replacement Algorithms\n1.Enter data\n2.FIFO\n3.Optimal\n4.LRU\n5.LFU\n6.Exit\nEnter your choice:");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
          getData();
          break;


      case 2:
          fifo();
          break;


      case 3:
          optimal();
          break;


      case 4:
          lru();
          break;


      case 5:
          lfu();
          break;


      default:
          return 0;
          break;
      }
  }
}


























IPC
#include<stdio.h>
#include<unistd.h>


int main() {
   int pipefds[2];
   int returnstatus;
   char writemessages[2][20]={"Hello", "World"};
   char readmessage[20];
   returnstatus = pipe(pipefds);


   if (returnstatus == -1) {
    printf("Unable to create pipe\n");
    return 1;
   }


   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
   printf("Writing to pipe - Message 2 is %s\n", writemessages[1]);
   write(pipefds[1], writemessages[1], sizeof(writemessages[0]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);
   return 0;
}
















ZOMBIE
#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t t;
t=fork();
if(t==0)
{
printf("Child ID %d\n",getpid());
}
else
{
printf("Parent ID %d\n",getpid());
sleep(10);
}
}




































ORPHAN
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_tp;
p=fork();
if(p==0)
{
sleep(5);
printf("CHILD PID %d\n",getpid());
printf("Child's Parent PID %d\n",getppid());
}
else
{printf("Parent PID %d\n",getpid());
printf("My child PID %d\n",p);
}
}






________________


DINING PHILOSOPHER V2: 
#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>




#define NUM_PHILO 5


pthread_mutex_t forks[NUM_PHILO];
sem_t waiter;




void* philosopher(void* num) {
    int philo_id = *((int *) num);
    // We are assuming that the fork we are picking is the left fork
    // and calculating the right fork from that
    int left_fork = philo_id;
    int right_fork = (philo_id + 1) % NUM_PHILO;


    while (1){
        printf("Philosopher %d is thinking\n", philo_id + 1);
        sleep(1);
        sem_wait(&waiter);
        printf("Philosopher %d is hungry\n", philo_id + 1);
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d has taken the left fork\n", philo_id + 1);
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d has taken the right fork\n", philo_id + 1);
        printf("Philosopher %d is eating\n", philo_id + 1);
        sleep(1);
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d has put down the left fork\n", philo_id + 1);
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d has put down the right fork\n", philo_id + 1);
        sem_post(&waiter);
    }
    return NULL;    
}


int main() {
    pthread_t phisophers[NUM_PHILO];
    int philo_id[NUM_PHILO];


    sem_init(&waiter, 0, NUM_PHILO - 1);
    for (int i = 0; i < NUM_PHILO; i++) {
        pthread_mutex_init(&forks[i], NULL);
        philo_id[i] = i;
        pthread_create(&phisophers[i], NULL, philosopher, &philo_id[i]);
    }


    for (int i=0; i<NUM_PHILO; i++) {
        pthread_join(phisophers[i], NULL);
    }
    return 0;
}




________________


Deadlock v2: 
#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10


int main() {
  int np, nr;
  int alloc[MAX_PROCESSES][MAX_RESOURCES];
  int request[MAX_PROCESSES][MAX_RESOURCES];
  int avail[MAX_RESOURCES];
  int r[MAX_RESOURCES];
  int w[MAX_RESOURCES];
  int mark[MAX_PROCESSES] = {0};


  printf("Enter the number of processes: ");
  scanf("%d", &np);
  printf("Enter the number of resources: ");
  scanf("%d", &nr);
  for (int i = 0; i < nr; i++) {
      printf("Total Amount of Resource R%d: ", i + 1);
      scanf("%d", &r[i]);
  }
  printf("Enter the request matrix:\n");
  for (int i = 0; i < np; i++)
      for (int j = 0; j < nr; j++)
          scanf("%d", &request[i][j]);
  printf("Enter the allocation matrix:\n");
  for (int i = 0; i < np; i++)
      for (int j = 0; j < nr; j++)
          scanf("%d", &alloc[i][j]);
  for (int j = 0; j < nr; j++) {
      avail[j] = r[j];
      for (int i = 0; i < np; i++) {
          avail[j] -= alloc[i][j];
      }
  }
  for (int i = 0; i < np; i++) {
      int count = 0;
      for (int j = 0; j < nr; j++) {
          if (alloc[i][j] == 0)
              count++;
          else
              break;
      }
      if (count == nr)
          mark[i] = 1;
  }
  for (int j = 0; j < nr; j++) {
      w[j] = avail[j];
  }




  int loops=0;
    while(loops<np){
      for (int i = 0; i < np; i++) {
          int canBeProcessed = 0;
          if (mark[i] != 1) {
              for (int j = 0; j < nr; j++) {
                  if (request[i][j] <= w[j])
                      canBeProcessed = 1;
                  else {
                      canBeProcessed = 0;
                      break;
                  }
              }
              if (canBeProcessed) {
                  mark[i] = 1;
                  for (int j = 0; j < nr; j++) {
                      w[j] += alloc[i][j];
                      alloc[i][j]=0;
                  }
              }
          }
      }
      loops++;
    }


  int deadlock = 0;
  for (int i = 0; i < np; i++) {
      if (mark[i] != 1)
          deadlock = 1;
  }
  if (deadlock)
      printf("Deadlock detected\n");
  else
      printf("No deadlock possible\n");
  return 0;
}



// DEADLOCK BACKUP 

#include <stdio.h> 
int main() 
{ 
    int p = 5;  //Number of different processes
    int r = 3;  //Number of types of resource chunks

    int alloc[5][3] = { { 0, 0, 1 },{ 3, 0, 0 },{ 1, 0, 1 },{ 2, 3, 2 }, { 0, 0, 3 } }; 
    int max[5][3] = { { 7, 6, 3 }, { 3, 2, 2 }, { 8, 0, 2 },  { 2, 1, 2 }, { 5, 2, 3 } }; 

    //Available resources
    int avail[3] = { 2, 3, 2 }; 

    int f[p], ans[p], ind = 0; 

    //Initializing the finished check array
    for (int k = 0; k < p; k++) { 
        f[k] = 0; 
    } 

    //Finiding the requirement array
    int need[p][r]; 
    for (int i = 0; i < p; i++) { 
        for (int j = 0; j < r; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 


    int y = 0; 
    for(int k = 0 ; k < 5 ; k++)
    {
    //For the number of processes in total
        for (int i = 0; i < p; i++) { 
            //If the process has not finished executing
            if (f[i] == 0) { 
                int flag = 0; 
                //Initialize a new loop that iterates for each type of resource needed
                for (int j = 0; j < r; j++) { 
                    //If the requirement is more than available then exit
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                        break; 
                    } 
                } 
                //If the requirement is satisfied 
                if (flag == 0) { 
                    //Add the process to safe sequence
                    ans[ind++] = i; 

                    //Initialize loop that simulates the freeing of resources after processing 
                    for (int y = 0; y < r; y++) 
                        avail[y] += alloc[i][y]; 
                    //Mark Process as completed
                    f[i] = 1; 
                } 
            } 
  }}
    printf("Th SAFE Sequence is as follows\n"); 
    for (int i = 0; i < p - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[p - 1]); 
    return (0); 
}
