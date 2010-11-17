#include <QtCore>
#include <QtGui>
#include <QTranslator>

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

    // Inicializuje se translator.
    QTranslator translator;
    translator.load("../felchess_en");
    app.installTranslator(&translator);


    // Vytvori se okno aplikace.
    MainWindow * mainWindow = new MainWindow();
    mainWindow->show();

    // Spusteni Qt.
    return app.exec();

    // Uvolneni pameti alokovanych objektu.
    delete mainWindow;
}
