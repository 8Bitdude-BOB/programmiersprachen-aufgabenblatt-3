#include <iostream>   // Für std::cout
#include <vector>     // Für std::vector
#include <random>     // Für Zufallszahlen
#include <numeric>    // Für std::accumulate

int main()
{
    // Erstellt eine echte Zufallsquelle vom Betriebssystem
    std::random_device rd;

    // Mersenne-Twister-Zufallsgenerator
    // Wird mit rd() initialisiert
    std::mt19937 generator{ rd() };

    // Definiert den Zahlenbereich:
    // Zahlen von 0 bis 99
    // (100 ist exklusiv)
    std::uniform_int_distribution<unsigned int> distribution{ 0, 99 };

    // Vector für unsere Zahlen
    std::vector<unsigned int> numbers;

    // Reserviert Speicher für 300 Elemente
    // Dadurch muss der Vector später seltener wachsen
    numbers.reserve(300);

    // Schleife läuft 300-mal
    for (std::size_t i{ 0 }; i < 300; ++i)
    {
        // Erzeugt eine Zufallszahl
        // und fügt sie in den Vector ein
        numbers.push_back(distribution(generator));
    }

    // Gibt alle Zahlen aus
    for (const auto number : numbers)
    {
        std::cout << number << '\n';
    }

    // Berechnet die Summe aller Zahlen
    //
    // begin()  -> Start des Vectors
    // end()    -> Ende des Vectors
    // 0u       -> Startwert der Summe als unsigned int
    const auto sum =
        std::accumulate(numbers.begin(), numbers.end(), 0u);

    // Berechnet den Durchschnitt
    //
    // static_cast<double>
    // verhindert Ganzzahldivision
    const auto average =
        static_cast<double>(sum) / numbers.size();

    // Ausgabe der Summe
    std::cout << "\nSumme: " << sum << '\n';

    // Ausgabe des Durchschnitts
    std::cout << "Arithmetischer Mittelwert: "
        << average << '\n';
}