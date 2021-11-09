/*Formato e tipos de Tramas

    - Tramas de Informação (I):
      | F | A | C | BCC1 | D1 | Data | Dn | BCC2 | F |

      F - Flag
      A - Campo de Endereço
      C - Campo de Controlo -> 0 S 0 0 0 0 0 0  - S = N(s)
      D1, Data, Dn - Campo de Informação (contém pacote gerado pela Aplicação)
      BCC1/2 - Campos de Protecção independentes (1 – cabeçalho, 2 – dados)
             - XOR (^) entre A e C
 
    - Tramas de Supervisão (S) e Não Numeradas (U):
      | F | A | C | BCC1 | F |
 
      F - Flag
      A - Campo de Endereço
      C - Campo de Controlo
          SET -  0 0 0 0 0 0 1 1 (set up)
          DISC - 0 0 0 0 1 0 1 1 (disconnect)
          UA -   0 0 0 0 0 1 1 1 (unnumbered acknowledgment)
          RR -   R 0 0 0 0 1 0 1 (receiver ready / positive ACK)
          REJ -  R 0 0 0 0 0 0 1  - R = N(r) (reject / negative ACK)
      BCC1 - Campo de Protecção (cabeçalho)
*/

#define TRAMA_SIZE 5
//I

#define FLAG 0x7E       //01111110 - valor dito nos slides
#define A_EE 0x03       //comandos Enviados pelo Emissor (EE) e Respostas enviadas pelo Recetor
#define A_ER 0x01       //comandos Enviados pelo Recetor (ER) e Respostas enviadas pelo Emissor

//S ou U

#define C_SET 0x03
#define C_DISC 0x0B
#define C_UA 0x07
//#define C_RR 0x_5  //What is R = N(r)??
//#define C_REJ 0x_1

#define BCC(A, C) A^C