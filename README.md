# CALC — Turbo C 7 Calculator Project

A modular calculator project developed for **Turbo C 7 / DOSBox** using the Borland Graphics Interface (BGI).

---

## 📁 Project Structure

```text
Project/
│
├── CALC.C          # Main program
├── MSK.C           # Common utility function implementations
├── TEMP.C          # Temperature conversion functions
├── BASE.C          # Base conversion functions
└── MSK.H           # Shared headers, macros and function declarations
```

### File Responsibilities

* **`CALC.C`** — Main program and calculator UI.
* **`MSK.C`** — Common graphics/UI helper function implementations such as `fill()`, `re()` and `txt()`.
* **`TEMP.C`** — Temperature conversion module.
* **`BASE.C`** — Binary, octal, decimal and hexadecimal conversion module.
* **`MSK.H`** — Common library includes, macros, constants and function declarations.

> **Important:** `.C` source files are compiled as separate project source files. Do **not** include `TEMP.C`, `BASE.C` or `MSK.C` directly inside `CALC.C`.

---

# 1. Clone the Project

Clone or download the project repository to your computer.

After cloning, make sure the project contains:

```text
CALC.C
MSK.C
TEMP.C
BASE.C
MSK.H
```

---

# 2. Set Up Directory in Turbo C

1. Move/copy the cloned project folder into your Turbo C directory, for example:

   ```text
   C:\TC\BIN\
   ```

   or into your designated DOSBox-mounted drive.

2. Open **Turbo C**.

3. Go to:

   ```text
   File → Change Dir
   ```

4. Select the project directory.

---

# 3. Set Up the Turbo C Project

The project contains multiple `.C` source files:

```text
CALC.C
MSK.C
TEMP.C
BASE.C
```

and one header file:

```text
MSK.H
```

The `.C` files should be compiled as **separate source files**.

## Important

Do **not** write this in `CALC.C`:

```c
#include "TEMP.C"
#include "BASE.C"
#include "MSK.C"
```

Instead, use:

```c
#include "MSK.H"
```

when the declarations and macros from the header are required.

The `.C` files should be added separately to the Turbo C project.

---

# 4. Open `CALC.C`

Go to:

```text
File → Open
```

and select:

```text
CALC.C
```

`CALC.C` is the main source file of the application.

> **Note:** `CALC.C` is the main source file, but `MSK.C`, `TEMP.C`, and `BASE.C` must also be added to the Turbo C project so they are compiled and linked with the main program.

---

# 5. Configure `MSK.H`

`MSK.H` contains the common library includes, macros, constants and function declarations.

It uses an include guard:

```c
#ifndef MSK
#define MSK

/* headers */
/* macros */
/* constants */
/* function declarations */

#endif
```

The include guard prevents the contents of `MSK.H` from being processed multiple times within the same compilation unit.

## Function Declarations

Functions such as:

```c
void fill(int left, int up, int right, int down, int patt, int color);

void re(int left, int up, int right, int down, int color);

void txt(int X, int Y, int color, int font, int dir, int size, char text[]);
```

should be declared in `MSK.H`.

Their implementations should be placed in `MSK.C`.

---

# 6. Configure `MSK.C`

`MSK.C` contains the implementations of the common utility functions declared in `MSK.H`.

For example:

```c
#include "MSK.H"

void fill(int left, int up, int right, int down, int patt, int color)
{
    setfillstyle(patt, color);
    bar(left, up, right, down);
}

void re(int left, int up, int right, int down, int color)
{
    setcolor(color);
    rectangle(left, up, right, down);
}

void txt(int X, int Y, int color, int font, int dir, int size, char text[])
{
    setcolor(color);
    settextstyle(font, dir, size);
    outtextxy(X, Y, text);
}
```

This keeps function implementations out of the header file.

---

# 7. Configure `BASE.C`

The base conversion module contains the base-selection and conversion functions.

The module includes functions such as:

```c
void selectbase();

void enterbase(
    int val,
    char str1[],
    char str2[],
    char str3[],
    char str4[],
    int val1
);

void btoany(char cha[]);

void otoany(char cha[]);

void dtoany(char cha[]);

void hextoany(char cha[]);
```

The module supports conversion between:

* Binary
* Octal
* Decimal
* Hexadecimal

The conversion functions produce the corresponding converted results for display.

---

# 8. Configure `TEMP.C`

`TEMP.C` contains the temperature conversion functionality used by the calculator.

The temperature converter supports:

* Kelvin
* Celsius
* Fahrenheit
* Reaumur

The implementation remains in `TEMP.C` and should be compiled as a separate source file.

---

# 9. Enable Graphics Library (Required)

The project uses the **Borland Graphics Interface (BGI)**.

Before compiling, ensure that the graphics library is enabled.

In Turbo C, go to:

```text
Options → Linker → Libraries
```

Make sure:

```text
Graphics Library
```

is enabled.

---

# 10. Configure the BGI Path

The `initgraph()` call in `CALC.C` must point to the location of the BGI driver files.

A typical Turbo C installation uses:

```c
initgraph(&gd, &gm, "C:\\TC\\BGI");
```

If your Turbo C installation is located somewhere else, change the path accordingly.

For example:

```c
initgraph(&gd, &gm, "D:\\TC\\BGI");
```

Use the actual path available inside your DOSBox environment.

---

# 11. Add All Source Files to the Project

Make sure the Turbo C project contains:

