CXX      := g++
# -Wno-long-long is added to allow int64_t/long long in C++98 without pedantic warnings
CXXFLAGS := -std=c++98 -pedantic -Wall -Wextra -Werror -Wno-long-long -O3 -march=native -fomit-frame-pointer -Iinclude
LDFLAGS  :=

BUILD_DIR := build
BIN_DIR   := bin
SRC_DIR   := src
TEST_DIR  := tests

TARGET    := $(BIN_DIR)/optimized_app
TEST_EXEC := $(BIN_DIR)/run_tests

# Source files
SRCS      := $(wildcard $(SRC_DIR)/*.cpp)
OBJS      := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Filter out main.o for testing if we are linking other source files
# This assumes main logic is in src/main.cpp
MAIN_OBJ  := $(BUILD_DIR)/main.o
LIB_OBJS  := $(filter-out $(MAIN_OBJ), $(OBJS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Create directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile source objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test objects
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link main application
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Link test executable
# Links test objects AND library objects (excluding main)
$(TEST_EXEC): $(TEST_OBJS) $(LIB_OBJS) | $(BIN_DIR)
	$(CXX) $(TEST_OBJS) $(LIB_OBJS) -o $@ $(LDFLAGS)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean test
