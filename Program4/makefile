CC = g++  # use g++ compiler

FLAGS = -std=c++17  # compile with C++ 17 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -I.. -I.     # compile with parent directory on #include system path

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


Floyd : Floyd.cpp Floyd.h
	$(LINK) $@ $<

test : Floyd
	@./Floyd


clean:
	@rm -f Floyd \
	@rm -f output.txt