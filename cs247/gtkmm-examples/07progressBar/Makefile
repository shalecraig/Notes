CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`

hello: examplewindow.o main.o
	$(CXX) examplewindow.o main.o $(CXXFLAGS) -o hello

clean:
	rm examplewindow.o main.o hello
