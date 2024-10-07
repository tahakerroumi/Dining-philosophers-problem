## Dining Philosophers

# - Project Overview
    This project tackles the Dining Philosophers problem, a classic exercise in concurrency and synchronization, using threads and mutexes for the mandatory part, and processes and semaphores for the bonus part. It helps develop skills in multithreading, process management, and handling race conditions.

# - Problem Description
- Philosophers sit around a table, alternating between eating, thinking, and sleeping.
- To eat, each philosopher needs two forks (one on the left, one on the right).
- If a philosopher doesn’t eat within a certain time, they starve and the simulation ends.
- The challenge is to manage resource sharing (forks) without deadlock or starvation.

# - Mandatory Part
- Implemented with threads and mutexes.
- Each philosopher is a thread and forks are shared resources, protected by mutexes.
- Input: number of philosophers, time limits (to eat, sleep, or die), and an optional stop condition (number of meals).

# Bonus Part
- Implemented with processes and semaphores.
- Philosophers are processes, and the number of available forks is controlled by a semaphore.
