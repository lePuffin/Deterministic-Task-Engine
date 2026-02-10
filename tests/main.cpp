/**
 * @file: main.cpp
 * @brief: Test runner entry point
 * @details: Main function for the CppUTest unit test framework that discovers and executes
 *           all registered test cases.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/
// Public

/**
 * @brief Main entry point for the test suite
 * @param argc Command line argument count
 * @param argv Command line arguments
 * @return Exit code from CppUTest framework (0 on success, non-zero on failure)
 * @details Initializes and runs all registered CppUTest test cases discovered
 *          during compilation and returns the overall test result status.
 */
int main(int argc, const char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

// Private

// End of file
