//
// Created by Gao on 2022/11/26.
//

/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(void) {
    struct sockaddr_in servaddr, cliaddr;       /* 用socket的ipv4的结构初始化 */
    socklen_t cliaddr_len;
    int listenfd, connfd;                        /* 初始化fd */
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof (cliaddr);
        connfd = accept(listenfd,(struct sockaddr*)&cliaddr, &cliaddr_len );

        n = read(connfd,buf,MAXLINE);
        printf("received from %s at PORT %d\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
               ntohs(cliaddr.sin_port));

        for (i = 0; i < n; i++)
            buf[i] = toupper(buf[i]);
        write(connfd, buf, n);
        close(connfd);

    }
}