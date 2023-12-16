/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-eloi.tisserand
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>

typedef struct all{
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f player_position;
} all_t;

void main(void);
int launch_main_menu(all_t *all);
int checkif_play(all_t *all);
void launch_play_mode(all_t *all);
int my_strlen(char const *str);


#endif /* !MY_H_ */
