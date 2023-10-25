

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h> 

int selecione, x, menu;

// Definição da struct para representar um quarto
struct Quarto
{
    bool disponivel;
    int andar, numero;
    double preco;
    char nome_cliente[100], cpf_cliente[15], nomeF[30];
    char data_checkin[11], data_checkout[11];
} quartos[5][10][3]; // Inicialização dos quartos em uma array de structs;

void limpar_Tela()
{
    system("cls || clear"); // Limpa a tela no Windows e linux deixa o codigo mais limpo
}

int precoF(struct Quarto *quarto, int hotel, const char *nome_hotel); //Função dos aumentos nos valores

// A cima do main estão variaves e funções globais
int main()
{
    setlocale(LC_ALL, "Portuguese");

     char *nomeP, nomeF[30]; // Variáveis para login do funcionário, ponteiro e endereço
     nomeP = &nomeF[0];

    //funções sendo declaradas, seus codes estão no final do programa
    
    void desenhoM(); //Desenho de tela inicial
    INICIO: // Label para retornar a tela inicial
    desenhoM(); //chamada de função

    int menu1(); // Função para o primeiro menu
    int menu2(int hotel, char *nomeP); // Função para o menu secundario
    void senha1(); // Função para senha de acesso ao menu secundario

    int termosDeUso();
    void textoP(); // política de privacidade
    void textoT(); // termos de uso

     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            quartos[i][j][k].disponivel = true;
            quartos[i][j][k].andar = i + 1;
            quartos[i][j][k].numero = j + 1;

            switch (i + 1)
            { // preços por andar
            case 1:
                quartos[i][j][k].preco = 500.00;
                break;
            case 2:
                quartos[i][j][k].preco = 700.00;
                break;
            case 3:
                quartos[i][j][k].preco = 900.00;
                break;
            case 4:
                quartos[i][j][k].preco = 1100.00;
                break;
            case 5:
                quartos[i][j][k].preco = 1300.00;
                break;
            }
            }
        }
    }


    do
    {
         termosDeUso();

        if (x == 1)
        goto INICIO;
        
        REFAZ: //rótulo de salto para retornar ao menu hotéis (label)
        menu1(); // chamada de função, primeiro menu

        switch (menu)
        {
        case 1:
            limpar_Tela();
            printf("Você selecionou o Hotel São Paulo\n\n");

            printf("\tLogin de funcionário\n\n");
            printf("\nDigite o nome do funcionário: ");
            scanf(" %29[^\n]", nomeF);

            senha1(); //chamada de função, senha
            menu2(menu, &nomeF[0]); //chamada de função, menu secundario

            if(x==1)
               goto REFAZ; //volta para o menu inicial

            break;
        case 2:
            limpar_Tela();
            printf("Você selecionou o Hotel Rio de janeiro\n\n");

            printf("\tLogin de funcionário\n\n");
            printf("\nDigite o nome do funcionário: ");
            scanf(" %29[^\n]", nomeF);

            senha1();
            menu2(menu, &nomeF[0]);

            if (x == 1)
               goto REFAZ;
            
            break;
        case 3:
             limpar_Tela();
             printf("Você selecionou o Hotel Salvador\n\n");

             printf("\tLogin de funcionário\n\n");
             printf("\nDigite o nome do funcionário: ");
             scanf(" %29[^\n]", nomeF);
 
            senha1();
            menu2(menu, &nomeF[0]);

            if (x == 1)
                goto REFAZ;
            
            break;
        case 4:
            printf("\nSaindo do programa!\n\n");
            return 0; // Encerra o programa imediatamente
        default:
            printf("\n\nOpção inválida. Tente novamente.\n\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }

        // Limpar o menu de entrada
        while (getchar() != '\n')
            ;

        // Se o usuário não selecionou um hotel válido, continue pedindo a seleção do hotel
    } while (menu < 1 || menu > 3);
}

//funções criadas abaixo do main, para evitar poluição visual

int termosDeUso() {

POL:
  limpar_Tela();
  printf("\n\tPolítica de Privacidade de Dados:\n");
  textoP();
  printf("\n\n\tTermos de uso:\n");
  textoT();

  printf("\nPressione Enter para continuar...");
  getchar();
  while (getchar() != '\n')
    ;

  x = 0;

  char senha[7];
  char senha_correta = false;

  do {
    limpar_Tela();
    printf("Você aceita os Termos e Condições de uso? \n(aceito/recuso): ");
    scanf("%s", senha);
    if (strcmp(senha, "aceito") == 0 || strcmp(senha, "Aceito") == 0) {

      senha_correta = true;
    } else {
      printf("\n\nNão é possível prosseguir sem aceitar os Termos e Condições "
             "de uso.\n\n");

      printf("\nPressione Enter para continuar...");
      getchar();
      while (getchar() != '\n')
        ;

      do {
        limpar_Tela();
        printf("\n1- Voltar a tela inicial.\n2- Voltar à Política de "
               "Privacidade de Dados.\n\n");
        printf("Escolha uma opção para prosseguir: ");
        scanf("%d", &x);

        switch (x) {
        case 1:
          limpar_Tela();
          goto INICIO;
          break;
        case 2:
          goto POL;
          break;
        default:
          printf("\n\n>> Opção inválida, tente novamente. \n");

          printf("\nPressione Enter para continuar...");
          getchar();
          while (getchar() != '\n')
            ;
        }
      } while (x != 1 || x != 2);
    }
  } while (!senha_correta);

  if (x == 0)
    return x;

INICIO:
  x = 1;

  return x;
}

int menu1() {

  limpar_Tela();
  printf("Bem vindo! Qual hotel gostaria de se hospedar?\n\n");
  printf("1- Hotel São Paulo\n");
  printf("2- Hotel Rio de janeiro\n");
  printf("3- Hotel Salvador\n");
  printf("4- Sair\n");

  printf("\nDigite uma opção para continuar: ");
  scanf("%d", &menu);

  return menu;
}

void senha1(){

  int senha;
  int senha_correta = false;
  do
  {
      printf("Digite sua senha de acesso:");
      scanf("%d", &senha);
      if (senha == 123)
      {
          senha_correta = true;
      }
      else
      {
          printf("Senha incorreta !\n\n");
          printf("Pressione Enter para continuar...");
          getchar();
      }
  } while (!senha_correta);
  
}


int menu2(int hotel, char *nomeP){

     char *nome[] = {"Hotel Salvador", "Hotel São Paulo", "Hotel Rio de janeiro"}; // Nome dos hotéis para consulta de reserva, não alterar a ordem

  do
  {
      limpar_Tela();
      printf("Menu de Opções:\n\n");
      printf("1 - Quartos Disponíveis\n");
      printf("2 - Reservar um Quarto\n");
      printf("3 - Cancelar a Reserva\n");
      printf("4 - Consultar a Reserva\n");
      printf("5 - Gerar Cobrança\n");
      printf("6 - Gerar Relatórios\n");
      printf("7 - Voltar para a seleção de hotéis\n\n");
      printf("Escolha uma opção para prosseguir: ");
      scanf("%d", &selecione);

      switch (selecione)
      {
      case 1:

          limpar_Tela();
          printf("Você selecionou a Opção 1 - Quartos Disponíveis\n\n");

          int andar;
          printf("Selecione o andar (1°, 2°, 3°, 4°, 5°): ");
          scanf("%d", &andar);

          if (andar >= 1 && andar <= 5)
          {
              printf("\nQuartos disponíveis no %d° andar:\n\n", andar);

              for (int quarto = 0; quarto < 10; quarto++)
              {
                  if (quartos[andar - 1][quarto][hotel].disponivel)
                  {
                      printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
                      printf("Disponível\n");
                      printf("Preço: R$ %.2lf\n", quartos[andar - 1][quarto][hotel].preco);
                  }
                  else
                  {
                      printf("Quarto %d\n", quartos[andar - 1][quarto][hotel].numero);
                      printf("Indisponível\n");
                  }
                  printf("\n");
              }
          }
          else
          {
              printf("Andar inválido!\n");
          }

          printf("Pressione Enter para voltar ao menu...");
          getchar();
          break;

      case 2:

          limpar_Tela();
          //printf("Você selecionou a Opção 2 - Reservar um Quarto\n\n");

          char nome_cliente[100];
          char cpf_cliente[15];

          printf("Digite o nome do cliente: ");
          scanf(" %99[^\n]", nome_cliente);

          printf("Digite o CPF do cliente: ");
          scanf(" %14s", cpf_cliente);

          int andar_reserva, quarto_reserva;
          printf("\nSelecione o andar (1°, 2°, 3°, 4°, 5°): ");
          scanf("%d", &andar_reserva);

          if (andar_reserva >= 1 && andar_reserva <= 5)
          {
              printf("\nQuartos disponíveis no %d° andar:\n\n", andar_reserva);
              bool quartos_disponiveis_reserva = false;

              for (int quarto = 0; quarto < 10; quarto++)
              {
                  if (quartos[andar_reserva - 1][quarto][hotel].disponivel)
                  {
                      quartos_disponiveis_reserva = true;
                      printf("Quarto %d\n", quartos[andar_reserva - 1][quarto][hotel].numero);
                      printf("Preço: R$ %.2lf\n", quartos[andar_reserva - 1][quarto][hotel].preco);
                      printf("Disponível\n\n");
                  }
              }

              if (quartos_disponiveis_reserva)
              {
                  printf("Escolha o número do quarto desejado: ");
                  scanf("%d", &quarto_reserva);

                  if (quarto_reserva >= 1 && quarto_reserva <= 10 && quartos[andar_reserva - 1][quarto_reserva - 1][hotel].disponivel)
                  {
                      quartos[andar_reserva - 1][quarto_reserva - 1][hotel].disponivel = false;
                      strcpy(quartos[andar_reserva - 1][quarto_reserva - 1][hotel].nome_cliente, nome_cliente);
                      strcpy(quartos[andar_reserva - 1][quarto_reserva - 1][hotel].cpf_cliente, cpf_cliente);
                      strcpy(quartos[andar_reserva - 1][quarto_reserva - 1][hotel].nomeF, nomeP);

                      // Solicite a data de check-in
                      printf("\nDigite a data de check-in (dd/mm/yyyy): ");
                      scanf("%10s", quartos[andar_reserva - 1][quarto_reserva - 1][hotel].data_checkin);

                      // Solicite a data de check-out
                      printf("\nDigite a data de check-out (dd/mm/yyyy): ");
                      scanf("%10s", quartos[andar_reserva - 1][quarto_reserva - 1][hotel].data_checkout);

                      while (getchar() != '\n')
                          ;
                  }
                  else
                  {
                      printf("Quarto selecionado não está disponível ou é inválido.\n");
                  }
              }
              else
              {
                  printf("Nenhum quarto disponível neste andar para reserva.\n");
              }
          }
          else
          {
              printf("Andar inválido!\n");
          }

          printf("\nPressione Enter para voltar ao menu...");
          getchar();
          break;

      case 3:

          limpar_Tela();
          printf("Você selecionou a Opção 3 - Cancelar a Reserva\n\n");

          char cpf_cliente_cancelar[15];

          printf("Digite o CPF do cliente para cancelar a reserva: ");
          scanf(" %14s", cpf_cliente_cancelar);

          bool reserva_encontrada = false;

          for (int i = 0; i < 5; i++)
          {
              for (int j = 0; j < 10; j++)
              {
                for(int k = 0; k < 3; k++){
                  if (!quartos[i][j][k].disponivel && strcmp(quartos[i][j][k].cpf_cliente, cpf_cliente_cancelar) == 0)
                  {
                      quartos[i][j][k].disponivel = true;
                      strcpy(quartos[i][j][k].nome_cliente, "");
                      strcpy(quartos[i][j][k].cpf_cliente, "");
                      strcpy(quartos[i][j][k].nomeF, "");
                      reserva_encontrada = true;
                  }
                  }
              }
          }

          if (reserva_encontrada)
          {
              printf("Reserva cancelada com sucesso.\n\n");
          }
          else
          {
              printf("CPF inválido. Não foi possível encontrar a reserva.\n");
          }

          printf("\nPressione Enter para voltar ao menu...");
          getchar();
          break;

      case 4:

          limpar_Tela();
          printf("Você selecionou a Opção 4 - Consultar a Reserva\n\n");

          char cpf_consulta[15];
          printf("Digite o CPF do cliente para consultar a reserva: ");
          scanf(" %14s", cpf_consulta);

          bool reserva_encontrada_consulta = false;

          for (int i = 0; i < 5; i++)
          {
              for (int j = 0; j < 10; j++)
              {
                for(int k = 0; k < 3; k++){
                  if (!quartos[i][j][k].disponivel && strcmp(quartos[i][j][k].cpf_cliente, cpf_consulta) == 0)
                  {
                      printf("\nReserva encontrada: ");
                      printf("%s\n", nome[k]);
                      printf("Realiza por: %s\n", quartos[i][j][k].nomeF);
                      printf("\n");
                      printf("Andar: %d\n", quartos[i][j][k].andar);
                      printf("Número do Quarto: %d\n", quartos[i][j][k].numero);
                      printf("Nome do Cliente: %s\n", quartos[i][j][k].nome_cliente);
                      printf("CPF do Cliente: %s\n", quartos[i][j][k].cpf_cliente);
                      printf("Data de Check-in: %s\n", quartos[i][j][k].data_checkin);
                      printf("Data de Check-out: %s\n", quartos[i][j][k].data_checkout);
                      // Chame a função precoF para exibir o preço atualizado
                      precoF(&quartos[i][j][k], menu, nome[hotel - 1]);
                      printf("\n");
                      reserva_encontrada_consulta = true;
                  }
                  }
              }
          }

          if (!reserva_encontrada_consulta)
          {
              printf("CPF inválido. Não foi possível encontrar a reserva.\n");
          }

          printf("\nPressione Enter para voltar ao menu...");
          getchar();
          break;

      case 5:

          limpar_Tela();
          printf("Você selecionou a Opção 5 - Gerar Cobrança\n\n");

          int andar_cobranca;
          printf("Digite o andar para gerar a cobrança (1°, 2°, 3°, 4°, 5°): ");
          scanf("%d", &andar_cobranca);

          if (andar_cobranca >= 1 && andar_cobranca <= 5)
          {
              // Variável para rastrear se há pelo menos um quarto ocupado no andar
              bool quarto_ocupado = false;
              int quarto_pago = -1;

              printf("Quartos ocupados no %d° andar:\n\n", andar_cobranca);
              for (int quarto = 0; quarto < 10; quarto++)
              {
                  if (!quartos[andar_cobranca - 1][quarto][hotel].disponivel)
                  {
                      printf("Quarto %d\n", quartos[andar_cobranca - 1][quarto][hotel].numero);

                      printf("\n");
                      quarto_ocupado = true;
                  }
              }

              if (quarto_ocupado)
              {
                  int quarto_cobranca;
                  printf("Escolha o número do quarto para gerar a cobrança: ");
                  scanf("%d", &quarto_cobranca);

                  if (quarto_cobranca >= 1 && quarto_cobranca <= 10 && !quartos[andar_cobranca - 1][quarto_cobranca - 1][hotel].disponivel)
                  {
                      quarto_pago = quarto_cobranca - 1;

                      // Exibir informações detalhadas da reserva
                      printf("Reserva realiza por: %s\n", quartos[andar_cobranca - 1][quarto_pago][hotel].nomeF);
                      printf("\n");
                      printf("Nome do Cliente: %s\n", quartos[andar_cobranca - 1][quarto_pago][hotel].nome_cliente);
                      printf("CPF do Cliente: %s\n", quartos[andar_cobranca - 1][quarto_pago][hotel].cpf_cliente);
                      
                      // Chamando precoF para atualizar o preço
                      precoF(&quartos[andar_cobranca - 1][quarto_pago][hotel], hotel, nome[hotel]);
                      
                      printf("Data de Check-in: %s\n", quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkin);
                      printf("Data de Check-out: %s\n", quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkout);
                      printf("\n");

                      int pagamento_confirmado;
                      printf("Quarto %d pago? (1 para sim, 0 para não): ", quarto_cobranca);
                      scanf("%d", &pagamento_confirmado);

                      if (pagamento_confirmado == 1)
                      {
                          // Marcar o quarto como disponível novamente
                          quartos[andar_cobranca - 1][quarto_pago][hotel].disponivel = true;
                          strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].nome_cliente, "");
                          strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].cpf_cliente, "");
                          strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkin, "");
                          strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].data_checkout, "");
                          strcpy(quartos[andar_cobranca - 1][quarto_pago][hotel].nomeF, "");
                      }
                  }
                  else
                  {
                      printf("Quarto selecionado não está ocupado ou é inválido.\n");
                  }
              }
              else
              {
                  printf("Nenhum quarto ocupado neste andar para gerar cobrança.\n");
              }
          }
          else
          {
              printf("Andar inválido!\n");
          }

          printf("\nPressione Enter para voltar ao menu...");
          getchar(); // Limpa o buffer do teclado
          break;


      case 6:
          limpar_Tela();
          printf("Você selecionou a Opção 6 - Gerar Relatórios\n\n");

          int andar_relatorio;
          printf("Digite o andar para gerar o relatório (1°, 2°, 3°, 4°, 5°): ");
          scanf("%d", &andar_relatorio);

          if (andar_relatorio >= 1 && andar_relatorio <= 5)
          {
              // Loop para percorrer os quartos do andar especificado e mostra na tela apenas
              printf("Relatório de Quartos no %d° andar:\n\n", andar_relatorio);
              for (int quarto = 0; quarto < 10; quarto++)
              {
                  printf("Andar: %d\n", quartos[andar_relatorio - 1][quarto][hotel].andar);
                  printf("Número do Quarto: %d\n", quartos[andar_relatorio - 1][quarto][hotel].numero);
                  printf("Disponibilidade: %s\n", quartos[andar_relatorio - 1][quarto][hotel].disponivel ? "Disponível" : "Indisponível");
                  
                  precoF(&quartos[andar_relatorio - 1][quarto][hotel], hotel, nome[hotel]);
                  
                  if (!quartos[andar_relatorio - 1][quarto][hotel].disponivel)
                  {
                      printf("Nome do Cliente: %s\n", quartos[andar_relatorio - 1][quarto][hotel].nome_cliente);
                      printf("CPF do Cliente: %s\n", quartos[andar_relatorio - 1][quarto][hotel].cpf_cliente);
                      printf("Reserva realiza por: %s\n", quartos[andar_relatorio - 1][quarto][hotel].nomeF);
                  }
                  printf("\n");
              }
          }
          else
          {
              printf("Andar inválido!\n");
          }

          printf("Pressione Enter para voltar ao menu...");
          getchar();
          break;

      case 7:
          goto REFAZ; //volta para onde a palavra estiver, usar a variavel com moderação!!!
          break;

      default:
          limpar_Tela();
          printf("Opção inválida. Tente novamente.\n\n");
          printf("Pressione Enter para continuar...");
          getchar();
      }

      // Limpar o menu de entrada
      while (getchar() != '\n')
          ;

  } while (selecione != 7);

  if(x==0)
    return x;
  
    REFAZ:
    x=1;

  return x;
}

