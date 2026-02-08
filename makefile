OUTPUT=sort
compile: main.cpp
	 g++ main.cpp -o $(OUTPUT)

run: $(OUTPUT)
	 ./$(OUTPUT) $(VAR)

clean: sort
	 rm sort
