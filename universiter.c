#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define KRED "\x1B[31m"


struct Etudiant
{
    int CIN;
    char Nom[100];
    char Prenom[100];
    int niv;
    char classe[100];
    char sexe;
    char date_naiss[10];
};

struct Etudiant Etud;

/*fonction rechercher*/
int recherchere(int CINrech)
{
    FILE *f;
    f = fopen("etudiant.txt", "r");
    do
    {

        fscanf(f, "%d ;%s ;%s ;%d ;%s ;%c ;%s ", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);
        fflush(stdin);
        if (Etud.CIN == CINrech)
        {
            fclose(f);
            return 1;
        }
    } while (!feof(f));
    fclose(f);
    return -1;
}

// Ajouter des etudiants par classe
void AjoutEtudiantsclass()
{
    FILE *f;
    int num;
    int n, p;
    char class[20];

    printf("donner le classe:\t");
    scanf("%s", &class);
    printf("donner la nombre des etudiants:\t");
    scanf("%d", &n);
    struct Etudiant E[100];
    f = fopen("etudiant.txt", "a");
    p = 1;
    for (int i = 0; i < n; i++)
    {
        printf("donner le CIN  etudiant numro [%d]:\t", p);
        scanf("%d", &num);
        fflush(stdin);
        while (recherchere(num) == 1)
        {
            printf("\033[31;01mCette CIN existe deja !!\033[00m\n");
            printf("donner un autre CIN:\t");
            scanf("%d", &num);
        }
        E[i].CIN = num;
        printf("\n donner le nom etudiant [%d]:\t", p);
        gets(E[i].Nom);
        fflush(stdin);
        printf("donner le prenom etudiant [%d]:\t", p);
        gets(E[i].Prenom);
        fflush(stdin);
        printf("donner le niveau etudiant [%d]:\t", p);
        scanf("%d", &E[i].niv);
        fflush(stdin);
        // printf ("donner la classe  etudiant:\t");
        // scanf("%s",&Etud.classe);
        fflush(stdin);
        printf("donner la sexe etudiant [%d]:\t ", p);
        scanf("%c", &E[i].sexe);
        fflush(stdin);
        printf("donner date de naissance etudiant [%d]:\t ", p);
        gets(E[i].date_naiss);
        fflush(stdin);
        fprintf(f, "%d ;%s ;%s ;%d ;%s ;%c ;%s \n", E[i].CIN, E[i].Nom, E[i].Prenom, E[i].niv, class, E[i].sexe, E[i].date_naiss);
        p++;
    }
    fclose(f);
}

// Ajouter un etudiant
void AjoutEtudiant()
{
    FILE *f;
    int num;
    f = fopen("etudiant.txt", "a");
    printf("donner le CIN du nouveau etudiant:\t");
    scanf("%d", &num);
    fflush(stdin);
    while (recherchere(num) == 1)
    {
        printf("\033[31;01mCette CIN existe deja !!\033[00m\n");
        printf("donner un autre CIN:\t");
        scanf("%d", &num);
    }
    Etud.CIN = num;
    printf("\n donner le nom etudiant:\t");
    gets(Etud.Nom);
    fflush(stdin);
    printf("donner le prenom etudiant:\t");
    gets(Etud.Prenom);
    fflush(stdin);
    printf("donner le niveau etudiant:\t");
    scanf("%d", &Etud.niv);
    fflush(stdin);
    printf("donner la classe  etudiant:\t");
    scanf("%s", &Etud.classe);
    fflush(stdin);
    printf("donner la sexe etudiant:\t ");
    scanf("%c", &Etud.sexe);
    fflush(stdin);
    printf("donner date de naissance etudiant:\t ");
    gets(Etud.date_naiss);
    fflush(stdin);
    fprintf(f, "%d ;%s ;%s ;%d ;%s ;%c ;%s \n", Etud.CIN, Etud.Nom, Etud.Prenom, Etud.niv, Etud.classe, Etud.sexe, Etud.date_naiss);
    fclose(f);
}

