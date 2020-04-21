# Change the name of EXEC to your executable
EXEC = chess
CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -g
SOURCES = ${wildcard *.cc}
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

