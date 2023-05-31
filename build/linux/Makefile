CXX = g++
CXXFLAGS := -g -I/usr/include/SDL2 -D_REENTRANT -I../../src

TARGET_EXEC := SDL2Demo

BUILD_DIR := .
SRC_DIRS := ../../src ../..

SRC := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(patsubst ../../src/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
#OBJS := $(SRC:$(SRC_DIRS)/%.cpp=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	echo "SRC=" $(SRC) \
	echo "OBJS=" $(OBJS) \
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: ../../src/%.cpp
	echo "Left=" $@\
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
