#!/bin/sh
g++ -c src/main.cpp
g++ main.o -o ElieTest -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
rm main.o
./ElieTest
