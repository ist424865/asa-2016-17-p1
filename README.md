## Análise e Síntese de Algoritmos - 1º Projeto
### Descrição do Problema

O Sr. João decidiu fazer um album de fotografias. Ao abrir uma gaveta num móvel da arrecada-
ção o Sr. João encontrou uma grande quantidade de fotografias que tinha acumulado ao longo
dos anos. As fotografias não eram digitais, tinham sido obtidas a partir de rolo fotográfico. O Sr.
João pensou que seria uma boa oportunidade para organizar um album de família que poderia
partilhar com os filhos e os netos.
O objectivo seria organizar as fotografias por data, contudo ele já não se lembra das datas
de todas as fotografias e a máquina que tinha usado também não guardava datas. Como as
fotografias não são digitais também não é possível ordenar pela data do ficheiro, ou pela metadata.
Tudo o que o Sr. João consegue fazer é comparar duas fotos, nalguns casos pensa que
sabe qual delas ocorreu primeiro.
O objectivo deste projeto é desenvolver um sistema que ajude o Sr. João com a sua tarefa.
Ele vai começar por numerar as fotografias e para alguns pares indicar qual das duas fotografias
acha que ocorreu primeiro. O objectivo do software é indicar qual é a ordem temporal das fotografias.
Contudo podem surgir alguns problemas. Pode acontecer que a informação fornecida
pelo Sr. João seja insuficiente e exista mais do que uma organização possível. O software deve
indicar esse problema. Também pode acontecer que o Sr. João se tenha enganado nalgumas
das relações que indicou e que portanto não é possível indicar uma ordem coerente. O software
também deve indicar esse problema.

### Input

O ficheiro de entrada contém a informação sobre a ordem relativa de alguns pares de fotografias.
1
O input é definido da seguinte forma:
- Uma linha com o número de fotografias N (N ≥ 2) e o número de pares para os quais é
conhecida a ordem L separados por um espaço em branco.
- Uma lista de L linhas, em que cada linha contém dois inteiros u e v (separados por um
espaço em branco) indicando que a primeira fotografia ocorreu antes da segunda.
Assume-se que a identificação das fotografias é um inteiro entre 1 e N.

### Output

O seu programa deverá escrever no output a seguinte informação:
- Caso não seja possível determinar uma organização temporal das fotografias porque há relações
inconsistentes, o output deve consistir de uma linha com a palavra Incoerente,
seguida de um caracter de fim de linha.
- Caso não seja possível determinar uma única organização temporal das fotografias porque
a informação é insuficiente, o output deve consistir de uma linha com a palavra
Insuficiente, seguida de um caracter de fim de linha.
- Se ambos os problemas ocorrerem simultaneamente deve ser apresentado o output do
caso Incoerente.
- Caso seja possível organizar as fotografias, então o output deverá consistir numa linha
de números correspondendo à organização temporal das fotografias, em que cada par de
números está separado por um espaço em branco. A linha termina com um caracter de
fim de linha.

<br/>
<hr>

### Exemplos
<br/>

**Input 1**

`4 4
1 2
2 3
3 2
3 4`

**Output 1**

`Incoerente`

<br/>

**Input 2**

`4 4
1 2
3 1
3 4
4 2`

**Output 2**

`Insuficiente`

<br/>

**Input 3**

`5 6
1 2
2 3
3 2
3 4
1 5
5 4`

**Output 3**

`Incoerente`

<br/>

**Input 4**

`5 4
1 2
2 3
3 4
4 5`

**Output 4**

`1 2 3 4 5`

<br/>

### Implementação

A implementação do projecto deverá ser feita preferencialmente usando as linguagens de programação
C ou C++. Submissões em linguagem Java também são aceitáveis, devendo no en-
3
tanto ter particular atenção a aspectos de implementação.
O tempo estimado para implementar este projecto é inferior a 10 horas.

<br/>

### Submissão do Projecto

A submissão do projecto deverá incluir um relatório resumido e um ficheiro com o código
fonte da solução. Serão utilizadas as plataformas Mooshak para a submissão do código e Fénix
para submissão do relatório. Informação sobre as linguagens de programação possíveis está
disponível no website do sistema Mooshak. A linguagem de programação é identificada pela
extensão do ficheiro. Por exemplo, um projecto escrito em c deverá ter a extensão .c. Após
a compilação, o programa resultante deverá ler do ’standard input’ e escrever para o ’standard
output’. Informação sobre as opções e restrições de compilação podem ser obtidas através do
botão ’help’ do sistema Mooshak. O comando de compilação não deverá produzir output, caso
contrário será considerado um erro de compilação.
O relatório deverá ser entregue no formato PDF com não mais de 4 páginas, fonte de 12pt,
e 3cm de margem. O relatório deverá incluir uma introdução breve, a descrição da solução, a
análise teórica e a avaliação experimental dos resultados. O relatório deverá incluir qualquer referência
que tenha sido utilizada na realização do projecto. Relatórios que não sejam entregues
em formato PDF terão nota 0. O código fonte deve ser submetido através do sistema Mooshak
e o relatório (em formato PDF) deverá ser submetido através do Fénix. O código fonte será
avaliado automaticamente pelo sistema Mooshak. Observe que apenas a última submissão será
considerada para efeitos de avaliação. Todas as submissões anteriores serão ignoradas; tal inclui
o código fonte e o relatório.
Os alunos são encorajados a submeter, tão cedo quanto possível, soluções preliminares para
o sistema Mooshak e para o Fénix. Note que também é possível submeter várias vezes no Fénix
e que não serão aceites relatórios fora de prazo e não haverá extensão de prazo.
O sistema Mooshak indica o tempo disponível para o projecto ser submetido. Os projectos
têm que ser submetidos para o sistema Mooshak; não existe outra forma de submissão do
projecto. Os relatórios têm que ser submetidos no sistema Fénix; não existe outra forma de
submissão dos relatórios.

<br/>

### Avaliação

O projecto deverá ser realizado em grupos de um ou dois alunos e será avaliado em duas fases.
Na primeira fase, durante a submissão, cada implementação será executada num conjunto de
testes, os quais representam 80% da nota final. Na segunda fase, o relatório será avaliado. A
nota do relatório contribui com 20% da nota final.

<br/>

### Avaliação Automática

A primeira fase do projecto é avaliada automaticamente com um conjunto de testes, os quais são
executados num computador com o sistema operativo GNU/Linux. É essencial que o código
fonte compile sem erros e respeite os standards de entrada e saída indicados anteriormente. Os
projectos que não respeitem os formatos especificados serão penalizados e poderão ter nota 0,
caso falhem todos os testes. Um conjunto reduzido de testes utilizados pelo sistema Mooshak
serão públicos. A maior parte dos testes não serão divulgados antes da submissão. No entanto,
todos os testes serão disponibilizados após o deadline para submissão do projecto. Além de verificar
a correcção do output produzido, o ambiente de avaliação restringe a mémoria e o tempo
de execução disponíveis. A maior parte dos testes executa o comando diff da forma seguinte:

<br/>

`diff output result`

<br/>

O ficheiro result contém o output gerado pelo executável a partir do ficheiro input. O
ficheiro output contém o output esperado. Um programa passa num teste e recebe o valor
correspondente, quando o comando diff não reporta quaisquer diferenças (i.e., não produz
qualquer output). Existem 16 testes. Assim, o sistema reporta um valor entre 0 e 16.
A nota obtida na classificação automática poderá sofrer eventuais cortes caso a análise do có-
digo demonstre recurso a soluções ajustadas a inputs concretos ou outputs aleatórios/constantes.




