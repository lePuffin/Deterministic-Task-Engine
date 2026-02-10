/**
 * @file task_manager.hpp
 * @brief Declaration of the TaskManager class for managing and executing tasks.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

#ifndef _task_manager_hpp_
#define _task_manager_hpp_

/****** Includes ******/
#include <memory>
#include <queue>
#include "task.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

/**
 * @class TaskManager
 * @brief Manages a queue of tasks and executes them with retry logic.
 */
class TaskManager {
  public:
    /**
     * @brief Construct a new TaskManager object.
     */
    TaskManager() = default;

    /**
     * @brief Destroy the TaskManager object and clean up the queue.
     */
    ~TaskManager();

    /**
     * @brief Add a task to the queue.
     * @param task Shared pointer to the Task to add.
     */
    void addTask(std::shared_ptr<Task> task);

    /**
     * @brief Execute all tasks in the queue, handling retries and failures.
     */
    void execute();

  private:
    std::queue<std::shared_ptr<Task>> m_queue;        /**< Queue of tasks to execute. */
    static constexpr const char*      TAG = "[Task]"; /**< Tag for logging. */
};

};  // namespace thecpuffin

#endif  // _task_manager_hpp_

// End of file
