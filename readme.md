# C Programming

* `main` method is entry point
* `main` method may or may not accept arg
* `void` arg mean no arg
    ```c
    int main(void)
    ```
* Modern compilers don't need to include `stdio.h` for standard input/output functions like `printf`
* including header files literally mean copying contents of the header file to the program file

## CL Compiler Tips
* `/nologo` switch suppresses the compiler lnfo text.
    ```
    cl .\program.c /nologo
    ```
* `/W4` switch increases the level of diagnostic the compiler will emit
    ```
    cl .\program.c /W4
    ```
* `/TP` switch tells compiler to assume that the code is C++ rather that C. Compiler will give compatibility issues which will be useful is we want to migrate the code to C++ in future.
    ```
    cl .\program.cs /TP
    ```
* `/c` just compile not link
* `/Fe` control output exe file name. Notice no space after switch.
    ```
    cl *.obj /nologo /W4 /FeProgram.exe
    ```

## Compilation Model
* Compiler produces `.obj` file. This is "object code" and is language independent.
* `exe` file is generated by linker by taking all object files and linking them together.

## Function Declaration vs Definition
Declaration is only signature. Definition is with details like initialization of variable and implementation of function.

## Local variable declaration vs definition
definition provides type and space
```c
int apples;
```

## Global variables
Allow variable access to multiple functions
Global variables, if uninitialized, will be auto initialized to 0.

## Static global variables

## Questions
1. For `main` method, is there any restriction for return type?

## References
1. [Pluralsight - C Programming Fundamentals](https://app.pluralsight.com/player?course=c-lang-fundamentals&author=kenny-kerr&name=c-m1-introduction&clip=5&mode=live)