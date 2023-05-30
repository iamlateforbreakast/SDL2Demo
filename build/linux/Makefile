CXX = g++
CXXFLAGS := -g -I/usr/include/SDL2 -D_REENTRANT

TARGET_EXEC := SDL2Demo

BUILD_DIR := .
SRC_DIRS := ../../src ../..

SRC := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(patsubst %.o,%.c,$(SRC))

DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
