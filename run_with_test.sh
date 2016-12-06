bison -d foo.y && flex bar.l && g++-6 foo.tab.c lex.yy.c -ll -ly fubar.c && ./a.out < $1 && xdot fchart.dot
