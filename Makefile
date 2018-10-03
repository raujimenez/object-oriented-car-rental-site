CXXFLAGS += --std=c++17

test: test_vehicle
	@./test_vehicle 2> error_vehicle.txt

test_vehicle: test_vehicle.cpp vehicle.o
	${CXX} ${CXXFLAGS} -o test_vehicle test_vehicle.cpp vehicle.o

vehicle.o: vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c vehicle.cpp

clean:
	rm -rf error_* *.o test_vehicle