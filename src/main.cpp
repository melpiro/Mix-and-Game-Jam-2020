#include "App.hpp"



void init_texture_manager()
{
    O::graphics::ressourceManager.setDefaultTextureDir("resources/Graphics");
    O::graphics::ressourceManager.setDefaultFontDir("resources/Fonts");
    O::graphics::ressourceManager.setDefaultAudioDir("resources/Audio");
    O::graphics::ressourceManager.loadLanguage("resources/Language/fr");


    O::graphics::ressourceManager.addTextureAndLoadIt("LoadingMenu/loadIcon.png", "loadIcon");
    O::graphics::ressourceManager.addTexture("LoadingMenu/background.jpg", "loadingMenuBackground");
    O::graphics::ressourceManager.addTexture("MainMenu/boutonTexture.png", "boutonTexture");

    for(int i = 0; i < 5; i++){
        O::graphics::ressourceManager.addTexture("TileSet/tile_"+std::to_string(i)+".png", "t"+ std::to_string(i));
    }
    O::graphics::ressourceManager.addTexture("TileSet/test.png","test");
    O::graphics::ressourceManager.addTexture("TileSet/water.png","water");
    O::graphics::ressourceManager.addTexture("TileSet/grass.png","grass");
    O::graphics::ressourceManager.addTexture("TileSet/murGrass.png","murGrass");
    O::graphics::ressourceManager.addTexture("TileSet/bordGrass.png","bordGrass");


    O::graphics::ressourceManager.addFontAndLoadIt("Soft Marshmallow.otf", "mainFont");
}

int main()
{
    init_texture_manager();

    App app;
    app.run();

}