CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -I$(SRCDIR)
AR = ar
ARFLAGS = rcs

LIBRARY = libplayer.a
TARGET = main

# Source directory
SRCDIR = src
OBJDIR = obj

$(shell mkdir -p $(OBJDIR))

OBJS = $(OBJDIR)/bow.o $(OBJDIR)/eventData.o $(OBJDIR)/events.o $(OBJDIR)/guard.o $(OBJDIR)/logger.o $(OBJDIR)/noGuard.o $(OBJDIR)/noTool.o $(OBJDIR)/player.o $(OBJDIR)/playerState.o $(OBJDIR)/saveHistory.o $(OBJDIR)/soundManager.o $(OBJDIR)/steelGuard.o $(OBJDIR)/sword.o $(OBJDIR)/tool.o $(OBJDIR)/woodenGuard.o

all: $(LIBRARY) $(TARGET)

# Build the static library
$(LIBRARY): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Object file compilation rules
$(OBJDIR)/bow.o: $(SRCDIR)/bow.cpp $(SRCDIR)/bow.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/bow.cpp -o $@

$(OBJDIR)/eventData.o: $(SRCDIR)/eventData.cpp $(SRCDIR)/eventData.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/eventData.cpp -o $@

$(OBJDIR)/events.o: $(SRCDIR)/events.cpp $(SRCDIR)/events.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/events.cpp -o $@

$(OBJDIR)/guard.o: $(SRCDIR)/guard.cpp $(SRCDIR)/guard.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/guard.cpp -o $@

$(OBJDIR)/logger.o: $(SRCDIR)/logger.cpp $(SRCDIR)/logger.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/logger.cpp -o $@

$(OBJDIR)/noGuard.o: $(SRCDIR)/noGuard.cpp $(SRCDIR)/noGuard.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/noGuard.cpp -o $@

$(OBJDIR)/noTool.o: $(SRCDIR)/noTool.cpp $(SRCDIR)/noTool.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/noTool.cpp -o $@

$(OBJDIR)/player.o: $(SRCDIR)/player.cpp $(SRCDIR)/player.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/player.cpp -o $@

$(OBJDIR)/playerState.o: $(SRCDIR)/playerState.cpp $(SRCDIR)/playerState.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/playerState.cpp -o $@

$(OBJDIR)/saveHistory.o: $(SRCDIR)/saveHistory.cpp $(SRCDIR)/saveHistory.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/saveHistory.cpp -o $@

$(OBJDIR)/soundManager.o: $(SRCDIR)/soundManager.cpp $(SRCDIR)/soundManager.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/soundManager.cpp -o $@

$(OBJDIR)/steelGuard.o: $(SRCDIR)/steelGuard.cpp $(SRCDIR)/steelGuard.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/steelGuard.cpp -o $@

$(OBJDIR)/sword.o: $(SRCDIR)/sword.cpp $(SRCDIR)/sword.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/sword.cpp -o $@

$(OBJDIR)/tool.o: $(SRCDIR)/tool.cpp $(SRCDIR)/tool.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/tool.cpp -o $@

$(OBJDIR)/woodenGuard.o: $(SRCDIR)/woodenGuard.cpp $(SRCDIR)/woodenGuard.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/woodenGuard.cpp -o $@

# Link the executable with the static library
$(TARGET): main.cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) main.cpp -L. -lplayer -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) *.a $(TARGET)

.PHONY: all run clean