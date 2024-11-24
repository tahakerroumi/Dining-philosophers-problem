# Dining Philosophers Problem

## Overview

This project addresses the **Dining Philosophers Problem**, a classic synchronization challenge in concurrent programming. The problem demonstrates the complexities of managing shared resources (in this case, forks) among multiple threads (philosophers) without causing deadlocks or starvation.

## About the Solution

I implemented the solution in **C**, using the following key concepts:

- **Threads**: To simulate philosophers as concurrent processes.
- **Mutexes**: To manage access to shared resources safely and prevent race conditions.
- **Asymmetric Locking (Numbered Forks)**: A strategy to prevent deadlocks by ensuring consistent lock acquisition order.

This project not only solved the synchronization issue but also deepened my understanding of **multithreading** and **concurrent programming**. 

## What I Learned

While working on this problem, I gained hands-on experience with:

- **Thread management**:
  - Creating and joining threads using `pthread_create` and `pthread_join`.
  - Using thread-specific data structures for efficient communication.
- **Synchronization primitives**:
  - Initializing and using **mutexes** (`pthread_mutex_init`, `pthread_mutex_lock`, and `pthread_mutex_unlock`).
  - Preventing race conditions while optimizing for performance.
- **Deadlock prevention**:
  - Understanding conditions that lead to deadlocks.
  - Implementing algorithms like **Asymmetric Locking** to prevent them.
- **Concurrency challenges**:
  - Dealing with shared data and minimizing contention.
  - Testing and debugging concurrent code.
- **Problem-solving under constraints**:
  - Designing a solution with minimal resource usage.
  - Balancing fairness and efficiency among threads.

## How It Works

1. **Simulation**: Philosophers eat, sleep and think in cycles.
2. **Fork Management**: Each philosopher must pick up two forks (mutexes) to eat, but they pick them up in a predefined order to avoid deadlocks.
3. **Concurrency**: Multiple philosophers operate concurrently, but the use of mutexes ensures they do not interfere with each other.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/dining-philosophers.git
   cd dining-philosophers
   cd philo
2. Compile the program using make
   ```bash
   make
3. run the program
   ```bash
   ./philo [number of philosophers] [time to die] [eating time] [sleeping time] [number of meals (optional)]


