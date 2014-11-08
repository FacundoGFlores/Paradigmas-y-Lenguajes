#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define NUM_THREADS 2
 
/* Una estructura para demostrar el manejo de threads */
typedef struct _PACKAGE_THREAD_T {
	int threadID;
	float data;
} PACKAGE_THREAD_T;
 
/* La función que ejecutaremos en forma concurrente */
void *worker(void *arg) {
	PACKAGE_THREAD_T *pkg = (PACKAGE_THREAD_T *)arg;
 
	fprintf(stdout, "Este es el thread con id: %d\n", pkg->threadID);
	fprintf(stdout, "El thread contiene la sig info: %f\n", pkg->data);
	pthread_exit(NULL);
}
 
int main(int argc, char **argv) {
	/* Un array con threads */
	pthread_t threads[NUM_THREADS];

	/* Auxiliares */
	int i, _error;

	/* Creamos un array PACKAGE_THREAD_T */
	PACKAGE_THREAD_T threads_pkg[NUM_THREADS];

	/* Creamos los threads */
	for (i = 0; i < NUM_THREADS; ++i) {
		threads_pkg[i].threadID = i;
		threads_pkg[i].data = i / 2.0f;
		//Intentamos la creación de un thread
		_error = pthread_create(&threads[i], NULL, worker, &threads_pkg[i]);
		if (_error){
		  fprintf(stderr, "error: pthread_create, rc: %d\n", _error);
		  return EXIT_FAILURE;
		}
	}

	/* Bloqueamos la ejecución hasta que todos los threads hayan terminado */
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_join(threads[i], NULL);

	return EXIT_SUCCESS;
}
