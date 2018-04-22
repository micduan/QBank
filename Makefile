CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD 
OBJECTS=main.o start.o question.o displayquestion.o file.o testbank.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=main -lallegro -lallegro_main -lallegro_dialog -lallegro_ttf -lallegro_font -lallegro_image
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.o main
.PHONY: clean
