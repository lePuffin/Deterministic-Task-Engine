/**
 * @file: TestExample.cpp
 * @brief: Example test suite demonstrating CppUTest framework usage
 * @details: Provides a template example showing test group setup with lifecycle hooks
 *           (setup/teardown) and basic test assertions.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/
// Public

// clang-format off
/**
 * @defgroup FirstTestGroup Example Test Group
 * @brief Demonstrates CppUTest test group with setup and teardown lifecycle hooks
 */
TEST_GROUP(FirstTestGroup){
   /**
    * @brief Setup hook called before each test
    * @details Custom initialization code can be placed here to prepare test fixtures.
    */
   void setup() {
       // Code here will be called immediately before each test
   }
   /**
    * @brief Teardown hook called after each test
    * @details Custom cleanup code can be placed here to release test resources.
    */
   void teardown() {
       // Code here will be called immediately after each test
   }
};
// clang-format on

/**
 * @test FirstTestGroup::FirstTest
 * @brief Basic example test demonstrating test assertion
 * @details Shows the simplest form of a test case using CHECK() macro.
 */
TEST(FirstTestGroup, FirstTest) {
    // Test code here. Use CHECK() and related functions to verify your tests.
    CHECK(true);
}

// Private

// End of file
