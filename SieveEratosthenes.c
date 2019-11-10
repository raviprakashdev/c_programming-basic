  
/* Universidade Federal do Espírito Santo - Ufes
   Centro Universitário Norte do Espírito Santo - Ceunes
   Sistemas Operacionais 2018/1 - TG20181
   
   Crivo de erastótenes com threads
   Data: XX/03
   Autores: Elyabe Alves / Danielli Costa / Thayza sacconi
  Obs.: Necessita de uma estrutura de fila, ver mais em https://github.com/daniellic9/Crivo_Erastotenes_SO
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef enum { FALSE, TRUE } Bool;

typedef long long unsigned lu_t;

#include "fila.h"

#define NUM_SIEVES 8
#define TAM_STORAGE 100
#define size_tp sizeof(lu_t)*8
#define i_div( i ) (i - 2)/(size_tp)
#define i_mod( i ) (i - 2)%(size_tp)

typedef struct resource
{
	// quantidade de longs que tem bits necessários para guardar os resultados
	lu_t id_thread,// id da thread  
		*storage,  // Vetor armazenamento
	 	i_sto,	   // Indice armazenamento [0, tam];
	 	size_sto;  // Tamanho maximo do armazem
	Fila *buffer;  // Buffer da sieve				
	sem_t sm_free_buff, sm_busy_buff;
	pthread_mutex_t mtx_fila;
	Bool wait;

} Resource_sieve ;

// prime : Vetor de bits 1: é primo, 0: nao primo
// tam_primo : Quantidade de numeros usados como vetor de bits
// N : Limitante superior do intervalo [2, N]
// M : Tamanho do buffer das sieves
// sieve_resp : String com id da sieve responsavel pela resposta
lu_t *prime = NULL, N, M, tam_prime;
char *sieve_resp = NULL;
Bool *primo = NULL;

Resource_sieve resources_sv[NUM_SIEVES];
pthread_t sieves[NUM_SIEVES];

pthread_mutex_t mutex_bits, mutex_result;
sem_t esp_bits, esp_bits_s, esp_resul, esp_resul_s;

// Incializa elementos necessários 
void initialize_parameters();

// Exibe o vetor de bits de resultados para primo (1), não primo (0)
void show_bits();

// Função que modela as tarefas de cada thread
void* thread_funcao( void *args );

// Exibe resultados das classificações final
void show_results();

// Thread principal
int main ( int argc, char const *argv[] )
{
	// Quantidade de argumentos passados
	// quantidade de longs que tem bits necessários para guardar os resultados
	// Exemplo: 1 long pode guardar o resultado de até 64 numeros. de 2 a 66, po
	if ( argc < 3 ) exit(0);

	lu_t id_thread, numero_test, id;
	
	N = atoi( argv[1] ); 
	M = atoi( argv[2] );
	
	// Testa números no intervalo [2,N]
	if ( N >= 2 && M )
	{	
		initialize_parameters();
		
		// Gera os números e insere na rede de sieves
		numero_test = 2;
		while ( numero_test <= N )
		{
			if ( !fila_cheia( resources_sv[0].buffer ) )	
				resources_sv[0].buffer = push_back( resources_sv[0].buffer, numero_test++ );
		}
	
		// Merge resultados
		for ( id = 0; id < NUM_SIEVES; id++ ) 
			pthread_join( sieves[id], NULL );
	
		//Exibe resultados
		// Exibe cada thread responsável pela classificação do número em questão
		show_results();
		show_bits();	
		printf("%s\n", sieve_resp );
		

	}

	return 1;
}


void* thread_funcao( void *args )
{
	Resource_sieve *param = (Resource_sieve*)args;
	lu_t num_teste, id, c;
	
	id = param -> id_thread;

	do
	{
	
		if ( !fila_vazia( param -> buffer ) )
		{	
			// Se a thread anterior foi morta
			// Espera ter alguém no buffer: PROBLEMA AQUI
			// if ( !fila_vazia( param -> buffer ) )
			{
					num_teste = pop( param -> buffer );
			}

			
			// Procura por múltiplo prime
			for ( c = 0; c < param -> i_sto && num_teste % param -> storage[c] != 0; c++ );

			// Não achou multiplo nessa sieve
			if ( c == param -> i_sto )
			{
				if ( id < NUM_SIEVES - 1 &&  param -> i_sto )
				{
					//Mutex : Acesso exclusivo a fila para modificação
					pthread_mutex_lock( &resources_sv[id+1].mtx_fila );
					resources_sv[id+1].buffer = push_back( resources_sv[id+1].buffer, num_teste );
					pthread_mutex_unlock( &resources_sv[id+1].mtx_fila );
					
					if ( num_teste < N ) continue;
					else break;
				} else
				{
					// Armazena o prime encontrado :: TRATAR ARMAZENAMENTO BUFFER
					if ( param -> i_sto < param -> size_sto ) 
						param -> storage[ param -> i_sto++ ] = num_teste;
					
					//Registra primalidade do número e thread reponsável pela classificação
					primo[num_teste - 2] = TRUE;
					sieve_resp[num_teste - 2] = id + '0';
					// bit_func( &prime[ i_div(num_teste) ], i_mod(num_teste), ^= );
				}
			} else 
			{
				// Seta no vetor de bits indicando que não é prime
					// bit_func( &prime[ i_div(num_teste) ], i_mod(num_teste), ^= );
				sieve_resp[num_teste - 2] = id + '0';

			}
		} 

	} while ( num_teste < N && param -> wait == TRUE );

	// Flag que indica se a thread deve continuar esperando 
	param -> wait = FALSE;
	
	if ( id < NUM_SIEVES - 1 )
	{
		//Colocar mutex aqui
		while( !fila_vazia( resources_sv[id+1].buffer ) );
		resources_sv[id+1].wait = FALSE;
		// sem_post( &buffer_livre[id+1]);
	}

	return (void*)prime;
}

// Inicializa o vetor resultado de primes
void initialize_parameters()
{
	// quantidade de longs que tem bits necessários para guardar os resultados
	// Exemplo: 1 long pode guardar o resultado de até 64 numeros. de 2 a 66, po
	tam_prime = ceil( ( N - 2 )/(size_tp) ); 
	prime = (lu_t*)calloc( tam_prime, sizeof(lu_t) ); 
	sieve_resp = (char*)calloc( N + 1, sizeof(char) );
	primo = (Bool*)calloc( N - 1, sizeof(Bool) );

	// Seta todos os bits para 1;
	memset( prime, 0, sizeof(prime) );
	memset( sieve_resp, 32, sizeof(char)*N + 1 );

	// Inicializa a thread e seus recursos
	for ( int id = 0; id < NUM_SIEVES; id++ )
	{
		
		resources_sv[id].id_thread = id;
		resources_sv[id].storage = (lu_t*)malloc( TAM_STORAGE*sizeof(lu_t) );
		resources_sv[id].size_sto = TAM_STORAGE;
		resources_sv[id].i_sto = 0;
		resources_sv[id].buffer = criar_fila(N);
		resources_sv[id].wait = TRUE;

		pthread_mutex_init( &resources_sv[id].mtx_fila, NULL );
		// sem_init( &resources_sv[id].sm_free_buff, 0, M );
		// sem_init( &resources_sv[id].sm_busy_buff, 0, 0 );			
		
		pthread_create( &sieves[id], NULL, thread_funcao, &resources_sv[id] );
	}
}

// Exibe o vetor completo de bits
void show_bits()
{
	lu_t pos, numero_test;
	numero_test = 1;
	while( ++numero_test <= N )
	{
	 	/*if ( bit_func( &prime[i_div(numero_test)], i_mod(numero_test), & ) ) printf("1");
	 	else printf("0");*/
	 	if ( primo[numero_test-2] == TRUE ) printf("1");
	 	else printf("0");
	}
	printf("\n");
}

void show_results()
{
	int numero_test, c, id_thread, tam;
	for ( numero_test = 2; numero_test <= N; numero_test++ )
	{
		id_thread = sieve_resp[numero_test - 2] - '0';
		if ( primo[numero_test - 2] == TRUE )/*bit_func( &prime[i_div(numero_test)], i_mod(numero_test) , & )*/  
		{	
			printf("%d is prime ( stored in sieve %c )\n", numero_test, sieve_resp[numero_test - 2] );
		}
		else
		{
			tam = resources_sv[ id_thread ].i_sto;
			lu_t *vet = resources_sv[ id_thread ].storage;
			for ( c = 0; c < tam && numero_test % vet[c] != 0 ; c++ );

			printf("%d divided by %lld in sieve %c\n", numero_test, vet[c], sieve_resp[ numero_test - 2 ] );

		}
	}
}
