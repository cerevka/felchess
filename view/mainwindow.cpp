#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
{
    createActions();
    createMenus();

    setWindowTitle(tr("windowTitle"));
    setFixedHeight(700);
    setFixedWidth(1000);
}

MainWindow::~MainWindow() {

}

void MainWindow::createActions() {
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

    // Vytvori se menu s vyberem jazyku.
    QActionGroup * languageGroup = new QActionGroup(this);
    languageGroup->addAction("en");
    languageGroup->addAction("cs");

    showSettingsAct = new QAction(tr("settingAct"), this);
    connect(showSettingsAct, SIGNAL(triggered()), this, SLOT(switchLanguageSlot()));

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

    toolMenu->addMenu(tr("languageAct"));
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

void MainWindow::switchLanguageSlot()
{

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
