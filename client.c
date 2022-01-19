#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TAMMSSG 1000

void produzMsg (char *buf) {
    strcpy (buf, "Mensagem de teste");
}

void trataMsg (char *buf) {
    printf("Recebeu: %s\n", buf);
}

int main () {
    int fcli, fserv;
    char buf[TAMMSSG];

    if ((fserv = open("/tmp/servidor", O_WRONLY)) < 0) {
        return 1;
    } if ((fcli = open("/tmp/cliente", O_RDONLY)) < 0) {
        return 1;
    }

    produzMsg(buf);
    write(fserv, buf, TAMMSSG);
    read(fcli, buf, TAMMSSG);
    trataMsg(buf);

    close(fserv);
    close(fcli);
    return 0;
}