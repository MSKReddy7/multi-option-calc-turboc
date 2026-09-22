Here is the updated **`README.md`** content with a note about the matrix feature coming soon:

```markdown
# Multi-Option Calculator (Turbo C)

A feature-packed desktop utility built for **Turbo C / DOSBox** featuring an **Infix Expression Calculator**, **Temperature Converter**, **Base Converter**, and **Matrix Calculator**.

---

## 🚀 How to Run the Project

Follow these steps to set up, compile, and run the program:

### 1. Clone the Repository
Open your terminal or command prompt and clone the repository:
```bash
git clone [https://github.com/MSKReddy7/multi-option-calc-turboc.git](https://github.com/MSKReddy7/multi-option-calc-turboc.git)

```

### 2. Set Up Directory in Turbo C

1. Move/copy the cloned project folder into your Turbo C directory (e.g., `C:\TC\BIN\` or your designated DOSBox mounted drive).
2. Open **Turbo C**.
3. Change your working directory to the project folder (`File` $\rightarrow$ `Change dir`).

### 3. Open `CALC.C`

Go to **File** $\rightarrow$ **Open** and select **`CALC.C`**.

> **Note:** You **only** need to open `CALC.C`. Do **not** open or compile `TEMP.C`, `BASE.C`, or `MSK.H` separately—`CALC.C` automatically includes all necessary module files and headers.

### 4. Enable Graphics Library (Required)

Before compiling, ensure the BGI graphics driver is linked:

1. In Turbo C, go to **Options** $\rightarrow$ **Linker** $\rightarrow$ **Libraries**.
2. Make sure **Graphics library** is checked/enabled.
3. Ensure your `initgraph` path in `CALC.C` matches your local BGI folder path (default: `C:\TC\BGI`).

### 5. Compile and Run

* Press **Ctrl + F9** to compile and run the program directly.

---

## 💡 Features

* **Default Calculator:** Evaluates multi-digit arithmetic expressions using operator precedence and parentheses support (Infix algorithm).
* **Temperature Converter:** Converts temperatures between Kelvin, Celsius, Fahrenheit, and Reaumur.
* **Base Converter:** Supports conversion across Binary, Octal, Decimal, and Hexadecimal.
* **Matrix Calculator:** *(Work in Progress)* Full matrix operations UI frame is integrated, but calculation routines are currently not implemented—coming soon!

