CC = gcc
CFLAGS = -Wall -Wextra -O3 -lGL -lglfw -lGLEW
LDLIBS = -lGL -lglfw -lGLEW

SRC = game.c helper.c window.c
OBJ = ${SRC:.c=.o}
EXE = gameoflife

all: build run clean

build: comp link

comp:
	$(CC) $(CFLAGS) $(SRC) -c

link:
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

run:
	./$(EXE)

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} ${EXE}
# END
