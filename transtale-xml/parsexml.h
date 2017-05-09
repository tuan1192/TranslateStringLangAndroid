#ifndef PARSEXML_H
#define PARSEXML_H

#include <QObject>
#include <QDomDocument>


class ParseXml : public QObject
{
    Q_OBJECT
public:
    explicit ParseXml(QObject *parent = 0);
    QString GetTranslation(QString s);
    void XMLTranslate();
    void SaveFile(QDomDocument dom);

signals:

public slots:
};

#endif // PARSEXML_H
