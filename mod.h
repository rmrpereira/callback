#include <stdio.h>

/*
 * initmodule
 *
 * Initializes the callback pointer, pointing to the function
 * provided by the user that will be called during the
 * interrupt service routine and installs the interrupt handler.
 *
 */
void initmodule(void (*user_fp));
