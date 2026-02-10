/**
 * @file: ExecutionPolicyTest.cpp
 * @brief: Unit tests for the ExecutionPolicy class
 * @details: Tests the ExecutionPolicy class functionality including scripted execution results
 *           and behavior when the script is exhausted.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "CppUTest/TestHarness.h"
#include "execution_policy.hpp"

/****** Defines ******/

/****** Functions ******/
// Public

using namespace thecpuffin;

TEST_GROUP(ExecutionPolicyGroup){};

/**
 * @test ExecutionPolicyGroup::ScriptedResultsAndExhaustion
 * @brief Tests scripted execution results and default behavior when script is exhausted
 * @details Verifies that ExecutionPolicy returns results from the script in order,
 *          and returns FAILURE as default when the script is exhausted.
 */
TEST(ExecutionPolicyGroup, ScriptedResultsAndExhaustion) {
    std::vector<ExecutionResult> script = {ExecutionResult::SUCCESS, ExecutionResult::TIMEOUT};

    auto policy = std::make_shared<thecpuffin::ExecutionPolicy>(script);

    CHECK(policy->execute() == ExecutionResult::SUCCESS);
    CHECK(policy->execute() == ExecutionResult::TIMEOUT);
    // Script exhausted -> default FAILURE
    CHECK(policy->execute() == ExecutionResult::FAILURE);
}

// Private

// End of file
