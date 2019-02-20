# The makefile format
#target-name: target dependencies
#{-tab-}actions

#==================================================
# MACRO definitions
CC = clang
CFLAG = -fcilkplus -lm

#==================================================
# All Targets
all: problem1

#Individual
problem1:
	$(CC) $(CFLAG) -o problem1.out problem1.cpp

# problem2:
# 	$(CC) $(CFLAG) -o problem2.out problem2.cpp

# problem3:
# 	$(CC) $(CFLAG) -o problem3.out problem3.cpp

# problem4:
# 	$(CC) $(CFLAG) -o problem4.out problem4.cpp

#==================================================
#Clean all objected files and the executable file
clean:
	rm -f *.o
	rm -f *.out
#==================================================