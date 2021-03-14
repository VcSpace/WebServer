APP = WebServer
CXX = g++
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -W -Wall -g
else
    CXXFLAGS += -W -Wall -O2
endif

OBJS = main.cpp ./server/server.cpp ./sql/sql.cpp ./log/log.cpp
LIB = -lpthread -lmysqlclient

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ./build/$(APP) $(LIB)

clean:
	rm ./build/$(APP)