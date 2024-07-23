#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <unistd.h> // for abdu sa3eed
using namespace std;
using namespace std::chrono;

typedef struct
{
    int* arr;
    int front, rear;
    int size, max_size;
} Queue;

Queue init_queue(int max_size)
{
    Queue new_queue;
    new_queue.arr = (int*) malloc(sizeof(int) * max_size);
    new_queue.max_size = max_size;
    new_queue.rear = 0;
    new_queue.front = 0;
    new_queue.size = 0;
    return new_queue;
}
bool empty_queue(Queue q)
{
    return q.size == 0;
}

bool over_queue(Queue q)
{
    return q.size == q.max_size;
}


void enqueue(Queue* q, int val)
{
    if(q->size == q->max_size)
    {
        printf("Queue is Full\n");
        return;
    }
    q->arr[q->rear] = val;
    q->rear = (q->rear + 1) % q->max_size;
    q->size++;
}
int dequeue(Queue* q)
{
    if(q->size == 0)
    {
        printf("Queue is Empty\n");
        return -999;
    }
    int temp = q->arr[q->front];
    q->front = (q->front + 1) % q->max_size;
    q->size--;
    return temp;

}

int rand_rang(int max,int min)
{
    return (min+rand()%( max + 1 - min));
}

double rand_ex(double lamda)
{
    float x=(float)rand()/((float)RAND_MAX + 1.0);
    double res= -(log(1-x)/log(10))/lamda;
    return res;
}
//struct task
//{
//    int arrival;
//    int service_time=rand_rang(5,1);
//    int id;
//};

Queue queue_wait =init_queue(30);

void pause_s1(int n) // pauses the thread until service time is over
{
    high_resolution_clock::time_point clock_start = high_resolution_clock::now();
    std::cout<<endl << "pause of s1\n " << n <<endl;
    std::this_thread::sleep_for (std::chrono::seconds(n));
    high_resolution_clock::time_point clock_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(clock_end - clock_start);
    cout<<endl<<dequeue(&queue_wait)<<" task1 done\n"<<endl;
    std::cout << "Task 1 took " << time_span.count() << " seconds."<<endl;
}

void pause_s2(int n) // pauses the thread until service time is over
{
    high_resolution_clock::time_point clock_start = high_resolution_clock::now();
    std::cout<<endl << "pause of s2\n " << n<<endl;
    std::this_thread::sleep_for (std::chrono::seconds(n));
    high_resolution_clock::time_point clock_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(clock_end - clock_start);
    cout<<endl<<dequeue(&queue_wait)<<" task2 done\n"<<endl;
    std::cout << "Task 2 took " << time_span.count() << " seconds."<<endl;

}




int main()
{

    high_resolution_clock::time_point start_c = high_resolution_clock::now();

    srand(time(0));


    for(int i=0; i<30; i++) // fill queue wait w/ tasks
    {

        enqueue(&queue_wait,rand()%30);
        sleep(rand_ex(3));
    }


    std::thread task1;
    std::thread task2;

    while(!empty_queue(queue_wait))
    {

       task1 = std::thread(pause_s1,rand_rang(10,3));
       task1.detach();
       task2 = std::thread(pause_s2,rand_rang(10,3));
       task2.detach();
       std::this_thread::sleep_for(chrono::seconds(11));
    }

    high_resolution_clock::time_point end_c = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_c - start_c);

    cout << "============================\n============================\nTasks done\nThey took " << time_span.count() << " seconds.";

    return 0;
}
