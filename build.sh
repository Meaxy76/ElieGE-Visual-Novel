#!/bin/sh
cd src
g++ -c *.cpp -fpermissive
g++ *.o -o ElieTest -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
rm main.o
./ElieTest
