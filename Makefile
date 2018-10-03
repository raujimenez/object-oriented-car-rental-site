CXXFLAGS += --std=c++17

test: test_vehicle test_rental_site
	@./test_vehicle 2> errors_vehicle.txt
	@./test_rental_site 2> errors_rental_site.txt

test_vehicle: test_vehicle.cpp vehicle.o
	${CXX} ${CXXFLAGS} -o test_vehicle test_vehicle.cpp vehicle.o
test_rental_site: test_rental_site.cpp rental_site.o vehicle.o
	${CXX} ${CXXFLAGS} -o test_rental_site test_rental_site.cpp rental_site.o vehicle.o

rental_site.o: rental_site.cpp *.h
	${CXX} ${CXXFLAGS} -c rental_site.cpp
vehicle.o: vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c vehicle.cpp

clean:
	rm -rf errors_* *.o test_vehicle test_rental_site