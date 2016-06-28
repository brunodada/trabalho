#include <stdio.h>
#include <string.h>

void cadastro();
void listar();
void editar();
void excluir();

struct computadores{
	char modelo[30];
	int capmemoria;
	int caphd;
	int freqproc;
	char modproc[30];
}reg;

FILE *arq;
int teste;

main(){
	for(;;){
	int n;
	printf("___Digite 1 para cadastrar___\n");
	printf("___Digite 2 para listar______\n");
	printf("___Digite 3 para editar______\n");
	printf("___Digite 4 para excluir_____\n");
	printf("OPCAO:");
	scanf("%d", &n);
	switch(n){
			case 1:
				cadastro();
				break;
			case 2:
				listar();
				break;
			case 3:
				editar();
				break;
			case 4:
				excluir();
				break;
			default:
				break;
		}
	}
}

void cadastro(){
	arq=fopen("cad_pc.txt","ab");
	
	if(arq){
		printf("Entre com o modelo do PC:");
		scanf("%s", &reg.modelo);
		printf("Entre com a capacidade de memoria:");
		scanf("%d", &reg.capmemoria);
		printf("Entre com a capacidade de HD:");
		scanf("%d", &reg.caphd);
		printf("Entre com a frequencia do processador:");
		scanf("%d", &reg.freqproc);
		printf("Entre com o modelo do processador:");
		scanf("%s", &reg.modproc);
		fwrite(&reg, sizeof(struct computadores),1,arq);
	}
	fclose(arq);
}

void listar(){
	arq=fopen("cad_pc.txt","rb");
	if(arq){
		while(!feof(arq)){
			teste = fread(&reg, sizeof(struct computadores),1,arq);
			if (teste && strcmp){
			printf("%s\n", reg.modelo);
			printf("%d\n", reg.capmemoria);
			printf("%d\n", reg.caphd);
			printf("%d\n", reg.freqproc);
			printf("%s\n", reg.modproc);
		}
		}
	}
	fclose(arq);
}

void editar(){
	char nomepesq[30];
	int achei,apontador;
	arq=fopen("cad_pc.txt","rb+");
	if(arq){
		achei=0;
		printf("Qual deseja editar?");
		scanf("%s", &nomepesq);
		rewind(arq);
		apontador=0;
		while(!feof(arq) && achei==0){
			teste=fread(&reg, sizeof(struct computadores),1,arq);
			apontador++;
			if(teste){
				if(strcmp(reg.modelo,nomepesq)==0){
					printf("%s\n", reg.modelo);
					printf("%d\n", reg.capmemoria);
					printf("%d\n", reg.caphd);
					printf("%d\n", reg.freqproc);
					printf("%s\n", reg.modproc);
					achei=1;
					
					printf("Editando o registro\n");
					
					printf("Entre com o modelo do PC:");
					scanf("%s", &reg.modelo);
					printf("Entre com a capacidade de memoria:");
					scanf("%d", &reg.capmemoria);
					printf("Entre com a capacidade de HD:");
					scanf("%d", &reg.caphd);
					printf("Entre com a frequencia do processador:");
					scanf("%d", &reg.freqproc);
					printf("Entre com o modelo do processador:");
					scanf("%s", &reg.modproc);
					apontador--;
					fseek(arq,apontador * sizeof(struct computadores),SEEK_SET);
					teste=fwrite(&reg, sizeof(struct computadores),1,arq);
				}
			}
		}
	}
	fclose(arq);
}

void excluir(){
	char nomepesq[30];
	int achei,apontador;
	arq=fopen("cad_pc.txt","rb+");
	if(arq){
		achei=0;
		printf("Qual deseja excluir?");
		scanf("%s", &nomepesq);
		rewind(arq);
		apontador=0;
		while(!feof(arq) && achei==0){
			teste=fread(&reg, sizeof(struct computadores),1,arq);
			apontador++;
			if(teste){
				if(strcmp(reg.modelo,nomepesq)==0){
					printf("%s\n", reg.modelo);
					printf("%d\n", reg.capmemoria);
					printf("%d\n", reg.caphd);
					printf("%d\n", reg.freqproc);
					printf("%s\n", reg.modproc);
					achei=1;
					
					printf("Excluindo o registro...\n");
					
					strcpy(reg.modelo,"");
					reg.capmemoria=0;
					reg.caphd=0;
					reg.freqproc=0;
					strcpy(reg.modproc,"");
					apontador--;
					fseek(arq,apontador * sizeof(struct computadores),SEEK_SET);
					teste=fwrite(&reg, sizeof(struct computadores),1,arq);
					printf("\nExcluido com sucesso!\n\n");
				}
			}
		}
	}
	fclose(arq);
}

