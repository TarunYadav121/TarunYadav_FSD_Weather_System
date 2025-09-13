Weather Data Storage System
Overview

This project implements a Weather Data Storage System in C++ using a 2D array (vector of vectors). It allows users to store, retrieve, and manage temperature data for multiple cities over a range of years (2000–2025). The program demonstrates row-major and column-major data access and uses NaN to represent missing data.

Features

Insert a Record

Store a temperature for a specific city and year.

Example: Insert 30°C for Delhi in 2024.

Delete a Record

Remove temperature data for a city in a given year.

Retrieve a Record

Display temperature data for a specific city and year.

If no data exists, a message is shown.

Display Row-Major

Iterates through years first, then cities.

Shows all available data row by row.

Display Column-Major

Iterates through cities first, then years.

Shows all available data city by city.

Missing Data Handling

Missing or empty data is represented using NaN.

Only valid temperature records are printed.

Supported Cities

Delhi

Mumbai

Kolkata

Chennai

You can modify the city list in the code.

Year Range

2000 to 2025 (inclusive)

Total of 26 years

Data outside this range cannot be inserted or retrieved.

Installation & Compilation

Ensure you have a C++ compiler (G++ recommended).

Clone or download the project.

Compile the program:

g++ main.cpp -o weather_data


Run the program:

./weather_data   # Linux/macOS
weather_data.exe # Windows

Usage

Upon running, you will see a menu:

Weather Data Storage System
1. Insert a record
2. Delete a record
3. Retrieve a record
4. Display data (Row-Major)
5. Display data (Column-Major)
6. Exit


Choose an option by entering a number (1–6).

Enter year, city, and temperature as prompted.

For retrieval or deletion, input the city and year.

Example Insert Flow:

Enter year: 2024
Enter city: Delhi
Enter temperature: 30
Record inserted successfully.

Notes

The program is case-insensitive for city names.

Only one record per city per year is stored.

Row-major and column-major outputs are the same in content but differ in traversal order.

License

This project is free to use for educational purposes.



Student Details:
Name : Tarun Yadav
Roll No. : 2401350015
University: K.R. Mangalam University
Course: Btech CSE (FULL STACK DEVELOPMENT)
Subject : Data Structure And Algorothms
Course Code: ENCS205 / ENCA 201