#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <unistd.h> // for sleep
#include <mutex>    // for mutex
#include <condition_variable> // for condition_variable

using namespace std;
using namespace std::chrono;

typedef struct
{
    vector<int> arr;
    int front, rear;
    int size, max_size;
    mutex mtx;  // Mutex for thread synchronization
    condition_variable cv;  // Condition variable for waiting
} Queue;

Queue init_queue(int max_size)
{
    Queue new_queue;
    new_queue.arr.resize(max_size);
    new_queue.max_size = max_size;
    new_queue.rear = 0;
    new_queue.front = 0;
    new_queue.size = 0;
    return new_queue;
}

bool empty_queue(Queue& q)
{
    lock_guard<mutex> lock(q.mtx);
    return q.size == 0;
}

bool over_queue(Queue& q)
{
    lock_guard<mutex> lock(q.mtx);
    return q.size == q.max_size;
}

void enqueue(Queue& q, int val)
{
    unique_lock<mutex> lock(q.mtx);
    q.cv.wait(lock, [&q] { return q.size < q.max_size; });

    q.arr[q.rear] = val;
    q.rear = (q.rear + 1) % q.max_size;
    q.size++;
    lock.unlock();
    q.cv.notify_all();
}

int dequeue(Queue& q)
{
    unique_lock<mutex> lock(q.mtx);
    q.cv.wait(lock, [&q] { return q.size > 0; });

    int temp = q.arr[q.front];
    q.front = (q.front + 1) % q.max_size;
    q.size--;
    lock.unlock();
    q.cv.notify_all();
    return temp;
}

int rand_rang(int max, int min)
{
    return (min + rand() % (max + 1 - min));
}

double rand_ex(double lambda)
{
    float x = (float)rand() / ((float)RAND_MAX + 1.0);
    double res = -(log(1 - x) / log(10)) / lambda;
    return res;
}

struct Task
{
    int arrival;
    int service_time;
    int id;
};

Queue queue_wait = init_queue(30);

void pause_s(int n, int task_id, const string& task_name)
{
    high_resolution_clock::time_point clock_start = high_resolution_clock::now();
    cout << endl << "Pause of " << task_name << "\n" << n << endl;
    this_thread::sleep_for(chrono::seconds(n));
    high_resolution_clock::time_point clock_end = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(clock_end - clock_start);
    cout << endl << task_id << " " << task_name << " done\n" << endl;
    cout << task_name << " took " << time_span.count() << " seconds." << endl;
}

int main()
{
    high_resolution_clock::time_point start_c = high_resolution_clock::now();
    srand(time(0));

    for (int i = 0; i < 30; i++) // Fill queue wait with tasks
    {
        enqueue(queue_wait, rand() % 30);
        sleep(rand_ex(3));
    }

    while (!empty_queue(queue_wait))
    {
        int service_time_1 = rand_rang(10, 3);
        int service_time_2 = rand_rang(10, 3);
        int task_id_1 = dequeue(queue_wait);
        int task_id_2 = dequeue(queue_wait);

        thread task1(pause_s, service_time_1, task_id_1, "Task 1");
        thread task2(pause_s, service_time_2, task_id_2, "Task 2");

        task1.detach();
        task2.detach();

        this_thread::sleep_for(chrono::seconds(11));
    }

    high_resolution_clock::time_point end_c = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_c - start_c);

    cout << "============================\n============================\nTasks done\nThey took " << time_span.count() << " seconds." << endl;

    return 0;
}
