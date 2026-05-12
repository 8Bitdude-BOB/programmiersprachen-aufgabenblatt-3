#ifndef BUW_STACK_HPP
#define BUW_STACK_HPP

// Ein #ifndef ... #define ... #endif verhindert, dass die Datei mehrfach eingebunden wird
// Das nennt sich "Include Guard"

#include <vector>
// Wir nutzen std::vector zum Speichern der Elemente

#include <stdexcept>
// Für Exception-Handling (std::underflow_error)


// TEMPLATE-KLASSENDEFINITION


// template <typename T> bedeutet:
// "Das folgende ist ein Template für jeden Typ T"
// Beispiel: Stack<int>, Stack<string>, Stack<float> funktionieren alle
template <typename T>
class Stack
{
public:

    // KONSTRUKTOR


    // Stack() = default;
    // Der Standard-Konstruktor macht hier nichts Besonderes
    // Das = default bedeutet: "Benutze den automatisch generierten Konstruktor"
    // Der automatisch generierte Konstruktor erzeugt einen leeren vector
    Stack() = default;


    // METHODE: push (etwas oben auf den Stack legen)


    // void push(T const& value);
    // Parameter:
    //   - T const&     : Eine konstante Referenz auf ein Element vom Typ T
    //                    (Referenz = kein Kopieren, const = nicht ändern)
    //   - value        : Das Element, das wir hinzufügen wollen
    // Rückgabewert: void (nichts zurück)
    // 
    // Was macht diese Methode?
    // Sie fügt ein neues Element oben auf den Stack hinzu
    void push(T const& value)
    {
        // data_.push_back(value);
        // push_back() ist eine vector-Methode, die ein Element am ENDE anfügt
        // Da wir push_back() für unser "oben" verwenden, ist das Ende = die Spitze
        data_.push_back(value);
    }


    // METHODE: pop (das oberste Element entfernen)
 

    // void pop();
    // Parameter: keine
    // Rückgabewert: void (nichts zurück - das ist absichtlich!)
    //
    // Was macht diese Methode?
    // Sie entfernt das oberste Element (das zuletzt hinzugefügte)
    // WICHTIG: Sie gibt das Element NICHT zurück!
    // Wenn du das Element brauchst, rufe vorher top() auf!
    //
    // Design-Grund: Wenn pop() einen Wert zurückgäbe, könntest du nicht sehen,
    // ob die Rückgabe 0 ist (echtes Element) oder ob der Stack leer war
    void pop()
    {
        // Sicherheitscheck: Stack darf nicht leer sein!
        if (empty()) {
            // Wenn Stack leer ist, werfe einen Fehler (Exception)
            // Das Programm kann diesen Fehler dann abfangen und behandeln
            throw std::underflow_error("Stack ist leer! pop() geht nicht.");
        }

        // data_.pop_back();
        // pop_back() ist eine vector-Methode, die das LETZTE Element entfernt
        // Das ist genau das Element, das wir oben auf unserem Stack haben
        data_.pop_back();
    }


    // METHODE: top (schaue auf das oberste Element, ohne es zu entfernen)


    // T top() const;
    // Parameter: keine
    // Rückgabewert: T (ein Element vom Typ T)
    // const: Diese Methode ändert nichts am Stack!
    //
    // Was macht diese Methode?
    // Sie gibt das oberste Element zurück, entfernt es aber NICHT
    // Das ist praktisch, wenn du sehen willst, was oben liegt, ohne es zu entfernen
    T top() const
    {
        // Sicherheitscheck: Stack darf nicht leer sein!
        if (empty()) {
            // Wenn Stack leer ist, werfe einen Fehler
            throw std::underflow_error("Stack ist leer! top() geht nicht.");
        }

        // return data_.back();
        // back() ist eine vector-Methode, die das LETZTE Element ZURÜCKGIBT
        // (ohne es zu entfernen)
        return data_.back();
    }

 
    // METHODE: empty (ist der Stack leer?)


    // bool empty() const;
    // Parameter: keine
    // Rückgabewert: bool (true = ja, Stack ist leer; false = nein, hat Elemente)
    // const: Diese Methode ändert nichts am Stack!
    //
    // Was macht diese Methode?
    // Sie prüft, ob der Stack leer ist
    bool empty() const
    {
        // return data_.empty();
        // empty() ist eine vector-Methode, die true zurückgibt, wenn der vector leer ist
        return data_.empty();
    }


    // METHODE: size (wie viele Elemente sind auf dem Stack?)


    // std::size_t size() const;
    // Parameter: keine
    // Rückgabewert: std::size_t (eine ganze Zahl >= 0, die eine Größe angibt)
    // const: Diese Methode ändert nichts am Stack!
    //
    // Was macht diese Methode?
    // Sie gibt an, wie viele Elemente gerade auf dem Stack sind
    std::size_t size() const
    {
        // return data_.size();
        // size() ist eine vector-Methode, die die Anzahl der Elemente zurückgibt
        return data_.size();
    }


    // PRIVATE DATEN (Nur für die Klasse sichtbar)


private:
    // std::vector<T> data_;
    // Der private Member data_ speichert alle Stack-Elemente
    // 
    // Typ: std::vector<T>
    //   - std::vector = eine dynamische Liste (kann wachsen und schrumpfen)
    //   - <T> = sie speichert Elemente vom Typ T
    //
    // Name: data_
    //   - data_ bedeutet: "Das ist die Datenvariable" (der Unterstrich zeigt: private)
    //
    // Warum vector?
    // - push_back() : O(1) durchschnittliche Zeit
    // - pop_back()  : O(1) Zeit
    // - back()      : O(1) Zeit
    // Das ist perfekt für einen Stack!
    std::vector<T> data_;
};


#endif // BUW_STACK_HPP
