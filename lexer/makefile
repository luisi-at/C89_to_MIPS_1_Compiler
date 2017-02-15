CPPFLAGS += -W -Wall -g -std=gnu++11

c_lexer.yy.cpp : src/c_lexer.flex
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/c_lexer : src/c_lexer.yy.cpp src/lexer_main.cpp
	g++ $(CPPFLAGS) -o bin/c_lexer  src/c_lexer.yy.cpp src/lexer_main.cpp

clean :
	-rm c_lexer c_lexer.exe
	-rm *.yy.cpp