int precoF(struct Quarto *quarto, int hotel, const char *nome_hotel) {
  // Verificar se o quarto está reservado
  if (!quarto->disponivel) {
    // Obtenha a data atual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char data_atual[11];
    sprintf(data_atual, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1,
            tm.tm_mday);

    // Converter datas para o formato ano-mês-dia (yyyy-mm-dd) para facilitar a
    // comparação
    int ano_checkin, mes_checkin, dia_checkin;
    int ano_checkout, mes_checkout, dia_checkout;
    int ano_atual, mes_atual, dia_atual;

    sscanf(quarto->data_checkin, "%d/%d/%d", &dia_checkin, &mes_checkin,
           &ano_checkin);
    sscanf(quarto->data_checkout, "%d/%d/%d", &dia_checkout, &mes_checkout,
           &ano_checkout);
    sscanf(data_atual, "%d-%d-%d", &ano_atual, &mes_atual, &dia_atual);

    // Calcule a diferença de dias
    int dias_restantes = (ano_checkout - ano_atual) * 365 +
                         (mes_checkout - mes_atual) * 30 +
                         (dia_checkout - dia_atual);

    // Calcule o preço com base nas semanas adicionais (após a primeira semana)
    double preco_atualizado = quarto->preco;

    if (dias_restantes > 7) {
      int dias_excedentes = dias_restantes - 7;
      int semanas_adicionais =
          (dias_excedentes + 5) / 6; // Arredondamento para cima

      preco_atualizado +=
          semanas_adicionais *
          (0.10 * quarto->preco); // 10% a mais por semana adicional
    }

    // Exibir o preço atualizado apenas para quartos reservados
    printf("Preço:R$ %.2lf\n", preco_atualizado);
  }

  return x;
}

