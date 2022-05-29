// file that will link the neccessary files when the program is being compiled

cipher: cipher.c functions.o
	gcc -o cipher cipher.c functions.o

functions.o: functions.c
	gcc -c functions.c
