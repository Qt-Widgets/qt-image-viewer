#ifndef EDITFORMRESIZE_H
#define EDITFORMRESIZE_H

#include <QWidget>
#include <QGraphicsView>


namespace Ui {
class editformResize;
}

class editformResize : public QWidget
{
    Q_OBJECT
    
public:
    explicit editformResize();

    void loadImage(QPixmap pixmap_old);
    QPixmap *getpixmap();

    ~editformResize();
    
private slots:
    void resizeprewiew();
    void on_widthSpinBox_valueChanged(int arg1);
    void on_heightSpinBox_valueChanged(int arg1);
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();
    void on_widthSpinBox_editingFinished();
    void on_heightSpinBox_editingFinished();
    void on_aspectratioCheckBox_clicked();

signals:
    void editFinished(bool);

private:
    QGraphicsScene* scene;
    QPixmap* pixmap;
    double zoom;
    int im_width,im_height;
    double originalAspectratio;
    Ui::editformResize *ui;
};

#endif // EDITFORMRESIZE_H