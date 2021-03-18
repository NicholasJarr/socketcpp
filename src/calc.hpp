#ifndef CALC_HPP
#define CALC_HPP

#include <doctest/doctest.h>

int add(int a, int b);

TEST_CASE("add should add two numbers together") {
  CHECK(add(1, 2) == 3);
}

#endif
