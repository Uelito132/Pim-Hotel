<<<<<<< HEAD
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// DefiniÁ„o da struct para representar um quarto
struct Quarto
{
    bool disponivel;
    int andar, numero;
    double preco;
    char nome_cliente[100], cpf_cliente[15];
    char data_checkin[11], data_checkout[11];
};

void limpar_Tela()
{
    system("cls"); // Limpa a tela no Windows deixa o codigo mais limpo
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int selecione;

    // InicializaÁ„o dos quartos em uma array de structs
    struct Quarto quartos[5][10];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            quartos[i][j].disponivel = true;
            quartos[i][j].andar = i + 1;
            quartos[i][j].numero = j + 1;

            switch (i + 1)
            { // preÁos por andar
            case 1:
                quartos[i][j].preco = 500.00;
                break;
            case 2:
                quartos[i][j].preco = 700.00;
                break;
            case 3:
                quartos[i][j].preco = 900.00;
                break;
            case 4:
                quartos[i][j].preco = 1100.00;
                break;
            case 5:
                quartos[i][j].preco = 1300.00;
                break;
            }
        }
    }

    int menu;

    do
    {
        limpar_Tela();
        printf("Bem vindo! Qual hotel gostaria de se hospedar?\n\n");
        printf("1- Hotel Tokyo\n");
        printf("2- Hotel Holandes\n");
        printf("3- Hotel Miles Morales\n");
        printf("4- Sair\n");

        printf("\nDigite uma opÁ„o para continuar: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("VocÍ selecionou o Hotel Tokyo\n");

            int senha;
            int senha_correta = false;
            do
            {
                limpar_Tela();
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

            int selecione;
            do
            {
                limpar_Tela();
                printf("Menu de OpÁıes:\n\n");
                printf("1 - Quartos DisponÌveis\n");
                printf("2 - Reservar um Quarto\n");
                printf("3 - Cancelar a Reserva\n");
                printf("4 - Consultar a Reserva\n");
                printf("5 - Gerar CobranÁa\n");
                printf("6 - Gerar RelatÛrios\n");
                printf("7 - Voltar para a seleÁ„o de hotÈis\n\n");
                printf("Escolha uma opÁ„o para prosseguir: ");
                scanf("%d", &selecione);

                switch (selecione)
                {
                case 1:
                    limpar_Tela();
                    printf("VocÍ selecionou a OpÁ„o 1 - Quartos DisponÌveis\n\n");

                    int andar;
                    printf("Selecione o andar (1∞, 2∞, 3∞, 4∞, 5∞): ");
                    scanf("%d", &andar);

                    if (andar >= 1 && andar <= 5)
                    {
                        printf("\nQuartos disponÌveis no %d∞ andar:\n\n", andar);

                        for (int quarto = 0; quarto < 10; quarto++)
                        {
                            if (quartos[andar - 1][quarto].disponivel)
                            {
                                printf("Quarto %d\n", quartos[andar - 1][quarto].numero);
                                printf("DisponÌvel\n");
                                printf("PreÁo: R$ %.2lf\n", quartos[andar - 1][quarto].preco);
                            }
                            else
                            {
                                printf("Quarto %d\n", quartos[andar - 1][quarto].numero);
                                printf("IndisponÌvel\n");
                            }
                            printf("\n");
                        }
                    }
                    else
                    {
                        printf("Andar inv·lido!\n");
                    }

                    printf("Pressione Enter para voltar ao menu...");
                    getchar();
                    break;

                case 2:

                    limpar_Tela();
                    //printf("VocÍ selecionou a OpÁ„o 2 - Reservar um Quarto\n\n");

                    char nome_cliente[100];
                    char cpf_cliente[15];

                    printf("Digite o nome do cliente: ");
                    scanf(" %99[^\n]", nome_cliente);

                    printf("Digite o CPF do cliente: ");
                    scanf(" %14s", cpf_cliente);

                    int andar_reserva, quarto_reserva;
                    printf("\nSelecione o andar (1∞, 2∞, 3∞, 4∞, 5∞): ");
                    scanf("%d", &andar_reserva);

                    if (andar_reserva >= 1 && andar_reserva <= 5)
                    {
                        printf("\nQuartos disponÌveis no %d∞ andar:\n\n", andar_reserva);
                        bool quartos_disponiveis_reserva = false;

                        for (int quarto = 0; quarto < 10; quarto++)
                        {
                            if (quartos[andar_reserva - 1][quarto].disponivel)
                            {
                                quartos_disponiveis_reserva = true;
                                printf("Quarto %d\n", quartos[andar_reserva - 1][quarto].numero);
                                printf("PreÁo: R$ %.2lf\n", quartos[andar_reserva - 1][quarto].preco);
                                printf("DisponÌvel\n\n");
                            }
                        }

                        if (quartos_disponiveis_reserva)
                        {
                            printf("Escolha o n˙mero do quarto desejado: ");
                            scanf("%d", &quarto_reserva);

                            if (quarto_reserva >= 1 && quarto_reserva <= 10 && quartos[andar_reserva - 1][quarto_reserva - 1].disponivel)
                            {
                                quartos[andar_reserva - 1][quarto_reserva - 1].disponivel = false;
                                strcpy(quartos[andar_reserva - 1][quarto_reserva - 1].nome_cliente, nome_cliente);
                                strcpy(quartos[andar_reserva - 1][quarto_reserva - 1].cpf_cliente, cpf_cliente);

                                // Solicite a data de check-in
                                printf("\nDigite a data de check-in (dd/mm/yyyy): ");
                                scanf("%10s", quartos[andar_reserva - 1][quarto_reserva - 1].data_checkin);

                                // Solicite a data de check-out
                                printf("\nDigite a data de check-out (dd/mm/yyyy): ");
                                scanf("%10s", quartos[andar_reserva - 1][quarto_reserva - 1].data_checkout);

                                while (getchar() != '\n')
                                    ;
                            }
                            else
                            {
                                printf("Quarto selecionado n„o est· disponÌvel ou È inv·lido.\n");
                            }
                        }
                        else
                        {
                            printf("Nenhum quarto disponÌvel neste andar para reserva.\n");
                        }
                    }
                    else
                    {
                        printf("Andar inv·lido!\n");
                    }

                    printf("\nPressione Enter para voltar ao menu...");
                    getchar();
                    break;

                case 3:
                    limpar_Tela();
                    printf("VocÍ selecionou a OpÁ„o 3 - Cancelar a Reserva\n\n");

                    char cpf_cliente_cancelar[15];

                    printf("Digite o CPF do cliente para cancelar a reserva: ");
                    scanf(" %14s", cpf_cliente_cancelar);

                    bool reserva_encontrada = false;

                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            if (!quartos[i][j].disponivel && strcmp(quartos[i][j].cpf_cliente, cpf_cliente_cancelar) == 0)
                            {
                                quartos[i][j].disponivel = true;
                                strcpy(quartos[i][j].nome_cliente, "");
                                strcpy(quartos[i][j].cpf_cliente, "");
                                reserva_encontrada = true;
                            }
                        }
                    }

                    if (reserva_encontrada)
                    {
                        printf("Reserva cancelada com sucesso.\n\n");
                    }
                    else
                    {
                        printf("CPF inv·lido. N„o foi possÌvel encontrar a reserva.\n");
                    }

                    printf("\nPressione Enter para voltar ao menu...");
                    getchar();
                    break;

                case 4:

                    limpar_Tela();
                    printf("VocÍ selecionou a OpÁ„o 4 - Consultar a Reserva\n\n");

                    char cpf_consulta[15];
                    printf("Digite o CPF do cliente para consultar a reserva: ");
                    scanf(" %14s", cpf_consulta);

                    bool reserva_encontrada_consulta = false;

                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            if (!quartos[i][j].disponivel && strcmp(quartos[i][j].cpf_cliente, cpf_consulta) == 0)
                            {
                                printf("Reserva encontrada:\n");
                                printf("Andar: %d\n", quartos[i][j].andar);
                                printf("N˙mero do Quarto: %d\n", quartos[i][j].numero);
                                printf("Nome do Cliente: %s\n", quartos[i][j].nome_cliente);
                                printf("CPF do Cliente: %s\n", quartos[i][j].cpf_cliente);
                                printf("Data de Check-in: %s\n", quartos[i][j].data_checkin);
                                printf("Data de Check-out: %s\n", quartos[i][j].data_checkout);
                                printf("PreÁo: R$ %.2lf\n", quartos[i][j].preco);
                                printf("\n");
                                reserva_encontrada_consulta = true;
                            }
                        }
                    }

                    if (!reserva_encontrada_consulta)
                    {
                        printf("CPF inv·lido. N„o foi possÌvel encontrar a reserva.\n");
                    }

                    printf("\nPressione Enter para voltar ao menu...");
                    getchar();
                    break;

                case 5:
                    limpar_Tela();
                    printf("VocÍ selecionou a OpÁ„o 5 - Gerar CobranÁa\n\n");

                    // Implemente o cÛdigo para gerar cobranÁa aqui

                    printf("Pressione Enter para voltar ao menu...");
                    getchar(); // Limpa o buffer do teclado
                    break;

                case 6:
                    limpar_Tela();
                    printf("VocÍ selecionou a OpÁ„o 6 - Gerar RelatÛrios\n\n");

                    int andar_relatorio;
                    printf("Digite o andar para gerar o relatÛrio (1∞, 2∞, 3∞, 4∞, 5∞): ");
                    scanf("%d", &andar_relatorio);

                    if (andar_relatorio >= 1 && andar_relatorio <= 5)
                    {
                        // Loop para percorrer os quartos do andar especificado e mostra na tela apenas
                        printf("RelatÛrio de Quartos no %d∞ andar:\n\n", andar_relatorio);
                        for (int quarto = 0; quarto < 10; quarto++)
                        {
                            printf("Andar: %d\n", quartos[andar_relatorio - 1][quarto].andar);
                            printf("N˙mero do Quarto: %d\n", quartos[andar_relatorio - 1][quarto].numero);
                            printf("Disponibilidade: %s\n", quartos[andar_relatorio - 1][quarto].disponivel ? "DisponÌvel" : "IndisponÌvel");
                            printf("PreÁo: R$ %.2lf\n", quartos[andar_relatorio - 1][quarto].preco);
                            if (!quartos[andar_relatorio - 1][quarto].disponivel)
                            {
                                printf("Nome do Cliente: %s\n", quartos[andar_relatorio - 1][quarto].nome_cliente);
                                printf("CPF do Cliente: %s\n", quartos[andar_relatorio - 1][quarto].cpf_cliente);
                            }
                            printf("\n");
                        }
                    }
                    else
                    {
                        printf("Andar inv·lido!\n");
                    }

                    printf("Pressione Enter para voltar ao menu...");
                    getchar();
                    break;

                case 7:
                    break;

                default:
                    limpar_Tela();
                    printf("OpÁ„o inv·lida. Tente novamente.\n\n");
                    printf("Pressione Enter para continuar...");
                    getchar();
                }

                // Limpar o menu de entrada
                while (getchar() != '\n')
                    ;

            } while (selecione != 7);


        case 2:
            printf("VocÍ selecionou o Hotel Holandes\n");
            break;
        case 3:
            printf("VocÍ selecionou o Hotel Miles Morales\n");
            break;
        case 4:
            printf("Saindo do programa!\n\n");
            return 0; // Encerra o programa imediatamente
        default:
            printf("OpÁ„o inv·lida. Tente novamente.\n\n");
            printf("Pressione Enter para continuar...");
            getchar();
            break;
        }

        // Limpar o menu de entrada
        while (getchar() != '\n')
            ;

        // Se o usu·rio n„o selecionou um hotel v·lido, continue pedindo a seleÁ„o do hotel
    } while (menu < 1 || menu > 3);
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void limpar_Tela() {
    system("cls"); // Limpa a tela no Windows
}
//teste de edi√ß√£o
void main() {
    setlocale(LC_ALL, "Portuguese");

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

   int senha;
    int senha_correta = false;

    do {
        limpar_Tela();
        printf("Digite sua senha de acesso:");
        scanf("%d", &senha);

        if (senha == 123) {
            senha_correta = true;
        } else {
            printf("Senha incorreta !\n\n");
            printf("Pressione Enter para continuar...");
            getch();
        }
    } while (!senha_correta);

    // Aqui fiz uma verifica√ß√£o antes de acessar o projeto, ele pede uma senha
    // no caso a 123, caso nao seja digitada ele vai exibir a mensagem que esta incorretaa

    int selecione;

    // Matriz para representar os quartos em cada andar (5 andares x 10 quartos)
    int quartos[5][10];

    // Inicialize todos os quartos como dispon√≠veis (true)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            quartos[i][j] = true;
        }
    }

    do {
        limpar_Tela();
        printf("Menu de Op√ß√µes:\n\n");
        printf("1 - Quartos Dispon√≠veis\n");
        printf("2 - Reservar um Quarto\n");
        printf("3 - Cancelar a Reserva\n");
        printf("4 - Consultar a Reserva\n");
        printf("5 - Sair\n\n");
        printf("Escolha uma op√ß√£o para prosseguir: ");
        scanf("%d", &selecione);

        // menu com as op√ß√µes disponiveis

        switch (selecione) {
            case 1: // cada case √© uma das op√ß√µes a cima
                limpar_Tela(); //limpa a tela
                printf("Voc√™ selecionou a Op√ß√£o 1 - Quartos Dispon√≠veis\n\n"); //exibe essa mensagem e mostra as op√ß√µes disponiveis

                int andar; // aqui come√ßa as op√ß√µes das op√ß√µes, por exemplo os andar do predio
                printf("Selecione o andar (1¬∞, 2¬∞, 3¬∞, 4¬∞, 5¬∞): ");
                scanf("%d", &andar);

                if (andar >= 1 && andar <= 5) { // aqui vai fazer uma verifica√ß√£o para exibir a lista no for
                    printf("\nQuartos dispon√≠veis no %d¬∞ andar:\n\n", andar);

                    // Exibir os quartos dispon√≠veis no andar selecionado
                    for (int quarto = 0; quarto < 10; quarto++) {
                        if (quartos[andar - 1][quarto]) {
                            printf("Quarto %d\n\n", quarto + 1);
                            // Para continuar, decidir qual a melhor forma de colocar os pre√ßos
                            // Por exemplo pre√ßo fixo por andar
                            // Quanto mais alto mais caro
                        }
                    }
                } else {
                    printf("Andar inv√°lido !\n");
                }

                printf("Pressione Enter para voltar ao menu...");
                getchar();
                break;

		case 2:
                limpar_Tela();
                printf("Voc√™ selecionou a Op√ß√£o 2 - Reservar um Quarto\n\n");

                // continuar o c√≥digo

                printf("Pressione Enter para voltar ao menu...");
                getch();
                break;

            case 3:
                limpar_Tela();
                printf("Voc√™ selecionou a Op√ß√£o 3 - Cancelar a Reserva\n\n");

                // continuar o c√≥digo

                printf("Pressione Enter para voltar ao menu...");
                getch();
                break;

            case 4:
                limpar_Tela();
                printf("Voc√™ selecionou a Op√ß√£o 4 - Consultar a Reserva\n\n");

                // continuar o c√≥digo

                printf("Pressione Enter para voltar ao menu...");
                getch();
                break;
            case 5:

                printf("Saindo do programa!\n\n");
                break;
            default:
                limpar_Tela();
                printf("Op√ß√£o inv√°lida. Tente novamente.\n\n");
                printf("Pressione Enter para continuar...");
                getch();
        }

        // Limpar o menu de entrada
        while (getchar() != '\n');

    } while (selecione != 5);

        }
>>>>>>> 1849b65c5c3468b721b17774bf976297f9a19a1e
