ElieTest: main.c 
     $(shell g++ -c src/main.cpp)
     $(shell g++ main.o -o ElieTest -lsfml-graphics -lsfml-window -lsfml-system)
     $(shell rm main.o)
     $(shell ./ElieTest)
