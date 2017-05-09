#ifndef TRANSLATIONXML_H
#define TRANSLATIONXML_H

#include <QObject>
#include <QDomDocument>


class TranslationXML : public QObject
{
    Q_OBJECT
public:
    explicit TranslationXML(QObject *parent = 0);
    QString GetTranslation(QString transFile, QString s);
    void XMLTranslate(QString srcFile, QString transFile);
    void SaveFile(QString pathFile, QDomDocument dom);

signals:

public slots:
};

#endif // TRANSLATIONXML_H
