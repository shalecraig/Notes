CXX= g++
#CXXFLAGS = -g `/opt/local/bin/pkg-config gtkmm-2.4 --cflags --libs`
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = DeckGUI.o otherworld.o driver.o
EXEC = other

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

DeckGUI.o: DeckGUI.h DeckGUI.cc
otherworld.o: otherworld.h otherworld.cc
driver.o: otherworld.h driver.cc

clean:
	rm $(EXEC) $(OBJS)
