# C Programming

* `main` method is entry point
* `main` method may or may not accept arg
* `Void` arg mean no arg
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

## Questions
1. For `main` method, is there any restriction for return type?

## References
1. [Pluralsight - C Programming Fundamentals](https://app.pluralsight.com/player?course=c-lang-fundamentals&author=kenny-kerr&name=c-m1-introduction&clip=5&mode=live)