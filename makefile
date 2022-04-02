launch:	compil exe dot

compil:
	g++ ak.cpp ak_main.cpp -o e.exe

exe:
	./e.exe

dot:
	dot -Tpng graph.txt -o pict.png