#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QDir>
#include <QStringList>
#include "view/widgets/centerwidget.h"

#include "../globals.h"


/**
  * Hlavni okno programu, ktere zajistuje konstru GUI.
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
      * Vytvoreni noveho okna.
      * @param * parent Ukazatel na rodice/vlastnika.
      */
    explicit MainWindow(QWidget * parent = 0);

    /**
      * Destruktor okna.
      */
    virtual ~MainWindow(void);

private:

    /**
      * Vytvoreni menu hlavniho okna.
      */
    void createMenus(void);

    /**
      * Vytvoreni polozek hlavniho menu.
      */
    void createActions(void);

    QMenu * gameMenu;
    QMenu * toolMenu;
    QMenu * helpMenu;

    QAction * newGameAct;
    QAction * exitAct;

    QMenu * languageMenu;
    QActionGroup * languageActGroup;
    QList<QAction *> * languageActList;

    QAction * showSettingsAct;

    QAction * showAboutAct;
    QAction * showHelpAct;

signals:

    /**
      * Signal k prelozeni aplikace.
      */
    void retranslateSignal(void);

private slots:

    /**
      * Nacte preklady ke vsem komponentam.
      */
    void retranslateSlot(void);

    /**
      * Slot, ktery zpracovava zalozeni nove hry.
      */
    void newGameSlot(void);

    /**
      * Slot, ktery zpracovava ukonceni programu.
      */
    void exitSlot(void);

    /**
      * Slot, ktery zpracovava prepnuti jazyka.
      * @param * action Ukazatel na zvolenou akci (jazyk).
      */
    void switchLanguageSlot(QAction * action);

    /**
      * Slot, ktery zpracovava vstup do nastaveni.
      */
    void showSettingsSlot(void);

    /**
      * Slot, ktery zpracovava zobrazni informaci o aplikaci.
      */
    void showAboutSlot(void);

    /**
      * Slot, ktery zpracovava zobrazeni napovedy.
      */
    void showHelpSlot(void);

};

#endif // MAINWINDOW_H
