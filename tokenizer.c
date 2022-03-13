//****************************************************************************************************************************
//Program name: "Tokenizer".  This program demonstrates how to read from a file amd
//tokenize the string from the file based on a delimiter.  Copyright (C) 2021 Cory Caprioli    *
//                                                                                                                           *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.                                                                    *
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied         *
//warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     *
//A copy of the GNU General Public License v3 is available here:  <https://www.gnu.org/licenses/>.                           *
//****************************************************************************************************************************


//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this program is called a tokenizer. It takes a filename from the user and extracts
// the file's content into an array. it then gets a delimiter from the user to break up
// or tokenize the string into smaller strings, called tokens, based on that delimiter using strtok
// finally it prints out each token and stores them into an array.

int main(int argc, char const *argv[]) {

  char * token;
  char * filename = (char *)malloc(4096 * sizeof(char));
  char delim[2];
  char * file_content = (char *)malloc(16384 * sizeof(char));
  char * tokens_arr[500];

  printf("Welcome to Epic Software Systems, Inc. Head of Systems Lab: Cory Caprioli\n"); //greet the user
  printf("Enter the name of a file to be tokenized: "); //ask the user for a file name

  scanf("%s", filename); //get the file name from the user
  getchar();

  FILE * fptr = fopen(filename, "r"); // create a file pointer and open the file to be read from
  int k = 0;
  int onebyte;
  while ((onebyte = fgetc(fptr)) != EOF) { // read byte by byte until the end of file is reached
    file_content[k] = onebyte; // input each byte into the array
    k++; // increment to next array location
  }

  printf("%s", file_content); // print the array that we got from the file

  printf("%zu characters were read from the file into an array of the program.\n", strlen(file_content)); // print the number of charcters in the arry using strlen
  printf("The tokenizing is ready to begin.\n");
  printf("Enter the separator characters which may include white space and press enter: "); // ask for the delimiter character from the user

  fgets(delim, 2, stdin); // get the delimiter from the user

  printf("Confirmation: These are the separators => %s\n", delim); // show the user what the selected as a delimiter
  printf("Tokenizing has finished.\n");
  printf("Here is the complete list of tokens:\n");

  token = strtok(file_content, delim); // get the first token with strtok
  int i = 0;

  do {
    tokens_arr[i] = token; // before the loop starts input the first token we got outside the loop into the tokens array
    // while in the loop input each token into the tokens array
    i++; // increment to the next array location
  } while ((token = strtok(NULL, delim))); // loop until there are no tokens left and the file content array is NULL

  for(int j = 0; j < i; j++) {
    printf("token number %d is %s\n", j, tokens_arr[j]); // a loop to print out all the tokens with their respective number
  }

  printf("Total number of tokens is %d\n", i); // print the number of tokens using the i from the do-while loop
  printf("Have a nice evening.\n");


  return 0;
}
