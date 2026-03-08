#include <stdio.h>
#include <time.h>
#include <unistd.h>

/******************
 *
 * Sudoku Solver
 *
 * ***************/

int main(int argc, char* argv[]) {
    time_t now = time(NULL);
    printf("%ld\n", now);

    sleep(2);

    time_t two_secs = time(NULL);
    printf("%ld\n", two_secs);

    double diff = difftime(two_secs, now);
    printf("diff: %f\n", diff);

    char* string_now = ctime(&now);
    printf("%s\n", string_now);

    struct tm* gm_time = gmtime(&now);

    printf("tm_sec: %d\n", gm_time->tm_sec);
    printf("tm_min: %d\n", gm_time->tm_min);
    printf("tm_hour: %d\n", gm_time->tm_hour);
    printf("tm_mday: %d\n", gm_time->tm_mday);
    printf("tm_mon: %d\n", gm_time->tm_mon);
    printf("tm_year: %d\n", gm_time->tm_year);
    printf("tm_wday: %d\n", gm_time->tm_wday);
    printf("tm_yday: %d\n", gm_time->tm_yday);
    printf("tm_isdst: %d\n", gm_time->tm_isdst);

    return 0;
}

