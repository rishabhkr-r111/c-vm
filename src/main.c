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
int sp = -1;
int stack[256];


int fetch(){
  return pgm[ip];
}

void eval(int inst){
  switch (inst)
  {
  case HLT: {
    running = false;
    break;
  }
  case PSH:{
    stack[++sp] = pgm[++ip];
    break;
  }
  case POP:{
    int x = stack[sp];
    printf("poped value %d \n", x);
    sp--;

    break;
  }
  case ADD:{
    int x = stack[sp--];
    int y = stack[sp--];
    stack[++sp] = x + y;

    break;
  }
  
  default:
    break;
  }
}

int main() {
  while(running) {
    int inst = fetch();
    printf("%d \n", inst);
    eval(inst);
    ip++;
  }
  return 0;
}