CPPFLAGS = 
CC = gcc
CFLAGS = -Wall -Wextra -O3 -lGL -lglfw -lGLEW
LDFLAGS =
LDLIBS = -lGL -lglfw -lGLEW

SRC = game.c common.c window.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
EXE = gameoflife

all: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

window: window.o
	$(CC) $(CFLAGS) $(SRC) $(LDLIBS) -o $(EXE)

run:
	./$(EXE)

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} ${EXE}
# END
