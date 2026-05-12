
// #define DOCTEST_CONFIG_IMPLEMENT: Sagt doctest, dass main() in dieser Datei ist
#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>
#include <string>
#include "math_templates.hpp"
#include "stack.hpp"


// HILFSFUNKTION: factorial (Fakultät)


// factorial(n) berechnet n! = n × (n-1) × (n-2) × ... × 1
// Beispiel: 5! = 5 × 4 × 3 × 2 × 1 = 120
int factorial(int n)
{
    int result = 1;
    // Multipliziere alle Zahlen von 2 bis n
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


// TESTS FÜR FACTORIAL


TEST_CASE("factorial computes n!")
{
    // factorial(n) = n! (Fakultät)
    // Fakultät bedeutet: n! = n × (n-1) × (n-2) × ... × 1

    CHECK(factorial(0) == 1);        // 0! = 1 (Definition in Mathematik)
    CHECK(factorial(1) == 1);        // 1! = 1
    CHECK(factorial(5) == 120);      // 5! = 5×4×3×2×1 = 120
    CHECK(factorial(10) == 3628800); // 10! = 10×9×8×7×6×5×4×3×2×1 = 3628800
}


// TESTS FÜR MATH-TEMPLATES: square()


TEST_CASE("square mit int")
{
    // square(3): Compiler erkennt den Typ automatisch (type deduction)
    // Der Compiler sieht: "Du gibst int rein, also T=int"
    auto r = square(3);
    CHECK(r == 9);

    // square<int>(3): Typ wird EXPLIZIT angegeben
    // Das ist die gleiche Sache, aber wir sagen dem Compiler deutlich "T=int"
    // Explizite Angabe ist nützlich wenn der Typ nicht eindeutig erkennbar wäre.
    int s = square<int>(3);
    CHECK(s == 9);
}

TEST_CASE("square mit double")
{
    // square(3.5): Compiler deduciert T=double
    // 3.5 × 3.5 = 12.25
    // doctest::Approx() wird verwendet, weil Fließkommazahlen wegen 
    // Rundungsfehlern nicht exakt gleich sein können
    CHECK(square(3.5) == doctest::Approx(12.25));
}

// TESTS FÜR MATH-TEMPLATES: add()


TEST_CASE("add mit int")
{
    // add(5, 3): Compiler deduciert T=int
    // Beide Parameter sind int, also T=int
    CHECK(add(5, 3) == 8);
}

TEST_CASE("add mit double")
{
    // add(1.5, 2.5): Compiler deduciert T=double
    // 1.5 + 2.5 = 4.0
    CHECK(add(1.5, 2.5) == doctest::Approx(4.0));
}

TEST_CASE("add mit std::string")
{
    // add(std::string(...), std::string(...)): Compiler deduciert T=std::string
    // Funktioniert ohne Änderung, weil std::string den + Operator überlädt.
    // Das Template ruft einfach a + b auf
    // Für strings bedeutet + Konkatenation (Zusammenhängen)
    CHECK(add(std::string("Hello"), std::string(" World")) == "Hello World");
}


// TESTS FÜR STACK<int> (Ganzzahlen)


TEST_CASE("Stack<int> - Neu erstellter Stack ist leer")
{
    // ARRANGE: Erzeuge einen leeren Stack
    Stack<int> stack;

    // ASSERT: Prüfe Anfangszustand
    // Ein neu erzeugter Stack sollte leer sein und Größe 0 haben
    CHECK(stack.empty() == true);
    CHECK(stack.size() == 0);
}

TEST_CASE("Stack<int> - push() fügt Elemente hinzu")
{
    // ARRANGE
    Stack<int> stack;

    // ACT: Füge das erste Element hinzu
    stack.push(42);

    // ASSERT: Nach push() sollte size() größer werden
    CHECK(stack.size() == 1);
    CHECK(stack.empty() == false);

    // ACT: Füge ein zweites Element hinzu
    stack.push(17);
    CHECK(stack.size() == 2);

    // ACT: Füge ein drittes Element hinzu
    stack.push(99);
    CHECK(stack.size() == 3);
}

TEST_CASE("Stack<int> - top() gibt das oberste Element zurück")
{
    // ARRANGE: Stack mit mehreren Elementen
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);    // 30 ist das oberste Element (zuletzt eingefügt!)

    // ACT: Hole das oberste Element
    int top_val = stack.top();

    // ASSERT: Das oberste sollte 30 sein (zuletzt hinzugefügt!)
    CHECK(top_val == 30);

    // WICHTIG: top() entfernt das Element NICHT!
    // Die Größe sollte noch immer 3 sein
    CHECK(stack.size() == 3);
}

