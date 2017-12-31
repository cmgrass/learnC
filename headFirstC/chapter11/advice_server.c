#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void error(char *msg)
{
  fprintf(stderr, "%s: %i, %s\n", msg, errno, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[])
{
  int status = 0;

  char *advice[] = {
    "Don't wear that shirt, it's fugly!\r\n",
    "Bring home flowers, often.\r\n",
    "Stop lying.\r\n",
    "Take advantage of a company sponsored 401k match program.\r\n",
    "Bacon every day.\r\n"
  };

  /* Open Listener Socket */
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  if (listener_d == -1) {
    error("Could not open socket for listening.");
  }

  /* Bind the listener socket to a port */
  struct sockaddr_in socket_name;
  socket_name.sin_family = PF_INET; /* IPv4 */
  socket_name.sin_port = (in_port_t)htons(3123); /* Port Number */
  socket_name.sin_addr.s_addr = htonl(INADDR_ANY); /* use ANY interface */
  status = bind(listener_d, (struct sockaddr *) &socket_name,
                sizeof(socket_name));
  if (status == -1) {
    error("Could not bind listener socket to port");
  }

  /* Set Socket to Listen */
  status = listen(listener_d, 10);
  if (status == -1) {
    error("Could not listen");
  }

  /* Wait forever for connection partners */
  while(1) {
    puts("Waiting for connection");

    /* Accept a connection */
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr,
                           &address_size);
    if (connect_d == -1) {
      error("Error connecting to client");
    }

    /* Write to client socket */
    char *msg = advice[(rand() %5)]; /* random advice from our array 0 to 4 */
    status = send(connect_d, msg, strlen(msg), 0);
    if (status == -1) {
      error("Error writing to client");
    }

    /* Close the connection */
    status = close(connect_d);
    if (status == -1) {
      error("Could not close client socket");
    }

  } /* end-while */
  return 0;
}
