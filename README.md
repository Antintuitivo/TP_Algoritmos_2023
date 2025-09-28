#Purpose and Scope
This document provides an overview of a C++ console-based language learning application designed for interactive alphabet learning, educational word games, and text analysis. The system supports multiple languages (Spanish, English, French, Italian, and Portuguese) with specialized character handling for accented letters and diacritics.

The application serves as an educational platform featuring:

- Interactive alphabet display systems for five languages
- Educational word games including hangman (ahorcado), memory games, and word ciphers
- Text processing and statistical analysis capabilities
- User authentication and data persistence
- Console-based user interface with Windows API integration

##System Architecture Overview
The application follows a modular architecture centered around a main menu system that provides access to distinct functional modules. The system is implemented as a single-threaded console application with file-based data persistence.

##Core Components
###Application Entry Point
The system initializes through the main() function which orchestrates the startup sequence including loading screen (pantallaCarga()), welcome screen (bienvenida()), user authentication (login()), and main menu navigation (menuPrincipal()).

###Language Learning System
Five distinct alphabet modules handle language-specific character sets:

- ABCespaniol() - Spanish alphabet with ñ and accented vowels
- ABCingles() - English alphabet (no special characters)
- ABCfrances() - French alphabet with extensive diacritics
- ABCitaliano() - Italian alphabet with accented vowels
- ABCportugues() - Portuguese alphabet with ç and accented vowels
Each module uses the show() function for display and esRepetido() for input validation.

###Games and Interactive Features
Educational games provide interactive language practice:

- ahorcado() - Hangman game with word guessing
- palabraCifrada() - Word cipher puzzle game
- memoria() - Memory-based learning exercises
- numerosOtroIdioma() - Number recognition in different languages
Games integrate with the text processing system through functions like descubrir() for revealing letters and mostrarLetrasIngresadas() for tracking user input.

###Text Processing Engine
The text analysis system processes documents and word lists through:

- extraerPalabrasDeArchivo() - Extracts words from text files
- contarCaracteres() - Character frequency analysis
- menuEstadisticasPalabras() - Word statistics and analysis
- Linked list implementation (ListasEnlazadas) for word storage

###User Management
Authentication system manages user accounts through:

- login() - User authentication function
- Usuarios.txt - Text-based user data source
- Usuarios.bin - Binary user database
- ConvertirtxtaBin.cpp - User data conversion utility

##Technology Stack

###Component           -      Implementation
Language            -	   C++11/C++17 with Standard Library
Console Interface   -    Windows Console API (windows.h)
String Handling     -    std::string and C-style character arrays
File I/O            -    Standard C++ streams and C file operations
Data Structures     -    Custom linked lists (Nodo structure)
Memory Management   -    Stack-based allocation with RAII patterns
Build System        -    MinGW GCC compiler toolchain
The system utilizes Windows-specific APIs for console manipulation including GetStdHandle(), SetConsoleTextAttribute() for text coloring, and system() calls for screen clearing. Character encoding support handles extended ASCII for international characters.

##Navigation and Control Flow
The application implements a hierarchical menu system where menuPrincipal() serves as the central hub directing users to four main functional areas:

- Alphabet Learning (menuAbecedarios()) - Access to language modules
- Educational Games (menuJuegos()) - Interactive learning activities
- Text Processing (menuProcesadorTexto()) - Document analysis tools
- Statistics (menuEstadisticasPalabras()) - Word analysis and reporting
Each module maintains its own navigation loop with input validation through esUnDigito() and error handling via alertaDeError(). The salir() function provides consistent exit functionality across all modules.


https://app.devin.ai/wiki/Antintuitivo/TP_Algoritmos_2023