TEST_CASE("Stack<int> - top() ändert sich mit push()")
{
    // ARRANGE
    Stack<int> stack;

    // ACT: Füge das erste Element hinzu
    stack.push(100);

    // ASSERT: Jetzt ist 100 oben
    CHECK(stack.top() == 100);

    // ACT: Füge ein neues Element hinzu
    stack.push(200);

    // ASSERT: Jetzt ist 200 oben (das neueste!)
    CHECK(stack.top() == 200);

    // Das zeigt das LIFO-Prinzip: das neueste Element ist immer oben
}

TEST_CASE("Stack<int> - pop() entfernt das oberste Element")
{
    // ARRANGE: Stack mit Elementen
    Stack<int> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // ASSERT: Vorher
    CHECK(stack.top() == 15);
    CHECK(stack.size() == 3);

    // ACT: Entferne das oberste Element (15)
    stack.pop();

    // ASSERT: Nachher - 10 ist jetzt oben und size() ist kleiner
    CHECK(stack.top() == 10);
    CHECK(stack.size() == 2);

    // ACT: Entferne noch ein Element (10)
    stack.pop();

    // ASSERT
    CHECK(stack.top() == 5);
    CHECK(stack.size() == 1);
}

TEST_CASE("Stack<int> - LIFO-Verhalten (Last In, First Out)")
{
    // ARRANGE: Erzeuge einen Stack
    Stack<int> stack;

    // ACT: Füge Elemente in dieser Reihenfolge hinzu: 1, 2, 3, 4, 5
    // (5 ist das oberste Element)
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }

    // ASSERT & ACT: Entferne alle Elemente
    // Sie sollten in UMGEKEHRTER Reihenfolge entfernt werden! (LIFO)
    // Zuerst 5, dann 4, dann 3, dann 2, dann 1

    CHECK(stack.top() == 5);  // zuletzt eingefügt!
    stack.pop();

    CHECK(stack.top() == 4);
    stack.pop();

    CHECK(stack.top() == 3);
    stack.pop();

    CHECK(stack.top() == 2);
    stack.pop();

    CHECK(stack.top() == 1);
    stack.pop();

    // FINAL: Stack sollte jetzt leer sein
    CHECK(stack.empty() == true);
}

TEST_CASE("Stack<int> - Exception bei top() auf leerem Stack")
{
    // ARRANGE: Erzeuge einen leeren Stack
    Stack<int> stack;

    // ACT & ASSERT: Versuche top() auf einem leeren Stack
    // CHECK_THROWS(...) prüft, dass eine Exception geworfen wird
    // Das ist sicher, weil die Exception abgefangen wird
    CHECK_THROWS(stack.top());
}

TEST_CASE("Stack<int> - Exception bei pop() auf leerem Stack")
{
    // ARRANGE: Erzeuge einen leeren Stack
    Stack<int> stack;

    // ACT & ASSERT: Versuche pop() auf einem leeren Stack
    // Das sollte eine Exception werfen
    CHECK_THROWS(stack.pop());
}


// TESTS FÜR STACK<std::string> (Text)


TEST_CASE("Stack<std::string> - Neu erstellter Stack ist leer")
{
    // ARRANGE
    Stack<std::string> stack;

    // ASSERT
    CHECK(stack.empty() == true);
    CHECK(stack.size() == 0);
}

TEST_CASE("Stack<std::string> - push() und top() mit Strings")
{
    // ARRANGE
    Stack<std::string> stack;

    // ACT & ASSERT: Füge "hello" hinzu
    stack.push("hello");
    CHECK(stack.top() == "hello");
    CHECK(stack.size() == 1);

    // ACT & ASSERT: Füge "world" hinzu
    stack.push("world");
    CHECK(stack.top() == "world");  // "world" ist jetzt oben (zuletzt eingefügt)
    CHECK(stack.size() == 2);
}

TEST_CASE("Stack<std::string> - LIFO mit Strings")
{
    // ARRANGE
    Stack<std::string> stack;

    // ACT: Füge Strings hinzu
    stack.push("alpha");
    stack.push("beta");
    stack.push("gamma");

    // ASSERT & ACT: Entferne in umgekehrter Reihenfolge
    // Das zeigt das LIFO-Prinzip mit Strings
    CHECK(stack.top() == "gamma");   // zuletzt eingefügt
    stack.pop();

    CHECK(stack.top() == "beta");    // jetzt oben
    stack.pop();

    CHECK(stack.top() == "alpha");   // jetzt oben
    stack.pop();

    // ASSERT: Stack sollte leer sein
    CHECK(stack.empty() == true);
}

