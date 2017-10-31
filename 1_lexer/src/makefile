CPPFLAGS += -W -Wall -g -std=gnu++11

c_lexer.yy.cpp : c_lexer.flex
	flex -o c_lexer.yy.cpp  c_lexer.flex

bin/c_lexer : c_lexer.yy.cpp lexer_main.cpp
	g++ $(CPPFLAGS) -o lexer  c_lexer.yy.cpp lexer_main.cpp

clean :
	-rm c_lexer c_lexer.exe
	-rm *.yy.cpp
	-rm test/out/*
