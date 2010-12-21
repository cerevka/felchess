#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    started = false;
    player = true;
    chessboard = NULL;
    selectedPiece = NULL;
    playingPlayer = true;
}

Game::~Game()
{


}

Game * Game::getInstance()
{
    if (game == NULL)
    {
        game = new Game();
    }
    return game;
}

bool Game::startGameSlot(bool _player, QString _ip, QString _port)
{

    if (started == false)
    {
        // Hra jeste neni zalozena, zalozim ji.
        player = _player;

        chessboard = new Chessboard(this);

        connect(chessboard, SIGNAL(removePieceSignal(APiece*)), this, SLOT(removePieceSlot(APiece*)));

        // Na sachovnici se umisti figurky.
        placePieces();

        if (player == true)
        {
            // Vytvari se server.
            Server * server = new Server(_port.toInt(), this);
            Network * network = new Network(server, this);            
        }
        else
        {
            // Vytvari se klient.
            Client * client = new Client(_ip, _port.toInt(), this);
            Network * network = new Network(client, this);            
        }


        return true;
    }
    return false;
}

void Game::addPiece(APiece *piece)
{
    chessboard->addPiece(piece);
    emit addPieceSignal(piece);
}
void Game::placePieces(void)
{
    int row = 0;
    bool color = false;
    for (int i = 0; i < 2; ++i)
    {
        row = i * 7;
        Rook * rook1 = new Rook(color, QPoint (0, row), chessboard);
        addPiece(rook1);
        Knight * knight1 = new Knight(color, QPoint (1, row), chessboard);
        addPiece(knight1);
        Bishop * bishop1 = new Bishop(color, QPoint (2, row), chessboard);
        addPiece(bishop1);
        Queen * queen1 = new Queen(color, QPoint (3, row), chessboard);
        addPiece(queen1);
        King * king1 = new King(color, QPoint (4, row), chessboard);
        addPiece(king1);
        Bishop * bishop2 = new Bishop(color, QPoint (5, row), chessboard);
        addPiece(bishop2);
        Knight * knight2 = new Knight(color, QPoint (6, row), chessboard);
        addPiece(knight2);
        Rook * rook2 = new Rook(color, QPoint(7, row), chessboard);
        addPiece(rook2);

        // Vykresleni pesaku.
        Pawn * pawn;
        for (int j = 0; j < 8; ++j)
        {
            int y = (color)?(6):(1);
            pawn = new Pawn(color, QPoint (j, y), chessboard);
            addPiece(pawn);
        }

        color = !color;
    }

    // GUI se preda pozadavek na prekresleni.
    emit updateGUISignal();

}

void Game::boardClickedSlog(QPoint point)
{
    if (started == true && playingPlayer == player)
    {
        if (selectedPiece == NULL)
        {
            qDebug() << "Neni vybrana figura.";
            // Figura neni vybrana.
            if (chessboard->isEmpty(point) == false) {
                // Na poli se nejaka figura nachazi.
                if (chessboard->getPiece(point)->getColor() == player)
                {
                    qDebug() << "Byla vybrana figura." << point;
                    // Figura ma barvu hrace. Vybere se.
                    selectedPiece = chessboard->getPiece(point);
                }
            }
        }
        else
        {
            qDebug() << "Figura jiz je vybrana, zameruje se cil.";
            // Figura je vybrana.
            if (selectedPiece->getCoordinate() != point)
            {
                qDebug() << "Cil je ruzny od zdroje.";
                // Bylo kliknuto na jine pole.
                if (chessboard->isEmpty(point) == true)
                {
                    qDebug() << "Cilove pole je prazdne.";
                    // Cilove pole je prazdne. Staci overit validitu tahu.
                    if (chessboard->isMoveValid(selectedPiece->getCoordinate(), point))
                    {
                        qDebug() << "Figura se presunula na cilove pole.";
                        emit movePieceSignal(selectedPiece->getCoordinate(), point);
                        moveSlot(selectedPiece->getCoordinate(), point);
                    }
                }
                else
                {
                    qDebug() << "Cilove pole je obsazene.";
                    // Cilove pole je obsazene.
                    if (chessboard->getPiece(point)->getColor() != player)
                    {
                        qDebug() << "Cilove figura ma barvu protivnika.";
                        if (chessboard->isMoveValid(selectedPiece->getCoordinate(), point))
                        {
                            // Barva cilove figury je jina nez moje, mohu ji vzit.
                            emit movePieceSignal(selectedPiece->getCoordinate(), point);
                            moveSlot(selectedPiece->getCoordinate(), point);
                        }

                    }

                }
            }
            selectedPiece = NULL;
            emit updateGUISignal();
        }
    }

}

void Game::moveSlot(QPoint source, QPoint target)
{
    chessboard->movePiece(source, target);
    playingPlayer = !playingPlayer;
    emit updateGUISignal();
}

void Game::removePieceSlot(APiece *piece) {
    emit removePieceSignal(piece);
}
