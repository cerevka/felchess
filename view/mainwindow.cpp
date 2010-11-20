#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
{
    createActions();
    createMenus();

    setWindowTitle(tr("windowTitle"));
    setFixedHeight(700);
    setFixedWidth(1000);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    // Polozky herniho menu.
    newGameAct = new QAction(tr("newGame"), this);
    newGameAct->setShortcut(tr("CTRL+N"));
    newGameAct->setStatusTip(tr("newGameStatusTip"));
    connect(newGameAct, SIGNAL(triggered()), this, SLOT(newGameSlot()));

    exitAct = new QAction(tr("exitAct"), this);
    exitAct->setShortcut(tr("CTRL+Q"));
    exitAct->setStatusTip(tr("exitStatusTip"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(exitSlot()));

    // Polozky nastrojoveho menu.    

    // Zjisti se dostupne jazyky.
    languageActGroup = new QActionGroup(this);
    languageActGroup->setExclusive(true);
    connect(languageActGroup, SIGNAL(triggered(QAction*)), this, SLOT(switchLanguageSlot(QAction*)));

    QDir langDir (":/lang");
    QStringList fileNames = langDir.entryList(QStringList("felchess_*.qm"), QDir::Files, QDir::Name);
    languageActList = new QList<QAction *>;


    // Generovani prepinacu jazyku.
    QMutableStringListIterator i(fileNames);
    QAction * langAction;
    while (i.hasNext())
    {
        i.next();
        // Vytvori se tlacitko pro volbu jazyka a ulozi se do seznamu.
        langAction = new QAction(tr(i.value().toAscii()), this);
        // Vysekne se jen oznaceni jazykove verze.
        langAction->setData(i.value().mid(9, 2));

        langAction->setCheckable(true);

        // Napojeni prepinace do skupiny a jeho vlozeni do seznamu.
        languageActGroup->addAction(langAction);
        languageActList->append(langAction);

        // Zaskrtne se aktualni jazyk.
        if (langAction->data().toString() == Globals::settings->value("language/defaultLanguage").toString()) {
            langAction->setChecked(true);
        }
    }

    showSettingsAct = new QAction(tr("settingAct"), this);
    connect(showSettingsAct, SIGNAL(triggered()), this, SLOT(showSettingsSlot()));

    // Polozky menu s napovedou.
    showAboutAct = new QAction(tr("aboutAct"), this);
    connect(showAboutAct, SIGNAL(triggered()), this, SLOT(showAboutSlot()));
    showHelpAct = new QAction(tr("helpAct"), this);
    connect(showHelpAct, SIGNAL(triggered()), this, SLOT(showHelpSlot()));
}

void MainWindow::createMenus()
{
    // Nadefinovani herniho menu.
    gameMenu = menuBar()->addMenu(tr("gameMenu"));
    gameMenu->addAction(newGameAct);
    gameMenu->addSeparator();
    gameMenu->addAction(exitAct);

    // Nadefinovani nastrojoveho menu.
    toolMenu = menuBar()->addMenu(tr("toolMenu"));

    languageMenu = new QMenu(tr("languageMenu"), this);
    toolMenu->addMenu(languageMenu);

    for (int i = 0; i < languageActList->size(); i++)
    {
        //langAction = languageActList->at(i);
        languageMenu->addAction(languageActList->at(i));

    }

    toolMenu->addAction(showSettingsAct);

    // Nadefinovani menu s napovedou.
    helpMenu = menuBar()->addMenu(tr("helpMenu"));
    helpMenu->addAction(showHelpAct);
    helpMenu->addSeparator();
    helpMenu->addAction(showAboutAct);
}

void MainWindow::newGameSlot()
{

}

void MainWindow::exitSlot()
{
    close();
}

void MainWindow::switchLanguageSlot(QAction * action)
{
    // Nova konfigurace se ulozi do configu.
    Globals::settings->setValue("language/defaultLanguage", action->data().toString());
    QMessageBox messageBox;
    messageBox.setText(tr("switchLanguageMessageBox"));
    messageBox.exec();
}

void MainWindow::showSettingsSlot()
{

}

void MainWindow::showAboutSlot()
{

}

void MainWindow::showHelpSlot()
{

}
