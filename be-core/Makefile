CORE_SRC_DIR=./demo/main.cpp ./demo/register.cpp ./demo/Events.cpp
DEMO_SRC_DIR=./src/attribute.cpp  ./src/datafield.cpp  ./src/module.cpp      ./src/persistence.cpp   ./src/session.cpp \
			 ./src/auth.cpp       ./src/event.cpp      ./src/moduleList.cpp  ./src/presentation.cpp  ./src/transaction.cpp \
			 ./src/context.cpp    ./src/eventRule.cpp  ./src/object.cpp      ./src/rule.cpp          ./src/utils.cpp
INC_DIR=./include
BOOST_INC_DIR=C:/Boost/include/boost-1_59
BOOST_LIB_DIR=C:/Boost/lib-tdmgcc-64

CC = g++
COMPILER_FLAGS = -w -std=c++11
LINKER_FLAGS = -lsqlite3 -lsoci_core_3_2 -llibsoci_sqlite3_3_2

SRC= ${CORE_SRC_DIR} ${DEMO_SRC_DIR}
HEADERS = -I./include -I./lib/soci/include -I./lib/sqlite3 -I${BOOST_INC_DIR}
LIBS = -L./lib/sqlite3 -L./lib/soci/lib -L${BOOST_LIB_DIR}

OBJ_NAME = demo.exe

all	:$(OBJS)
	$(CC) $(SRC) $(COMPILER_FLAGS) $(HEADERS) $(LIBS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f *.o *.exe
