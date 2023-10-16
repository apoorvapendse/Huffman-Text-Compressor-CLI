# Huffman Text Compression Utility

This GitHub repository contains a command-line utility that demonstrates the Huffman compression algorithm for text compression. The utility allows you to compress text files using the Huffman coding technique. It is compatible with both Windows and Unix-like environments.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Compilation](#compilation)
- [Usage](#usage)

## Introduction

Huffman coding is a variable-length prefix coding algorithm used for lossless data compression. It assigns shorter binary codes to more frequent characters in the text, resulting in efficient compression. This utility provides a simple example of Huffman coding for text compression.

## Getting Started

### Prerequisites

To compile and use this utility, you'll need the following:

- C++ compiler (e.g., g++) for Unix-like systems or MinGW for Windows.
- A Windows or Unix-like environment.

### Compilation

#### For Unix-like Systems (e.g., Linux, macOS)

To compile the `main.cpp` file using `g++`, follow these steps:

1. Clone or download this repository to your local machine:

   ```bash
   git clone https://github.com/apoorvapendse/ITC6-Text-Compressor.git
   ```

2. Navigate to the project directory:

   ```bash
   cd huffman-compression
   ```

3. Compile the `main.cpp` file using `g++`:

   ```bash
   g++ main.cpp -o huffman
   ```

   This command will create an executable file named `huffman`.

#### For Windows

To compile the `main.cpp` file on Windows using MinGW, follow these steps:

1. **Install a C++ Compiler**:

   If you don't already have a C++ compiler installed on your Windows machine, you can use MinGW, which provides a Windows port of GCC (GNU Compiler Collection). You can download MinGW from [here](http://www.mingw.org/).

2. **Add MinGW to System Path**:

   After installing MinGW, add its `bin` directory to your system's PATH environment variable. This will allow you to use `g++` from the command prompt. To do this, you can follow these steps:
    - Right-click on "This PC" or "My Computer."
    - Select "Properties."
    - Click on "Advanced system settings."
    - Click on "Environment Variables."
    - In the "System Variables" section, scroll down to find "Path" and click "Edit."
    - Add the path to your MinGW `bin` directory (e.g., `C:\MinGW\bin`).

3. **Open a Command Prompt**:

   Open a command prompt or PowerShell window to compile and use the utility.

4. **Compile the `main.cpp` File**:

   In the command prompt, navigate to the project directory where `main.cpp` is located and compile it using the installed `g++` (MinGW). The command will look like this:

   ```bash
   g++ main.cpp -o huffman
   ```

   This will create an executable file named `huffman.exe`.

## Usage

Once you have compiled the utility, you can use it to compress text files using Huffman coding. To compress a text file, follow these steps:

1. Make sure you are in the project directory.

2. To compress a text file, run the `huffman` utility, passing the file name of the text you want to compress as a command-line argument. For example, if you have a file named `sample.txt`:

   ```bash
   huffman sample.txt
   ```

   The utility will compress the `sample.txt` file and display the output on your terminal window.

Please note that this utility is a simple demonstration and may not be suitable for compressing large or binary files. It is intended for educational purposes to illustrate the Huffman coding algorithm for text compression.

