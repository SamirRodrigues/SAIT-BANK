CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = src/Account.cpp src/Bank.cpp Main.cpp
SRCTEST = src/Account.cpp src/Bank.cpp test/test.cpp
OBJ = $(SRC:.cc=.o)
OBJTEST = $(SRCTEST:.cc=.o)
EXEC = run
EXECTEST = runtest

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

all: $(EXECTEST)

$(EXECTEST): $(OBJTEST)
	$(CXX) $(LDFLAGS) -o $@ $(OBJTEST) $(LBLIBSTEST)

clean:
	rm -rf $(OBJ) $(EXEC)
	rm -rf $(OBJTEST) $(EXECTEST)
