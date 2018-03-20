GTEST_DIR = GTEST

USER_DIR = ..

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = MyAppTest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

IProcessor.o : $(USER_DIR)/IProcessor.cpp $(USER_DIR)/IProcessor.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/IProcessor.cpp

ProcessWithWord.o : $(USER_DIR)/ProcessWithWord.cpp $(USER_DIR)/ProcessWithWord.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/ProcessWithWord.cpp

ProcessWithPoint.o : $(USER_DIR)/ProcessWithPoint.cpp $(USER_DIR)/ProcessWithPoint.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/ProcessWithPoint.cpp

MyFactory.o: $(USER_DIR)/MyFactory.cpp $(USER_DIR)/MyFactory.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/MyFactory.cpp

ProcessWithSpace.o : $(USER_DIR)/ProcessWithSpace.cpp $(USER_DIR)/ProcessWithSpace.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/ProcessWithSpace.cpp

MyApp_unittest.o : MyApp_unittest.cc \
		     $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(USER_DIR) -c MyApp_unittest.cc

MyAppTest : IProcessor.o ProcessWithWord.o ProcessWithPoint.o ProcessWithSpace.o MyFactory.o MyApp_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
