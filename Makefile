all:	signal-parent.o signal-child.o 
	g++ -o signal.exe signal-parent.o

signal-child.o:	signal-child.cpp 
		g++ -c signal-child.cpp
		g++ -o signal-child signal-child.cpp

signal-parent.o: signal-parent.cpp
		 g++ -c signal-parent.cpp

clean:
	rm *.o

