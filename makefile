#Este es el archivo de makefile para revisarFrase.c

revisarFrase.exe: revisarFrase.o funFrase.o
	       gcc revisarFrase.o funFrase.o -o revisarFrase.exe

funPlantilla.o: funFrase.c defFrase.h
		gcc -c funFrase.c

plantilla.o: revisarFrase.c defFrase.h
	 gcc -c revisarFrase.c

clean:
	rm *.o
	rm *.txt
	rm *.bin
