#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for usleep
#include <sys/ioctl.h> // for terminal size

void checkbalance(char*);
void transfermoney(char*);
void display(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(char*);
void logout(void);

void hidecursor() {
    printf("\033[?25l");
}

void showcursor() {
    printf("\033[?25h");
}

void clearscreen() {
    printf("\033[H\033[J");
}

void centerText(const char* text, int y) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int x = (w.ws_col - strlen(text)) / 2;
    printf("\033[%d;%dH%s", y, x, text);
}

struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char cartaocidadao[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
    double balance; // Adicionei o campo balance
};
 
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    double money1;
};

struct userpass {
    char password[50];
};

int main()
{
    int choice;

    hidecursor();
    clearscreen();

    centerText("BEM VINDO AO SISTEMA DE CRIAÇÃO DE CONTA BANCARIA", 3);
    centerText("**********************************", 5);
    centerText("DEVELOPER-Fegue", 7);
    centerText("1.... CRIAR UMA CONTA", 10);
    centerText("2.... JA E UTILIZADOR? ENTRE", 12);
    centerText("3.... SAIR", 14);
    centerText("FAÇA A SUA ESCOLHA..", 16);

    printf("\n\n");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            clearscreen();
            printf("\n\n USERNAME 50 CHARACTERES MAXIMO!!");
            printf("\n\n PASSWORD 50 CHARACTERES MAXIMO!!");
            account();
            break;
        case 2: 
            login();
            break;
        case 3:
            showcursor();
            exit(0);
            break;
    }
}

void account(void)
{
    char password[20];
    int passwordlenght, i;
    char ch;
    FILE *fp;
    struct pass u1;

    fp = fopen("username.txt", "ab");

    clearscreen();
    centerText("!!!!!CRIACAO DE CONTA!!!!!", 3);

    centerText("NOME..", 5);
    printf("\n\n");
    scanf("%s", u1.fname);

    centerText("SOBRENOME..", 8);
    printf("\n\n");
    scanf("%s", u1.lname);

    centerText("NOME DO PAI..", 11);
    printf("\n\n");
    scanf("%s", u1.fathname);

    centerText("NOME DA MAE..", 14);
    printf("\n\n");
    scanf("%s", u1.mothname);

    centerText("MORADA..", 17);
    printf("\n\n");
    scanf("%s", u1.address);

    centerText("TIPO DE CONTA", 20);
    printf("\n\n");
    scanf("%s", u1.typeaccount);

    centerText("DATA DE NASCIMENTO..", 23);
    printf("\n\n");
    printf("DATA-");
    scanf("%d", &u1.date);
    printf("MES-");
    scanf("%d", &u1.month);
    printf("ANO-");
    scanf("%d", &u1.year);

    centerText("NUMERO DO CARTAO DE CIDADAO", 26);
    printf("\n\n");
    scanf("%s", u1.cartaocidadao);

    centerText("NUMERO DE TELEMOVEL", 29);
    printf("\n\n");
    scanf("%s", u1.pnumber);

    centerText("USERNAME.. ", 32);
    printf("\n\n");
    scanf("%s", u1.username);

    centerText("PASSWORD..", 35);
    printf("\n\n");

    for (i = 0; i < 50; i++)  
    {
        ch = getchar();
        if (ch != '\n')  
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }
    password[i] = '\0';

    u1.balance = 1000.0; // Defina o saldo inicial aqui

    fwrite(&u1, sizeof(u1), 1, fp);
    fclose(fp);
    accountcreated();
}

void accountcreated(void)
{
    int i;
    clearscreen();
    centerText("POR FAVOR ESPERE....", 10);
    centerText("A SUA INFORMACAO ESTA A SER PROCESSADA....", 12);

    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }

    centerText("CONTA CRIADA COM SUCESSO....", 15);
    centerText("Pressione Enter para dar Login", 17);

    getchar();
    login();
}

void login(void)
{
    clearscreen();
    char username[50];
    char password[50];
    int i;
    char ch;
    FILE *fp;
    struct pass u1;

    fp = fopen("username.txt", "rb");
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }

    centerText("ACCOUNT LOGIN", 2);
    centerText("***********************************************", 5);
    centerText("==== LOG IN ====", 10);

    centerText("USERNAME.. ", 12);
    printf("\n\n");
    scanf("%s", username);

    centerText("PASSWORD..", 15);
    printf("\n\n");

    for (i = 0; i < 50; i++) {
        ch = getchar();
        if (ch != '\n') {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else
            break;
    }
    password[i] = '\0';

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username, u1.username) == 0) {
            loginsu();
            display(username);
        }
    }

    fclose(fp);
}

