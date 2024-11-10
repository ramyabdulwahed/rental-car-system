# rental-car-system
A C program that manages a car rental company's inventory using linked lists.


## Features
- Manage car rentals with linked lists for different statuses (available, rented, in-repair).
- Calculate rental charges based on mileage.
- Save and load data to/from files to maintain persistence.
- Evaluate postfix expressions using a stack data structure.

## Skills & Concepts Learned
- Linked Lists: Dynamic data management, sorted insertion, and list manipulation.
- File I/O in C: Reading and writing data to files for persistence.
- Stack Data Structures: Building and manipulating stacks for evaluating postfix expressions.
- Makefile Usage: Automating the compilation process with makefiles.


## Car Rental Program

### Linked Lists
- **Available for rent** (sorted by mileage, least to greatest)
- **Rented** (sorted by expected return date, earliest first)
- **In repair**

### Transactions
The program will prompt the user to input a transaction code, and based on the code, it will perform the respective action. The transaction codes are:

- `1` - Add a new car to the available list (prompt for plate number and mileage).
- `2` - Add a returned car to the available list (prompt for plate number and mileage).
- `3` - Add a returned car to the repair list (prompt for plate number and mileage).
- `4` - Transfer a car from repair to available list (prompt for plate number).
- `5` - Rent the first available car (prompt for expected return date in yymmdd format).
- `6` - Print all lists (no additional prompt needed).
- `7` - Quit the program.

### Rental Charges
For each car that is returned (transaction 2 or 3), the following charges are applied:
- A **flat rate of $80.00** for up to 200 km.
- **15 cents per km** for each additional km over 200.

### Program Quit
When the user selects the quit option (`7`), the program must **store the data** from all the lists into a file. The next time the program starts, it should read the data from this file and restore the lists.

### Initial Setup
- When the program runs for the first time, it should load data from initial txt files that contain at least 5 cars in each list (available, rented, and in repair).

### Files
Part 1 consists of 6 files, as follows:

1. **q1.c**: Contains the `main()` function, which controls the flow of the program.
2. **q1.h**: Contains the structure definitions and function prototypes.
3. **q1_functions.c**: Contains all the function implementations that are called by the `main()` function.
4. **available.txt**: Contains a list of all cars available for rent.
5. **rented.txt**: Contains a list of all cars that have been rented.
6. **repair.txt**: Contains a list of all cars that are currently under repair.

### Compiling the Program
To compile and run the program, follow these steps:

1. In the directory where the files are saved, type:
	make 
This will compile all necessary files into an executable.

2. To run the program, type:
./a2q1


## Reverse Polish Notation (RPN) 

- `+` (Addition)
- `-` (Subtraction)
- `*` (Multiplication)
- `/` (Division)

### Reverse Polish Notation (RPN) 
In RPN, operators appear **after** their operands. For example:
- The expression `1 2+` is equivalent to `1+2`.
- The expression `1 2 + 5 3 - *` is equivalent to `(1+2) *(5-3)`.

### Files
Part 2 consists of 3 files, as follows:

1. **q2.c**: Contains the `main()` function, which handles input parsing and initiates the expression evaluation process.
2. **q2.h**: Contains structure definitions and function prototypes for managing the stack and evaluating the postfix expressions.
3. **q2_functions.c**: Contains the function implementations for stack operations and evaluates the postfix expression.

### Operations
- implemented a **stack** data structure to store operands as you evaluate the expression.
- Operands are pushed onto the stack, and when an operator is encountered, the corresponding number of operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.


### Program Execution
The program should:
1. Take the postfix expression as a **command-line argument** with no spaces between the characters.
   - Example: `./a2q2 12+53-*`
   - In this example, `q2` is the name of the executable and `12+53-*` is the postfix expression.
2. **Evaluate** the postfix expression using stacks.
3. **Print** the result with exactly **two decimal places**.

### Compiling the Program
To compile and run the program for this program, follow these steps:

1. In the directory where the files are saved, type:
	make 
This will compile all necessary files into an executable.

2. To run the program, type:
./a2q2 <expression>


### File Structure
- **q1.c**: Contains the main program for (car rental program).
- **q2.c**: Contains the main program (RPN evaluator).
- **q1.h** and **q2.h**: Header files containing structure definitions and function prototypes for each program.
- **q1_functions.c** and **q2_functions.c**: Contain the implementation of functions used in each program.
- **makefile**: This should compile both programs and generate two executable files (such as `a2q1` and `a2q2`).


