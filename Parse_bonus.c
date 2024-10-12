
#include "ft_printf.h"

// Cette fonction va juste analyser les drapeaux genre '-', '0', etc.
void parse_individual_flags(const char **format, t_format *fmt)
{
    // Tant qu'on trouve des drapeaux, on les analyse
    while (**format == '-' || **format == '0' || **format == '#' || **format == '+' || **format == ' ')
    {
        if (**format == '-')        // Si c'est '-', on aligne à gauche
            fmt->left_align = 1;
        else if (**format == '0')   // Si c'est '0', on remplit avec des zéros
            fmt->zero_padding = 1;
        else if (**format == '#')   // Si c'est '#', on met '0x' pour les hexadécimaux
            fmt->hashtag = 1;
        else if (**format == '+')   // Si c'est '+', on affiche toujours le signe
            fmt->plus_sign = 1;
        else if (**format == ' ')   // Si c'est ' ', on ajoute un espace pour les nombres positifs
            fmt->space = 1;
        
        (*format)++;  // On passe au caractère suivant
    }
}

// Ici, on check si y'a une largeur minimale spécifiée (genre '10', '5', etc.)
void parse_width(const char **format, t_format *fmt)
{
    if (**format >= '0' && **format <= '9')   // Si c'est un chiffre
    {
        fmt->width = 0;  // On initialise la largeur
        while (**format >= '0' && **format <= '9')  // Tant qu'on lit des chiffres
        {
            fmt->width = fmt->width * 10 + (**format - '0');  // On accumule les chiffres pour former le nombre
            (*format)++;  // On avance dans la chaîne
        }
    }
}

// Ensuite, on regarde s'il y a une précision (avec un '.' genre '.5', '.3', etc.)
void parse_precision(const char **format, t_format *fmt)
{
    if (**format == '.')  // Si on trouve un point, c'est qu'il y a une précision
    {
        (*format)++;  // On passe le point
        fmt->precision = 0;  // On initialise la précision
        while (**format >= '0' && **format <= '9')  // Tant qu'on lit des chiffres
        {
            fmt->precision = fmt->precision * 10 + (**format - '0');  // On forme la précision
            (*format)++;  // On avance dans la chaîne
        }
    }
}

// C'est la fonction principale qui appelle toutes les autres pour gérer les drapeaux, la largeur et la précision
void parse_flags(const char **format, t_format *fmt, va_list args)
{
    // On initialise tout à zéro ou -1 (pour la précision qui est absente au début)
    fmt->left_align = 0;
    fmt->zero_padding = 0;
    fmt->width = 0;
    fmt->precision = -1;
    fmt->hashtag = 0;
    fmt->plus_sign = 0;
    fmt->space = 0;

    // On appelle les fonctions qui font le vrai boulot
    parse_individual_flags(format, fmt);  // On regarde les drapeaux
    parse_width(format, fmt);             // On vérifie s'il y a une largeur minimale
    parse_precision(format, fmt);         // On check s'il y a une précision
}
