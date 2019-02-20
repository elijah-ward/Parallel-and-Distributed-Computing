# The makefile format
#target-name: target dependencies
#{-tab-}actions

#==================================================
# MACRO definitions
CC = clang
CFLAG = -fcilkplus -lm

#==================================================
# All Targets
all: problem1 problem2 problem3 problem4

#Individual
problem1:
	$(CC) $(CFLAG) -o problem1 problem1.cpp

problem2:
	$(CC) $(CFLAG) -o problem2 problem2.cpp

problem3:
	$(CC) $(CFLAG) -o problem3 problem3.cpp

problem4:
	$(CC) $(CFLAG) -o problem4 problem4.cpp

#==================================================
#Clean all objected files and the executable file
clean:
	rm -f *.o
	rm -f problem1 problem2 problem3 problem4
#==================================================