// cette fonction est chercher des etudiants
void Rchercher()
{
    int CinR;
    printf("\n donner le CIN etudiant a rechercher:\t");
    scanf("%d", &CinR);

    FILE *F;
    F = fopen("etudiant.txt", "r");

    do
    {
        fscanf(F, "%d ;%s ;%s ;%d ;%s ;%c ;%s", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);

        if (Etud.CIN == CinR)
        {
            printf("\n\n--------------------     Information Etudiant :     --------------------\n\n");
            printf("CIN    :\t%d\n", Etud.CIN);
            printf("NOM    :\t%s\n", Etud.Nom);
            printf("PRENOM :\t%s\n", Etud.Prenom);
            printf("niveau :\t%d\n", Etud.niv);
            printf("classe :\t%s\n", Etud.classe);
            printf("sexe   :\t%c\n", Etud.sexe);
            printf("date de naissance: %s\n", Etud.date_naiss);
        }

    } while (!feof(F) && CinR != Etud.CIN);
    fclose(F);
}

// cette fonction est chercher des etudiants par classe
void Rchercherclasse()
{
    char class[20];
    printf("\n donner le classe  a rechercher:\t");
    scanf("%s", &class);

    FILE *F;
    F = fopen("etudiant.txt", "r");

    do
    {
        fscanf(F, "%d ;%s ;%s ;%d ;%s ;%c ;%s", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);

        if (strcmp(Etud.classe, class) == 0)
        {
            printf("\n\n--------------------     Information Etudiant :     --------------------\n\n");
            printf("CIN    :\t%d\n", Etud.CIN);
            printf("NOM    :\t%s\n", Etud.Nom);
            printf("PRENOM :\t%s\n", Etud.Prenom);
            printf("niveau :\t%d\n", Etud.niv);
            printf("classe :\t%s\n", Etud.classe);
            printf("sexe   :\t%c\n", Etud.sexe);
            printf("date de naissance: %s\n", Etud.date_naiss);
        }

    } while (!feof(F));
    fclose(F);
}

// modifier étudiant
void ModifEtud()
{
    FILE *f, *fich;
    int num, i;
    char rep = 'n';

    printf("donner le CIN a modifier :\t ");
    scanf("%d", &num);
    fflush(stdin);

    if (recherchere(num) == 1)
    {

        printf("voulez vous vraimment modifier ! :\t ");
        scanf("%c", &rep);
        fflush(stdin);

        if (rep == 'o' || rep == 'O')
        {
            f = fopen("etudiant.txt", "r");
            fich = fopen("tempetudiant.txt", "a");

            do
            {
                fscanf(f, "%d ;%s ;%s ;%d ;%s ;%c ;%s", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);
                if (num == Etud.CIN)
                {
                    printf("\n donner le nouveau nom :\t ");
                    gets(Etud.Nom);
                    printf("\n donner le nouveau prenom :\t ");
                    gets(Etud.Prenom);
                    printf("\n donner la nouvelle niveau :\t ");
                    scanf("%d", &Etud.niv);
                    fflush(stdin);
                    printf("\n donner la classe :\t ");
                    gets(Etud.classe);
                    fflush(stdin);
                    printf("\n donner la sexe etudiant:\t ");
                    scanf("%c", &Etud.sexe);
                    fflush(stdin);
                    printf("\n donner le nouveau date de naissance :\t ");
                    gets(Etud.date_naiss);
                }
                fprintf(fich, "%d ;%s ;%s ;%d ;%s ;%c ;%s \n", Etud.CIN, Etud.Nom, Etud.Prenom, Etud.niv, Etud.classe, Etud.sexe, Etud.date_naiss);
            } while (!feof(f));
            fclose(f);
            fclose(fich);
            remove("etudiant.txt");
            rename("tempetudiant.txt", "etudiant.txt");
            printf("modification avec succes !");
        }
    }

    else
    {
        printf("\n cette cin nexiste pas \n");
    }
}

