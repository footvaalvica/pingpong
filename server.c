#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TAMMSSG 1000

void trataPedido(char *buf) {
    printf("bom dia sou o chiquinho\n");
}

int main () {
    int fcli, fserv, n;
    char buf[TAMMSSG];

    if ((fserv = open("/tmp/servidor", O_RDONLY)) < 0) {
        return 1;
    } if ((fcli = open("/tmp/cliente", O_WRONLY)) < 0) {
        return 1;
    }

    while(1) {
        n = read(fserv, buf, TAMMSSG);
        if (n <= 0) {
            break;
        }
        trataPedido(buf);
        n = write(fcli, buf, TAMMSSG);
    }

    close(fserv);
    close(fcli);
    return 0;
}