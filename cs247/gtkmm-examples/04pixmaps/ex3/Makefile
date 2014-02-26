CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = pixbuf-demo.o
EXEC = pixbuf

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

pixbuf-demo.o: pixbuf-demo.cc

clean:
	rm $(EXEC) $(OBJS)