// supprimer étudiant
void SupprimerEtud()
{
    char rep;
    int numR;
    printf("\n donner un numero a supprimer ! :");
    scanf("%d", &numR);
    fflush(stdin);
    if (recherchere(numR) == 1)
    {
        printf("\n voulez vous vraimment supprimer o/n ! :");
        scanf("%c", &rep);
        fflush(stdin);
        if (rep == 'o' || rep == 'O')
        {
            FILE *f, *fich;
            f = fopen("etudiant.txt", "r");
            fich = fopen("tempetudiant.txt", "a");
            do
            {
                fscanf(f, "%d ;%s ;%s ;%d ;%s ;%c ;%s", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);
                if (numR != Etud.CIN)
                {
                    fprintf(fich, "%d ;%s ;%s ;%d ;%s ;%c ;%s \n", Etud.CIN, Etud.Nom, Etud.Prenom, Etud.niv, Etud.classe, Etud.sexe, Etud.date_naiss);
                }
            } while (!feof(f));
            fclose(fich);
            fclose(f);
            remove("etudiant.txt");
            rename("tempetudiant.txt", "etudiant.txt");
            printf("suppression avec succes ! ");
        }
    }
}

void affichtous()
{
    FILE *F;
    F = fopen("etudiant.txt", "r");
    if (F == NULL)
    {

        printf("n est pas etudiant");
        exit(1);
    }

    printf("la liste des etudiants est :\n \n ");
    printf("CIN \t| Nom \t        | prenom\t|niveau| classe\t| sexe\t|date de naissance\n");

    do
    {
        fscanf(F, "%d ;%s ;%s ;%d ;%s ;%c ;%s \n", &Etud.CIN, &Etud.Nom, &Etud.Prenom, &Etud.niv, &Etud.classe, &Etud.sexe, &Etud.date_naiss);
        fflush(stdin);

        printf("%d|", Etud.CIN);
        printf("%15s|", Etud.Nom);
        printf("%15s|", Etud.Prenom);
        printf("%5d |", Etud.niv);
        printf("%8s|", Etud.classe);
        printf("%6c |", Etud.sexe);
        printf("%8s\n", Etud.date_naiss);

    } while (!feof(F));
    fclose(F);
}


struct enseignant
{

    int num;
    char nom[20];
    char prenom[20];
    char matiere[20];
};

struct enseignant ens;

 /*fonction rechercher*/
int rechercher(int Numrech)
{
    FILE *f;
    f = fopen("enseignant.txt", "r");
    do
    {
        fscanf(f, "%d ;%s ;%s ;%s", &ens.num, &ens.nom, &ens.prenom, &ens.matiere);
        fflush(stdin);
        if (ens.num == Numrech)
        {
            fclose(f);
            return 1;
        }
    } while (!feof(f));
    fclose(f);
    return -1;
}

/*procedure ajouter enseignant*/
void ajouter()
{
    FILE *f;
    int num;
    f = fopen("enseignant.txt", "a");
    printf("\n donner un numero du nouveau enseignant : ");
    scanf("%d", &num);
    fflush(stdin);
    while (rechercher(num) == 1)
    {
        printf("\n ce numero existe deja ");
        printf("donner un autre numero ! ");
        scanf("%d", &num);
    }
    ens.num = num;
    printf("donner le nom : ");
    gets(ens.nom);
    fflush(stdin);
    printf("donner le prenom : ");
    gets(ens.prenom);
    fflush(stdin);
    printf("donner la matiere : ");
    gets(ens.matiere);
    fflush(stdin);
    fprintf(f, "\n %d ;%s ;%s ;%s", ens.num, ens.nom, ens.prenom, ens.matiere);
    fclose(f);
}

