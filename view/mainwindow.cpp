#include "mainwindow.h"

MainWindow::MainWindow()
{
    createMenuBar();

    setWindowTitle(tr("windowTitle"));
    setFixedHeight(700);
    setFixedWidth(1000);
}

void MainWindow::createMenuBar()
{
   // Nadefinovani herniho menu.
   gameMenu = menuBar()->addMenu(tr("gameMenu"));
   newGameAct = gameMenu->addAction(tr("newGameAct"));
   exitAct = gameMenu->addAction(tr("exitAct"));

   // Nadefinovani nastrojoveho menu.
   toolMenu = menuBar()->addMenu(tr("toolMenu"));
   switchLanguageAct = toolMenu->addAction(tr("languageAct"));
   showSettingsAct = toolMenu->addAction(tr("settingAct"));

   // Nadefinovani menu s napovedou.
   helpMenu = menuBar()->addMenu(tr("helpMenu"));
   showAboutAct = helpMenu->addAction(tr("aboutAct"));
   showHelpAct = helpMenu->addAction(tr("helpAct"));

   // Napojeni akci na sloty.
   connect(newGameAct, SIGNAL(triggered()), this, SLOT(newGameSlot()));
   connect(exitAct, SIGNAL(triggered()), this, SLOT(exitSlot()));
   connect(switchLanguageAct, SIGNAL(triggered()), this, SLOT(switchLanguageSlot()));
   connect(showSettingsAct, SIGNAL(triggered()), this, SLOT(switchLanguageSlot()));
   connect(showAboutAct, SIGNAL(triggered()), this, SLOT(showAboutSlot()));
   connect(showHelpAct, SIGNAL(triggered()), this, SLOT(showHelpSlot()));
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
