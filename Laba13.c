Написать программу, обрабатывающую получение сигналов (SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). Также программа, может возбуждать эти сигналы по указанию пользователя. В качестве обработчика должно быть реализовано логирование (вывод на консоль). 

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigabrt_handler(int signum) {
    printf("Caught SIGABRT\n");
}

void sigfpe_handler(int signum) {
    printf("Caught SIGFPE\n");
}

void sigill_handler(int signum) {
    printf("Caught SIGILL\n");
}

void sigint_handler(int signum) {
    printf("Caught SIGINT\n");
}

void sigsegv_handler(int signum) {
    printf("Caught SIGSEGV\n");
}

void sigterm_handler(int signum) {
    printf("Caught SIGTERM\n");
}

int main(void) {
    // Register signal handlers
    signal(SIGABRT, sigabrt_handler);
    signal(SIGFPE, sigfpe_handler);
    signal(SIGILL, sigill_handler);
    signal(SIGINT, sigint_handler);
    signal(SIGSEGV, sigsegv_handler);
    signal(SIGTERM, sigterm_handler);

    // Simulate a signal
    raise(SIGINT);

    return 0;
}
