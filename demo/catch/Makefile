CURRPATH	= $(abspath .)
CXXFLAGS       ?= -ggdb

TESTFILES	= $(wildcard test*.cpp)
TESTEXECUTABLES	= $(patsubst test%.cpp,test%,$(TESTFILES))

SRCFILES	= $(filter-out $(TESTFILES), $(wildcard *.cpp) )
EXECUTABLES	= $(patsubst %.cpp,%,$(SRCFILES))

CXX		?= clang++

INCLUDES 	?= -I.

TESTINCLUDES += $(INCLUDES)
CXXFLAGS += $(LDFLAGS)

all : $(EXECUTABLES)


tests : $(TESTEXECUTABLES)
	@echo -e "Running all tests\n"

% : %.cpp 
	$(CXX) -x c++ $(CXXFLAGS) $(INCLUDES) $< -o $(CURRPATH)/$@

test% : test%.cpp 
	@echo -e "Building test $@ from $<!\n"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(CURRPATH)/$@ $<
	@echo -e "executing $@\n"
	timeout 5 $(CURRPATH)/$@


clean : 
	@echo -e "Cleaning directory from executables"
	rm -vf `find . -executable`

help :
	@echo -e "This Makefile assumes, that all source code files  "
	@echo -e "that start with test_ contain catch unit tests"

print :
	@echo -e "found the following source code files with tests\n\t$(TESTFILES)\n"
	@echo -e "found the following source code files with code\n\t$(SRCFILES)\n"
