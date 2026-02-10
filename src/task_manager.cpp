/**
 * @file task_manager.cpp
 * @brief Implementation of the TaskManager class methods.
 * @author lePuffin
 * @date 2026-01-30
 */

/****** Includes ******/
#include "task_manager.hpp"
#include <iostream>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public

/**
 * @brief Destroy the TaskManager object and clean up the queue.
 */
TaskManager::~TaskManager() {
    // Destructor: Clean up the task queue by removing all remaining tasks.
    while (!m_queue.empty()) {
        m_queue.pop();  // Remove each task from the queue.
    }
}

/**
 * @brief Add a task to the queue.
 * @param task Shared pointer to the Task to add.
 */
void TaskManager::addTask(std::shared_ptr<Task> task) {
    // Add a new task to the end of the queue for future execution.
    m_queue.push(task);
}

/**
 * @brief Execute all tasks in the queue, handling retries and failures.
 */
void TaskManager::execute() {
    // Process all tasks in the queue one by one.
    while (!m_queue.empty()) {
        // Get the next task from the front of the queue.
        auto task = m_queue.front();
        m_queue.pop();

        std::cout << TAG << " Executing " << task->Id() << "\n";

        // Attempt to run the task.
        bool success = task->Run();

        if (!success && task->CanRetry()) {
            // If the task failed but can be retried, log and requeue it.
            std::cout << TAG << " Retry " << task->Id() << "\n";
            m_queue.push(task);

        } else if (!success) {
            // If the task failed and cannot be retried, log and throw an error.
            std::cout << TAG << " Aborted " << task->Id() << "\n";
            throw std::runtime_error("Task " + task->Id() + " failed and cannot retry.");

        } else {
            // Task succeeded.
            std::cout << TAG << " Success " << task->Id() << "\n";
        }
    }
}

// Private

};  // namespace thecpuffin

// End of file