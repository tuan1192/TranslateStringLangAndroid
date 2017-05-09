#include "translationxml.h"
#include <QDebug>
#include <QString>
#include <QDomDocument>
#include <QFile>
#include <stdlib.h>

TranslationXML::TranslationXML(QObject *parent) : QObject(parent)
{

}

bool icompare_pred(unsigned char a, unsigned char b)
{
    return std::tolower(a) == std::tolower(b);
}

bool icompare(std::string const& a, std::string const& b)
{
    if (a.length()==b.length()) {
        return std::equal(b.begin(), b.end(),
                           a.begin(), icompare_pred);
    }
    else {
        return false;
    }
}

// Truyền vào key word, trả về tiếng anh
QString TranslationXML::GetTranslation(QString transFile, QString input)
{
       //load the file
       QFile xmlFile(transFile);
       if (!xmlFile.exists() || !xmlFile.open(QFile::ReadOnly | QFile::Text)) {
              qDebug() << "Check your file";
              return "";
        }

       int total = 0;
       QDomDocument domDocument;
       domDocument.setContent(&xmlFile);
       QDomElement topElement = domDocument.documentElement();

       // Level 1 - Lấy Worksheet
       QDomNode domNode = topElement.firstChild();
       while (!domNode.isNull()) {
           QDomElement domElement = domNode.toElement();
           if (!domElement.isNull()) {
               if (domElement.tagName() == "Worksheet") {
                   // Level 2 - Lấy table
                   QDomNode nodeTable = domElement.firstChild();
                   while (!nodeTable.isNull()) {
                       QDomElement elementTable = nodeTable.toElement();
                       if (!elementTable.isNull()) {
                           if (elementTable.tagName() == "Table") {
                               // Level 3 - Lấy table
                               QDomNode nodeRow = elementTable.firstChild();
                               while (!nodeRow.isNull()) {
                                   QDomElement elementRow = nodeRow.toElement();
                                   if (!elementRow.isNull()) {
                                       if (elementRow.tagName() == "Row") {
                                           // Level 4 - Lấy Cell
                                           QDomNode nodeCell = elementRow.firstChild();
                                           while (!nodeCell.isNull()) {
                                               QDomElement elementCell = nodeCell.toElement();
                                               if (!elementCell.isNull()) {
                                                   if (elementCell.tagName() == "Cell") {
                                                       // Lấy dữ liệu cần thiết
                                                       QDomElement elementData = elementCell.toElement();
                                                       std::string str1 = elementData.text().toStdString();
                                                       std::string str2 = input.toStdString();
                                                       // Compare 2 Strings
                                                       if (icompare(str1,str2)) {
                                                          qDebug() << "Found! - Find translation...";
                                                          QString ts = nodeCell.nextSibling().toElement().firstChildElement("Data").text();
                                                          return  ts != NULL ? ts : NULL;
                                                       }
                                                       total++;
                                                   }

                                               }
                                               nodeCell = nodeCell.nextSibling();
                                           }
                                           total++;
                                       }

                                   }
                                   nodeRow = nodeRow.nextSibling();
                               }
                           }

                       }
                       nodeTable = nodeTable.nextSibling();
                   }
               }
           }
           domNode = domNode.nextSibling();
       }
       return NULL;
}

void TranslationXML::XMLTranslate(QString srcFile, QString transFile)
{
       //load the file
       QFile xmlFile(srcFile);
       if (!xmlFile.exists() || !xmlFile.open(QFile::ReadOnly | QFile::Text)) {
              qDebug() << "Check your file";
              return;
        }
       QDomDocument domDocument;
       domDocument.setContent(&xmlFile);
       QDomElement topElement = domDocument.documentElement();
       QDomNode domNode = topElement;
       int totalOrigin = 0;
       int totalTranslated = 0;
       while (!domNode.isNull()) {
           QDomElement domElement = domNode.toElement();
           if (!domElement.isNull()) {
               //qDebug() << domElement.tagName();
               if (domElement.tagName() == "resources") {
                   QDomNode node = domElement.firstChild();
                   while (!node.isNull()) {
                       QDomElement element = node.toElement();
                       if (!element.isNull()) {
                           const QString tagName(element.tagName());
                           if (tagName == "string") {

                               QString trans = GetTranslation(transFile, element.text());

                               if (trans != NULL) {
                                   qDebug() << "Origin: " << element.text() << node.nodeType() << "--" << node.nodeValue();
                                   qDebug() << "Translation: " << trans;
                                   element.firstChild().setNodeValue(trans);
                                   qDebug() << "After set: " << element.text();
                                   totalTranslated++;
                               }
                               totalOrigin++;

                           }
                       }
                       node = node.nextSibling();
                   }
               }
           }
           domNode = domNode.nextSibling();
       }
       SaveFile(srcFile, domDocument);
       qDebug() << "Total Origin: " << totalOrigin << "\nTotal Translated: " << totalTranslated;
}

void TranslationXML::SaveFile(QString pathFile, QDomDocument dom)
{
    // xuất ra file cùng folder với file nguồn

    QString path = pathFile.left(pathFile.length()-4)+"-translated.xml";
    qDebug() << path;
    QFile outFile( path);
    if( !outFile.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream stream( &outFile );
    stream << dom.toString();
    outFile.close();
}
