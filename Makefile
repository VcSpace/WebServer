APP = WebServer
CXX = g++
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -W -Wall -std=c++11 -g
else
    CXXFLAGS += -W -Wall -std=c++11 -O2
endif

OBJS = ./server/server.cpp ./log/log.cpp ./sql/sql.cpp
LIB = -lpthread -lmysqlclient

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIB) -o ./build/$(APP)

clean:
	rm ./build/$(APP)