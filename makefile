ElieTest: main.cpp
     $(shell g++ -c src/main.cpp)
     $(shell g++ main.o -o ElieTest -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
     $(shell rm main.o)
     $(shell ./ElieTest)
