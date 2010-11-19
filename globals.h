#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSettings>
#include "view/mainwindow.h"

/**
  * Specialni trida udrzujici ukazatele na singletonove tridy.
  */
class Globals
{
public:

    /**
      * Instance hlavniho okna aplikace.
      */
    static MainWindow * mainWindow;

    static QSettings * settings;

};

#endif // GLOBALS_H
