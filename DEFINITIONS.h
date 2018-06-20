#ifndef FLAPPYBIRDS_DEFINITIONS_H
#define FLAPPYBIRDS_DEFINITIONS_H

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 924

#define INTRO_STATE_SHOW_TIME 3.0

#define INTRO_SCENE_BACKGROUND_FILEPATH "Resources/res/intro.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"

#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"

#define GAME_OVER_FILEPATH "Resources/res/game-over.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"

#define PLAY_BUTTON_FILEPATH "Resources/res/button.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"

#define GROUND_FILEPATH "Resources/res/Ground.png"

#define BIRD_FRAME_1_FILEPATH "Resources/res/bird.png"

#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define FONT_FILEPATH "Resources/fonts/font.ttf"

//experimental number
#define PIPE_MOVEMENT_SPEED 200.0f

#define PIPE_SPAWN_FREQUENCY 2.0f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 200.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATUIN 0.25f
#define TIME_BEFORE_GAME_OVER 2.0f

enum GameStates{
    READY,
    PLAY,
    GAMEOVER
};



#endif