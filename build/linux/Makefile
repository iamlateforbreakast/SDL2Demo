#
CXX = g++
CXXFLAGS := -g -Wall -I/usr/include/SDL2 -D_REENTRANT -I../../src
LDFLAGS := -lSDL2

TARGET_EXEC := SDL2Demo

BUILD_DIR := .
SRC_DIRS := ../../src

SRC := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(patsubst ../../src/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
OBJS := $(OBJS) $(patsubst ../../%.cpp,$(BUILD_DIR)/%.o,../../main.cpp)
#OBJS := $(SRC:$(SRC_DIRS)/%.cpp=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: ../../%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: ../../src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET_EXEC)
