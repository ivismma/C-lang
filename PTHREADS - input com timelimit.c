#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <locale.h>
#include <sys/select.h> // <-- não irá compilar em Windows (!!!)
                        // use onlinegdb/etc nesse caso.
#define TIME_LIMIT 4 // 4s


/*  Prática de pthreads...

	Uso de threads para interromper um input e seguir em frente.
	- Uma thread para leitura.
	- Uma thread para contagem e checagem de tempo.
	
*/

// Se responder dentro do tempo, thread leitura cancela a thread timer.
// Se tempo esgotar, thread timer cancela a thread leitura.

typedef struct {
    char *msg;       // msg. do printf()
    int buffer;      // resposta
    bool answered;   // flag se respondeu ou não
} param_readInput;  

typedef struct {
    int limit;       // limite (por padrão, TIME_LIMIT) 
    bool *answered;  // ponteiro para o timer vigiar a flag
} param_timer;

static pthread_t th_input;  // thread de input
static pthread_t th_timer;  // thread p/ contagem de tempo

static void input(param_readInput *args) {
    args->answered = false;

    // uso de select para executar scanf somente no caso de input...
    printf("%s", args->msg);
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = TIME_LIMIT+2; // só para que a thread timer seja útil.
    tv.tv_usec = 0;
    
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    if (ret > 0) {
        scanf("%d", &args->buffer);
        args->answered = true; // atualiza flag e interrompe thread timer.
        if(pthread_cancel(th_timer) != 0){
			printf("falha na destruição da thread timer. terminando...\n");
			exit(11);
		}
    }
}

static void timer(param_timer *args) {
    for(int i = 0; i < TIME_LIMIT*100; ++i)
        usleep(10000); // checa de 10 em 10ms até completar tempo.
                       // (4s -> 400 checagens)
	
	// acabou o tempo... finaliza thread de leitura.
	if(pthread_cancel(th_input) != 0){
		printf("falha na destruição da thread leitura. terminando...\n");
		exit(12);
	}
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    printf("%d segundos para responder!\n\n", TIME_LIMIT);

    param_readInput argsRead = {"Quanto é 2 + 2?\n", 0, false};
    param_timer argsTimer = {TIME_LIMIT, &argsRead.answered};

    // criação das threads...
    if(pthread_create(&th_timer, NULL, (void *) timer, &argsTimer) != 0)
        return 1; // falha criaçao de thread.
    if(pthread_create(&th_input, NULL, (void *) input, &argsRead) != 0)
        return 1; // falha criaçao de thread.
    pthread_join(th_timer, NULL); // main() espera thread timer.


    if(argsRead.answered == false)
        printf("Você não respondeu a tempo! :(\n");
    else{
        if (argsRead.buffer == 4)
            printf("Resposta correta ;)\n");
        else
            printf("Resposta incorreta.\n");
    }
    printf("\n<restante do código aqui...>\n");
    return 0;
}
