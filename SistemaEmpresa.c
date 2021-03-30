#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct cadastro{
    int cod;
    char nome[50], emp[50], dep[50], tel[15], cel[15];
    }CAD;

typedef struct elemento *Lista;


Lista cria_lista();


CAD cadastro(Lista *li);


int cria_codigo(Lista *li, int codigo);


int insere_funcionario(Lista *li, CAD cl);


int exibe_relatorio_cres(Lista *li);


int exibe_relatorio_decres(Lista *li);


int busca_codigo(Lista *li, int cod);

int busca_nome(Lista *li, char nome[50]);


int tamanho_lista(Lista *li);


int edita_funcionario(Lista *li, int cod);


int remove_funcionario(Lista *li, int cod);


void grava_arquivo(Lista *li, FILE *f);


void apaga_lista(Lista *li);

struct elemento{
    CAD dados;
    struct elemento *prox, *ant;
};

typedef struct elemento ELEM;

Lista cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

CAD cadastro(Lista *li){
    CAD cl;
    int codigo =1;
    while(cria_codigo(li, codigo) == 1){
        codigo++;
    }
    cl.cod = codigo;
    printf("Seu codigo é: %d\n", cl.cod);
    fflush(stdin);
    printf("Digite seu nome: ");
    gets(cl.nome);
    fflush(stdin);
    printf("Digite o seu e-mail: ");
    gets(cl.emp);
    fflush(stdin);
    printf("Digite o nome do setor a que pertence: ");
    gets(cl.dep);
    fflush(stdin);
    printf("Digite seu número de telefone: ");
    gets(cl.tel);
    fflush(stdin);
    printf("Digite seu número de celular: ");
    gets(cl.cel);
    return cl;
}

int cria_codigo(Lista *li, int cod){
    ELEM *no= *li;
    while(no != NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no != NULL){
        return 1;
    }else{
    return 0;
    }
}

int insere_funcionario(Lista *li, CAD cl){
    if(li == NULL){
            return 0;
        }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cl;
    if(*li == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        ELEM *anterior, *atual=*li;
        while(atual != NULL && atual->dados.cod < cl.cod){
            anterior = atual;
            atual= atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant=no;
            no->prox=(*li);
            *li = no;
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return 1;
}

int exibe_relatorio_cres(Lista *li){
    int cont =0;
    if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        no = no->prox;
        cont++;
        system("pause");
    }
    if(cont != 0){
    return 1;
    }else{
     return 0;
    }
}

int exibe_relatorio_decres(Lista *li){
    int cont=0;
    if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no->prox != NULL){
        no=no->prox;
    }
    while(no != NULL){
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        cont++;
        system("pause");
        no = no->ant;
    }
    if(cont !=0){
    return 1;
    }else{
     return 0;
    }
}

int  busca_codigo(Lista *li, int cod){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        printf("======================\n\n");
        printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
     return 1;
    }
}

int busca_nome(Lista *li, char nome[50]){
    int cont=0;
     if(li == NULL || *li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL ){
            if(strncmp(no->dados.nome, nome, strlen(nome)) == 0){
            printf("======================\n\n");
            printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
            system("pause");
            cont++;
            }
        no=no->prox;
    }
    if(cont != 0){
        return 1;
    }else{
        return 0;
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int cont=0;
    ELEM *no = *li;
    while(no != NULL){
        cont++;
        no= no->prox;
    }
    return cont;
}

int edita_funcionario(Lista *li, int cod){
    if(li == NULL){
            return 0;
        }
    int opc, opc2;
    char novo[50];
    ELEM *no = *li;
    while(no != NULL && no->dados.cod != cod){
            no=no->prox;
        }
    if(no == NULL){
        return 0;
    }
    CAD cl;
    do{
        printf("\n\n======== INFORMAÇOES DO FUNCIONÁRIO =============\n\n");
        printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
        printf("|1| - Alterar nome\n|2| - Alterar e-mail\n|3| - Alterar Setor\n|4| - Alterar telefone\n|5| - Alterar celular\n|6| - Voltar\nDigite a opção: ");
        scanf("%d", &opc);
        switch(opc){
          case 1:system("cls");
            printf("Digite o novo nome: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo nome: %s\n\nNovo nome: %s\n",no->dados.nome, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n|1| - Efetuar troca de dados \n|2| - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.nome, novo);
            }
            system("pause");
            system("cls");
            break;
         case 2:system("cls");
            printf("Digite o novo e-mail: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo e-mail: %s\n\nNovo e-mail: %s\n",no->dados.emp, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n|1| - Efetuar troca de dados \n|2| - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.emp, novo);
            }
            system("pause");
            system("cls");
            break;
            case 3:system("cls");
            printf("Digite o novo nome do setor: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo nome do setor: %s\n\nNovo nome do setor: %s\n",no->dados.dep, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n|1| - Efetuar troca de dados \n|2| - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strcpy(no->dados.dep, novo);
            }
            system("pause");
            system("cls");
            break;
            case 4:system("cls");
            printf("Digite o novo número de telefone: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo número de telefone: %s\n\nNovo número de telefone: %s\n",no->dados.tel, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n|1| - Efetuar troca de dados \n|2| - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strncpy(no->dados.tel,  novo,10);
            }
            system("pause");
            system("cls");
            break;
            case 5:system("cls");
            printf("Digite o novo celular: ");
            fflush(stdin);
            gets(novo);
            printf("\nAntigo número de celular: %s\n\nNovo número de celular: %s\n",no->dados.cel, novo );
            printf("\t\t\n=================== OPÇÕES ======================\n|1| - Efetuar troca de dados \n|2| - Cancelar troca de dados\nDigite a opção: ");
            scanf("%d", &opc2);
           if(opc2 == 1){
            strncpy(no->dados.cel, novo, 10);
            }
            system("pause");
            system("cls");
            break;
        }
    }while(opc != 6);
    return 1;
}

