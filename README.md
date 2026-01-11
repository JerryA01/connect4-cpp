# Connect 4 in C++

---

## Project Overview

This is a **C++ implementation of the classic Connect 4 game**, enhanced with two unique features that add strategic depth to gameplay:

1. **Remove a Row** – Players can remove all counters from a single row. This can clear the path for future moves or disrupt an opponent’s strategy.
2. **Remove a Counter** – Players can remove a single counter from the board, allowing them to block a winning move or create a new opportunity.

These mechanics introduce a **new layer of strategy and unpredictability**, encouraging players to think dynamically and adapt to sudden changes during play. Limitations (such as using the abilities only once per game or under specific conditions) are implemented to maintain **balance and fairness**.

---

## Object-Oriented Design

This project is implemented using **object-oriented programming (OOP)** principles:

- **Classes** represent key game entities, such as `Board`, `Player`, `HumanPlayer`, and `Game`.
- **Encapsulation** is used to hide board data and player state, exposing only relevant methods.
- **Inheritance** allows `HumanPlayer` to extend the abstract `Player` class.
- **Polymorphism** is used to allow different player types to implement `makeMove` differently.
- The modular design makes the code **extensible and maintainable**, demonstrating good OOP practice.

---

## Features

- Standard Connect 4 gameplay
- Turn-based play between two players (human or AI)
- Dynamic board manipulation through:
  - Row removal
  - Single counter removal
- Board state printed to the console after each move
- Win detection for vertical, horizontal, and diagonal connections

---

## How to Compile and Run

1. Clone the repository:

```bash
git clone https://github.com/JerryA01/tic-tac-toe-cpp.git
cd tic-tac-toe-cpp
