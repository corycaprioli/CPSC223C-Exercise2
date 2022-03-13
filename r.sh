#/bin/bash

#Program: Tokenizer
#Author: Cory Caprioli

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile tokenizer.c"
gcc -c -Wall -m64 -fno-pie -no-pie -o token.o tokenizer.c -std=gnu11

echo "Link the object files"
gcc -m64 -no-pie -o toke.out token.o -std=gnu11

echo "Run the program Tokenizer:"
./toke.out

echo "The script file will terminate"
