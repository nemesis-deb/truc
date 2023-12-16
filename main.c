/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-eloi.tisserand
** File description:
** my_hunter
*/

#include "my.h"

int checkif_play(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);

    if (mouse_pos.x > 650 && mouse_pos.x < 938){
        if (mouse_pos.y > 450 && mouse_pos.y < 542){
            return 1;
        }
    }
    return 0;
}

int launch_main_menu(all_t *all)
{
    sfTexture *play_button = sfTexture_createFromFile("./Assets/Images/Menu/Buttons/play_button.png", NULL);
    sfSprite *play_buttonSprite = sfSprite_create();
    sfVector2f play_button_position = {650, 450};
    sfVector2f scale_play = {0.5, 0.5};
    sfVector2f scale_cancel = {0.39, 0.39};
    sfText *title_text;
    sfFont *font;
    sfVector2f title_text_position = {250, 100};
    sfText *topscore_text;
    sfVector2f topscore_text_position = {250, 250};
    sfText *topscore1_text;
    sfVector2f topscore1_text_position = {700, 250};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    sfVector2f mouse_pos2f = {mouse_pos.x, mouse_pos.y};
  
    sfSprite_setTexture(play_buttonSprite, play_button, sfTrue);
    sfSprite_setScale(play_buttonSprite, scale_play);
    sfSprite_setPosition(play_buttonSprite, play_button_position);
    while (sfMouse_isButtonPressed(sfMouseLeft)){
        }
    while (sfRenderWindow_isOpen(all->window)){
        while (sfRenderWindow_pollEvent(all->window, &(all->event))){
            if (all->event.type == sfEvtClosed){
                sfRenderWindow_close(all->window);
            }
        }
        mouse_pos = sfMouse_getPositionRenderWindow(all->window);
        mouse_pos2f.x = mouse_pos.x;
        mouse_pos2f.y = mouse_pos.y;
        if (all->event.type == sfEvtMouseButtonPressed){
                if (checkif_play(all) == 1){
                    launch_play_mode(all);
                }
            }
        sfRenderWindow_clear(all->window, sfWhite);
        sfRenderWindow_drawSprite(all->window, play_buttonSprite, NULL);
        sfRenderWindow_display(all->window);
    }
}

void main(void)
{
    all_t *all;
    all = malloc(sizeof(all_t));
    sfVideoMode mode = {1600, 900, 60};


    all->window = sfRenderWindow_create(mode, "prout", sfClose, NULL);
    launch_main_menu(all);
}
