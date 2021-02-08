excel: excel_main.o excel_utility.o
	g++ -o  excel excel_main.o excel_utility.o
excel_main.o: excel_main.cc
	g++ -g -c   excel_main.cc
excel_utility.o: excel_utility.cc
	g++ -g -c excel_utility.cc
clean:
	rm excel excel_main.o excel_utility.o

