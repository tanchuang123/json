#ifndef JSONREAD_H
#define JSONREAD_H
#include <QVariant>

class JsonRead
{
public:
    JsonRead();
    QVariant getJsonVariant(const QByteArray &json);
    QVariant getJsonVarian(const QString &filePath);
    void addFolderImages(QString path);
    bool FindFile(const QString & path);

};

#endif // JSONREAD_H
