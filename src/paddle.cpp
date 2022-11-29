#include "paddle.h"
#include "engine.h"

paddle::paddle() {}
paddle::~paddle() {}


void paddle::setPlayerReset() {
    setPosition(0.0f, (engine::yRes / 2) - (texture.getSize().y / 2));
}

void paddle::setCPUReset() {
    setPosition(engine::xRes - (texture.getSize().x / 2), (engine::yRes / 2) - (texture.getSize().y / 2));
}
