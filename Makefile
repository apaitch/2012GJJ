CXX = g++
CXXFLAGS = -g -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

EXEC = main
OBJ = main.o ImageManager.o Game.o
DEPENDS = ${OBJ:.o=.d}

${EXEC} : ${OBJ} 
	${CXX} ${CXXFLAGS} ${OBJ} -o ${EXEC} ${LIBS}

-include ${DEPENDS}

clean :
	rm ${OBJ} ${DEPENDS} 

