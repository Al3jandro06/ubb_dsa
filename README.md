# ATM Application

A C++ ATM simulation built to demonstrate core data structures and algorithms in a practical context. The project is split into two progressive versions, showcasing the evolution from a basic implementation to a fully generic, feature-rich solution.

---

## Features

- Deposit and withdrawal transactions
- Display full transaction history
- Filter transactions by custom criteria

---

## Data Structures & Algorithms

| Concept | Description |
|---|---|
| **Collection** | Custom container for managing transaction records |
| **Ordered Set** | Maintains sorted, unique transaction entries |
| **Dynamic Programming** | Applied to withdrawal logic for optimal computation |

---

## Repository Structure

```
📁 v1/
   ├── Basic Collection and Ordered Set (non-generic)
   └── Displays transaction history without filtering

📁 v2/
   ├── Generic (template-based) data structures
   └── Extended filtering capabilities with multiple criteria
```

### Progression

- **v1** establishes the foundational data structures and core ATM functionality
- **v2** refactors using C++ templates for reusability and introduces advanced filtering

---

## Tech Stack

- **Language:** C++
- **Key Concepts:** OOP, templates, dynamic programming, ordered data structures

---

## Getting Started

```bash
# Clone the repository
git clone https://github.com/<your-username>/<repo-name>.git

# Navigate to the desired version
cd v1   # or v2

# Compile
g++ -o atm main.cpp

# Run
./atm
```

---
