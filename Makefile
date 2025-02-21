
OBJFILES = main.o
PROGRAM = main

%.o: src/%.cpp
	g++ -o $@ $< -c

make: $(OBJFILES)
	g++ -o $(PROGRAM) $(OBJFILES)
	./$(PROGRAM)

clean:
	-rm $(OBJFILES)
	-rm $(PROGRAM)