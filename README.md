# CO222: Programming Methodology

## Project 1: QR Code Generator - Specification
## Introduction

Given a URL you have to encode it to a QR (Quick Response) Code (According to the given
algorithm) and print it on the Linux terminal. You will be given a sample program that would do
the same task. Your task is to replicate the functionality of the given program.
**_The output should print exactly at the same place and scale as the given sample
program._**
Please note that all the algorithms which are given are made up algorithms, you cannot reverse
the QR to the string by the existing QR scanners.

## Inputs:

**User inputs:**
● You should get the URL as a user input through STDIN (this string should be greater
than 3 characters and less than 120 characters)
**Command-line arguments:**
● If a colour is given as an argument to the program with the ‘-c’ flag, the program should
be able to print the QR code using the given colour. If no argument is given use black
and white as default.

![](Images/QR1.png)



Eg: ./program -c red
Given the above arguments, the program should print the QR code in red and white.

![](Images/QR2.png)

These colors should be supported by the program - black, red, green, yellow, blue,
magenta, cyan
● If -h flag is given or the given arguments are invalid, you should print the usages of your
program (how the arguments should be given). See the sample binary given for the
expected behaviour.

## Output:

Print the relevant QR code in the terminal. Consider the length of the string and choose to which
version the string should be encoded. If the input string is less than or equal 20 characters it
should be encoded to the smaller version as in the 2nd figure and if the number of characters of
the input string is more than 20 it should be encoded to the larger version as in 1st figure.


## String Hashing algorithm

To encode a string to QR code, first, you need to hash the string and convert it to a fixed-length
string. For the smaller QR version (Input string length less than or equal 20) you need to hash
the string to 24 characters and for the larger version(Input string greater than 20) you need to
hash the string to 132 characters. Follow the below steps to get the hashed string.
The ASCII value of the first character of the hashed string = Length of the input string + 50
(which is used for decoding purposes).
Assume the length of the input string is L. Then, the next L characters of the hashed string
should be the characters of the input string. To fill the remaining characters (this part of the
string is used for error detection), add 1 to the ASCII values of characters in the input string and
append them to the string until you reach the required length. Do this by incrementing the
number you are adding by 1 in each round until all the required number of characters is
obtained. Then reverse the error detection part of the hashed string.
Observe the given example:
Input string: ABCDEFGH
First character = 50 + 8


## QR generation algorithm

Each QR Code has 3 Position identification squares (6x6 unit squares) in 3 corners. They
should be drawn in the pattern given below:
The remaining area is for character encoding, which is divided into small squares. (of size 3x
unit squares each).
Each small square represents one character of the hashed string. Figures below represent
which character should be encoded within each square in the 2 different versions.
The QR has a white border(of width 1 unit square) for clarity, observe the outputs of the sample
program and implement the exact same thing. Considering scale position and color.


● The small version - for string length 20 or less (First get the hashed string of length 24)
● The larger version - for string length above 20 (first obtain the hashed string of length
132)


After finding the relevant character of the square, to encode it you should get the ASCII value of
the character and then get the binary representation using 9 bits. Then colour each unit square
of the 3x3 square according to the value of the corresponding bit. Black if the value is 1 and
white otherwise. (Consider MSB as b1 and LSB as b9)
Eg ‘W’ ASCII value = 87 Binary representation: 001010111
The encoded pattern for W:

## Problem breakdown

Instead of directly going to code the solution, you must break down the problem into smaller
subproblems, such as

1. How to get user input
2. How to hash the string to a fixed-length
3. How to print basic frame and position identification squares
4. How to print the encoded pattern of one character
5. How to print multiple patterns in different positions of the console.
6. How to assign a color when printing
7. Error handling and the argument handling
Instead of thinking about the problem as a whole, try and find the solutions for each one of the
above questions. That will help you to reach the final goal smoothly and accumulatively.

