# Cstring Library (C++)

A custom C++ string library that implements common string manipulation functionality using dynamic character arrays.

This project was created to better understand **manual string handling, dynamic memory management, and operator overloading in C++** without relying on `std::string`.

---

## 🚀 Key Technical Highlights

- **Manual Memory Management:** Implemented dynamic allocation using `new` and `delete[]` to handle strings of any size efficiently.
- **The Rule of Three:** Full implementation of the **Destructor**, **Copy Constructor**, and **Copy Assignment Operator** to ensure deep copying and prevent memory leaks or "double-free" crashes.
- **Operator Overloading:** Designed the class to integrate seamlessly with C++ syntax using `+`, `==`, `=`, and `<<`.
- **Const Correctness:** Adheres to modern C++ standards by using `const` parameters and methods, allowing safe handling of string literals and temporary objects.

---

## 🛠️ Features

### Core Operations
* **Search:** `find(char)` and `find(char*)` to locate characters or substrings.
* **Modification:** `insert()`, `remove()`, and `replace()` (supports char-to-char and string-to-string).
* **Cleaning:** `trim()`, `trimLeft()`, and `trimRight()` to remove whitespace.
* **Slicing:** `left()`, `right()`, and `SubString()` for extracting parts of a string.

### Transformation & Utility
* **Case Control:** `makeUpper()` and `makeLower()`.
* **Ordering:** `reverse()`.
* **Access:** `at(index)` for safe character access and `getLength()` for size tracking.

---

## 📂 Project Structure

- `Cstrings.h`: Header file containing the class definition and method prototypes.
## Function Prototypes

![Function Prototypes](Function.png)
---

- `Cstrings.cpp`: Implementation file containing the logic for the class methods.
- `main.cpp`: A comprehensive test driver that simulates real-world data scenarios.

---



## Implemented Functions

### Constructors
- Default constructor
- Character constructor
- C-string constructor
- Copy constructor
- Destructor

### String Queries
- `getLength()`
- `isEmpty()`
- `CountChar()`
- `find()`

### String Modification
- `insert()`
- `remove()`
- `replace()`
- `Resize()`
- `clear()`

### Transformations
- `makeUpper()`
- `makeLower()`
- `reverse()`
- `trim()`
- `trimLeft()`
- `trimRight()`

### Substring Operations
- `left()`
- `right()`
- `SubString()`

### Concatenation
- `concat()`
- `concatEqual()`

### Operator Overloading
- Assignment operator (`=`)
- Concatenation operator (`+`)
- Equality comparison (`==`)
- Stream output (`<<`)

---

## Example Usage

```cpp
#include "Cstrings.h"
#include <iostream>

int main()
{
    Cstring s1("Hello");
    Cstring s2(" World");

    Cstring result = s1 + s2;

    std::cout << result << std::endl;

    return 0;
}
```

Output:

```
Hello World
```

---

## How to Compile

Using **g++**:

```bash
g++ main.cpp Cstrings.cpp -o program
```

Run the program:

```bash
./program
```

---

## Project Purpose

This project was built as a **learning exercise** to:

- Understand low-level string manipulation
- Practice dynamic memory management in C++
- Implement object-oriented class design
- Explore operator overloading

---

## Future Improvements

Possible improvements for the library include:

- Move constructor and move assignment operator
- Additional comparison operators (`<`, `>`, etc.)
- STL-style functions such as `startsWith()` and `endsWith()`
- Performance optimizations
- Unit testing support

---

## Author

**Zaeem**  
BS Data Science — PUCIT  
C++ • Python • Problem Solving
