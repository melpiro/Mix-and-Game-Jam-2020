#include "App.hpp"

#include "JsonData.hpp"

void init_texture_manager()
{
    O::graphics::ressourceManager.setDefaultTextureDir("resources/Graphics");
    O::graphics::ressourceManager.setDefaultFontDir("resources/Fonts");
    O::graphics::ressourceManager.setDefaultAudioDir("resources/Audio");

    O::graphics::ressourceManager.loadLanguage("resources/Language/fr");

    O::graphics::ressourceManager.addTextureAndLoadIt("LoadingMenu/loadIcon.png", "loadIcon");
    O::graphics::ressourceManager.addTexture("LoadingMenu/background.jpg", "loadingMenuBackground");
    O::graphics::ressourceManager.addTexture("MainMenu/boutonTexture.png", "boutonTexture");
    O::graphics::ressourceManager.addTexture("Tetris/cell.png", "tetrisCell");
    O::graphics::ressourceManager.addTexture("Inventory/background.png", "inventoryBackground");
    O::graphics::ressourceManager.addTexture("Inventory/box.png", "boxIcon");
    
    
    O::graphics::ressourceManager.addFontAndLoadIt("Soft Marshmallow.otf", "mainFont");

    // Tilemap
    O::graphics::ressourceManager.addTexture("Tilemap/tilemap_packed.png", "et_tilemap");

    // Enemies
    O::graphics::ressourceManager.addTexture("Enemies/blob.png", "blob_enemy");
}

int main()
{
    srand(time(NULL));
    init_texture_manager();

    App app;
    app.run();
}