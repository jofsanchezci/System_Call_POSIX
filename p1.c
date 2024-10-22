#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Crea un proceso hijo

    if (pid == -1) {
        // Error al crear el proceso
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Código del proceso hijo
        printf("Soy el proceso hijo con PID %d\n", getpid());
        execlp("/bin/ls", "ls", NULL);  // Reemplaza el proceso hijo con otro
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Código del proceso padre
        wait(NULL);  // Espera a que el proceso hijo termine
        printf("Soy el proceso padre con PID %d\n", getpid());
    }

    return 0;
}
