/*
** EPITECH PROJECT, 2018
** mlib
** File description:
** Char* to int
*/

static int getnbr1(char *str)
{
    int nega = 0;

    for (int i = 0 ; str[i] < '0' || str[i] > '9' ; i++) {
        if (str[i] == '-')
            nega++;
        if (str[i] != '-' && str[i] != '+')
            nega = 0;
    }
    return (nega);
}

int mgetnbr(char *str)
{
    long nbr = 0;
    long counter = 1;
    int i = 0;
    int nega = getnbr1(str);

    for (i = 0 ; str[i] < '0' || str[i] > '9' ; i++);
    for ( ; '0' <= str[i] && str[i] <= '9' ; i++, counter *= 10);
    counter /= 10;
    for (i = 0 ; str[i] < '0' || str[i] > '9' ; i++);
    for ( ; counter >= 1 ; i++) {
        nbr += (str[i] - '0') * counter;
        counter /= 10;
    }
    if (nega % 2 == 1)
        nbr *= -1;
    if (nbr < -2147483648 || nbr > 2147483647)
        nbr = 0;
    return (nbr);
}
