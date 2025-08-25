# C Data Structures

This project is a **utility library** of common data structures in C that I use across my C projects.  
The main purpose is **code reuse** keeping implementations of reusable data structures in one place.

It also contains **test cases** to ensure each data structure works correctly before being used in other projects.

A `Makefile` is provided for easy compilation and building.

## 📂 Project Structure

```
c-data-structures/
├── build/ # Build output (auto-generated)
├── include/ # Header files (.h)
│ └── dynamic_array.h
│
├── src/ # Implementation files (.c)
│ └── dynamic_array.c
│
├── main.c # Program entry point
├── Makefile # Build configuration
└── README.md

```

## Build & Run

### Prerequisites
- GCC (or Clang)
- GNU Make (or `mingw32-make` on Windows with MinGW/MSYS2)

### Build
```bash
make
````

This compiles all `.c` files in `src/` plus `main.c` into a single executable inside the `build/` folder.

### Run

```bash
./build/program
```

(On Windows, it will be `./build/program.exe`)

### Clean build files

```bash
make clean
```

---

## Adding New Data Structures

1. Add your `.h` file to `include/`.
2. Add your `.c` implementation to `src/`.
3. Include the header in `main.c` or any other file where you want to use it.
4. Run `make` again — no changes needed in the Makefile.

---

## Example Output

If you run the included dynamic array example:

```
Initial array: 10 20 30
After set: 10 99 30
After pop: 10 99
```

---

## 📌 Notes

- Error handling is done using `fprintf` + `exit` for invalid operations.
- The project is kept simple for learning purposes feel free to extend it.
