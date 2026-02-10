# Use an official build image for C++
FROM ubuntu:24.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    g++ \
    clang \
    clang-format \
    cppcheck \
    cpplint \
    cpputest \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy the source code into the container
COPY . .

# Default command for the container (optional)
CMD ["bash"]