/*
** EPITECH PROJECT, 2023
** truc
** File description:
** play_mode
*/

#include "my.h"

void launch_play_mode(all_t *all)
{
    int orientation;
    sfTexture *playerTexture = sfTexture_createFromFile("./Assets/Images/player.png", NULL);
    sfSprite *playerSprite = sfSprite_create();
    sfTexture *enemyTexture = sfTexture_createFromFile("./Assets/Images/player.png", NULL);
    sfSprite *enemySprite = sfSprite_create();
    sfTexture *backgroundTexture = sfTexture_createFromFile("./Assets/Images/play_mode_background.jpg", NULL);
    sfSprite *backgroundSprite = sfSprite_create();
    sfTexture *knifeTexture = sfTexture_createFromFile("./Assets/Images/knife.png", NULL);
    sfSprite *knifeSprite = sfSprite_create();
    all->player_position.x = 500;
    all->player_position.y = 450;
    sfVector2f player_scale = {0.5, 0.5};
    sfVector2f enemy_scale = {0.5, 0.5};
    sfVector2f knife_scale = {0.05, 0.05};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    sfVector2f mouse_pos2f = {mouse_pos.x, mouse_pos.y};
    sfVector2f center = {all->player_position.x, all->player_position.y};
    sfVector2f half_size = {640, 360};
    sfVector2f player_origin = {40, 30};
    sfVector2f knife_position;
    sfView* view1 = sfView_create();

    sfSprite_setTexture(playerSprite, playerTexture, sfTrue);
    sfSprite_setTexture(knifeSprite, knifeTexture, sfTrue);
    sfSprite_setOrigin(playerSprite, player_origin);
    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    sfSprite_setTexture(enemySprite, enemyTexture, sfTrue);
    sfSprite_setScale(playerSprite, player_scale);
    sfSprite_setScale(enemySprite, enemy_scale);
    sfSprite_setScale(knifeSprite, knife_scale);
    sfSprite_setPosition(playerSprite, all->player_position);
    sfView_setCenter(view1, center);
    sfView_setSize(view1, half_size);
    sfSprite_setRotation(knifeSprite, 45);
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
            
        }
        if (sfKeyboard_isKeyPressed(sfKeyW)){
            all->player_position.y -= 0.1;
            center.y -= 0.1;
            sfView_setCenter(view1, center);
            sfSprite_setRotation(playerSprite, 0);
        }
        if (sfKeyboard_isKeyPressed(sfKeyS)){
            all->player_position.y += 0.1;
            center.y += 0.1;
            sfView_setCenter(view1, center);
            sfSprite_setRotation(playerSprite, 180);
        }
        if (sfKeyboard_isKeyPressed(sfKeyA)){
            all->player_position.x -= 0.1;
            center.x -= 0.1;
            sfView_setCenter(view1, center);
            sfSprite_setRotation(playerSprite, 270);
        }
        if (sfKeyboard_isKeyPressed(sfKeyD)){
            all->player_position.x += 0.1;
            center.x += 0.1;
            sfView_setCenter(view1, center);
            sfSprite_setRotation(playerSprite, 90);
        }
        if (sfKeyboard_isKeyPressed(sfKeyF)){
            sfSprite_setPosition(knifeSprite, all->player_position);
            knife_position = all->player_position;
            orientation = sfSprite_getRotation(playerSprite);
            printf("%d\n", orientation);
        }
        if (orientation == 0){
            sfSprite_setRotation(knifeSprite, 45);
            knife_position.y -= 0.2;
        }
        if (orientation == 180){
        sfSprite_setRotation(knifeSprite, 225);
        knife_position.y += 0.2;
        }
        if (orientation == 90){
        sfSprite_setRotation(knifeSprite, 135);
        knife_position.x += 0.2;
        }
        if (orientation == 270){
        sfSprite_setRotation(knifeSprite, 315);
        knife_position.x -= 0.2;
        }
        sfSprite_setPosition(playerSprite, all->player_position);
        sfSprite_setPosition(knifeSprite, knife_position);
        sfRenderWindow_clear(all->window, sfWhite);
        sfRenderWindow_drawSprite(all->window, backgroundSprite, NULL);
        sfRenderWindow_drawSprite(all->window, knifeSprite, NULL);
        sfRenderWindow_drawSprite(all->window, playerSprite, NULL);
        sfRenderWindow_drawSprite(all->window, enemySprite, NULL);
        //sfRenderWindow_setView(all->window, view1);
        sfRenderWindow_display(all->window);
    }
}