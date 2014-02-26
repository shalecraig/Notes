CXX= g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = hello.o
EXEC = hello

hello: hello.o
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

hello.o: hello.cc
