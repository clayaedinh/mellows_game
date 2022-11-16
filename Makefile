SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -I include -I headers
CPPFLAGS :=
CXXFLAGS := -I include -I headers

all : build/output

build/output: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

VAL_OBJ_DIR := obj/valgrind
VAL_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(VAL_OBJ_DIR)/%.o,$(SRC_FILES))
VALCFLAGS := -g

valgrind : valgrind/output

valgrind/output: $(VAL_OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(VAL_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(VALCFLAGS) $(CXXFLAGS) -c -o $@ $<
