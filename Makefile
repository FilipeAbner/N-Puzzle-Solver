# Variáveis
CXX = g++
CXXFLAGS = -std=c++17 -I./src -I./src/algorithm -I./src/graph -I./src/util
LDFLAGS = -std=c++17
BUILD_DIR = build

# Diretórios
SRCDIR = src
ALGORITHMDIR = $(SRCDIR)/algorithm
GRAPHDIR = $(SRCDIR)/graph
UTILDIR = $(SRCDIR)/util

# Arquivos Fonte
SRC = $(SRCDIR)/main.cpp \
      $(ALGORITHMDIR)/a_star.cpp \
      $(ALGORITHMDIR)/heuristic.cpp \
      $(GRAPHDIR)/graph.cpp \
      $(GRAPHDIR)/node.cpp \
      $(UTILDIR)/util.cpp \
      $(ALGORITHMDIR)/sucessors.cpp \
      $(ALGORITHMDIR)/ida_star.cpp

# Arquivos Objeto
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

# Executável
EXEC = my_program

# Regras
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
