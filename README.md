# Deterministic Task Engine

A C++ library for deterministic task scheduling and execution with explicit state management, retry policies, and execution control.

## Overview

The Deterministic Task Engine provides a robust foundation for building reliable task execution systems. Unlike concurrent task schedulers, this engine emphasizes **deterministic behavior** with controlled execution paths, making it ideal for scenarios where consistency and predictability are paramount (such as AI agent execution loops, workflow engines, and state-machine-based systems).

## Features

- **Deterministic Execution**: Tasks execute with predictable outcomes controlled by execution policies
- **Retry Mechanism**: Built-in retry logic with configurable retry limits per task
- **State Transitions**: Explicit task states (PENDING, RUNNING, SUCCESS, FAILED) with clear lifecycle management
- **Execution Policies**: Pluggable execution policy system for controlling task behavior and outcomes
- **Type-Safe**: Written in modern C++ with strong type safety and memory management

## Project Structure

- **`src/`** - Core library implementation
  - `task.hpp/cpp` - Task definition and lifecycle management
  - `task_manager.hpp/cpp` - Central task orchestration engine
  - `execution_policy.hpp/cpp` - Pluggable execution policy system
  - `main.cpp` - Example usage and application entry point

- **`tests/`** - Comprehensive unit tests
  - `TaskTest.cpp` - Task functionality and retry behavior tests
  - `TaskManagerTest.cpp` - TaskManager orchestration tests
  - `ExecutionPolicyTest.cpp` - ExecutionPolicy scripting tests
  - `TestExample.cpp` - CppUTest framework examples

## Documentation

Complete API documentation is generated using Doxygen. To view the documentation:

1. **Generate the documentation** (if not already generated):
   ```bash
   doxygen .\docs\Doxyfile
   ```

2. **View the HTML documentation**:
   Open `docs/DoxygenOutput/html/index.html` in your web browser

The generated documentation includes:
- Class and function references
- Detailed method signatures and parameters
- Usage examples from the test suite
- Namespace and module organization
- File structure and dependencies

## Architecture

The system is built around three core components:

### 1. **Task**
Represents a unit of work with an identity, retry policy, and execution policy.
- Manages its own state transitions
- Tracks retry attempts
- Executes via an assigned ExecutionPolicy

### 2. **ExecutionPolicy**
Defines how a task executes and what result it produces.
- Supports scripted execution for deterministic testing
- Returns execution results (SUCCESS, FAILURE, TIMEOUT)
- Exhaustion behavior (defaults to FAILURE when script exhausted)

### 3. **TaskManager**
Orchestrates task execution and maintains overall system state.
- Manages task queues
- Executes tasks sequentially
- Throws exceptions on task failures for explicit error handling

## Design Philosophy

This project follows the principle that **LLM agents are decision-makers**, not execution engines. Real systems require predictable, testable execution engines underneath. By separating concerns:

- **Decision Layer**: Where the LLM or AI system decides *what* to do
- **Execution Layer**: This engine - handles *how* and *when* tasks execute

## Trade-offs & Constraints

| Feature | Status |
|---------|--------|
| Single-threaded execution | ✓ By design |
| Deterministic outcomes | ✓ Core feature |
| Retry policies | ✓ Implemented |
| Persistence | ✗ Not implemented |
| Async scheduling | ✗ Not implemented |
| Timeout enforcement | ✗ Planned |
| Parallel execution | ✗ Not applicable |

## Building & Testing

```bash
# Build the project
cmake -B build
cmake --build build

# Run tests
ctest --test-dir build
```

## Future Enhancements

- **Timeout Enforcement**: Time-based task cancellation
- **Persistence Layer**: Save/restore task state to disk
- **Async Executor**: Non-blocking task execution with callbacks
- **MCP Integration**: Model Context Protocol tool execution support
- **Advanced Policies**: Exponential backoff, circuit breaker patterns
