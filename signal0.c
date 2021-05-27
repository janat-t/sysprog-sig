#include <signal.h> /* signal */
#include <unistd.h> /* write */

void handler(int sig) {
    return;
}

void alarm_handler(int sig) {
    write(STDERR_FILENO, "*", 1);
    alarm(5);
    return;
}

int main() {
    /* Exercise 1: Implement here. */
    signal(SIGINT, handler);

    /* Exercise 2: Implement here. */
    signal(SIGALRM, alarm_handler);
    alarm(5);

    /* Prints dots. */
    for (;;) {
        for (int j = 0; j < 1024 * 1024 * 500; j++)
            ; /* busy loop */
        write(STDERR_FILENO, ".", 1);
    }
    return 0;
}
