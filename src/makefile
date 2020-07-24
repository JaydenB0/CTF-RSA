CXX=g++
LDLIBS=-lboost_program_options -lgmpxx -lgmp
SRC=main.cpp calculations.cpp variables.cpp
CPATH=includes
RM=rm -f
DIRS=../build

make:
	$(shell mkdir -p $(DIRS))
	$(CXX) $(SRC) -I$(CPATH) -o ../build/ctfrsa $(LDLIBS)

clean:
	$(RM) ctfrsa