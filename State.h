#ifndef FLAPPYBIRDS_STATE_H
#define FLAPPYBIRDS_STATE_H

class State {

public:
    virtual void init() = 0;

    virtual void handleInput() = 0;

    virtual void update(float dt) =0;

    virtual void draw(float d) = 0;

    virtual void pause() {};

    virtual void resume() {};
};

#endif //FLAPPYBIRDS_STATE_H
