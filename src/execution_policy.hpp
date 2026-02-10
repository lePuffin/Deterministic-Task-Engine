/**
 * @file execution_policy.hpp
 * @brief Declares the ExecutionPolicy class and ExecutionResult enum for task execution control.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

#ifndef _execution_policy_hpp_
#define _execution_policy_hpp_

/****** Includes ******/
#include <memory>
#include <vector>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/**
 * @enum ExecutionResult
 * @brief Represents the possible outcomes of executing a task.
 */
enum class ExecutionResult { SUCCESS, FAILURE, TIMEOUT };

/****** Classes ******/

/**
 * @class ExecutionPolicy
 * @brief Controls the execution flow of a task by providing a script of results.
 */
class ExecutionPolicy {
  public:
    /**
     * @brief Construct a new ExecutionPolicy object.
     * @param script A vector of ExecutionResult values to simulate task outcomes.
     */
    ExecutionPolicy(std::vector<ExecutionResult> script) : m_script(std::move(script)) {}

    /**
     * @brief Executes the next step in the policy script.
     * @return ExecutionResult The result of the current execution step.
     */
    ExecutionResult execute();

  private:
    std::vector<ExecutionResult>
           m_script; /**< The sequence of results to return on each execute call. */
    size_t index{0}; /**< Current position in the script. */
};

};  // namespace thecpuffin

#endif  // _execution_policy_hpp_

// End of file
