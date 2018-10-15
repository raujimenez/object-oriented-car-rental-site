CXXFLAGS += --std=c++17
GTKFLAGS += `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o controller.o view.o rental_site.o vehicle.o renter.o dialog.o
	${CXX} ${CXXFLAGS} -o main main.o controller.o view.o rental_site.o vehicle.o renter.o dialog.o ${GTKFLAGS}

test: test_vehicle test_rental_site test_view 
	@./test_vehicle 2> errors_vehicle.txt 
	@./test_rental_site 2> errors_rental_site.txt
	@./test_view 2> errors_view.txt


test_view: test_view.cpp view.o rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_view test_view.cpp view.o rental_site.o vehicle.o renter.o
test_vehicle: test_vehicle.cpp vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_vehicle test_vehicle.cpp vehicle.o renter.o
test_rental_site: test_rental_site.cpp rental_site.o vehicle.o renter.o
	${CXX} ${CXXFLAGS} -o test_rental_site test_rental_site.cpp rental_site.o vehicle.o renter.o

main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp ${GTKFLAGS}
controller.o: controller.cpp *.h
	${CXX} ${CXXFLAGS} -c controller.cpp ${GTKFLAGS}
view.o: view.cpp *.h
	${CXX} ${CXXFLAGS} -c view.cpp
rental_site.o: rental_site.cpp *.h
	${CXX} ${CXXFLAGS} -c rental_site.cpp
vehicle.o: vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c vehicle.cpp
renter.o: renter.cpp *.h
	${CXX} ${CXXFLAGS} -c renter.cpp
dialog.o: dialog.cpp *.cpp
	${CXX} ${CXXFLAGS} -c dialog.cpp ${GTKFLAGS}
clean:
	rm -rf errors_* *.o test_vehicle test_rental_site test_view test_controller main expected.txt