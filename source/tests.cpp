#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>
#include <string>
#include "math_templates.hpp"

int factorial(int n)
{
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

TEST_CASE("factorial computes n!")
{
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(10) == 3628800);
}

TEST_CASE("square mit int")
{
    // square(3): Compiler erkennt den Typ automatisch (type deduction)
    auto r = square(3);
    CHECK(r == 9);

    // square<int>(3): Typ wird explizit angegeben, Ergebnis ist identisch.
    // Explizite Angabe ist nuetzlich wenn der Typ nicht eindeutig erkennbar waere.
    int s = square<int>(3);
    CHECK(s == 9);
}

TEST_CASE("square mit double")
{
    CHECK(square(3.5) == doctest::Approx(12.25));
}

TEST_CASE("add mit int")
{
    CHECK(add(5, 3) == 8);
}

TEST_CASE("add mit double")
{
    CHECK(add(1.5, 2.5) == doctest::Approx(4.0));
}

TEST_CASE("add mit std::string")
{
    // Funktioniert ohne Aenderung, weil std::string den + Operator ueberlaedt.
    // Das Template ruft einfach a + b auf - fuer strings bedeutet das Konkatenation.
    CHECK(add(std::string("Hello"), std::string(" World")) == "Hello World");
}

int main(int argc, char* argv[])
{
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    return ctx.run();
}