CXX += g++
CXXFLAGS += --std=c++17


vehicle.o: vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c vehicle.cpp