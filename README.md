# Queue-based task processing system using multithreading

## Project Documentation

**Contributors:**  
Fares Fathy  
Abdulrahman Saeed

**Course:**  
Algorithms & Data Structures

This project simulates a queue-based task processing system using multithreading in C++. The program enqueues tasks with random service times and processes them concurrently using two worker threads.

## Features

- Implementation of a circular queue.
- Enqueuing tasks with random arrival and service times.
- Multithreading to simulate concurrent task processing.
- Calculation and display of the total time taken to process all tasks.

## Code Explanation

### Queue Structure

The `Queue` structure is defined with the following attributes:
- `arr`: Dynamic array to store the queue elements.
- `front`: Index of the front element.
- `rear`: Index of the rear element.
- `size`: Current size of the queue.
- `max_size`: Maximum capacity of the queue.

### Functions

- `init_queue(int max_size)`: Initializes the queue with a specified maximum size.
- `empty_queue(Queue q)`: Checks if the queue is empty.
- `over_queue(Queue q)`: Checks if the queue is full.
- `enqueue(Queue* q, int val)`: Adds an element to the queue.
- `dequeue(Queue* q)`: Removes and returns the front element from the queue.
- `rand_rang(int max, int min)`: Generates a random integer between `min` and `max`.
- `rand_ex(double lambda)`: Generates a random exponentially distributed number with a given lambda using a lambda function.

### Task Simulation

Two functions, `pause_s1(int n)` and `pause_s2(int n)`, simulate task processing by pausing the thread for `n` seconds.

### Main Function

- Initializes the queue.
- Enqueues 30 tasks with random arrival times.
- Creates two threads to process tasks concurrently.
- Displays the total time taken to process all tasks.

## Output

The program will output the task processing details and the total time taken to complete all tasks.
Here's an example of the output:
pause of s1
 3
pause of s2
 6

9 task1 done

Task 1 took 3.00022 seconds.

11 task2 done

Task 2 took 6.00074 seconds.


pause of s1
 5
pause of s2
 8

19 task1 done

Task 1 took 5.01563 seconds.

26 task2 done

Task 2 took 8.00059 seconds.

...

============================
============================
Tasks done
They took 334.123 seconds.

In the previous example:

The output alternates between pause_s1 and pause_s2.
The number after pause of s1 or pause of s2 indicates the random pause duration in seconds.
The task completion messages show which task was done along with its id and the time it took.
The final summary displays the total time taken to process all tasks.

## Note
- The program uses `pthread` for multithreading support.

---

For further questions, please contact us at [ffathy2004@gmail.com](mailto:ffathy2004@gmail.com) or [abdosaaed749@gmail.com](mailto:ffathy2004@gmail.com). 
