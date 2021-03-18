#ifdef DOCTEST_CONFIG_DISABLE

#include <iostream>

#include "cmake_variables.hpp"

int main()
{
  std::cout << socketcpp_VERSION << std::endl;
  return EXIT_SUCCESS;
}

#else

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#endif
