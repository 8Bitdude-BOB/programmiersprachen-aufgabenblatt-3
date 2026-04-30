#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest.h>

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

int main(int argc, char* argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