void loginsu(void)
{
    int i;
    clearscreen();
    centerText("Fetching account details.....", 10);

    for (i = 0; i < 20000; i++) {
        i++;
        i--;
    }

    centerText("LOGIN SUCCESSFUL....", 12);
    centerText("Press enter to continue", 14);

    getchar();
}

void display(char username1[])
{
    clearscreen();
    FILE* fp;
    int choice;
    struct pass u1;

    fp = fopen("username.txt", "rb");
    if (fp == NULL) {
        printf("error in opening file");
    }

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username1, u1.username) == 0) {
            centerText("WELCOME, ", 1);
            printf("%s %s", u1.fname, u1.lname);

            centerText("==== YOUR ACCOUNT INFO ====", 6);
            centerText("***************************", 8);
            centerText("NAME..", 10);
            printf("%s %s\n", u1.fname, u1.lname);

            centerText("FATHER's NAME..", 12);
            printf("%s %s\n", u1.fathname, u1.lname);

            centerText("MOTHER's NAME..", 14);
            printf("%s\n", u1.mothname);

            centerText("CARTAO DE CIDADAO..", 16);
            printf("%s\n", u1.cartaocidadao);

            centerText("MORADA..", 18);
            printf("%s\n", u1.address);

            centerText("TIPO DE CONTA..", 20);
            printf("%s\n", u1.typeaccount);

            centerText("DATA DE NASCIMENTO..", 22);
            printf("%d-%d-%d\n", u1.date, u1.month, u1.year);

            centerText("NUMERO DE TELEMOVEL..", 24);
            printf("%s\n", u1.pnumber);

            centerText("USERNAME..", 26);
            printf("%s\n", u1.username);

            centerText("BALANÇO..", 28);
            printf("%.2f\n", u1.balance); // Exibe o saldo

            centerText("**************************", 30);
            centerText("PRESS ENTER TO CONTINUE", 32);
            getchar();
            afterlogin(username1);
        }
    }
    fclose(fp);
}

void afterlogin(char username1[])
{
    int choice;
    clearscreen();
    centerText("Escolha uma opcao:", 5);
    centerText("1. Verificar Saldo", 7);
    centerText("2. Transferir Dinheiro", 9);
    centerText("3. Sair", 11);
    centerText("Insira a sua escolha: ", 13);

    printf("\n\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkbalance(username1);
            break;
        case 2:
            transfermoney(username1);
            break;
        case 3:
            logout();
            break;
        default:
            centerText("Invalido", 15);
            usleep(2000000);
            afterlogin(username1);
    }
}

void checkbalance(char username1[])
{
    FILE* fp;
    struct pass u1;
    fp = fopen("username.txt", "rb");

    if (fp == NULL) {
        printf("Error in opening file");
        return;
    }

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username1, u1.username) == 0) {
            clearscreen();
            centerText("O BALANÇO DA SUA CONTA É: ", 10);
            printf("%.2f\n", u1.balance); // Exibe o saldo
            centerText("Pressione enter para continuar...", 12);
            getchar();
            getchar(); // Extra getchar() to handle the newline character
            afterlogin(username1);
        }
    }
    fclose(fp);
}

void transfermoney(char username1[])
{
    clearscreen();
    FILE* fp;
    struct pass u1;
    char recipient[50];
    double amount;
    int found = 0;

    centerText("TRANSFERIR DINHEIRO", 3);
    centerText("USERNAME DO BENEFICIÁRIO: ", 5);
    printf("\n\n");
    scanf("%s", recipient);

    centerText("QUANTIDADE A TRANSFERIR: ", 7);
    printf("\n\n");
    scanf("%lf", &amount);

    fp = fopen("username.txt", "rb+");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username1, u1.username) == 0) {
            if (u1.balance < amount) {
                centerText("Saldo insuficiente.", 9);
                fclose(fp);
                usleep(2000000);
                afterlogin(username1);
                return;
            } else {
                u1.balance -= amount;
                fseek(fp, -sizeof(u1), SEEK_CUR);
                fwrite(&u1, sizeof(u1), 1, fp);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        centerText("Usuário remetente não encontrado.", 9);
        fclose(fp);
        usleep(2000000);
        afterlogin(username1);
        return;
    }

    rewind(fp);
    found = 0;

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(recipient, u1.username) == 0) {
            u1.balance += amount;
            fseek(fp, -sizeof(u1), SEEK_CUR);
            fwrite(&u1, sizeof(u1), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        centerText("Usuário beneficiário não encontrado.", 9);
        usleep(2000000);
        afterlogin(username1);
        return;
    }

    centerText("Transferência realizada com sucesso.", 9);
    usleep(2000000);
    afterlogin(username1);
}

void logout(void)
{
    clearscreen();
    centerText("Saindo...", 10);
    centerText("\n\n", 1);
    showcursor();
    exit(0);
}
