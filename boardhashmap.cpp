#include "boardhashmap.h"

BoardHashMap::BoardHashMap() {
    storage = QHash<QString, QSharedPointer<Board>>();
}

BoardHashMap::~BoardHashMap()
{
    storage.clear();
}

void BoardHashMap::insert(QString key, QSharedPointer<Board> board)
{
    storage.insert(key, board);
}

QSharedPointer<Board> BoardHashMap::value(QString key)
{
    return storage.value(key);
}

int BoardHashMap::remove(QString key)
{
    return storage.remove(key);
}
