CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I 3_compiler/include

3_compiler/src/c_parser.tab.cpp src/c_parser.tab.hpp : 3_compiler/src/c_parser.y
	bison -v -d 3_compiler/src/c_parser.y -o 3_compiler/src/c_parser.tab.cpp

3_compiler/src/c_lexer.yy.cpp : 3_compiler/src/c_lexer.flex 3_compiler/src/c_parser.tab.hpp
	flex -o 3_compiler/src/c_lexer.yy.cpp  3_compiler/src/c_lexer.flex

bin/print_hierarchy : 3_compiler/src/print_hierarchy.o 3_compiler/src/c_parser.tab.o 3_compiler/src/c_lexer.yy.o 3_compiler/src/c_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_hierarchy $^

bin/c_compiler : 3_compiler/src/c_generator.o 3_compiler/src/c_parser.tab.o 3_compiler/src/c_lexer.yy.o 3_compiler/src/c_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

clean :
	rm 3_compiler/src/*.o
	rm bin/*
	rm 3_compiler/src/*.tab.cpp
	rm 3_compiler/src/*.yy.cpp
