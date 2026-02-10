/**
 * @file task.cpp
 * @brief Implementation of the Task class methods.
 * @author lePuffin
 * @date 2026-01-31
 */

/****** Includes ******/
#include "task.hpp"
#include <iostream>
#include <thread>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public

/**
 * @brief Construct a new Task object.
 * @param id Unique identifier for the task.
 * @param maxRetries Maximum number of retries allowed.
 * @param timeout Timeout duration for the task.
 */
Task::Task(std::string id, uint8_t maxRetries, std::shared_ptr<ExecutionPolicy> policy)
    : m_id(std::move(id)),
      m_state(TaskState::CREATED),
      m_retries(0),
      m_maxRetries(maxRetries),
      m_policy(policy) {
    // Initialize a new Task with the given ID, retry limit, and execution policy.
    // The task starts in the CREATED state with zero retries.
}

/**
 * @brief Run the task. Simulates processing and updates state.
 * @return true if the task succeeded, false otherwise.
 */
bool Task::Run() {
    // Set the state to RUNNING to indicate the task is in progress.
    m_state = TaskState::RUNNING;

    switch (m_policy->execute()) {
        case ExecutionResult::SUCCESS:
            m_state = TaskState::SUCCESS;
            return true;

        case ExecutionResult::FAILURE:
            m_state = TaskState::FAILED;
            ++m_retries;
            return false;

        case ExecutionResult::TIMEOUT:
            m_state = TaskState::FAILED;
            ++m_retries;
            return false;
    }

    return false;  // Should never reach here, but return false by default.
}

/**
 * @brief Check if the task can be retried.
 * @return true if retries are available, false otherwise.
 */
bool Task::CanRetry() const {
    // Returns true if the task has not yet reached the maximum retry count.
    return m_retries < m_maxRetries;
}

/**
 * @brief Reset the task state and retry count.
 */
void Task::Reset() {
    // Reset the task to its initial state and clear the retry count.
    m_state   = TaskState::CREATED;
    m_retries = 0;
}

/**
 * @brief Get the current state of the task.
 * @return TaskState The current state.
 */
TaskState Task::State() const {
    // Return the current state of the task (CREATED, RUNNING, etc.).
    return m_state;
}

/**
 * @brief Get the unique identifier of the task.
 * @return const std::string& The task ID.
 */
const std::string& Task::Id() const {
    // Return the unique identifier for this task.
    return m_id;
}

// Private

};  // namespace thecpuffin

// End of file
