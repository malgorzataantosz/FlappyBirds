#ifndef FLAPPYBIRDS_DEFINITIONS_H
#define FLAPPYBIRDS_DEFINITIONS_H

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 924

#define INTRO_STATE_SHOW_TIME 3.0

#define INTRO_SCENE_BACKGROUND_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/intro.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/sky.png"

#define GAME_BACKGROUND_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/sky.png"

#define GAME_TITLE_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/title.png"

#define PLAY_BUTTON_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/button.png"

#define PIPE_UP_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/PipeDown.png"

#define GROUND_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/Ground.png"

#define BIRD_FRAME_1_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/bird.png"

#define SCORING_PIPE_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/res/InvisibleScoringPipe.png"

#define FONT_FILEPATH "/home/malgorzata/clion/FlappyBirds/Resources/fonts/font.ttf"

//experimental number
#define PIPE_MOVEMENT_SPEED 200.0f

#define PIPE_SPAWN_FREQUENCY 2.0f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 200.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATUIN 0.25f

enum GameStates{
    READY,
    PLAY,
    GAMEOVER
};



#endif