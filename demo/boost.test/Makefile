CURRPATH	= $(abspath .)
CXXFLAGS       ?= -ggdb

TESTFILES	= $(wildcard test*.cpp)
TESTEXECUTABLES	= $(patsubst test%.cpp,test%,$(TESTFILES))

SRCFILES	= $(filter-out $(TESTFILES), $(wildcard *.cpp) )
EXECUTABLES	= $(patsubst %.cpp,%,$(SRCFILES))

CXX		?= clang++

TESTINCLUDES	= -lboost_unit_test_framework
INCLUDES 	?= -I.

ifdef BOOST_INC
	TESTINCLUDES += -I$(BOOST_INC)
	INCLUDES += -I$(BOOST_INC)
endif

ifdef BOOST_LIB
	TESTINCLUDES += -L$(BOOST_LIB)
	INCLUDES += -L$(BOOST_LIB)	
endif

TESTINCLUDES += $(INCLUDES)
CXXFLAGS += $(LDFLAGS)

all : $(EXECUTABLES)


tests : $(TESTEXECUTABLES)
	@echo -e "Running all tests\n"

% : %.cpp 
	$(CXX) -x c++ $(CXXFLAGS) $(INCLUDES) $< -o $(CURRPATH)/$@

test% : test%.cpp 
	@echo -e "Building test $@ from $<!\n"
	$(CXX) $(CXXFLAGS) $(TESTINCLUDES) -o $(CURRPATH)/$@ $<
	@echo -e "executing $@\n"
	timeout 5 $(CURRPATH)/$@


clean : 
	@echo -e "Cleaning directory from executables"
	@rm -vf `find . -type f -executable`

help :
	@echo -e "This Makefile assumes, that all source code files  "
	@echo -e "that start with test_ contain BOOST.Test unit tests"
	@echo -e "and hence need to be linked against boost_unit_test_framework"
	@echo -e "the boost include and library paths maybe given to "
	@echo -e "the boost include and library paths maybe given as "
	@echo -e "\t\$ BOOST_INC=/path/to/boost/include BOOST_LIB=/path/to/boost/lib make\n"

print :
	@echo -e "found the following source code files with tests\n\t$(TESTFILES)\n"
	@echo -e "found the following source code files with code\n\t$(SRCFILES)\n"
