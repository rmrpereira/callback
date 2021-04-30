#include <stdio.h>
#include <unistd.h>
#include "mod.h"

/*
 * User functions that can be selected to run in response to the interrupt
 */
void function1(void);
void function2(void);


int main (char nargin , char vararg[])
{
  printf("Callback demo.\n");
  printf("Type Ctrl-Z to generate an interruption.\n");
  printf("Ctrl-C terminates the programa.\n");

  /*
   * The argument passed to initmodule will be the function called
   * by the interrupt service routine.
   * It corresponds to a user function, executed when an interrupt is raised.
   *
   * In this example, it can be either function1 or function2.
   */
  initmodule(function2);

  /* Main loop, just for signalling that the program is alive... */
  while(1){
    sleep(1);
    printf(".");
    fflush(stdout);
  }
}

/*
 * First user defined function
 */
void function1(void)
{
  printf("This is function 1!\n");
  return;
}

/*
 * Second user defined function
 */
void function2(void)
{
  printf("This is function 2!\n");
  return;
}
