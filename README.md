# Film-and-Series-Library
This project is a C++ application designed to manage and search a database of movies and series. It was developed by Dénes Péter István for the Programozás alapjai 2 course.
+1

## Project Goals
The program is designed to store various media types and provide a robust search interface. It tracks essential metadata including:

Title, length, and release year.

Original language and category (genre).

Availability and age ratings.

Specific details for documentaries (short descriptions).

Specific details for series (seasons, episode counts, and completion dates).

## Technical Architecture
### Base Class: Tartalom (Content)

The core of the system is an abstract base class that represents a general media object.

Data Members: Includes title, genre, language, type, age rating, release date, and duration.

Linked List: Utilizes a pointer (*Tartalom kov) to the next item for dynamic storage.

Abstract Methods: Defines mandatory functions for printing (kiir, kiir_reszletes) and saving to files (elment).
+2

### Derived Classes

sorozat (Series): Manages season/episode counts and tracks if a show is ongoing or finished.
+1

minisorozat (Miniseries): A specialized version of a series focusing on a specific number of episodes.
+1

jatekfilm (Feature Film): Represents standard cinematic movies.

dokumentumfilm (Documentary): Extends the base class with a leiras (description) field.
+1

### Utility Classes

Ido (Time): Handles hours and minutes, including operator overloading for input and output.
+2

Datum (Date): Handles year, month, and day values with custom formatting.
+2

## User Documentation
### Main Menu

Upon launching the program, the user is presented with several options:

Összes listázása: List all stored content.

Filmek listázása: Filter and display only movies.

Sorozatok listázása: Filter and display only series.

Részletes listázás: Display all data, including descriptions and episode breakdowns.
+1

Kategória szerinti listázás: Filter content by a specific genre.

Keresés: Search for a specific title to view its full data.
+1

Kilépés: Exit the program.

### Data Formats

The program outputs data in a structured block format. For example, a Játékfilm entry appears as:

Cím: [Title] 

Műfaj: [Genre] 

Megjelenés: [YYYY-MM-DD] 

Időtartam: [H:M]
