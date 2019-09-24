//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include "../include/interface.hpp"

Core loop_game(Core core,  DLLoader<IDisplayModule> load)
{
    int i;
    int j;
    for(i = 0; core._libs.at(i).find( core.getInstance()->getName()) != std::string::npos; i++);
    for(j = 0; core._games.at(j) !=  core._gameChosen; j++);

    i++;
    j++;


    if (core._gameChosen != "" && core._play) {
        Arcade::Input valInput = Arcade::Input::None;
        DLLoader<IGameModule> loadGame;
        IGameModule *gametmp;



        // ** SEGFAULT quand on load une lib graphic à la place d'un jeu  **//
        IGameModule *gameInstance = loadGame.getInstance(core._gameChosen.c_str());  // <--  ICI

        if (dlsym(gameInstance->getHandle(), "gamecheck") == NULL) {
             core._play = false;

            loadGame.destroyInstance(gameInstance);
            return core;
        }
        while (valInput != Arcade::Input::P && core._play) {
            core._instance->setDeltaTime();
            core._instance->clearWindow();
            
            valInput = core._instance->coreInputs();
            gameInstance->updateInput(valInput);
            core._score = gameInstance->updateGame(core._instance);

            
            if (valInput == Arcade::Input::M || valInput == Arcade::Input::Escape || core._score > 0) core._play = false;
            switch (valInput)
            {
                case Arcade::Input::Num1: i--;
                    if (i < 0)
                        i = (int)core._libs.size()-1;
                    load.destroyInstance(core.getInstance());
                    core.setInstance(load.getInstance(core._libs.at(i)));
                    core._instance->startClock();
                break;
                case Arcade::Input::Num2: i++;
                    if (i == (int)core._libs.size())
                        i = 0;
                    load.destroyInstance(core.getInstance());
                    core.setInstance(load.getInstance(core._libs.at(i)));
                    core._instance->startClock();
                break;
                case Arcade::Input::Num3: j--;
                    if (j < 0)
                        j = (int)core._games.size()-1;
                    gametmp = loadGame.getInstance(core._games.at(j));
                    if (dlsym(gametmp->getHandle(), "gamecheck") != NULL) {
                        loadGame.destroyInstance(gameInstance);
                        gameInstance = loadGame.getInstance(core._games.at(j));
                    }
                    loadGame.destroyInstance(gametmp);

                break;
                case Arcade::Input::Num4: j++;
                    if (j == (int)core._games.size())
                        j = 0;
                    
                    gametmp = loadGame.getInstance(core._games.at(j));
                    if (dlsym(gametmp->getHandle(), "gamecheck") != NULL) {
                        loadGame.destroyInstance(gameInstance);
                        gameInstance = loadGame.getInstance(core._games.at(j));
                    }
                    loadGame.destroyInstance(gametmp);
                break;
                default:
                    break;
            }
            gameInstance->drawGame(core._instance);
            core._instance->displayWindow();
        }
        loadGame.destroyInstance(gameInstance);
    }
    return core;
}





Core loop_menu(Core core, DLLoader<IDisplayModule> load)
{
    Menu menu;
    core._val = core._instance->coreInputs();
    menu.initMenu(core._games, core._libs);
    core._instance->clearWindow();
    DLLoader<IGameModule> loadGame;

    if (core._score >= 0) menu.theScore.setString("Your previous Score: " + std::to_string(core._score));
    menu.titleAtcuLib.setString(core._instance->getName().c_str());

    menu.updateMenu(core._val);

    menu.drawTitle(core._instance);
    menu.drawOptionLib(core._instance);
    menu.drawOptionGame(core._instance);

    core._instance->drawRectangle(menu.bigRect);
    core._instance->drawRectangle(menu.rect);

    menu.setPseudo(core._val);
    core._instance->drawText(menu.selector);
    core._instance->drawText(menu.pseudoName);

    core._instance->displayWindow();
    core._instance->drawText(menu.selector);
    core._val = core._instance->coreInputs();



    while (core._val != Arcade::Input::Escape) {

        if (core._play) {
            core = loop_game(core, load);
        }

        core._val = core._instance->coreInputs();

        if (core._score >= 0) menu.theScore.setString("Your previous Score: " + std::to_string(core._score));
        menu.titleAtcuLib.setString(core._instance->getName().c_str());


        if (core._val == Arcade::Input::Return) {
            for (unsigned int i = 0; i < menu.gameNames.size(); i++) {
                if (menu.selector.getPosition().y == menu.gameNames.at(i).getPosition().y &&
                    menu.selector.getPosition().x == 450) {
                    core.setGame(menu.gameNames.at(i).getString());
                    core._play = true;
                }
            }
            for (unsigned int i = 0; i < menu.libNames.size(); i++) {
                if (menu.selector.getPosition().y == menu.libNames.at(i).getPosition().y &&
                    menu.selector.getPosition().x == 650 &&
                    menu.libNames.at(i).getString().find(core._instance->getName()) == std::string::npos) {
                    load.destroyInstance(core.getInstance());
                    core.setInstance(load.getInstance(menu.libNames.at(i).getString()));
                    core._instance->startClock();
            
                    

                }
            }
        }

        core._instance->clearWindow();

        menu.updateMenu(core._val);

        menu.drawTitle(core._instance);
        menu.drawOptionLib(core._instance);
        menu.drawOptionGame(core._instance);

        core._instance->drawRectangle(menu.bigRect);
        core._instance->drawRectangle(menu.rect);

        menu.setPseudo(core._val);
        core._instance->drawText(menu.selector);
        core._instance->drawText(menu.pseudoName);

        core._instance->displayWindow();

    }
    return core;
}



std::string verifLib(char *av)
{
    std::string first_lib = "";
    first_lib += av;

    if (first_lib.find("lib/") != std::string::npos)
        first_lib.replace(0, 5, " ");
    first_lib.replace(0,2, "./lib/");
    return av;
}


int main(int ac, char **av)
{
    DLLoader<IDisplayModule> load;

    std::string first_lib = "";

    if (error(ac, av) == 84)
        return 84;
    if ((first_lib = verifLib(av[1])) == "Error")
        return 84;

    Core core(load.getInstance(first_lib.c_str()));
    core._instance->startClock();
    core = loop_menu(core, load);

    load.destroyInstance(core.getInstance());

    return 0;
}
