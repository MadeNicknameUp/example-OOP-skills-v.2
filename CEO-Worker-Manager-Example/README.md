# CEO-Worker-Manager-Example

This project is an example of an object-oriented C++ program that simulates a hierarchy of employees in a company: CEO, Manager, Worker, and Team. The project demonstrates the use of classes, inheritance, composition, and other OOP principles.

## Project Structure

The project consists of the following files:

- **CEO.h** / **CEO.cpp**: The `CEO` class represents the Chief Executive Officer of the company. The CEO makes decisions that affect the entire company.
- **Manager.h** / **Manager.cpp**: The `Manager` class represents a manager. Managers oversee teams of workers and make decisions based on the CEO's directives.
- **Worker.h** / **Worker.cpp**: The `Worker` class represents a worker. Workers perform tasks assigned by their manager.
- **Team.h** / **Team.cpp**: The `Team` class represents a team of workers. A team consists of multiple workers and is managed by a manager.
- **main.cpp**: The main file of the program, which runs the company simulation.

## How to Build and Run the Project

### Requirements

- A C++ compiler (e.g., `g++` or `clang++`)
- A build system (e.g., `make` or manual compilation via command line)

### Building the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/CEO-Worker-Manager-Example.git
   cd CEO-Worker-Manager-Example```

2. Compile the project:

  g++ -o main main.cpp CEO.cpp Manager.cpp Team.cpp Worker.cpp
  (Alternatively, use make if you have a Makefile)

## Example Output

The program creates a hierarchy of employees, starting with the CEO, who makes decisions. Managers oversee teams of workers, and workers perform tasks. During execution, the program outputs the state of each employee and team.

# Example output:

```
Worker 1 is free
Worker 2 performs task A
Worker 3 is free
Manager 1 made decision: 2
```

## How the Project Works

   **CEO**: The Chief Executive Officer makes decisions that affect the entire company. Decisions are passed down to managers.

   **Manager**: Managers oversee teams of workers and make decisions based on the CEO's directives.

   **Worker**: Workers perform tasks assigned by their manager. Each worker can be either free or busy with a task.

   **Team**: A team consists of multiple workers and is managed by a manager.

## License

**This project is licensed under the MIT License. See the LICENSE file for details.**
