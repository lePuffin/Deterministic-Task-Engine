/**
 * @file task.hpp
 * @brief Declaration of the Task class and TaskState enum for task management.
 * @author lePuffin
 * @date 2026-01-31
 */

#ifndef _task_hpp_
#define _task_hpp_

/****** Includes ******/
#include <chrono>
#include <string>
#include "execution_policy.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @enum TaskState
 * @brief Represents the state of a task.
 */
enum class TaskState {
    CREATED, /**< Task has been created but not started. */
    RUNNING, /**< Task is currently running. */
    SUCCESS, /**< Task completed successfully. */
    FAILED,  /**< Task failed. */
    ABORTED  /**< Task was aborted. */
};

/**
 * @class Task
 * @brief Represents a single task with retry and timeout logic.
 */
class Task {
  public:
    /**
     * @brief Construct a new Task object.
     * @param id Unique identifier for the task.
     * @param maxRetries Maximum number of retries allowed.
     * @param timeout Timeout duration for the task.
     */
    Task(std::string id, uint8_t maxRetries, std::shared_ptr<ExecutionPolicy> policy);

    /**
     * @brief Destroy the Task object.
     */
    ~Task() = default;

    /**
     * @brief Run the task.
     * @return true if the task succeeded, false otherwise.
     */
    bool Run();

    /**
     * @brief Reset the task state and retry count.
     */
    void Reset();

    /**
     * @brief Get the current state of the task.
     * @return TaskState The current state.
     */
    TaskState State() const;

    /**
     * @brief Get the unique identifier of the task.
     * @return const std::string& The task ID.
     */
    const std::string& Id() const;

    /**
     * @brief Check if the task can be retried.
     * @return true if retries are available, false otherwise.
     */
    bool CanRetry() const;

  private:
    std::string                      m_id;         /**< Unique identifier for the task. */
    TaskState                        m_state;      /**< Current state of the task. */
    uint8_t                          m_retries;    /**< Number of retries attempted. */
    uint8_t                          m_maxRetries; /**< Maximum number of retries allowed. */
    std::chrono::milliseconds        m_timeout;    /**< Timeout duration for the task. */
    std::shared_ptr<ExecutionPolicy> m_policy;     /**< Execution policy for the task. */
};

};  // namespace thecpuffin

#endif  // _task_hpp_

// End of file
