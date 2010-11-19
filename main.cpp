#include <QtCore>
#include <QtGui>
#include <QTranslator>
#include <QSettings>
#include <QDebug>

#include "view/mainwindow.h"

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

    // Nacte se konfigurace.
    QSettings * settings = new QSettings("../data/config.ini", QSettings::IniFormat);

    // Inicializuje se translator.
    QTranslator translator;
    translator.load("../data/felchess_" + settings->value("language/default_language").toString() + ".qm");
    app.installTranslator(&translator);


    // Vytvori se okno aplikace.
    MainWindow * mainWindow = new MainWindow();
    mainWindow->show();

    // Spusteni Qt.
    return app.exec();

    // Uvolneni pameti alokovanych objektu.
    delete settings;
    delete mainWindow;
}
