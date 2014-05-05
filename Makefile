CXX = clang++
CXXFLAGS = -Wall -c -std=c++11 -I/usr/local/lib

SDL = -framework SDL2 -framework SDL2_image -framework OpenGL
LDFLAGS = $(SDL) -F /Library/Frameworks

SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR = obj
OBJECTS = $(subst $(SRC_DIR)/, $(OBJ_DIR)/, $(patsubst %.cpp, %.o, $(SOURCES)))
#$(warning $(OBJECTS))

BIN_DIR = bin
EXE = game

# run these no matter what
.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(BIN_DIR)/$(EXE) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf obj bin

run:
	./$(BIN_DIR)/$(EXE)
