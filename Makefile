OBJ = main.o ScreenText.o RandomObjects.o Controls.o imageloader.o
COMP = gcc

main: $(OBJ)
	$(COMP) -lglut -lGLU -lGL -lm $(OBJ) -o baron.out

main.o: main.cpp main.hpp
	$(COMP) -c main.cpp -o main.o

ScreenText.o: ScreenText.cpp ScreenText.hpp
	$(COMP) -c ScreenText.cpp -o ScreenText.o

RandomObjects.o: RandomObjects.cpp RandomObjects.hpp
	$(COMP) -c RandomObjects.cpp -o RandomObjects.o

Controls.o: Controls.cpp Controls.hpp
	$(COMP) -c Controls.cpp -o Controls.o

imageloader.o: imageloader.cpp imageloader.h
	$(COMP) -c imageloader.cpp -o imageloader.o

clean:
	rm -rf $(OBJ) baron.out
