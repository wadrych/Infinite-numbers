aisd: main.o comparer.o digit.o number.o numbersArray.o
	g++ -o aisd main.o comparer.o digit.o number.o numbersArray.o
main.o: main.cpp
	g++ -c main.cpp
comparer.o: comparer.cpp comparer.h
	g++ -c comparer.cpp
digit.o: digit.cpp digit.h
	g++ -c digit.cpp
number.o: number.cpp number.h
	g++ -c number.cpp 
numbersArray.o: numbersArray.cpp numbersArray.h
	g++ -c numbersArray.cpp

clean:
	rm aisd main.o comparer.o digit.o number.o numbersArray.o