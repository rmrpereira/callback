#include <stdlib.h>
#include <signal.h>
#include "mod.h"


/*
 * Prototypes for internal (private) functions
 */
void module_service_routine(int signal);


/*
 * Function pointer to hold the user function to be called during interruption
 */
void (*fp)(void);

void initmodule(void (*user_fp))
{
  /* Install Ctrl-Z handler */
  signal(SIGTSTP, module_service_routine);

  /* Initialize the function pointer */
  fp = user_fp;

}

/*
 * module_service_routine
 *
 * In this case, the only action performed by the interrupt service routine
 * is to call the user provided function.
 */
void module_service_routine(int signal)
{
  if (fp == NULL)
  {
    fprintf(stderr,"Error: fp called with no init.");
    exit(-1);
  }
  else{
    (*fp)();
  }
}
