#ifndef BOARDHASHMAP_H
#define BOARDHASHMAP_H

#include <QObject>
#include <board.h>
#include <QHash>

class BoardHashMap : QObject
{
    Q_OBJECT
public:
    BoardHashMap();
    ~BoardHashMap();

    void insert(QString key, QSharedPointer<Board> board);
    QSharedPointer<Board> value(QString key);
    int  remove(QString key);
private:
    QHash<QString, QSharedPointer<Board>> storage;
};

#endif // BOARDHASHMAP_H
