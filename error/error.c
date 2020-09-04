#include "error.h"
#include <string.h>

char* get_error_message(const char* format,const char* argument)
{
  
  size_t needed = 0;
  if(argument)
      needed = snprintf(NULL, 0, format, argument) + 1;
  else
      needed = strlen(format);
  char *buffer = malloc(needed);
  sprintf(buffer, format, argument);
  return buffer;
}

void log_error(char* message)
{
    printf("%s", message);
    free(message);
}

int handle_error(const char* format,const char* argument)
{
    char* buffer = get_error_message(format, argument);
    log_error(buffer);
    return -1;
}
