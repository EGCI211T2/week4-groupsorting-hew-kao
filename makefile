
compile: main.cpp
	 g++ main.cpp -o sort

run: sort
	 ./sort $(VAR)

clean: sort
	 rm sort
