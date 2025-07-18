# FILE--HANDLING--PROGRAM

*COMPANY* : CODTECH IT SOULUTIONS

*NAME* : BHUMIKA

*INERN ID* : CT08K876

*DURATION* : 4 WEEKS

*MENTOR* : NEELA SANTOSH


File Input/Output (I/O) Operations
----------------------------------------------------
This program, encapsulated within a single C file (file_io_example.c), serves as a fundamental demonstration of how C applications interact with a computer's file system. It covers the core operations necessary for managing text-based data in files: creation, writing, appending, and reading. Understanding these operations is paramount for any program that needs to persist data beyond its runtime, such as saving user preferences, logging events, or managing configuration files. The program uses standard C library functions from <stdio.h> for file handling and <stdlib.h> for general utilities.

Logic:
-------
The program is structured around three distinct functions, each dedicated to a specific file operation, orchestrated by the main function.

1 . createAndWriteFile(const char *filename):
---------------------------------------------------
This function initiates the file interaction. It opens a specified file using fopen(filename, "w"). The "w" mode is critical here: if the file (codtech_task1.txt in this case) does not exist, it is created. If the file does exist, its entire content is truncated and overwritten. This means any previous data in codtech_task1.txt would be lost.

A robust check if (fp == NULL) immediately follows the fopen call. This is crucial for error handling. If fopen returns NULL, it indicates that the file could not be opened or created (e.g., due to invalid path, lack of write permissions, or disk full conditions). In such a scenario, an error message is printed to the console, and the function exits, preventing attempts to write to a non-existent file pointer, which would lead to a crash.

Upon successful file opening, fprintf(fp, "This is the initial content written to the file.\n"); is used to write a formatted string into the file pointed to by fp. fprintf is similar to printf but writes to a file stream instead of the standard output.

Finally, fclose(fp); is called to close the file stream. This is an extremely important step; it flushes any buffered data to the disk, releases the file handle, and prevents resource leaks. Failure to close files can lead to data corruption, lost data, or even prevent other programs from accessing the file. A success message is then printed.

2. appendToFile(const char *filename):
---------------------------------------------------
This function demonstrates how to add data to an existing file without destroying its current content. It opens the file using fopen(filename, "a"). The "a" mode stands for append. If the file doesn't exist, it's created, just like with "w". However, if it exists, fopen positions the file pointer at the very end of the existing data.

Similar to createAndWriteFile, it includes error checking (if (fp == NULL)) to handle scenarios where the file cannot be opened for appending (e.g., due to permissions).

fprintf(fp, "This is the appended content.\n"); writes the new string to the end of the file.

fclose(fp); ensures the file is properly closed, and a confirmation message is displayed.

3. readFile(const char *filename):
---------------------------------------------------
This function is responsible for retrieving and displaying the content of the file. It opens the file using fopen(filename, "r"). The "r" mode signifies read-only access. If the file does not exist, fopen will return NULL, leading to an "Error reading file!" message, as there's no content to read.

After successful opening, the program enters a while loop: while ((ch = fgetc(fp)) != EOF). fgetc(fp) reads a single character from the file stream fp and assigns it to ch. The loop continues as long as the character read is not EOF (End-Of-File), which is a special macro indicating that the end of the file has been reached.

Inside the loop, putchar(ch); prints each character to the console. This effectively copies the file's content to standard output.

Finally, fclose(fp); closes the file, and the function concludes.

Execution:
---------------------------------------------------------------
The main function is the entry point, executing the file operations in a specific sequence:

const char *filename = "codtech_task1.txt";: Defines the target file name.

createAndWriteFile(filename);: This call creates (or overwrites) codtech_task1.txt and writes "This is the initial content written to the file.\n". At this point, the file contains only this line.

appendToFile(filename);: This call opens the existing codtech_task1.txt and adds "This is the appended content.\n" to its end. The file now contains two lines.

readFile(filename);: This call opens the codtech_task1.txt and reads its entire content, printing both the initial and appended lines to the console.

This sequential execution clearly demonstrates the impact of each file operation mode ("w", "a", "r") on the file's content.

Expected Output:
---------------------------------------------------------------------
File created and written successfully.
Content appended successfully.
File contents:
This is the initial content written to the file.
This is the appended content.

OUTPUT
--------

<img width="1918" height="1075" alt="Image" src="https://github.com/user-attachments/assets/978dc80f-ca08-4e97-b376-e3a24768e7f9" />




