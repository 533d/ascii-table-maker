# ascii-table-maker
This project is a tool written in C++ that converts input data (represented in a character-separated format) into a structured ASCII table.

## Usage

Create a file (e.g., input.txt) and input the table data like the following example:

|test|test2|test3|
|A|B||

Run the program, redirecting the file as input. In the terminal, use the following command:

```bash
cat input.txt | ./ascii-table-maker
```

The program will generate and display the following formatted ASCII table:

+------+-------+-------+
| test | test2 | test3 |
+------+-------+-------+
|  A   |       B       |
+------+-------+-------+
