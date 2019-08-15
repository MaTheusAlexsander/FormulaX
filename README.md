# FormulaX

<p align="center">
  <img src="figuras/logo.jpg?raw=true" alt="logo"/>
</p>



## Sumário

- [Introdução](#introdução)
- [Manual do Usuário](#manual-do-usu%C3%A1rio)
- [Interface no QT](#interface-no-qt)
- [Interface na Web](#interface-na-web)
- [Informações Técnicas](#informa%C3%A7%C3%B5es-t%C3%A9cnicas)
- [Materiais](#materiais)
- [Circuito](#circuito)

## Introdução
<p>O FormulaX é um sistema de monitoriamento da performance com iluminação inteligente. Nesse protópio o usuário poderá analisar a sua perfomace através da análise dos dados gerados a partir de sensor de infravermelho.</p>

## Manual do Usuário

#### Interface no QT

Na interface no Qt podemos manipular as funções do programa. Primeiramente, é necessário identificar a porta serial disponível para o acesso, somente depois de escolher a porta que conecta ao circuito o programa liberará ao usuário todas as outras funções, mas o usuário só terá acesso se a porta escolhida conectar com o circuito, caso não ocorra as outras funções permanecem bloqueadas.

![QT_PORTA](figuras/porta_qt.png)

Após configuramos a porta serial COM3, se faz necessário escolher a velocidade de comunicação, que por padrão, deverá ser escolhida 115200.

![QT_VELOCIDADE](figuras/velocidade_qt.png)

Para estabelecer a conexão é necessário que os passos anteriores estejam corretamente executados.

![qt_conexao](figuras/conexao_qt.png)

Pronto! Após estabelecermos a comunicação, o usuário pode definir o tempo que em o led ficar acesso após a atuação do infravermelho, como também liga-lo e desliga-lo no tempo que jugar necessário.

![qt_led](figuras/LED_QT.png)



#### Interface na Web

## Informações Técnicas

#### Materiais

- NODEMCU
- Sensor Infravermelho(3 receptor e 3 emissor)
- Protoboard
- 6 resistores de 220, 3 de 1k e 3 de 10k

###### Circuito

![circuito](figuras/circuito.jpeg)

INTERRUPÇÃO

<p>Utilizar interrupções significa definir um pino para detectar pulsos de tensão. Em nosso circuito utilizamos o parâmetro RISING pois ao interromper o IR(infrared) ocorre um pico de tensão.</p>
<p>Existem alguma peculiaridades no nodemcu para serem configuradas com o objetivo de fazer o pino de interrupção funcionar corretamente:</p>
<p>-Definir a versão da esp8266 para 2.5.0 pois as versões mais atualzadas não funcionam com as funções de interrupção;</p>
<p>-Utilizar as funcões attachInterrupt() e digitalPinToInterrupt() assim como definir o pino como INPUT_PULL UP, colocar o prefixo ICACHE_RAM_ATTR ao declarar a função de interrupção (Ex.: void ICACHE_RAM_ATTR interrupt()) e declarar qualquer variável utilizada na interrupção como volatile;</p>
<p>-ICACHE_RAM_ATTR serve para fazer a função rodar na RAM e volatile para assegurar o valor da variável caso utilize interrupções muito rápidas;</p>
<p>-Se utilizar dos pinos D0 a D7 ligar o pino a um resistor(de preferência com uma resistencia alta, como 10kOhms), o resistor ligar no terra e sua interrupção ligar no ponto pino-resistor, pois os pinos quando setados como INPUT_PULLUP e digitalPinToInterrupt() ficam em nivél alto o tempo todo;</p>







  
 






