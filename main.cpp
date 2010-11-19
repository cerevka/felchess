#include <QtCore>
#include <QtGui>
#include <QTranslator>
#include <QDebug>
#include <QFile>

#include "globals.h"

// Nadefinovani referenci ze tridy Globals.
MainWindow * Globals::mainWindow = NULL;
QSettings * Globals::settings = NULL;

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

    // Zkontroluje se existence konfiguracniho souboru a jinak se vytvori z resource.
    if (!QFile::exists("config.ini")) {
        QFile::copy(":/config.ini", "config.ini");
    }

    // Nacte se konfigurace.
    Globals::settings = new QSettings("config.ini", QSettings::IniFormat);

    // Inicializuje se translator.
    QTranslator translator;
    translator.load(":/lang/felchess_" + Globals::settings->value("language/default_language").toString() + ".qm");
    app.installTranslator(&translator);


    // Vytvori se okno aplikace.
    Globals::mainWindow = new MainWindow();
    Globals::mainWindow->show();

    // Spusteni Qt.
    return app.exec();

    // Uvolneni pameti alokovane ve staticke tride Globals.
    delete Globals::settings;
    delete Globals::mainWindow;
}
