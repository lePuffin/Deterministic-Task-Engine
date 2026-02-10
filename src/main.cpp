/**
 * @file main.cpp
 * @brief Entry point for the Deterministic Task Engine application.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

/****** Includes ******/
#include <chrono>
#include <iostream>
#include <memory>
#include "execution_policy.hpp"
#include "task_manager.hpp"

/****** Defines ******/
static constexpr const char* TAG = "[Main]";

/****** Functions ******/
// Public

int main() {
    // Initialization phase: Print a message and create the TaskManager.
    std::cout << "Initializing application..." << std::endl;

    thecpuffin::TaskManager manager;

    // Create a sample task with an ID, max retries, and timeout, then add it to the manager.
    std::vector<thecpuffin::ExecutionResult> script = {thecpuffin::ExecutionResult::FAILURE,
                                                       thecpuffin::ExecutionResult::FAILURE,
                                                       thecpuffin::ExecutionResult::SUCCESS};

    auto policy = std::make_shared<thecpuffin::ExecutionPolicy>(script);

    auto task = std::make_shared<thecpuffin::Task>("example_task", script.size(), policy);
    manager.addTask(task);

    // Main execution phase: Run the task(s) and handle any errors.
    try {
        std::cout << TAG << " Application is running..." << std::endl;
        manager.execute();  // This will process all tasks in the queue.

        while (1) {
            // Usual application logic would go here (e.g., event loop, more tasks, etc.)
            break;  // For this example, we just break immediately
        }

    } catch (const std::exception& e) {
        // Handle known exceptions and print the error message.
        std::cerr << TAG << " An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;

    } catch (...) {
        // Handle any other unknown exceptions.
        std::cerr << TAG << " An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    // Cleanup phase: Print a message before exiting.
    std::cout << TAG << " Cleaning up and exiting..." << std::endl;

    return EXIT_SUCCESS;
}

// End of file
