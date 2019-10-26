#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
  //Writing this string to the file
  char a[] = "Hello World\n";

  //Opening a file using file descriptor
  int fd = open("writefile.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
  if(fd < 0){
    perror("Error");
  }
  
  //Writing to a file
  int w = write(fd, a, sizeof(a)); 

  return 0;
}
