CORE_SRC_DIR=./src
DEMO_SRC_DIR=./demo
INC_DIR=./include
#agg_win32_bmp.cpp agg_platform_support.cpp

CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lsqlite3 -lsoci_core -lsoci-sqlite3

SRC= $(wildcard ${CORE_SRC_DIR} *.c) $(wildcard ${DEMO_SRC_DIR} /*.c)
HEADERS = -I./include -I./lib/soci/include -I./lib/sqlite3
LIBS = -L./lib/sqlite3 -L./lib/soci/lib

OBJ_NAME = demo.exe

all	:$(OBJS)
	$(CC) $(SRC) $(COMPILER_FLAGS) $(HEADERS) $(LIBS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f *.o *.exe
