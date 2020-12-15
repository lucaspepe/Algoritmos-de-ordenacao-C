#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000 //DEFINI��O M�XIMA DO TAMANHO DO VETOR 10^9


//GERAR N�MEROS ALEAT�RIOS NO VETOR
void gerar_aleatorio(int *vetor, int tamanho){
	srand(time(NULL));
	int i, v;
	for(i = 0; i < tamanho; i++){
		v = rand() %MAX;
		vetor[i] = v;
	}	
}


//M�TODO DE COPIAR VETOR
void copia_vetor(int *vetor, int *vetor2,  int tam){
	int i;
	
	for(i = 0; i < tam; i++){
		vetor2[i] = vetor[i];
	}
}

//M�TODO DE COPIAR VETOR HEAP
void copia_vetor_heap(int *vetor, int *vetor3, int tam2){
	int i;
	
	for(i = 1; i < tam2; i++){
		vetor3[i] = vetor[i - 1];
	}
	
}

//IMPRESS�O DO VETOR NA TELA
void imprimir (int *vetor, int tam){
	printf("\n\nDados do vetor ");
	int i;
	for(i = 0; i < tam; i++){
		printf("[%d]\t", vetor[i]);
	}
}

//IMPRESS�O DO VETOR NA TELA HEAP
void imprimir_heap (int *vetor, int tam){
	printf("\n\nDados do vetor ");
	int i;
	for(i = 1; i < tam; i++){
		printf("[%d]\t", vetor[i+1]);
	}
}

//M�TODO DE INSER��O DIRETA
void insercao_direta(int *vetor, int tam){
		
	int i, j, aux;
		
	for(i = 1; i < tam; i++){
		aux = vetor[i];
		j = i - 1;

		while((j >= 0) && (aux < vetor[j])){
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = aux;
	}
	
	imprimir(vetor, tam);	
}

//M�TODO BUBBLE SORT
void bubble_sort(int *vetor, int tam){
	
	int aux, troca, j, i;
	j = tam - 1;
	do{
		troca = 0;
		for(i = 0; i < j; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				troca = 1;
			}
		}
		j--;		
	}while(troca);
	
	imprimir(vetor, tam);
	printf("\n\nOrdenacao Bubble Sort concluida com sucesso!");
}

//M�TODO DE SELE��O DIRETA
void selecao_direta(int *vetor, int tam){	

	int menor,posmenor, i, j;
	
  	for (i=0; i<tam; i++){
		menor=vetor[i];
		posmenor=i;
		for (j=i+1; j<tam; j++){
		 	 if (vetor[j]<menor){
				menor=vetor[j];
				posmenor=j;
			 }
		}
	vetor[posmenor]=vetor[i];
	vetor[i]=menor;
  }
	imprimir(vetor, tam); 
}

//M�TODO SHAKE SORT
void shakesort(int *vetor, int tam){
	
	int j,k,l,r, aux;
	
	l=1;  
 	k=tam-1;
 	r= k;
 	
 	do {
		for (j=r; j>=l; j--){
			if (vetor[j-1]>vetor[j]){
			 aux=vetor[j-1];
			 vetor[j-1] = vetor[j];
			 vetor[j] = aux;
			 k=j;
		 	}
		}
		
		l= k+1;
		
	   for (j=l; j<=r; j++){
			if (vetor[j-1]>vetor[j]){
			 aux=vetor[j-1];
			 vetor[j-1] = vetor[j]; 
			 vetor[j] = aux;
			 k=j;
			}
		}

		r=k-1;
		
	} while (l<=r);
	
	imprimir(vetor, tam); 
}


//M�TODO QUICK SORT
void quicksort(int *vetor, int e, int d){

	int i;
    if (d > e){ 
		i = particao (vetor, e, d); /* importante */
      	quicksort(vetor, e, i-1);
     	quicksort(vetor, i+1, d);
	}  
}

//PARTI��O QUICK SORT
int particao (int *vetor, int e, int d) {
	
	int v, i, j, aux;
	
  v = vetor[d];   
	i = e -1;   
	j = d;
	
 	do {  
		do{ 
        i = i+1; /* esquerda*/
	    }while ((vetor[i] < v) &&  (i < d)); 
	
   	do{ 
       		j = j-1; /* direita*/
		}while ((vetor[j] > v) && (j > 0)); 
	
    aux = vetor[i];  
		vetor[i] = vetor[j]; 
		vetor[j] = aux; 
        
 	}while (j > i);
	
	vetor[j] = vetor[i];  
	vetor[i] = vetor[d];
	vetor[d] = aux;
	
	return (i);
}


