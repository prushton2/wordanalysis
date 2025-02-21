
OBJFILES = main.o

%.o: src/%.cpp
	g++ -o $@ $< -c

make: $(OBJFILES)
	g++ -o main $(OBJFILES)
	./main