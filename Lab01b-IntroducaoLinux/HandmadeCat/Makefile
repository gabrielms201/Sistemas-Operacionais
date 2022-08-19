PROGRAM_NAME = HandmadeCat


output: $(PROGRAM_NAME).o
	gcc $(PROGRAM_NAME).o -o $(PROGRAM_NAME)

$(PROGRAM_NAME).o: $(PROGRAM_NAME).c
	gcc -c $(PROGRAM_NAME).c

clean: 
	rm *.o $(PROGRAM_NAME)