TEST_CASE("Stack<std::string> - Längere Strings")
{
    // ARRANGE
    Stack<std::string> stack;
    std::string long_text = "Dies ist ein längerer Text mit mehreren Wörtern";

    // ACT: Füge einen längeren String hinzu
    stack.push(long_text);

    // ASSERT
    CHECK(stack.top() == long_text);
    CHECK(stack.size() == 1);

    // ACT: Entferne ihn
    stack.pop();

    // ASSERT
    CHECK(stack.empty() == true);
}


// TESTS FÜR STACK<float> (Fließkommazahlen)


TEST_CASE("Stack<float> - Neu erstellter Stack ist leer")
{
    // ARRANGE
    Stack<float> stack;

    // ASSERT
    CHECK(stack.empty() == true);
    CHECK(stack.size() == 0);
}

TEST_CASE("Stack<float> - push() und top() mit Floats")
{
    // ARRANGE
    Stack<float> stack;

    // ACT & ASSERT: Füge 3.14 hinzu
    stack.push(3.14f);
    // doctest::Approx() wird verwendet, weil Fließkommazahlen
    // wegen Rundungsfehlern nicht exakt gleich sein können
    CHECK(stack.top() == doctest::Approx(3.14f));

    // ACT & ASSERT: Füge 2.71 hinzu
    stack.push(2.71f);
    CHECK(stack.top() == doctest::Approx(2.71f));

    // ACT & ASSERT: Füge 1.41 hinzu
    stack.push(1.41f);
    CHECK(stack.top() == doctest::Approx(1.41f));
}

TEST_CASE("Stack<float> - pop() verringert die Größe korrekt")
{
    // ARRANGE
    Stack<float> stack;

    // ACT: Füge drei Elemente hinzu
    stack.push(1.5f);
    stack.push(2.5f);
    stack.push(3.5f);

    // ASSERT: Größe ist 3
    CHECK(stack.size() == 3);

    // ACT & ASSERT: Entferne Elemente und prüfe die Größe
    stack.pop();
    CHECK(stack.size() == 2);

    stack.pop();
    CHECK(stack.size() == 1);

    stack.pop();
    CHECK(stack.size() == 0);
}

TEST_CASE("Stack<float> - LIFO-Verhalten mit Floats")
{
    // ARRANGE
    Stack<float> stack;

    // ACT: Füge vier Floats hinzu
    stack.push(1.1f);
    stack.push(2.2f);
    stack.push(3.3f);
    stack.push(4.4f);

    // ASSERT & ACT: Prüfe LIFO-Reihenfolge
    CHECK(stack.top() == doctest::Approx(4.4f));  // zuletzt eingefügt
    stack.pop();

    CHECK(stack.top() == doctest::Approx(3.3f));
    stack.pop();

    CHECK(stack.top() == doctest::Approx(2.2f));
    stack.pop();

    CHECK(stack.top() == doctest::Approx(1.1f));
    stack.pop();

    // ASSERT: Stack sollte jetzt leer sein
    CHECK(stack.empty() == true);
}

TEST_CASE("Stack<float> - Negative und positive Werte")
{
    // ARRANGE
    Stack<float> stack;

    // ACT: Füge negative, Null und positive Werte hinzu
    stack.push(-5.5f);   // negativ
    stack.push(0.0f);    // null
    stack.push(5.5f);    // positiv

    // ASSERT: Prüfe in korrekter Reihenfolge (LIFO)
    CHECK(stack.top() == doctest::Approx(5.5f));
    stack.pop();

    CHECK(stack.top() == doctest::Approx(0.0f));
    stack.pop();

    CHECK(stack.top() == doctest::Approx(-5.5f));
}

// MAIN FUNCTION


// main() - Das wird von doctest aufgerufen
// argc und argv sind die Kommandozeilenargumente
int main(int argc, char* argv[])
{
    // doctest::Context: Das Test-Framework
    doctest::Context ctx;

    // applyCommandLine(): Verarbeite Kommandozeilenargumente
    // Damit kannst du z.B. nur bestimmte Tests ausführen
    // Beispiel: ./test --filter=factorial  (nur factorial-Tests)
    ctx.applyCommandLine(argc, argv);

    // run(): Führe alle Tests aus
    // Gibt die Anzahl fehlgeschlagener Tests zurück
    // (0 = alles erfolgreich, >0 = Fehler)
    return ctx.run();
}
