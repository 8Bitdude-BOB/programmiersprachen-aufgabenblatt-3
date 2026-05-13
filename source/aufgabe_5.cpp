#include <iostream>
#include <array>

// Wann wählt man std::array gegenüber std::vector?
//
// std::array verwendet man, wenn:
// - die Größe zur Compile-Zeit feststeht (keine Änderung möglich)
// - maximale Performance und minimale Overhead wichtig sind
// - keine dynamische Speicherverwaltung benötigt wird
// - der Speicher oft auf dem Stack liegen soll
//
// std::vector verwendet man, wenn:
// - die Größe zur Laufzeit variabel ist
// - Elemente hinzugefügt oder entfernt werden sollen
// - flexible Speicherverwaltung benötigt wird

int main()
{
    // std::array mit fester Größe 10
    std::array<int, 10> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Ausgabe aller Elemente mit range-based for
    for (const auto number : numbers)
    {
        std::cout << number << '\n';
    }
}