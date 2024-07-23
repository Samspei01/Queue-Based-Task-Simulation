# Queue-based task processing system using multithreading

## Project Documentation

**Contributors:**  
Fares Fathy  
Abdulrahman Saeed

**Course:**  
Algorithms & Data Structures

---
# Queue-Based Task Simulation

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

## Usage

1. Compile the program:
    ```bash
    g++ -std=c++11 -pthread -o task_simulation task_simulation.cpp
    ```

2. Run the program:
    ```bash
    ./task_simulation
    ```

## Output

The program will output the task processing details and the total time taken to complete all tasks.

## Note
- The program uses `pthread` for multithreading support.

For further questions, please contact me at ffathy2004@gmail.com.