```text
CALC.C
MSK.C
TEMP.C
BASE.C
```

The header file is:

```text
MSK.H
```

The basic relationship is:

```text
              MSK.H
             /  |  \
            /   |   \
           ↓    ↓    ↓
       CALC.C  MSK.C  TEMP.C
                    \
                     \
                    BASE.C
```

More simply:

```text
.H → declarations/macros
.C → implementations
```

Do **not** treat `.C` files as header files.

---

# 12. Compile the Project

After adding all source files to the project:

## Compile

Use:

```text
Compile → Compile
```

to compile the currently selected source file.

## Build All

Use:

```text
Compile → Build All
```

to rebuild all source files in the project.

### Recommended

After changing `MSK.H`, use:

```text
Compile → Build All
```

because multiple source files may depend on the header.

---

# 13. Run the Program

After successfully building the project:

```text
Ctrl + F9
```

can be used to build and run the program.

If Turbo C reports linker errors such as:

```text
Undefined symbol
```

check that the `.C` file containing the required function has been added to the project.

---

# 14. Common Error: Multiple Declaration

If Turbo C reports errors such as:

```text
Multiple declaration for 'fill'
Multiple declaration for 're'
Multiple declaration for 'txt'
```

check whether `.C` files are being included directly.

## Incorrect

```c
#include "MSK.H"
#include "TEMP.C"
#include "BASE.C"
```

## Correct

```c
#include "MSK.H"
```

Then add the source files separately to the Turbo C project:

```text
CALC.C
MSK.C
TEMP.C
BASE.C
```

---

# 15. Header vs Source File

The important difference is:

## Header File

```text
MSK.H
```

Contains:

```c
void fill(...);
void re(...);
void txt(...);
```

These are **declarations**.

## Source File

```text
MSK.C
```

Contains:

```c
void fill(...)
{
    ...
}

void re(...)
{
    ...
}

void txt(...)
{
    ...
}
```

These are the **implementations**.

This structure prevents the same function implementation from being compiled repeatedly through multiple source-file inclusions.

---

# 💡 Features

## Default Calculator

* Evaluates multi-digit arithmetic expressions.
* Supports operator precedence.
* Supports parentheses.
* Uses an infix-expression evaluation approach.

## Temperature Converter

Supports conversion between:

* Kelvin
* Celsius
* Fahrenheit
* Reaumur

## Base Converter

Supports conversion between:

* Binary
* Octal
* Decimal
* Hexadecimal

The base-conversion module contains functions for selecting a base, accepting input and converting binary, octal, decimal and hexadecimal values. 

## Matrix Calculator

**Work in Progress**

* Matrix operations UI frame is integrated.
* Matrix calculation routines are currently not implemented.
* Matrix calculation functionality will be added in a future version.

---

# 🛠️ Technologies Used

* **Language:** C
* **IDE:** Turbo C 7
* **Runtime Environment:** DOSBox
* **Graphics:** Borland Graphics Interface (BGI)
* **Compiler:** Turbo C Compiler

---

# ⚠️ Important Turbo C Notes

## 1. Use DOS-Compatible Paths

Turbo C / DOSBox uses DOS-style paths.

Example:

```text
C:\TC\BGI
```

Inside a C string, use:

```c
"C:\\TC\\BGI"
```

---

## 2. Keep Source Files Separate

Use:

```text
CALC.C
MSK.C
TEMP.C
BASE.C
```

as separate source files.

Do **not** merge them by writing:

```c
#include "TEMP.C"
#include "BASE.C"
```

---

## 3. Use the Header for Shared Declarations

Use:

```c
#include "MSK.H"
```

when a source file needs the declarations or macros provided by the header.

---

## 4. Rebuild After Changing the Header

If you modify:

```text
MSK.H
```

use:

```text
Compile → Build All
```

so that all affected source files are rebuilt.

---

# 📋 Quick Setup Checklist

Before running the project, verify:

* [ ] Turbo C 7 is installed/configured in DOSBox.
* [ ] The project directory is accessible from DOSBox.
* [ ] `CALC.C` exists.
* [ ] `MSK.C` exists.
* [ ] `TEMP.C` exists.
* [ ] `BASE.C` exists.
* [ ] `MSK.H` exists.
* [ ] All `.C` source files are added to the Turbo C project.
* [ ] `.C` files are **not** included using `#include`.
* [ ] `MSK.H` uses an include guard.
* [ ] Graphics Library is enabled.
* [ ] The `initgraph()` BGI path is correct.
* [ ] The project builds successfully.
* [ ] `Ctrl + F9` runs the application.

---

# 🚀 Running the Project

The basic workflow is:

```text
Open DOSBox
    ↓
Mount Turbo C directory
    ↓
Open Turbo C 7
    ↓
Change directory to the project
    ↓
Open CALC.C
    ↓
Make sure all .C files are added to the project
    ↓
Build All
    ↓
Ctrl + F9
    ↓
Run Calculator
```

---

# 📌 Development Status

| Module                      | Status              |
| --------------------------- | ------------------- |
| Default Calculator          | ✅ Implemented       |
| Temperature Converter       | ✅ Implemented       |
| Base Converter              | ✅ Implemented       |
| Matrix Calculator UI        | 🚧 Work in Progress |
| Matrix Calculation Routines | ⏳ Coming Soon       |

---

# 📄 License

Add the project's license information here if applicable.