//M�TODO MERGE SORT
void mergesort(int *vetor, int e, int d){
  
  int meio;
  
  if (e < d-1)   {
	meio = (e + d)/2;
	mergesort(vetor, e, meio);
	mergesort(vetor, meio, d);
	intercala(vetor, e, meio, d);
 }
 
}

//INTERCALA M�TODO MERGE SORT
void intercala(int *vetor, int e, int meio, int d){
	
  int i, j, k, *w;

  w = (int *) malloc((d-e)*sizeof(int));
  i=e; 
  j=meio; 
  k=0;
  
  while (i < meio && j < d){
   if (vetor[i] < vetor[j])
	  w[k++]  = vetor[i++];
   else
	  w[k++] = vetor[j++];
  }
  
  while (i < meio){
	w[k++] = vetor[i++];
  }
  while (j < d){
	w[k++]=vetor[j++];
  }
  for (i=e; i<d; ++i){
	 vetor[i] = w[i-e];
  }
  free(w);
}


//M�TODO HEAP SORT
void heapsort (int *vetor, int n){
	
  int p, m, x; 
  
  for (p = n/2; p >= 1; --p){
      peneira (p, n, vetor); 		// monta um heap, partindo-se do vetor original
	}	
  for (m = n; m >= 2; --m) { 
      x = vetor[1];                	// coloca o maior na ultima posi��o
      vetor[1] = vetor[m];
      vetor[m] = x; 
      peneira (1, m-1, vetor);  	// reconstr�i o heap desconsiderando o �ltimo 
  } 
}

//PENEIRA HEAP SORT
void peneira (int p, int m, int *vetor){
	
 int x = vetor[p];
 
 while (2*p <= m){ 
	int f = 2*p; 
    if (f < m && vetor[f] < vetor[f+1]){
    	++f; 
	} 
	if (x >= vetor[f]){
		break; 
	} 
   	vetor[p] = vetor[f]; 
	p = f; 
 } 
	vetor[p] = x; 
} 



int main(){
	
	int num, *vetor, *vetor2, *vetor3, tam, tam2, i;
	char continuar;
	do{
		printf("======================================\n");
		printf(" 1 - Para Criar Vetor");
		printf("\n 2 - Exibir vetor original");
		printf("\n 3 - Ordenacao Insercao Direta");
		printf("\n 4 - Ordenacao Bubble Sort ");
		printf("\n 5 - Ordenacao Selecao Direta ");
		printf("\n 6 - Ordenacao Shake Sort ");
		printf("\n 7 - Ordenacao Quick Sort ");
		printf("\n 8 - Ordenacao Merge Sort ");
		printf("\n 9 - Ordenacao Heap Sort ");
		printf("\n 0 - Para sair");
		printf("\n======================================\n");
		
		printf("Digite um numero: ");		
		scanf("%d", &num);
		printf("Numero digitado: %d", num);	
	
		switch(num){
			case 1:
				printf("\n\nDigite o tamanho de vetor desejado: ");
				scanf("%d", &tam);
				vetor = (int*)malloc(tam*sizeof(int));
				vetor2 = (int*)malloc(tam*sizeof(int));				
				gerar_aleatorio(vetor, tam);
				printf("Vetor criado com sucesso!");
				break;
			case 2:
				imprimir(vetor, tam);
				break;	
			case 3:
				copia_vetor(vetor, vetor2, tam);
				insercao_direta(vetor2, tam);	
				break;
			case 4:
				copia_vetor(vetor, vetor2, tam);
				bubble_sort(vetor2, tam);
				break;
			case 5:
				copia_vetor(vetor, vetor2, tam);
				selecao_direta(vetor2, tam);
				break;
			case 6:
				copia_vetor(vetor, vetor2, tam);
				shakesort(vetor2, tam);
				break;
			case 7:
				copia_vetor(vetor, vetor2, tam);
				quicksort(vetor2, 0, tam-1);
				imprimir(vetor2, tam); 
				break;
			case 8:
				copia_vetor(vetor, vetor2, tam);
				mergesort(vetor2, 0, tam);
				imprimir(vetor2, tam);
				break;
			case 9:
				tam2 = tam + 1;
				vetor3 = (int*)malloc(tam2*sizeof(int));
				copia_vetor_heap(vetor, vetor3, tam2);
				heapsort(vetor3, tam2);
				imprimir_heap(vetor3, tam2);
				break;			
		}
	
		printf("\n\nDeseja voltar ao MENU? [S/N]? ");
		scanf(" %c", &continuar);
		system("cls");
		
	}while(continuar == 's');
return 0;
}
