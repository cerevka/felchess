#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
{
    createActions();
    createMenus();

    setFixedHeight(700);
    setFixedWidth(1000);

    retranslate();
}

MainWindow::~MainWindow(void)
{

}

void MainWindow::createActions(void)
{
    // Polozky herniho menu.
    newGameAct = new QAction(this);
    connect(newGameAct, SIGNAL(triggered()), this, SLOT(newGameSlot()));

    exitAct = new QAction(this);
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

    showSettingsAct = new QAction(this);
    connect(showSettingsAct, SIGNAL(triggered()), this, SLOT(showSettingsSlot()));

    // Polozky menu s napovedou.
    showAboutAct = new QAction(this);
    connect(showAboutAct, SIGNAL(triggered()), this, SLOT(showAboutSlot()));
    showHelpAct = new QAction(this);
    connect(showHelpAct, SIGNAL(triggered()), this, SLOT(showHelpSlot()));
}

void MainWindow::createMenus(void)
{
    // Nadefinovani herniho menu.
    gameMenu = new QMenu(this);
    menuBar()->addMenu(gameMenu);
    gameMenu->addAction(newGameAct);
    gameMenu->addSeparator();
    gameMenu->addAction(exitAct);

    // Nadefinovani nastrojoveho menu.
    toolMenu = new QMenu(this);
    menuBar()->addMenu(toolMenu);

    languageMenu = new QMenu(this);
    toolMenu->addMenu(languageMenu);

    for (int i = 0; i < languageActList->size(); i++)
    {
        languageMenu->addAction(languageActList->at(i));

    }

    toolMenu->addAction(showSettingsAct);

    // Nadefinovani menu s napovedou.
    helpMenu = new QMenu(this);
    menuBar()->addMenu(helpMenu);
    helpMenu->addAction(showHelpAct);
    helpMenu->addSeparator();
    helpMenu->addAction(showAboutAct);
}

void MainWindow::retranslate(void) {
    setWindowTitle(tr("windowTitle"));
    gameMenu->setTitle(tr("gameMenu"));
    toolMenu->setTitle(tr("toolMenu"));
    languageMenu->setTitle(tr("languageMenu"));
    helpMenu->setTitle(tr("helpMenu"));

    newGameAct->setText(tr("newGame"));
    newGameAct->setShortcut(tr("CTRL+N"));
    newGameAct->setStatusTip(tr("newGameStatusTip"));

    exitAct->setText(tr("exitAct"));
    exitAct->setShortcut(tr("CTRL+Q"));
    exitAct->setStatusTip(tr("exitStatusTip"));

    showSettingsAct->setText(tr("settingAct"));

    showAboutAct->setText(tr("aboutAct"));
    showHelpAct->setText(tr("helpAct"));
}

void MainWindow::newGameSlot(void)
{

}

void MainWindow::exitSlot(void)
{
    close();
}

void MainWindow::switchLanguageSlot(QAction * action)
{
    // Nova konfigurace se ulozi do configu.
    Globals::settings->setValue("language/defaultLanguage", action->data().toString());

    // Vytvori se novy translator a zaregistruje se.
    QTranslator translator;
    translator.load(":/lang/felchess_" + Globals::settings->value("language/defaultLanguage").toString() + ".qm");
    Globals::application->installTranslator(&translator);

    // Prelozi se cela aplikace do zvoleneho jazyka.
    retranslate();
}

void MainWindow::showSettingsSlot(void)
{

}

void MainWindow::showAboutSlot(void)
{

}

void MainWindow::showHelpSlot(void)
{

}
