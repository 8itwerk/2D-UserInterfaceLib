CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

debug:
	g++ $(CFLAGS) debug_main.cpp character.cpp display.cpp

ui:
	g++ -c ui_main.cpp
	g++ page.cpp ui_main.o -o ui $(SFML_FLAGS)

run:
	make ui
	./ui 

run_debug:
	./a.out

clean:
	rm ui *.o
