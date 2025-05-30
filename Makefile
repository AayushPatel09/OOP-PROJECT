# Compiler
CXX = g++
CXXFLAGS = -std=c++17

# Source Files
SRCS = main.cpp \
       RentalManager.cpp \
       Rental.cpp \
       Customer.cpp \
       Vehicle.cpp \
       Car.cpp \
       Truck.cpp \
       ElectricCar.cpp \
       Utils.cpp \
	   UIManager.cpp\
	   

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Output binary
TARGET = rental_system

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run: all
	./$(TARGET)