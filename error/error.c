#include "error.h"

char* get_error_message(const char* format,const char* argument)
{
  
  size_t needed = 0;
  if(argument)
      needed = snprintf(NULL, 0, format, argument) + 1; // + 1 to account for null terminator
  else
      needed = strlen(format) + 1; 
  char *buffer = (char*) malloc(needed);
  sprintf(buffer, format, argument);
  return buffer;
}

void log_error(char* message, int status)
{
    printf("%s", message);
    //Error message from libgit2
    const git_error *e = git_error_last();
    if(e) printf("Error %d/%d: %s\n", status, e->klass, e->message);
    free(message);
}

int handle_error(const char* format,const char* argument, int status)
{
    char* buffer = get_error_message(format, argument);
    log_error(buffer, status);
    return -1;
}
