# ---------------------------------------------------------------------
# **Make**

# We're going to use make to figure out when to Recompile/not Recompile.
# A comment:
# If the timestamp of any of the source files have changed, we will execute the rule to rebuild the target.

# Rule: this command is dependent on these files
	# execute this command if the rule is triggered
program.exe: main.o ADT1.o ADT2.o
	g++ -c main.cpp -o main.o 

# ------------------------------------------
# Macros:

# new macro - CXX = g++
CXX = g++
# debug compiler and optimization.
CXXFlags = -g -Wall

OBJECTS = main.o ADT1.o ADT2.o

EXEC = program.exe

# the $ expands the macro
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFlags} ${OBJECTS} -o ${EXEC}

main.o : main.cpp stack.have
	${CXX} ${CXXFlags} -c main.cpp

# ------------------------------------------
# Implicit Rules:

# variables and initialization
CXX = g++
CXXFLAGS = -g -Wall
OBJECTS = main.o stack.o node.o
EXEC = program

${EXEC} : ${OBJECTS} # default target
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

# gmake automagically knows how to build .o ﬁles given CXX and CXXFLAGS
# just need to list dependencies
main.o : main.cpp stack.h
stack.o : stack.cpp stack.h node.h
node.o : node.cpp node.h stack.h

# --------------------------------------------
# Automagically Derived Dependencies

# You should be able to re-use this makefile without thinking about it.

# variables and initialization
CXX = g++
# builds dependency lists in .d ﬁles
CXXFLAGS = -g -Wall -MMD
OBJECTS = main.o stack.o node.o
# substitute ".o" with ".d"
DEPENDS = ${OBJECTS:.o=.d}
EXEC = program

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
# separate make target; cleans directory of all temp files.
clean: 
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
# reads the .d ﬁles and re-runs the make with dependencies
-include ${DEPENDS}
