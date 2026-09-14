# Philosophers

A concurrency and synchronization project implemented in **C** as part of the 42 Network curriculum.

The project simulates the **Dining Philosophers Problem**, where multiple philosophers share a limited number of resources and must coordinate their actions while avoiding synchronization problems and starvation.

The main focus of the project is understanding **multithreading, mutexes, synchronization, timing, and concurrent resource management**.

---

## 🧠 Project Overview

Each philosopher repeatedly goes through a cycle of:

```text
Think
  ↓
Take forks
  ↓
Eat
  ↓
Release forks
  ↓
Sleep
  ↓
Think again
```

The simulation must coordinate multiple philosophers running concurrently while respecting the timing constraints provided at execution.

The implementation focuses on:

* POSIX threads
* Mutex synchronization
* Shared resource management
* Concurrent execution
* Precise time measurement
* Philosopher state monitoring
* Input validation
* Graceful termination

---

## 🛠️ Technologies

* **C**
* **POSIX Threads (`pthread`)**
* **Mutexes**
* **Linux / Unix**
* **Make**
* **Standard C libraries**

---

## 📁 Project Structure

```text
philo/
├── include/
│   └── philo.h
│
├── src/
│   ├── main.c
│   │
│   ├── monitor/
│   │   └── monitor.c
│   │
│   ├── routine/
│   │   └── routine.c
│   │
│   └── utils/
│       ├── create_forks.c
│       ├── create_threads.c
│       ├── parsing.c
│       ├── time.c
│       └── utils.c
│
└── Makefile
```

### Architecture

The implementation is organized into several responsibilities:

**`main.c`**

Responsible for initializing and starting the simulation.

**`routine/`**

Contains the main philosopher execution logic and concurrent routines.

**`monitor/`**

Handles monitoring of philosopher states and simulation conditions.

**`utils/create_threads.c`**

Responsible for creating and managing philosopher threads.

**`utils/create_forks.c`**

Handles initialization of the shared fork resources.

**`utils/parsing.c`**

Handles validation and parsing of program arguments.

**`utils/time.c`**

Provides timing utilities used by the simulation.

**`utils/utils.c`**

Contains supporting utility functions shared across the project.

**`include/philo.h`**

Contains the project's shared structures, definitions, and function declarations.

---

## ⚙️ Compilation

Clone the repository and enter the project directory:

```bash
git clone <your-repository-url>
cd philo/philo
```

Compile the project:

```bash
make
```

The Makefile uses compiler flags suitable for development and debugging.

To remove object files:

```bash
make clean
```

To remove all generated files:

```bash
make fclean
```

To rebuild:

```bash
make re
```

---

## ▶️ Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments

| Argument                                    | Description                                                    |
| ------------------------------------------- | -------------------------------------------------------------- |
| `number_of_philosophers`                    | Number of philosophers and forks                               |
| `time_to_die`                               | Maximum time a philosopher can go without eating               |
| `time_to_eat`                               | Time spent eating                                              |
| `time_to_sleep`                             | Time spent sleeping                                            |
| `number_of_times_each_philosopher_must_eat` | Optional number of meals required before ending the simulation |

### Example

```bash
./philo 5 800 200 200
```

With a meal limit:

```bash
./philo 5 800 200 200 7
```

---

## 🔄 Concurrency Model

The simulation uses a thread-based concurrency model where philosophers execute independently while sharing access to fork resources.

The implementation has to carefully coordinate:

* Thread creation
* Fork ownership
* Mutual exclusion
* Philosopher state changes
* Timing
* Monitoring
* Simulation termination

This requires synchronization to prevent multiple threads from accessing the same shared resource incorrectly.

---

## ⏱️ Timing & Monitoring

Timing is a critical part of the simulation.

The program tracks philosopher activity and continuously monitors conditions such as:

* Time since the philosopher's last meal
* Eating duration
* Sleeping duration
* Simulation state
* Termination conditions

The monitoring logic is separated from the philosopher routines to keep responsibilities organized.

---

## 🧵 Synchronization

The project provides practical experience with concurrent programming concepts including:

* Threads
* Mutexes
* Shared state
* Critical sections
* Race-condition prevention
* Resource ownership
* Synchronization
* Concurrent termination

The main challenge is coordinating multiple independent execution flows while maintaining consistent shared state.

---

## 🧪 Development Focus

While implementing the project, I focused on:

* Designing a clear thread-based architecture
* Managing shared resources safely
* Handling timing accurately
* Separating simulation responsibilities into dedicated modules
* Validating program input
* Managing thread and mutex lifecycle
* Debugging concurrent behavior

---

## 🎯 Skills Developed

This project strengthened my understanding of:

* Concurrent programming in C
* POSIX threads
* Mutex synchronization
* Race conditions
* Shared memory and resources
* Thread lifecycle management
* Timing-sensitive programming
* Systems programming
* Debugging concurrent applications
* Modular C project organization

---

## 🎓 Context

This project was completed as part of the **42 Network / 1337 project-based curriculum**.

The project emphasizes practical understanding of concurrency rather than relying on high-level abstractions, requiring the programmer to directly manage threads, synchronization primitives, resources, and timing.

---

## 👤 Author

**Anas Chanek**

Computer Science Student — Software Engineering • Systems • DevOps

[GitHub](https://github.com/Achaneks)