/*procedure afficher tous les enseignants */
void affichage()
{
    printf("la liste de tous les enseignants : \n");
    FILE *f;
    f = fopen("enseignant.txt", "r");
    do
    {
        printf("\n");
         printf("_________________________________________________\n");
        fscanf(f, "%d ;%s ;%s ;%s", &ens.num, &ens.nom, &ens.prenom, &ens.matiere);
        printf(" numero : %d \n", ens.num);
        printf(" nom : %s \n", ens.nom);
        printf(" prenom : %s \n", ens.prenom);
        printf(" matiere : %s \n ", ens.matiere);
        
    } while (!feof(f));
}

// /*procedure rechercher et affichage */
void rech()
{
    int numR;
    printf("donner un numero a chercher !: ");
    scanf("%d", &numR);
    FILE *f;
    f = fopen("enseignant.txt", "r");
    do
    {
        fscanf(f, "%d ;%s ;%s ;%s", &ens.num, &ens.nom, &ens.prenom, &ens.matiere);
        if (numR == ens.num)
        {
            printf("_________________________________________________");
            printf(" info de l enseignant : \n");
            printf(" numero : %d \n", ens.num);
            printf(" nom : %s \n", ens.nom);
            printf(" prenom : %s \n", ens.prenom);
            printf(" matiere : %s \n ", ens.matiere);
            
        }
    } while (!feof(f));
    fclose(f);
}

/* supprimer enseignant */
void supprimer()
{
    char rep;
    int numR;
    printf("\n donner un numero a supprimer ! :");
    scanf("%d", &numR);
    fflush(stdin);
    if (rechercher(numR) == 1)
    {
        printf("voulez vous vraimment supprimer o/n ! : ");
        scanf("%c", &rep);
        fflush(stdin);
        if (rep == 'o' || rep == 'O')
        {
            FILE *f, *fich;
            f = fopen("enseignant.txt", "r");
            fich = fopen("repenseignant.txt", "a");
            do
            {
                fscanf(f, "%d ;%s ;%s ;%s \n", &ens.num, &ens.nom, &ens.prenom, &ens.matiere);
                if (numR != ens.num)
                {
                    fprintf(fich, "\n %d ;%s ;%s ;%s", ens.num, ens.nom, ens.prenom, ens.matiere);
                }
            } while (!feof(f));
            fclose(fich);
            fclose(f);
            remove("enseignant.txt");
            rename("repenseignant.txt", "enseignant.txt");
            printf("suppression avec succes ! ");
        }
    }
}

// /* modifier enseignant */
void modifier()
{
    FILE *f, *fich;
    int num,i;
    char rep;
    printf("donner le num a modifier ! : ");
    scanf("%d", &num);
    fflush(stdin);
    if (rechercher(num) == 1)
    {
        printf("voulez vous vraimment modifier o/n ! : ");
        scanf("%c", &rep);
        fflush(stdin);
        if (rep == 'o' || rep == 'O')
        {
            f = fopen("enseignant.txt", "r");
            fich = fopen("repenseignant.txt", "a");
            do
            {
                fscanf(f, "%d ;%s ;%s ;%s \n", &ens.num, &ens.nom, &ens.prenom, &ens.matiere);
                if (num == ens.num)
                {
                    ens.num = num;
                    printf("\n donner le nouveau nom : ");
                    gets(ens.nom);
                    printf("\n donner le nouveau prenom : ");
                    gets(ens.prenom);
                    printf("\n donner la nouvelle matiere : ");
                    gets(ens.matiere);
                }
                fprintf(fich, "\n %d ;%s ;%s ;%s", ens.num, ens.nom, ens.prenom, ens.matiere);
            } while (!feof(f));
            fclose(f);
            fclose(fich);
            remove("enseignant.txt");
            rename("repenseignant.txt", "enseignant.txt");
            printf("modification avec succes !");
        }
    }
}





COORD coord = {0,0};

void gotoxy(int x,int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}





int token = 0,tokens[50],payment_counter=0;




