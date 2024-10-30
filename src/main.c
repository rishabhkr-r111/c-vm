#include<stdio.h>
#include<stdbool.h>

typedef enum {
  PSH,
  ADD,
  POP,
  SET,
  HLT,
} InstructionSet;

const int pgm[] = {
 PSH, 5,
 PSH, 6, 
 ADD, 
 POP, 
 HLT,
};

int ip = 0;
bool running = true;

int fetch(){
  return pgm[ip];
}

int main() {
  while(running) {
    int inst = fetch();
    printf("%d", inst);
    if(inst == HLT){
      running = false;
    }
    ip++;
  }
  return 0;
}