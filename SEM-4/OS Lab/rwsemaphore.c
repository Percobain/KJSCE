#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct {
    int id;
    int rt;
    int wt;
    int ri;
    int wi;
    int nr;
    int nw;
} td;

sem_t mtx;
sem_t wrt;
int rc = 0;
int fr = 0;
int fw = 0;

void *reader(void *arg) {
    td *d = (td *)arg;
    for (int i = 0; i < d->nr; i++) {
        sem_wait(&mtx);
        rc++;
        if (rc == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mtx);

        printf("Reader %d is reading\n", d->id);
        sleep(d->rt);

        sem_wait(&mtx);
        rc--;
        if (rc == 0) {
            sem_post(&wrt);
        }
        sem_post(&mtx);

        sleep(d->ri);
    }

    printf("Reader %d finished reading\n", d->id);
    fr++;

    return NULL;
}

void *writer(void *arg) {
    td *d = (td *)arg;
    for (int i = 0; i < d->nw; i++) {
        sem_wait(&wrt);

        printf("Writer %d is writing\n", d->id);
        sleep(d->wt);

        sem_post(&wrt);

        sleep(d->wi);
    }

    printf("Writer %d finished writing\n", d->id);
    fw++;

    return NULL;
}

int main() {
    int nr, nw, rt, wt, ri, wi, npr, npw;

    printf("Enter the number of reader threads: ");
    scanf("%d", &nr);

    printf("Enter the number of writer threads: ");
    scanf("%d", &nw);

    printf("Enter the time for each read operation (seconds): ");
    scanf("%d", &rt);

    printf("Enter the time for each write operation (seconds): ");
    scanf("%d", &wt);

    printf("Enter the time interval between read operations (seconds): ");
    scanf("%d", &ri);

    printf("Enter the time interval between write operations (seconds): ");
    scanf("%d", &wi);

    printf("Enter the number of reads per reader: ");
    scanf("%d", &npr);

    printf("Enter the number of writes per writer: ");
    scanf("%d", &npw);

    // Renamed rt to reader_threads to avoid the naming conflict
    pthread_t reader_threads[nr], wt_arr[nw];
    td rd[nr], wd[nw];

    sem_init(&mtx, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < nr; i++) {
        rd[i].id = i + 1;
        rd[i].rt = rt;
        rd[i].ri = ri;
        rd[i].nr = npr;
        pthread_create(&reader_threads[i], NULL, reader, &rd[i]);
    }

    for (int i = 0; i < nw; i++) {
        wd[i].id = i + 1;
        wd[i].wt = wt;
        wd[i].wi = wi;
        wd[i].nw = npw;
        pthread_create(&wt_arr[i], NULL, writer, &wd[i]);
    }

    for (int i = 0; i < nr; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    for (int i = 0; i < nw; i++) {
        pthread_join(wt_arr[i], NULL);
    }

    printf("All readers and writers have finished\n");

    sem_destroy(&mtx);
    sem_destroy(&wrt);

    return 0;
}