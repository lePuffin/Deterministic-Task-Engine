/**
 * @file execution_policy.cpp
 * @brief Implements the ExecutionPolicy class for task execution control.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

/****** Includes ******/
#include "execution_policy.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public

/**
 * @brief Executes the next step in the policy script.
 *
 * Returns the next ExecutionResult in the script. If the end of the script is reached,
 * returns FAILURE by default.
 *
 * @return ExecutionResult The result of the current execution step.
 */
ExecutionResult ExecutionPolicy::execute() {
    // If there are more results in the script, return the next one and advance the index.
    if (index < m_script.size()) {
        ExecutionResult result = m_script[index];
        ++index;  // Move to the next result for the next call.
        return result;
    }

    // If the script is exhausted, return FAILURE as a default.
    return ExecutionResult::FAILURE;
}

// Private

}  // namespace thecpuffin

// End of file
