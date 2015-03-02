simulator: simulator.o job.o resource.o
	g++ -std=c++11 -o simulator simulator.o job.o resource.o scheduler.o

simulator.o: simulator.cc
	g++ -std=c++11 -c simulator.cc

scheduler.o: scheduler.cc
	g++ -std=c++11 -c scheduler.cc 

job.o: job.cc job.h
	g++ -std=c++11 -c job.cc

resource.o: resource.cc resource.h
	g++ -std=c++11 -c resource.cc