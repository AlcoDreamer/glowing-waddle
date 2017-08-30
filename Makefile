TARGET		:= yasya

CC			:= g++
CFLAGS		:= -Wall -O2 -std=c++11
LDFLAGS		:= -framework SDL2 -Wall -O2 -std=c++11

SOURCE		:= main.cpp graphics.cpp
LIBS 		:= graphics.h

SOURCEROOT	:= /Users/dchernyshev/Documents/code/glowing-waddle
SOURCEDIR	:= $(addprefix $(SOURCEROOT)/, Src)
LIBSDIR		:= $(addprefix $(SOURCEROOT)/, Headers)
#PATH_S		:= $(addprefix $(SOURCEDIR)/, $(SOURCE))
#PATH_H		:= $(addprefix $(LIBSDIR)/, $(LIBS))
PATH_S		:= $(addprefix $(SOURCEDIR)/, $(shell ls $(SOURCEDIR)))
PATH_H		:= $(addprefix $(LIBSDIR)/, $(shell ls $(LIBSDIR)))

all: $(TARGET) $(PATH_S)

$(TARGET): $(patsubst %.cpp, %.o, $(wildcard $(PATH_S)))
	$(CC) $(LDFLAGS) $^ -o $(TARGET)

.PHONY: clean

clean:
	rm -rf $(TARGET) $(addprefix $(SOURCEDIR)/, *.o) $(addprefix $(SOURCEDIR)/, *.d)

%.o: %.cpp
	$(CC) -c -MD $(addprefix -I, $(LIBSDIR)) $< $(CFLAGS) -o $(<:.cpp=.o)