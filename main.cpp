#include <QtCore>
#include <QtGui>
#include <QTranslator>
#include <QDebug>
#include <QFile>

#include "globals.h"
#include "view/mainwindow.h"
#include "controller/game/game.h"

// Nadefinovani referenci ze tridy Globals.
QApplication * Globals::application = NULL;
QSettings * Globals::settings = NULL;
Game * Game::game = NULL;

/**
  * Vstupni bod do systemu.
  * @param argc Pocet argumentu prikazove radky.
  * @param argv[] Pole parametru prikazove radky.
  * @return Navratova hodnota programu.
  */
int main(int argc, char *argv[])
{
    // Inicializace Qt.
    QApplication app(argc, argv);
    Globals::application = &app;

    // Zkontroluje se existence konfiguracniho souboru a jinak se vytvori z resource.
    if (!QFile::exists("config.ini")) {
        QFile::copy(":/config.ini", "config.ini");
    }

    // Nacte se konfigurace.
    Globals::settings = new QSettings("config.ini", QSettings::IniFormat);

    // Inicializuje se translator.
    QTranslator translator;
    translator.load(":/lang/felchess_" + Globals::settings->value("language/defaultLanguage").toString() + ".qm");
    app.installTranslator(&translator);

    // Inicializuje se vstupni bod kontroleru.
    Game * game = Game::getInstance();

    // Vytvori se okno aplikace.
    MainWindow * mainWindow = new MainWindow();
    mainWindow->show();

    // Spusteni Qt.
    return app.exec();

    // Uvolneni pameti alokovane ve staticke tride Globals.
    delete Globals::settings;
    delete game;
    delete mainWindow;
}
