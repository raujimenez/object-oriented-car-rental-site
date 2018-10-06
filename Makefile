CXXFLAGS += --std=c++17

main: main.o controller.o view.o rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o main main.o controller.o view.o rental_site.o vehicle.o renter.o

test: test_vehicle test_rental_site test_view test_controller
	@./test_vehicle 2> errors_vehicle.txt 
	@./test_rental_site 2> errors_rental_site.txt
	@./test_view 2> errors_view.txt
	@./test_controller 2> errors_controller.txt 1> expected.txt < test_controller_input.txt

test_controller: test_controller.cpp controller.o view.o rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_controller test_controller.cpp controller.o view.o rental_site.o vehicle.o renter.o
test_view: test_view.cpp view.o rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_view test_view.cpp view.o rental_site.o vehicle.o renter.o
test_vehicle: test_vehicle.cpp vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_vehicle test_vehicle.cpp vehicle.o renter.o
test_rental_site: test_rental_site.cpp rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_rental_site test_rental_site.cpp rental_site.o vehicle.o renter.o

main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp
controller.o: controller.cpp *.h
	${CXX} ${CXXFLAGS} -c controller.cpp
view.o: view.cpp *.h
	${CXX} ${CXXFLAGS} -c view.cpp
rental_site.o: rental_site.cpp *.h
	${CXX} ${CXXFLAGS} -c rental_site.cpp
vehicle.o: vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c vehicle.cpp
renter.o: renter.cpp *.h
	${CXX} ${CXXFLAGS} -c renter.cpp

clean:
	rm -rf errors_* *.o test_vehicle test_rental_site test_view test_controller main expected.txt