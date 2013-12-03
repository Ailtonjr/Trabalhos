#include <iostream>
#include <conio2.h>
using namespace std;

void forcatela()
{
    cout<<endl<<endl<<endl;
    printf("**********************************************\n");
    printf("*                JOGO DA FORCA               *\n");
    printf("*                                            *\n");
    printf("*         ___                                *\n");
    printf("*        |   |                               *\n");
    printf("*        |   O                               *\n");
    printf("*        |  /|\\                              *\n");
    printf("*        |   |                               *\n");
    printf("*        |  / \\                              *\n");
    printf("*        |                                   *\n");
    printf("*                                            *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
}

bool verifica(char pegalinha[], char vet[],int tam)
{
    int x=0;
    for(int i=0;i<tam;i++)
    {
        if (pegalinha[i]==vet[i])
            {
                x++;
            }
    }
    if(x==tam)
    return(true);
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");

    FILE *arq;
    int result;

    arq = fopen("Arquivo.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }
    int  i = 1,v=0;
    char pegalinha[100];
    char *fim;
    char dica1[50],dica2[50],vet[100];
    int palav,letra;
    bool final=false;

    do
    {
        palav = rand() % 20 + 1; // sorteia o indice em que está a palavra
    }while((palav%2)!=0);

    while (!feof(arq))
    {
        fim = fgets(pegalinha, 100, arq);  // Faz a leitura dos caracteres
        if (fim) // Se foi possível ler
        {
            if (i == palav)  // compara o indice com a palavra
            {
                break;
            }
        }
        i++;
    }
    //cout <<i<<" - "<<pegalinha;
    fscanf(arq,"%s %s",dica1,dica2);
   // cout<<dica1<<" "<<dica2<<endl;
    int tam = strlen(pegalinha)-1;
    //cout<<"tamanho"<<tam<<endl<<endl;
    fclose(arq);
    forcatela();
    char x;


    for(int i=0;i<tam;i++)
        {
            vet[i]='_';
        }
    while(!final)
    {

        int t=12;
        for(int i=0;i<tam;i++)
        {
            gotoxy(t,13);
            cout<<vet[i]<<" ";
            t+=2;
        }
        gotoxy(2,20);
        cin>>x;
        gotoxy(2,20);
        cout<<" ";

        for(int i=0;i<tam;i++)
        {
            if (x==pegalinha[i])
            {
                vet[i]=x;
            }
        }


        final=verifica(pegalinha,vet,tam);
        //cout<<"vet1 ";
       // for(int i=0;i<=tam;i++)
            //cout<<pegalinha[i];
        //cout<<"  vet2 ";
      //  for(int i=0;i<=tam;i++)
           // cout<<vet[i];
    }
    return 0;
}
