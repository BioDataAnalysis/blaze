

# Set the minimum required cmake version:
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8 FATAL_ERROR)


# Set project information
PROJECT(Blaze)


# Find the boost library:
FIND_PACKAGE(Boost 1.54.0 COMPONENTS thread system REQUIRED)

# Find a BLAS library. See https://cmake.org/cmake/help/v3.0/module/FindBLAS.html
# NOTE: BLA_VENDOR is a variable to set checks only the specified vendor. If not
#       set, checks all the possibilities
FIND_PACKAGE(BLAS)

# Find the LAPACK library
FIND_PACKAGE(LAPACK)

INSTALL(DIRECTORY blaze DESTINATION include)
