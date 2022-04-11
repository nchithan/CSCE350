CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I.. -I.     # compile with parent directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


HorspoolMatching : HorspoolMatching.cpp #HorspoolMatching.h
	$(LINK) $@ $<

test : HorspoolMatching
	@./HorspoolMatching


clean:
	@rm -f HorspoolMatching \
	@rm -f output.txt