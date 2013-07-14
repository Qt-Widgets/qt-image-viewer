#ifndef PREVIEWLIST_H
#define PREVIEWLIST_H

#include <QObject>
#include <QHBoxLayout>
#include <QListWidget>
#include <QDebug>
#include <QImage>

class previewList : public QObject
{
    Q_OBJECT
public:
    previewList(QListWidget * previewListWidget);
    void loadList(QStringList list);
signals:
    void finished();
public slots:
    void run();
private:
    QStringList lst;
    QHBoxLayout layout;
    QListWidget * listWidget;
};

#endif // PREVIEWLIST_H