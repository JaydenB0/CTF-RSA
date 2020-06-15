CXX=g++
LDLIBS=-lboost_program_options -lgmpxx -lgmp
SRC=main.cpp calculations.cpp
CPATH=includes
RM=rm -f

make:
	$(CXX) $(SRC) -I$(CPATH) -o ./build/ctfrsa $(LDLIBS)

clean:
	$(RM) ctfrsa