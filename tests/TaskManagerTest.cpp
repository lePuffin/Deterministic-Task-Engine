/**
 * @file: TaskManagerTest.cpp
 * @brief: Unit tests for the TaskManager class
 * @details: Tests the TaskManager class functionality including task execution orchestration,
 *           error handling, and exception throwing on task failures.
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include <memory>
#include "CppUTest/TestHarness.h"
#include "execution_policy.hpp"
#include "task.hpp"
#include "task_manager.hpp"

/****** Defines ******/

/****** Functions ******/
// Public

using namespace thecpuffin;

TEST_GROUP(TaskManagerGroup){};

/**
 * @test TaskManagerGroup::ExecuteSingleSuccess
 * @brief Tests successful execution of a single task
 * @details Verifies that TaskManager can execute a single task with a successful
 *          execution policy without throwing exceptions.
 */
TEST(TaskManagerGroup, ExecuteSingleSuccess) {
    TaskManager                  manager;
    std::vector<ExecutionResult> script = {ExecutionResult::SUCCESS};
    auto                         policy = std::make_shared<ExecutionPolicy>(script);
    auto                         task   = std::make_shared<Task>("t1", 0, policy);
    manager.addTask(task);

    // Should not throw
    manager.execute();
}

/**
 * @test TaskManagerGroup::ExecuteAbortThrows
 * @brief Tests that TaskManager throws on task failure
 * @details Verifies that TaskManager throws a runtime_error exception when
 *          a task fails during execution.
 */
TEST(TaskManagerGroup, ExecuteAbortThrows) {
    TaskManager                  manager;
    std::vector<ExecutionResult> script = {ExecutionResult::FAILURE};
    auto                         policy = std::make_shared<ExecutionPolicy>(script);
    auto                         task   = std::make_shared<Task>("t2", 0, policy);
    manager.addTask(task);

    bool threw = false;
    try {
        manager.execute();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    CHECK(threw);
}

// Private

// End of file
