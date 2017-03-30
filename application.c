/**
* ********************************************
* Grupo 40, Alameda.
* Joao Freitas, 83478, e Rui Ribeiro, 83562.
* ********************************************
*/

#include <stdio.h>
#include <stdlib.h>

/**
* No de uma lista de adjacencias
*/
typedef struct node {
    int destino; /* Representa a aresta do current no */
    struct node* next;
} *Node;


/**
* Lista de adjacencias com referencia para o primeiro no
*/
typedef struct list {
    Node head;
} *List;


/**
* Grafo com todas as listas de adjacencias
*/
typedef struct graph {
    int vertices;
    List listas;
} *Graph;


/**
* Inicializacao de Funcoes
*/
Node criaNode(int destino);
Graph criaGraph(int vertices);
void addAresta(Graph grafo, int fonte, int destino);
void visitDFS(Graph grafo, int vertice);
void visitDFS(Graph grafo, int vertice);
void verificaInsuficiencia(Graph grafo);
int verificaUnicidade(Graph grafo, int fonte, int destino);
void libertar(Graph grafo);


/**
* Variaveis Globais
*/
int tempo, *color, *pre, *d, *f;
Node topologicHead = NULL;



/**
* Funcao que cria nos
*/
Node criaNode(int destino) {
    Node novoNode = (Node) malloc(sizeof(struct node));
    novoNode->destino = destino;
    novoNode->next = NULL;
    return novoNode;
}


/**
* Funcao que cria grafos
*/
Graph criaGraph(int vertices) {
    Graph novoGraph = (Graph) malloc(sizeof(struct graph));
    novoGraph->vertices = vertices;

    /* Aloca memoria para as listas de adjacencia do grafo */
    novoGraph->listas = (List) malloc(vertices * sizeof(struct list));

    /*  Inicializa cada lista de adjacencias como vazia */
    int i;
    for (i=0; i<vertices; i++) {
        novoGraph->listas[i].head = NULL;
    }

    return novoGraph;
}


/**
* Funcao que cria arestas
*/
void addAresta(Graph grafo, int fonte, int destino) {
    destino--;
    Node novoNode = criaNode(destino);

    /* Adiciona a nova aresta ao inicio da lista de adjacencias correspondente */
    fonte--;
    novoNode->next = grafo->listas[fonte].head;
    grafo->listas[fonte].head = novoNode;
}


/**
* Funcao que executa o algoritmo DFS
*/
void DFS(Graph grafo) {

    int vertices = grafo->vertices;
    /*
    * 0 -> white
    * 1 -> grey
    * 2 -> black
    */
    color = (int*) malloc(vertices * sizeof(int));
    pre = (int*) malloc(vertices * sizeof(int));
    d = (int*) malloc(vertices * sizeof(int));
    f = (int*) malloc(vertices * sizeof(int));

    /* Inicializa as propriedade do DFS para cada vertice */
    int i;
    tempo = 1;

    for (i=0; i<vertices; i++) {
        color[i] = 0;
        pre[i] = -1;
    }

    /* Visita os vertices a branco */
    for (i=0; i<vertices; i++) {
        if (color[i] == 0) {
            visitDFS(grafo,i);

        }
    }
}


/**
* Funcao auxiliar ao algoritmo DFS
*/
void visitDFS(Graph grafo, int vertice) {

    /* Muda a cor do vertice visitado para cinzento e o tempo de inicio */
    color[vertice] = 1;
    d[vertice] = tempo;

    tempo++;

    Node current = grafo->listas[vertice].head;

    int destino;
    while(current != NULL) {
        destino = current->destino;
        if (color[destino] == 0) {
            pre[destino] = vertice;
            visitDFS(grafo, destino);
        }
        /* Verifica se a aresta e um back edge logo e ciclica */
        else if (color[destino] == 1) {
            printf("Incoerente\n");
            libertar(grafo);
            exit(0);
            /* Verifica se a aresta e um cross edge e altera o predecessor */
        }
        current = current->next;

    }
    while(current != NULL) {
        Node temp = current;
        current = current->next;
        free(temp);
    }

    color[vertice] = 2;

    /* Adiciona o vertice a uma lista ordenada topologicamente */
    if (topologicHead == NULL){
        topologicHead = criaNode(vertice + 1);
    }
    else {
        Node auxiliar = criaNode(vertice + 1);
        auxiliar->next = topologicHead;
        topologicHead = auxiliar;
    }
    f[vertice] = tempo;
    tempo++;

}


/**
* Funcao que verifica se existe uma ligacao entre dois vertices
*/
int verificaUnicidade(Graph grafo, int fonte, int destino) {

    Node current;
    current = grafo->listas[fonte].head;

    int destiny;
    while(current != NULL) {
        destiny = current->destino;
        if (destiny == destino) {
            return 1;
        }
        current = current->next;
    }
    return 0;

}


/**
* Funcao que verifica se o a informacao e insuficiente
*/
void verificaInsuficiencia(Graph grafo) {

    /* Verifica se existe apenas uma solucao para o grafo */
    Node current = topologicHead;

    int fonte, destino;
    while (current != NULL) {
        fonte = current->destino;
        if (current->next != NULL) {
            destino = current->next->destino;
            if (verificaUnicidade(grafo,--fonte,--destino) == 0) {
                printf("Insuficiente\n");
                libertar(grafo);
                exit(0);
            }
        }
        current = current->next;
    }

    /* Imprime a lista topografica */
    current = topologicHead;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("%d", current->destino);
        }
        else {
            printf("%d ", current->destino);
        }
        current = current->next;
    }
    printf("\n");
}


/**
* Funcao que liberta a memoria alocada
*/
void libertar(Graph grafo) {
    Node head = topologicHead;
    while(head != NULL) {
        Node temp = head;
        head = head->next;
        free(temp);
    }
    free(color);
    free(pre);
    free(d);
    free(f);
    int i;
    for (i=0; i<grafo->vertices; i++) {
        head = grafo->listas[i].head;
        while(head != NULL) {
            Node temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(grafo->listas);
    free(grafo);

}


int main(int argc, const char * argv[]) {
    int vertices, arestas;

    scanf("%d %d", &vertices, &arestas);
    Graph grafo = criaGraph(vertices);

    int i, ligacoes[arestas][2];
    for (i = 0; i < arestas; i++) {
        if (scanf("%d %d", &ligacoes[i][0], &ligacoes[i][1]) == EOF) {
            printf("Incoerente\n");
            libertar(grafo);
            exit(0);
        }
        addAresta(grafo,ligacoes[i][0],ligacoes[i][1]);
    }

    DFS(grafo);

    /* Verifica se ha um numero suficiente de arestas */
    if (arestas < vertices - 1){
        printf("Insuficiente\n");
        libertar(grafo);
        return 0;
    }

    verificaInsuficiencia(grafo);

    libertar(grafo);

    return 0;
}
