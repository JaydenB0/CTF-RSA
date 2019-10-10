CXX=g++
LDLIBS=-lboost_program_options -lgmpxx
SRC=main.cpp
RM=rm -f

make:
	$(CXX) $(SRC) -o ctfrsa $(LDLIBS)

clean:
	$(RM) ctfrsa