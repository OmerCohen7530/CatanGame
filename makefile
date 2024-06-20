#!make -f

CXX=g++  
CXXFLAGS=-g -Wall 
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES_DEMO=Demo.cpp board.cpp player.cpp tile.cpp edge.cpp vertices.cpp catan.cpp developmentCards.cpp
OBJECTS_DEMO=$(subst .cpp,.o,$(SOURCES_DEMO))

SOURCES_TEST=board.cpp player.cpp tile.cpp edge.cpp vertices.cpp catan.cpp developmentCards.cpp TestCounter.cpp Test.cpp
OBJECTS_TEST=$(subst .cpp,.o,$(SOURCES_TEST))

catan: main
	./$^

main: $(OBJECTS_DEMO)
	$(CXX) $(CXXFLAGS) $^ -o main

test: TestCounter.o Test.o $(OBJECTS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: catan_game test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main test