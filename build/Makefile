CC = g++
#-xc++ -lstdc++ -shared-libgcc
DIR = ..
CFLAGS = -pedantic
TARGET = MyApp
HDRS = $(DIR)/Constant.h $(DIR)/IProcessor.h $(DIR)/MyFactory.h $(DIR)/MyFileReadWrite.h $(DIR)/ProcessWithSpace.h $(DIR)/ProcessWithPoint.h $(DIR)/ProcessWithWord.h
SRCS = $(DIR)/IProcessor.cpp $(DIR)/MyFactory.cpp $(DIR)/MyFileReadWrite.cpp $(DIR)/ProcessWithSpace.cpp $(DIR)/ProcessWithPoint.cpp $(DIR)/ProcessWithWord.cpp $(DIR)/main.cpp

OBJS = $(patsubst %.cpp, %.o, $(subst $(DIR)/,,$(SRCS)))

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: $(DIR)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $<
clean:
	-rm -f *.o *.exe