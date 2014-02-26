CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = examplewindow.o main.o
EXEC = examplewindow

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

examplewindow.o: examplewindow.h examplewindow.cc
main.o: examplewindow.h main.cc

clean:
	rm $(EXEC) $(OBJS)
