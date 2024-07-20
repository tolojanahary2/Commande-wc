#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*==============prototypes de tous les fonctions=======*/
void lire(FILE *fic, char *nomFichier);
void tous(FILE *fic, char *nomFichier, char *option);

int main(int argc, char *argv[])				//fonction principale
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <option> <fichier>\n", argv[0]);
        exit(1);
    }

    FILE *fic = NULL;							//appel au fonction
    lire(fic, argv[2]);
    tous(fic, argv[2], argv[1]);

    return 0;
}

void lire(FILE *fic, char *nomFichier)		//fonction d'ouverture au fonction
{
    fic = fopen(nomFichier, "r");			//ouverture au du fonction
    if (fic == NULL)						//tester le fichier s'il existe ou non
    {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier %s.\n", nomFichier);
        exit(1);
    }
    fclose(fic);							//fermeture du fichier
}

void tous(FILE *fic, char *nomFichier, char *option)		//fonction de tous les commandes accecible par cette programme
{
    fic = fopen(nomFichier, "r");							//reouverture du fichier pour l'execution du commande
    if (fic == NULL)
    {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier %s.\n", nomFichier);
        exit(1);
    }
															//tous les variables qu'on va utiliser pour realiser cette programme
    char chaine[100];
    int ligne = 0;
    int mot = 0;
    int caractere = 0;
    size_t max_ligne = 0;
    char max_chaine[200];

    if (strcmp(option, "-l") == 0)						//option -l (compter les nombres de saut de  ligne dans le fichier)
    {
        while (fgets(chaine, sizeof(chaine), fic) != NULL)
        {
            ligne++;
        }
        printf("%d %s\n", ligne, nomFichier);
    }
    else if (strcmp(option, "-w") == 0)					//option -w (compter les nombres des mots dans le fichier)
    {
        while (fscanf(fic, "%s", chaine) == 1)
        {
            mot++;
        }
        printf("%d %s\n", mot, nomFichier);
    }
    else if (strcmp(option, "-c") == 0)				   //option -c (compter les nombres des caracteres dans le fichier)
    {
        while (fgetc(fic) != EOF)
        {
            caractere++;
        }
        printf("%d %s\n", caractere, nomFichier);
    }
    else if (strcmp(option, "-L") == 0)				  //trouver ou se trouve les lignes qui contient le nombres des caracteres beaucoup
    {
        while (fgets(chaine, sizeof(chaine), fic) != NULL)
        {
            size_t length = strlen(chaine);
            if (length > max_ligne)
            {
                max_ligne = length;
                strcpy(max_chaine, chaine);
            }
        }
        max_ligne = max_ligne - 1;
        printf("%ld %s\n", max_ligne, nomFichier);
    }
    else if (strcmp(option, "-version") == 0)	    //pour trouver la version de cette commande avec le nom de la createur
    {
		printf("wc (GNU coreutils) 9.1 Copyright © 2024 Free Software Foundation, Inc.\n License GPLv3+ : GNU GPL version 3 ou ultérieure <https://gnu.org/licenses/gpl.html> \nCeci est un logiciel libre. Vous êtes libre de le modifier et de le redistribuer. \nCe logiciel n'est accompagné d'ABSOLUMENT AUCUNE GARANTIE, dans les limites \npermises par la loi.\n\nÉcrit par RAFANOMEZANTSOA Tolojanahary Jean Michel.\n");

    }
    
    else if (strcmp (option,"--help")==0)
        {
		printf ("Utilisation : wc [OPTION]... [FICHIER]...(uniquement)\nAfficher le nombre de sauts de ligne, de mots et d'octets pour chaque FICHIER\net une ligne totale si plus d'un fichier est spécifié. Un mot est une séquence\nde taille non nulle de caractères imprimables délimités par une espace.\nSans FICHIER ou quand FICHIER est -, lire l'entrée standard.\nLes options ci-dessous permettent de sélectionner les compteurs à afficher,\n\nqui sont toujours utilisés dans l'ordre suivant : saut de ligne, mot, caractère,\noctet, longueur de ligne maximale.\n\n-c, --bytes afficher le nombre d'octets\n\n-m, --chars afficher le nombre de caractères  \n\n-l, --lines            afficher le nombre de sauts de lignes\n\n-L, --max-line-length  afficher la largeur maximale d'affichage  \n\n-w, --words afficher le nombre de mots \n\n --help (FICHIER ) afficher l'aide et quitter \n\n--version (FICHIER) afficher des informations de version et quitter\nAide en ligne de GNU coreutils : <https://www.gnu.org/software/coreutils/>\nSignalez les problèmes de traduction à : <traduc@traduc.org>\nDocumentation complète <https://www.gnu.org/software/coreutils/wc>\nou disponible localement via: info '(coreutils) wc invocation'\n\ncette option ne semble pas a l'originale du commande mais c'est une commande modifiable donc n'est pas parfait\n\n");
		}
    else if (strcmp(option, "-lwc") == 0)		    //combinaison des options qui commence ici
    {
        // Logique pour l'option combinée -lwc
        while (fgets(chaine, sizeof(chaine), fic) != NULL)
        {
            ligne++;
            mot++;
            caractere += strlen(chaine);
        }
        printf("%d\n%d\n%d %s\n", ligne, mot, caractere, nomFichier);
    }
	else if (strcmp(option,"-lw")==0)
	{
		 while (fgets(chaine, sizeof(chaine), fic) != NULL)
        {
            ligne++;
            mot++;
		}
	printf("%d\n%d %s\n",ligne,mot,nomFichier);
	}
	
	else if (strcmp(option,"-lc")==0)
	{
		 while (fgets(chaine, sizeof(chaine), fic) != NULL)
        {
            ligne++;
			caractere += strlen(chaine);
		}
	printf("%d\n%d %s\n",ligne,caractere,nomFichier);
	}
	
	else if (strcmp(option,"-wc")==0)
	{                                  
		 while (fgets(chaine, sizeof(chaine), fic) != NULL)
	    	{
			mot++;
			caractere += strlen(chaine);
			}
		printf("%d\n%d %s\n",mot,caractere,nomFichier);
	}
		
    fclose(fic);								//fermeture du fichier ouvert apres tous les choses a faire dedans
}

/*cette programme peut etre n'est pas correctemment avec l'originale de cette commande,
 *  n'hesitez pas donc de me corriger s'il y a des problemes ou des choses qu'on va modifier 
 * pour l'amelioration de cette commande */
///Ecrit par jean Michel
