CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = helloworld.o MyDialogBox.o main.o
EXEC = hello

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

helloworld.o: helloworld.h helloworld.cc
main.o: helloworld.h main.cc
MyDialogBox.o: MyDialogBox.h MyDialogBox.cc

clean:
	rm $(EXEC) $(OBJS)
