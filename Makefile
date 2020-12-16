CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

tactics:
	g++ -c main.cpp
	g++ canvas.cpp main.o -o tactics $(SFML_FLAGS)

clean:
	rm tactics *.o

run:
	make tactics 
	./tactics 