void desenhoM(){

   printf("              ____________  \n");
  printf("             //        / /\\ \n");
  printf("            //        / /  \\ \n");
  printf("           //________/ /    \\ \n");
  printf("          //        / /      \\ \n");
  printf("         //        / /        \\ \n");
  printf("        //________/ /          \\ \n");
  printf("       //        / /            \\ \n");
  printf("      //        / /              \\ \n");
  printf("     //________/ /                \\ \n");
  printf("    //        / /__________________\\ \n");
  printf("   //        / /       ________     \\ \n");
  printf("  //        / /       /       /\\     \\ \n");
  printf(" //________/ /_______/_______/__\\_____\\ \n");
  printf(" | |    | |  _______  _____           _ \n");
  printf(" | |    | | |  ___  ||_   _| ______  | | \n");
  printf(" | |____| | | |   | |  | |  |   ___| | | \n");
  printf(" |  ____  | | |   | |  | |  |  |___  | | \n");
  printf(" | |    | | | |   | |  | |  |   ___| | | \n");
  printf(" | |    | | | |___| |  | |  |  |___  | |______\n");
  printf(" |_|    |_| |_______|  |_|  |______| |________|\n\n");

  // Desenho que vai aparecer na tela inicial antes de iniciar o projeto
  printf("Pressione Enter para continuar...");
  getchar();
    
  while (getchar() != '\n');
}

void textoP() {}
void textoT() {}
