# **Make files:**

# - Build process:
#   - preprocessor
#       - removes comments
#       - does guard statements and includes (+macros).
#   - compile individule modules (and all header and this their dependencies)

# Recompile main.cpp output to main.o.
g++ -c main.cpp -o main.o

# "Link" main.o with DT1.o, ADT2.o, and put into a file named exec.
g++ main.o ADT1.o ADT2.o -o exec

