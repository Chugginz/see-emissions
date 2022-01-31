#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
 
int main(int argc, char **argv) {
 
    struct hostent *host;
    struct sockaddr_in addr;
    int i;
 
    memset(&addr, '0', sizeof(addr));
 
    if(argc!=2) {
        printf("Please, Input IP Address or Domain Name\n");
        exit(1);
    }
 
    addr.sin_addr.s_addr=inet_addr(argv[1]);
    host=gethostbyaddr((char*)&addr.sin_addr, 4, AF_INET);
 
    if(host) {
        printf("DOMAIN NAME : %s \n\n",host->h_name);
    }
    else {
        host=gethostbyname(argv[1]);
        if(host) {
            printf("IP ADDRESS TYPE : %s \n", host->h_addrtype==AF_INET?"IPv4":"IPv6");
            printf("IP ADDRESS >>>> \n");
         
            for(i=0; host->h_addr_list[i]; i++) {
                puts(inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
            }
            fputc('\n',stdout);
        }
        else {
            printf("Get Host Error\n");
        }
    }
 
    return 0;
}
