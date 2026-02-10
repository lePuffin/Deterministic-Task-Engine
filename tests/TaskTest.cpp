/**
 * @file: TaskTest.cpp
 * @brief: Unit tests for the Task class
 * @details: Tests the Task class functionality including task execution, state transitions,
 *           success/failure handling, and retry mechanism.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include <memory>
#include "CppUTest/TestHarness.h"
#include "execution_policy.hpp"
#include "task.hpp"

/****** Defines ******/

/****** Functions ******/
// Public

using namespace thecpuffin;

TEST_GROUP(TaskGroup){};

/**
 * @test TaskGroup::RunSuccessAndState
 * @brief Tests successful task execution and state transitions
 * @details Verifies that a task with a successful execution policy runs successfully,
 *          transitions to SUCCESS state, and cannot be retried.
 */
TEST(TaskGroup, RunSuccessAndState) {
    std::vector<ExecutionResult> script = {ExecutionResult::SUCCESS};
    auto                         policy = std::make_shared<ExecutionPolicy>(script);
    Task                         t("task_ok", 0, policy);

    CHECK(t.Run());
    CHECK(t.State() == TaskState::SUCCESS);
    CHECK(!t.CanRetry());
}

/**
 * @test TaskGroup::FailureThenSuccessWithRetry
 * @brief Tests task failure and recovery through retry mechanism
 * @details Verifies that a task with failure followed by success can be retried,
 *          properly transitions through FAILED state, and succeeds on retry.
 */
TEST(TaskGroup, FailureThenSuccessWithRetry) {
    std::vector<ExecutionResult> script = {ExecutionResult::FAILURE, ExecutionResult::SUCCESS};
    auto                         policy = std::make_shared<ExecutionPolicy>(script);
    // Allow one retry: set maxRetries to 2 so m_retries (1) < maxRetries after first fail
    Task t("task_retry", 2, policy);

    CHECK(!t.Run());
    CHECK(t.State() == TaskState::FAILED);
    CHECK(t.CanRetry());

    CHECK(t.Run());
    CHECK(t.State() == TaskState::SUCCESS);
}

// Private

// End of file
