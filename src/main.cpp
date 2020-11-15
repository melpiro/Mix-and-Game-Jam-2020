#include "App.hpp"

#include "JsonData.hpp"

void init_texture_manager()
{
    O::graphics::ressourceManager.setDefaultTextureDir("resources/Graphics");
    O::graphics::ressourceManager.setDefaultFontDir("resources/Fonts");
    O::graphics::ressourceManager.setDefaultAudioDir("resources/Audio");

    O::graphics::ressourceManager.loadLanguage("resources/Language/en");

    O::graphics::ressourceManager.addTextureAndLoadIt("LoadingMenu/loadIcon.png", "loadIcon");
    O::graphics::ressourceManager.addTexture("MainMenu/menuBack.png", "loadingMenuBackground");
    O::graphics::ressourceManager.addTexture("MainMenu/boutonTexture.png", "boutonTexture");
    O::graphics::ressourceManager.addTexture("Tetris/cell.png", "tetrisCell");
    O::graphics::ressourceManager.addTexture("Inventory/background.png", "inventoryBackground");
    O::graphics::ressourceManager.addTexture("Inventory/box.png", "boxIcon");

    O::graphics::ressourceManager.addTexture("TileSet/bordGrass.png","bordGrass");
    O::graphics::ressourceManager.addTexture("TileSet/grass.png","grass");
    O::graphics::ressourceManager.addTexture("TileSet/murGrass.png","murGrass");
    O::graphics::ressourceManager.addTexture("TileSet/water.png","water");

    O::graphics::ressourceManager.addTexture("TileSet/bordPont.png","pontBord");
    O::graphics::ressourceManager.addTexture("TileSet/pontHorBas.png","pontHorBas");
    O::graphics::ressourceManager.addTexture("TileSet/pontHorhaut.png","pontHorHaut");
    O::graphics::ressourceManager.addTexture("TileSet/pontGauche.png","pontGauche");
    O::graphics::ressourceManager.addTexture("TileSet/pontDroite.png","pontDroite");
    O::graphics::ressourceManager.addTexture("TileSet/ladder.png","ladder");

    O::graphics::ressourceManager.addTexture("MainMenu/titre.png","titreJeu");
    O::graphics::ressourceManager.addTexture("MainMenu/gameTuto.png","tuto");
    O::graphics::ressourceManager.addTexture("MainMenu/credits.png","credits");
    O::graphics::ressourceManager.addTexture("MainMenu/normal_logo.png","logoJam");

    
    O::graphics::ressourceManager.addFontAndLoadIt("arcade.ttf", "mainFont");
    O::graphics::ressourceManager.addFontAndLoadIt("3Dventure.ttf", "titleFont");

    // Tilemap
    O::graphics::ressourceManager.addTexture("Tilemap/tilemap_packed.png", "et_tilemap");

    // Enemies
    O::graphics::ressourceManager.addTexture("Enemies/blob.png", "blob_enemy");
    O::graphics::ressourceManager.addTexture("Enemies/spitter.png", "spitter_enemy");
    O::graphics::ressourceManager.addTexture("Enemies/clone.png", "clone_enemy");

    //objets
    O::graphics::ressourceManager.addTexture("Objects/lifepack.png", "lifePack");
    O::graphics::ressourceManager.addTexture("Objects/spawner.png", "spawner");
}

int main()
{
    srand(time(NULL));
    init_texture_manager();

    App app;
    app.run();
}