int main_page()
{
    int i;
    //system("cls");
    //system("color 0B");

    printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'  Welcome to TEK-UP \n\t\t\t\t\t\t\t`'*'`-@@_@\n\n");
    printf("\n\n\n\n\t\t\t    Quality food.Serves good. (^_^)\n\n                       ");
    for (i=0;i<36;i++)
     {
        printf("~");
     }
    printf("\n");
    printf("                 $                                  $\n");
    printf("                       $    Selectionner unne option -          $\n");
    printf("                 $                                  $\n");
    printf("                       $    1. Nouveaux Ordre.                 $\n");
    printf("                 $                                  $\n");
    printf("                       $    2. Payment.              $\n");
    printf("                 $                                  $\n");
    printf("                       $    3. Quiter.                      $");
    printf("\n");
    // printf("                 $                                  $\n");
    // printf("                       $                                  $\n");



    for (i=0;i<36;i++)
     {
        printf("~");
     }
    printf("\n\n\n\n                         Entrer votre choix: ");
    int n;
    scanf("%d",&n);
    return n;
}





int menu_order()
{

    int arID[10],decision,arqty[10],Bill[10],counter=0;
    work:
    //system("cls");
    //system("color 4F");
    printf("\n\t\t\t\tNOTRE MENU\n\t\t\t\t---------\n");
    printf("\n\tBUNS :\n\n");
    printf("\t1. Kfteji ...................... 3/=\t  \n");
    printf("\t2. riz ..........................  7/=\n");
    printf("\t3. cake ...........................  2/=\t \n");
    printf("\t4. kouskous ..........  9/=\t \n");
    printf("\t5. escalope panne ...................  8/=\n");
    printf("\t6. salade vert ....................  6/=\n");
    printf("\t7. salade mechwia ........................  6/=\t  \n");
    printf("\t8. spaguetti ........................... 4/=\t \n");
    printf("\t9.  Coca-Cola ........................ 1/=\n");
    printf("\t10. yaourt   ........................ 1/=\n");
    printf("\n\n\tOrder your dish: (Enter 0 to finish order)\n");
    for(;;)
    {
        counter++;
        printf("\t Entrer le plat ID: ");
        scanf("%d",&arID[counter-1]);
        if(arID[counter-1]==0)
        {
            break;
        }
        printf("\t Entrer la quantitee: ");
        scanf("%d",&arqty[counter-1]);

    }
   // system("cls");
   printf("\n\n\n\n\n\n\n\n\n\n\t\tmerci pour votre commande. Nous preparons la vaisselle.\n\t\tJusque la, faire des selfies avec des amis. Prendre plaisir!\n\n\n\n\n\t\t\t  <Entrer 1 pour verifier votre facture>\n\t\t\tEntrer votre choix: ");

    scanf("%d",&decision);
    printf("\n\n\n\n\n\n\n\n");

    counter--;

    if(decision==1)
    {
        Bill_show(arID,arqty,counter);
    }

    else if(decision==2)
    {
       goto work;
    }

    else if(decision==3)
    {
        int k,j,n,d;
    k = main_page();

    if(k==1)
    {
        menu_order();
    }

    else if(k==2)
    {
        Bill_Payment();
    }

    else
    {
        //system("cls");
       // system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  TEK-UP RESTAU\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tCette commande de session a ete recue : %d\n\n",token);
        printf("\t\t\tCette facture de session payee      : %d\n\n",payment_counter);
        if(payment_counter<token)
        {printf("\t\t\t\t Encore a payer          : %d\n\n\n\n\n\n",token-payment_counter);}
        else
        {
            printf("\n\n\n\n\n\n");
        }
        return 0;
    }
    }

}





