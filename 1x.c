#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Artista {
  char nome[100];
  char genero[50];
  char local[100];
  char *albuns[50];
  int numAlbuns;
} Artista;

typedef struct ListaArtistas {
  Artista *artistas;
  int numArtistas;
} ListaArtistas;

// Prototipação das funções
void menuPrincipal();
void lerArquivoArtistas(ListaArtistas *lista);
void liberarListaArtistas(ListaArtistas *lista);
void mostrarArtistas(ListaArtistas *lista);
void inserirArtistaOrdenado(ListaArtistas *lista);
void removerArtista(ListaArtistas *lista);
void editarArtista(ListaArtistas *lista);
int buscarArtistaBinario(ListaArtistas *lista, char *nome);
int buscarAlbumSequencial(ListaArtistas *lista, char *nomeAlbum);
void salvarListaParaArquivo(ListaArtistas *lista);

int main() {
  ListaArtistas lista;
  lista.artistas = NULL;
  lista.numArtistas = 0;

  // Carrega artistas do arquivo
  lerArquivoArtistas(&lista);

  // Menu principal
  do {
    menuPrincipal();
    char opcao;
    scanf("%c", &opcao);
    switch (opcao) {
      case '1':
        inserirArtistaOrdenado(&lista);
        break;
      case '2':
        removerArtista(&lista);
        break;
      case '3':
        editarArtista(&lista);
        break;
      case '4':
        {
          char nome[100];
          printf("Digite o nome do artista a buscar: ");
          scanf("%s", nome);
          int posicao = buscarArtistaBinario(&lista, nome);
          if (posicao != -1) {
            printf("Artista encontrado na posição %d:\n", posicao + 1);
            mostrarArtista(&lista, posicao);
          } else {
            printf("Artista não encontrado.\n");
          }
        }
        break;
      case '5':
        {
          char nomeAlbum[100];
          printf("Digite o nome do álbum a buscar: ");
          scanf("%s", nomeAlbum);
          int encontrado = 0;
          for (int i = 0; i < lista.numArtistas; i++) {
            if (buscarAlbumsequencial (&lista, i, nomeAlbum)) {
              printf("Álbum encontrado na discografia de %s\n", lista.artistas[i].nome);
              encontrado = 1;
              break;
            }
          }
          if (!encontrado) {
            printf("Álbum não encontrado.\n");
          }
        }
        break;
      case '0':
        printf("Saindo do programa...\n");
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != '0');

  // Salva alterações no arquivo
  salvarListaParaArquivo(&lista);

  // Libera memória alocada
  liberarListaArtistas(&lista);

  return 0;
}

// Funções

void menuPrincipal(){
  printf("\nMenu Principal:\n");
  printf("1. Inserir novo artista\n");
  printf("2. Remover artista\n");
  printf("3. Editar artista\n");
  printf("4. Buscar artista por nome (binário)\n");
  printf("5. Buscar álbum por nome (sequencial)\n");
  printf("0. Sair\n");

 switch (opcao) {
            case 1:
                // Implemente a insercao ordenada de um novo artista
                break;
            case 2:
                // Implemente a remocao de um artista
                break;
            case 3:
                // Implemente a edicao de um artista
                break;
            case 4:
                // Implemente a busca binaria por um artista
                break;
            case 5:
                // Implemente a busca sequencial por um album
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        
    } while (opcao != 0);

    return 0;

}
