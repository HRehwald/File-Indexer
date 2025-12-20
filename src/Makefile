# ---- Project settings ----
CXX       := g++
CXXFLAGS  := -std=c++17 -O2 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS   :=
TARGET    := file_indexer

SRC_DIR   := src
OBJ_DIR   := build/obj

# Find all .cpp files under src/ recursively
SOURCES   := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJECTS   := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
DEPS      := $(OBJECTS:.o=.d)

# ---- Default target ----
.PHONY: all
all: $(TARGET)

# Link
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile (also generates .d dependency files)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include generated dependency files
-include $(DEPS)

# ---- Convenience targets ----
.PHONY: run
run: $(TARGET)
	./$(TARGET)

.PHONY: clean
clean:
	rm -rf build $(TARGET)

.PHONY: format
format:
	@echo "No formatter configured. (Optional: clang-format)"
