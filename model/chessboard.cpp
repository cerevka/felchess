#include "chessboard.h"

Chessboard::Chessboard(QObject *parent) : QObject(parent)
{
    // Vycisti pole na same NULL.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = NULL;            
        }
    }
}

Chessboard::~Chessboard(void)
{

}

bool Chessboard::isEmpty(QPoint target) {
    return (board[target.x()][target.y()] == NULL)?(true):(false);
}

void Chessboard::addPiece(APiece *piece)
{
    board[piece->getCoordinate().x()][piece->getCoordinate().y()] = piece;
}

bool Chessboard::isMoveValid(QPoint source, QPoint target)
{

    return board[source.x()][source.y()]->isMoveValid(this, target);
}

void Chessboard::movePiece(QPoint source, QPoint target)
{
    if (board[target.x()][target.y()] != NULL)
    {
        // Na cilovem poli je figura. Musi se odstranit z vykreslovani.
        emit removePieceSignal(board[target.x()][target.y()]);
    }
    board[target.x()][target.y()] = board[source.x()][source.y()];
    board[source.x()][source.y()] = NULL;
    board[target.x()][target.y()]->setCoordinate(target);

}

APiece * Chessboard::getPiece(QPoint coordinates)
{
    return board[coordinates.x()][coordinates.y()];
}
