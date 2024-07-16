# Employee Management System
#### Video Demo: https://youtu.be/GttP9gi0zug
#### Description:
The Employee Management System is a command-line application developed in C that helps manage employee records efficiently. This project was created as part of the CS50x final project, demonstrating skills in data structures, file handling, and command-line interface design.

## Features
- **Add Employee**: Add new employee records with details such as ID, name, age, and department.
- **View Employees**: Display a list of all employees currently in the system.
- **Search Employee**: Search for an employee by ID to view their details.
- **Update Employee**: Modify details of an existing employee.
- **Delete Employee**: Remove an employee record from the system.
- **Save to File**: Save all employee records to a file for persistent storage.
- **Load from File**: Load employee records from a file to resume work.

## Files
- **main.c**: The main file that contains the implementation of the Employee Management System.
- **employee.h**: Header file containing the structure definitions and function prototypes.
- **employee.c**: Implementation of the functions declared in employee.h.
- **data.txt**: A file used to store employee records persistently.

## Design Choices
- **Data Structures**: Used arrays to store employee records for simplicity and efficient indexing.
- **File Handling**: Implemented file I/O operations to allow data persistence between program runs.
- **User Interface**: Designed a command-line interface to interact with the system using simple text commands.

## How to Run
1. Compile the code using a C compiler, e.g., `gcc main.c employee.c -o employee_management`.
2. Run the executable: `./employee_management`.
3. Follow the on-screen instructions to manage employee records.

## Future Improvements
- Implement a database to manage a large number of employee records more efficiently.
- Add a graphical user interface (GUI) for better user experience.
- Enhance security features such as password protection for accessing the system.

## Author
- **Name**: Maryam Kordestani
- **GitHub Username**: kordestani79
- **edX Username**: maryamkordestani
- **City, Country**: Kermanshah, Iran
- **Date**: July 16, 2024
