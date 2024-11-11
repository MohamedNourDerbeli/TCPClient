/* sockets.c */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define PORT 80
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{

    int sockfd;
    struct sockaddr_in sock;
    char *IP, *data, buffer[BUFFER_SIZE];
    data = "HEAD / HTTP/1.0\r\n\r\n";

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <IP_address>\n", argv[0]);
        return -1;
    }
    IP = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        return -1;
    }

    sock.sin_port = htons(PORT);
    sock.sin_family = AF_INET;
    sock.sin_addr.s_addr = inet_addr(IP);

    if (connect(sockfd, (struct sockaddr *)&sock, sizeof(sock)) != 0)
    {
        perror("Error connecting");
        close(sockfd);
        return -1;
    }

    ssize_t bytes_sent = write(sockfd, data, strlen(data));
    if (bytes_sent < 0)
    {
        perror("Error writing to socket");
        close(sockfd);
        return -1;
    }

    memset(buffer, 0, 512);

    ssize_t bytes_read;
    while ((bytes_read = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0)
    {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (bytes_read < 0)
    {
        perror("Error reading from socket");
    }

    close(sockfd);

    return 0;
}