int remove_funcionario(Lista *li, int cod){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    int opc;
    while(no!= NULL && no->dados.cod != cod){
        no=no->prox;
    }
    if(no == NULL){
        return 0;
    }
    printf("\n\n============= INFORMAÇOES DO FUNCIONÁRIO =============\n\n");
    printf("Codigo: %d\nNome: %s\nE-mail: %s\nSetor: %s\nTelefone: %s\nCelular: %s\n\n", no->dados.cod, no->dados.nome, no->dados.emp, no->dados.dep, no->dados.tel, no->dados.cel );
    printf("\t\t\n=================== OPÇÕES ======================\n|1| - Demitir Funcionário \n|2| - Cancelar demissão do Funcionário \nDigite a opção: ");
    scanf("%d", &opc);
    if( opc == 1){
    if(no->ant == NULL){
        *li = no->prox;
    }else{
     no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
    }else{
        return 0;
    }
}

void grava_arquivo(Lista *li, FILE *f){
    ELEM *no= *li;
     while(no !=NULL){
        fwrite(&no->dados, sizeof(CAD),1,f);
        no = no->prox;
    }
}

void apaga_lista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li)!=NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, cod, x, ordem, n = 0;
    char nome[50];
    CAD cl;
    FILE *f;
    Lista *li;
    li=cria_lista();
    f = fopen("funcionarios.bin", "rb");
     if(f !=NULL){
        while(!feof(f)){
            n = fread(&cl,sizeof(CAD),1,f);
            if(n == 1){
                insere_funcionario(li,cl);
            }
        }
     }
     fclose(f);
    do{
        
        system("cls");
		system("color F1");
		printf("\n\n |------------------------------------------------------------|\n",201,187);
		printf(" |                                                            |\n");
		printf(" |\t\tSISTEMA DE CONTROLE EMPRESARIAL               | \n");
		printf(" |\t by: Alexssandro Rodrigues e Eudson Christyan         |\n");
		printf(" |                                                            |\n");
		printf(" |------------------------------------------------------------|\n\n",200,188);
		printf("|1| - Inserir novo Funcionário\n|2| - Gerar relatório total\n|3| - Gerar relatório individual\n|4| - Gerar relatório por nome\n|5| - Tamanho da lista\n|6| - Editar dados do Funcionário\n|7| - Remoção de Funcionário\n|8| - Salvar alterações e sair\n|9| - Sair sem salvar alteracões\n\nDigite a opção: ");
        scanf ("%d", &opcao);
    
        
        switch (opcao){
            case 1:
            	system("color F1");
                system("cls");
                printf("\t====================================\n\t=== INSERÇÃO DE NOVO FUNCIONÁRIO ===\n\t====================================\n");
                cl = cadastro(li);
                insere_funcionario(li, cl);
                if(x){
                    printf("\nFuncionário inserido com sucesso.\n\n");
                }else{
                    printf("\nFuncionário inserido com sucesso.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                printf("\t============================\n\t=== GERAÇÃO DE RELATÓRIO ===\n\t============================\n");
                printf("|1| - Exibir em ordem crescente\n|2| - Exibir em ordem decrescente\n|3| - Voltar\nDigite a opção: ");
                scanf("%d", &ordem);
                switch(ordem){
                    case 1:
                    x = exibe_relatorio_cres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista está vazia\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                    case 2:
                    x =exibe_relatorio_decres(li);
                    if(x){
                        printf("\n\n");
                    }else{
                        printf("\nA lista está vazia\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                default: ;
                system("cls");
                }

            break;
            case 3:
                system("cls");
                printf("\t=======================================\n\t=== GERAÇÃO DE RELATÓRIO INDIVIDUAL ===\n\t=======================================\n");
                printf("Digite o código a ser buscado: ");
                scanf("%d", &cod);
                x = busca_codigo(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro, código inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 4:
                system("cls");
                printf("\t=====================================\n\t=== GERAÇÃO DE RELATÓRIO POR NOME ===\n\t=====================================\n");
                printf("Digite o nome a ser buscado: ");
                fflush(stdin);
                gets(nome);
                x = busca_nome(li,nome);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro, nome inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 5: system("cls");
                printf("\t========================\n\t=== TAMANHO DA LISTA ===\n\t========================\n");
                x = tamanho_lista(li);
                printf("Tamanho da lista é: %d funcionário(s)\n", x);
                system("pause");
                system("cls");
            break;
            case 6: system("cls");
                printf("\t=============================\n\t=== EDIÇÃO DE FUNCIONÁRIO ===\n\t=============================\n");
                printf("Digite o código do funcionário a ser editado: ");
                scanf("%d", &cod);
                x = edita_funcionario(li, cod);
                if(x){
                    printf("\n\n");
                }else{
                    printf("\nErro ao editar, código inválido.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 7: system("cls");
                printf("\t==============================\n\t=== REMOÇÃO DE FUNCIONÁRIO ===\n\t==============================\n");
                printf("Digite o código do funcionário a ser removido: ");
                scanf("%d", &cod);
                x = remove_funcionario(li,cod);
                if(x){
                    printf("\nFuncionário removido com sucesso !\n\n");
                }else{
                    printf("\nErro ao remover funcionário.\n\n");
                }
                system("pause");
                system("cls");
            break;
            case 8: 
                    f = fopen("funcionarios.bin", "wb");
                    grava_arquivo(li, f);
                    fclose(f);
            break;
        default: ;
        }
    }while(opcao != 8 && opcao != 9);
    apaga_lista(li);
    return 0;
}
