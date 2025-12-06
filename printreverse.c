#include <stdio.h>

int main(int argc, char *argv[]){

int startingIndex = argc-1;

while (startingIndex != 0){
printf("%s\n", argv[startingIndex--]);
}
}
