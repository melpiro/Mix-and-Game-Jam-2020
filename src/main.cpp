#include "App.hpp"



void init_texture_manager()
{
    O::graphics::ressourceManager.setDefaultTextureDir("Ressources/Graphics");
    O::graphics::ressourceManager.setDefaultFontDir("Ressources/Fonts");
    O::graphics::ressourceManager.setDefaultAudioDir("Ressources/Audio");
    O::graphics::ressourceManager.loadLanguage("Ressources/Language/fr");


    O::graphics::ressourceManager.addTextureAndLoadIt("LoadingMenu/loadIcon.png", "loadIcon");
    O::graphics::ressourceManager.addTexture("LoadingMenu/background.jpg", "loadingMenuBackground");
    O::graphics::ressourceManager.addTexture("MainMenu/boutonTexture.png", "boutonTexture");
    
    
    O::graphics::ressourceManager.addFontAndLoadIt("Soft Marshmallow.otf", "mainFont");
}

int main()
{
    init_texture_manager();

    App app;
    app.run();

}