void Bill_show(int arID[],int arqty[],int counter)
{

    int n;
    //system("cls");
    // system("color B0");

    int i,sum=0;
    int costs[10]={3,7,2,9,8,6,6,4,1,1};
    char items[10][16]={"Kfteji","riz","cake","kouskous","escalope panne","salade vert","salade mechwia","spaguetti","Coca-Cola","yaourt"};
    printf("\n\nYour Bill:\n\n\n\t\tItem(s)\t\t     Quantity\t\t    Cost\n\n\n\n");

    for(i=0;i<counter;i++)
    {
        printf("\t%2d. %-16s ________\t%-5d piece(s) ____ %7d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
        sum=sum+(costs[arID[i]-1]*arqty[i]);
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    token ++;
    tokens[token]=sum;
    printf("\tVotre numero de jeton est %d. Utilisez ce jeton lors du paiement de la facture.\n\n\n\n\n\t\t\t<entrer (1) pour faire ue autre commande>\n\n\t\t\t<entrer (2) pour aller aux menu principale>\n\n\t\n\t\t\tEntrer votre choix: ",token);
    scanf("%d",&n);
    printf("\n\n\n");
    if(n==1)
    {
        menu_order();
    }
    else if(n==2)
    {
        int k,j,n,d;
    k = main_page();

    if(k==1)
    {
        menu_order();
    }

    else if(k==2)
    {
        Bill_Payment();
    }

    else
    {
        //system("cls");
       // system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  TEK-UP RESTAU\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tCette commande de session a ete recue : %d\n\n",token);
        printf("\t\t\tCette facture de session payee      : %d\n\n",payment_counter);
        if(payment_counter<token)
        {printf("\t\t\t\t Encore a payer          : %d\n\n\n\n\n\n",token-payment_counter);}
        else
        {
            printf("\n\n\n\n\n\n");
        }
        return 0;
    }

    }

}




void Bill_Payment()
{

    int k,i,cash,changer,n;
    redo:
    payment_counter++;
    //system("cls");
    // system("color 3F");
    printf("\n\n\n\t\t\tEntrez votre numero de jeton: ");
    scanf("%d",&k);
    printf("\t\t\tVotre facture totale est = %d",tokens[k]);
    work:
            printf("\n\t\t\tPayez votre addition: ");
            scanf("%d",&cash);
    changer = cash-tokens[k];
    if(changer == 0)
    {
        printf("\n\t\tMerci pour votre paiement. Passe une bonne journee!\n");
    }
    else if (changer<0)
    {
        //system("cls");
        printf("\n\t\t\tLe montant n est pas suffisant. :(\n\t\tVeuillez payer le juste prix de votre facture\n");
        goto work;
    }
    else
    {
        printf("\n\n\n\t\tVoici votre change : (%d - %d) = %d Tk.\n\t\t  ",cash,tokens[k],changer);

            for(i=0;i<19;i++)
            {
                printf("_");
            }
            if(changer>=1000 )
                {printf("\n\t\t1000 Tk. note(s) = %d\n",changer/1000);
                changer=changer%1000;}
            if(changer>=500 && changer<1000)
            {printf("\n\t\t 500 Tk. note(s) = %d\n",changer/500);
            changer=changer%500;}
            if(changer>=100 && changer<500)
            {printf("\n\t\t 100 Tk. note(s) = %d\n",changer/100);
            changer= changer%100;}
            if(changer>=50 && changer<100)
            {printf("\n\t\t  50 Tk. note(s) = %d\n",changer/50);
            changer=changer%50;}
             if(changer>=10 && changer<50)
            {printf("\n\t\t  10 Tk. note(s) = %d\n",changer/10);
            changer=changer%10;}
            if(changer>=5 && changer<10)
            {printf("\n\t\t   5 Tk. note(s) = %d\n",changer/5);
            changer=changer%5;}
            if(changer>=2 && changer<5)
            {printf("\n\t\t   2 Tk. note(s) = %d\n",changer/2);
            changer=changer%2;}
            if(changer>=1 && changer<2)
            {printf("\n\t\t   1 Tk. note(s) = %d\n",changer/1);
            changer=changer%1;}

            printf("\t\t  ");
            for(i=0;i<19;i++)
            {
                printf("_");
            }

        printf("\n\n\n\n\n\t\t\tMerci pour votre paiement.\n\t\t\t  Passe une bonne journee.!\n",changer);



    }
    printf("\n\n\t\t\t<Entrer (1) pour payer ue autre addition.>\n\t\t\t<Entrer (2) pour revenir aux menu principale>\n\n\n\t\t\tEntrer votre choix: \t");
        scanf("%d",&n);
        if(n==2)
        {
           int k,j,n,d;
    k = main_page();

    if(k==1)
    {
        menu_order();
    }

    else if(k==2)
    {
        Bill_Payment();
    }

    else
    {
        //system("cls");
       // system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  TEK-UP RESTAU\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tCette commande de session a ete recue : %d\n\n",token);
        printf("\t\t\tCette facture de session payee      : %d\n\n",payment_counter);
        if(payment_counter<token)
        {printf("\t\t\t\t Encore a payer          : %d\n\n\n\n\n\n",token-payment_counter);}
        else
        {
            printf("\n\n\n\n\n\n");
        }
        return 0;
    }
        }
        else if(n==1)
        {
           goto redo;
        }

}





void print_progress(int percent)
{
    const int mul = 2; // width factor
    percent = min(100, percent);

    // spinning animation
    static int spin_index = 0;
    char spinning[] = "_-\\|/-";

    // bar filler
    int len = (percent * mul / 10) + 1;
    char *bar = malloc(len);
    memset(bar, '<', len - 1);
    bar[len - 1] = 0;

    // write display
    printf("%c Loading: [%*s] %*d%%\r",
           percent == 100 ? ' ' : spinning[spin_index],
           mul * 10, bar,
           3, percent);
    spin_index = (spin_index + 1) % strlen(spinning);

    free(bar);
}

void main()
{
    char rep1;
    int choix1;

    do
    {
        printf("\n\n\t*************** Menu ***************");

        printf("\n\n\t1-Gestion des  Etudiants  \n ");
        printf("\n\n\t2-Gestion des  Enseignants \n");
        printf("\n\n\t3-Gestion des  Employees\n");
        printf("\n\n\t4-Gestion des  restourants\n");
        printf("\n\n\t5-Quitter\n");

        do
        {
            printf("\n -Enter Votre choix:");
            scanf("%d", &choix1);
        } while (choix1 < 1 || choix1 > 8);

        switch (choix1)
        {
        case 1:

            printf("\n\n\n\n\n\n\n\n");
            printf("\n Starting Loader...\n");
            for (int i = 10; i <= 100; i += 5)
            {
                print_progress(i);
                Sleep(150);
            }
            printf("\n\n\n\n\n\n\n\n");
            int choix;
            char rep;

            do
            {
                printf("\n\n\t*************** Menu Etudiants ***************");

                printf("\n\n\t1-Ajouter des Etudiants par classe \n");
                printf("\n\n\t2-Ajouter un Etudiant\n");
                printf("\n\n\t3-Rechercher un Etudiant\n");
                printf("\n\n\t4-Rechercher Etudiants par classe \n");
                printf("\n\n\t5-Supprimer un Etudiant\n");
                printf("\n\n\t6-Modifier un Etudiant\n");
                printf("\n\n\t7-Afficher tous les Etudiants\n");
                printf("\n\n\t8-Quitter \n");

                do
                {
                    printf("\n -Enter Votre choix:");
                    scanf("%d", &choix);
                } while (choix < 1 || choix > 8);

                switch (choix)
                {

                case 1:
                    AjoutEtudiantsclass();
                    break;
                case 2:
                    AjoutEtudiant();
                    break;
                case 3:
                    Rchercher();
                    break;
                case 4:
                    Rchercherclasse();
                    break;
                case 5:
                    SupprimerEtud();
                    break;
                case 6:
                    ModifEtud();
                    break;
                case 7:
                    affichtous();
                    break;
                case 8:
                    main();
                    break;
                }
                printf("\n Voulez-vouz continuez O/N:");
                scanf("%s", &rep);
                fflush(stdin);

            } while (rep == 'o' || rep == "O");
            break;


            

        case 2:
            printf("ens");
            int choixe;

            system("cls");
            printf(" ** MENU ** \n");
            printf("1 . ajouter enseignant \n");
            printf("2 . rechercher enseignant \n");
            printf("3 . modifier enseignant \n");
            printf("4 . supprimer enseignant \n");
            printf("5 . liste des enseignants \n");
            printf("6 . Quitter \n");


            do
            {
                printf("donner votre choix :\t");
                scanf("%d", &choixe);
            } while (choixe < 1 || choixe > 6);

            switch (choixe)
            {
            case 1:
                ajouter();
                break;
            case 2:
                rech();
                break;
            case 3:
                modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                affichage();
                break;
                case 6:
                main();
                break;
            }
             break;


        case 3:
            
        int i = 0;

    FILE *fp, *ft;
	char another, choice;


	struct emp
	{
		char name[40];
		int age;
		char address[20];
		float bs;
   };

   struct emp e;

   char empname[40];

   long int recsize;



   fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
}

recsize = sizeof(e);


while(1)
    {

        system("cls");

        printf(" \n  ::::::::::::::::::::::::::  |gestion des employees|  :::::::::::::::::::::::::: \n");
        gotoxy(30,05);
        printf("1.ajouter un employee");
        gotoxy(30,07);
        printf("2.liste des employees");
        gotoxy(30,9);
        printf("3.modifier un employee");
        gotoxy(30,11);
        printf("4.supprimer un employee");
        gotoxy(30,13);
        printf("5.quitter");
        gotoxy(30,15);
        printf("vos choix: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)
        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);


            another = 'o';
            while(another == 'o')
            {
                printf("\nEntrer le nom: ");
                scanf("%s",e.name);
                printf("\nEntrer lage: ");
                scanf("%d", &e.age);
                printf("\nEntrer  l'Address:");
                scanf("%s",e.address);
                printf("\n Entrer le salaire: ");
                scanf("%f", &e.bs);

                fwrite(&e,recsize,1,fp);

                printf("\nAjouter un autre employee(o/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");
            printf("EMPLOYEE's RECORD LIST (name, age, address, salary)");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {

                printf("\n\n%s \t\t%d \t%s \t%.2f",e.name,e.age,e.address,e.bs);
            }
            getch();
            break;

        case '3':
            system("cls");
            another = 'o';
            while(another == 'o')
            {
                printf("Entrer l'employee a modifier: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.name,empname) == 0)
                    {
                        printf("\nEntrer nouveaux nom,age,addresse et salaire: ");
                        scanf("%s%d%s%f",e.name,&e.age,&e.address,&e.bs);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nModifier un autre employee(o/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'o';
            while(another == 'o')
            {
                printf("\nEntrer le nom de l'employee a supprimer: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.name,empname) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT");
                rename("Temp.dat","EMP.DAT");
                fp = fopen("EMP.DAT", "rb+");
                printf("supprimer un autre employ��(o/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);
            main();
        }
    }
            break;


            
        case 4:
            printf("rest");
int k,j,n,d;
    k = main_page();

    if(k==1)
    {
        menu_order();
    }

    else if(k==2)
    {
        Bill_Payment();
    }

    else
    {
        //system("cls");
       // system("color 30");
        printf("\n\n\n\n\n\t\t       @@_@_\n\t\t         `'*'`  TEK-UP RESTAU\n\t\t\t\t\t`'*'`-@@_@\n\n");
        printf("\n\n\n\t\t\tCette commande de session a ete recue : %d\n\n",token);
        printf("\t\t\tCette facture de session payee      : %d\n\n",payment_counter);
        if(payment_counter<token)
        {printf("\t\t\t\t Encore a payer          : %d\n\n\n\n\n\n",token-payment_counter);}
        else
        {
            printf("\n\n\n\n\n\n");
        }
        
    }



            break;
        case 5:
            exit(0);
            break;
        }
        printf("\n Voulez-vouz continuez O/N:");
        scanf("%s", &rep1);

    } while (rep1 == 'o' || rep1 == "O");
}