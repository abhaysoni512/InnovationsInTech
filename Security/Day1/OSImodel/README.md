# OSI Model Demo (C++)

This folder contains a small CLI program that represents all 7 OSI layers and simulates **encapsulation** (sender) and **decapsulation** (receiver).

## Build

From the repo root:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic Security/Day1/OSImodel/osi_model.cpp -o osi_model
```

## Run

```bash
./osi_model
```

Choose:
- `1` to print OSI layers (name, function, examples)
- `2` to type a message and watch it move through the stack
