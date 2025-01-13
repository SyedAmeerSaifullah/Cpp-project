all: ./a.out

compRun:
	g++ -std=c++11 ticketsmain.cpp pmain.cpp staffmanagementfunction.cpp supplies.cpp tickets.cpp suppliesmain.cpp Tmain.cpp trains.cpp passengers.cpp -o r.out


run: clean compRun; ./r.out

clean:
	rm -f *.out
