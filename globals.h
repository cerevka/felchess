#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSettings>
#include "view/mainwindow.h"

class MainWindow;

/**
  * Specialni trida udrzujici ukazatele na singletonove tridy.
  */
class Globals
{
public:

    /**
      * Instance aplikace.
      */
    static QApplication * application;

    /**
      * Instance hlavniho okna aplikace.
      */
    static MainWindow * mainWindow;

    /**
      * Instance nastaveni z config.ini nacitaneho pri bootu aplikace.
      */
    static QSettings * settings;
};

#endif // GLOBALS_H
