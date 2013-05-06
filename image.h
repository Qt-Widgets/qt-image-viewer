#ifndef IMAGE_H
#define IMAGE_H
#include <QtGui>
#include <QGraphicsView>
#include <QMenu>
#include <QAction>
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsPixmapItem>
#include <QScrollBar>

namespace Ui {
class Properties;
}


class image : public QGraphicsView
{
    Q_OBJECT

public:
    image();
    //program blocks//
    void loadimage(QString path);
    void addToBuffer(QPixmap * pixmap);
    void resetZoom();
    void loadimagelist(QStringList list);

    //returned//
    bool isZoomed();
    int size();
    int currentImage();
    QString currentImageName();
    QPixmap currentPixmap();
    bool isReady();
    QStringList getImageList();


public slots:
    void reloadImage();
    void setOriginalSize();
    void setImage(int indx);
    void insertImage(QString filename,int pos);
    void zoomDec();
    void zoomInc();
    void rotateLeft();
    void rotateRight();
    void saveimage(QString filename);
    void setSaved();
    void setEdited();
    bool isSaved();
    void deleteCurrentItem();
    void prevBuffer();
    void nextBuffer();
    void setAsWallpaper();
    ///Mouse///
    void setMouseZoom(bool);
    void setMouseFullscreen(bool);
    bool getMouseZoom();
    bool getMouseFullscreen();

signals:
    void currentImageWasChanged(int indx);
    void itsPossibleToRedo(bool);
    void itsPossibleToUndo(bool);
    void itsSaved(bool);
    void needFullscreen();
    void needSlideshow();

private:
    QDesktopWidget desk;
    QPixmap * imagePixmap;
    QGraphicsScene *imageScene;
    QGraphicsPixmapItem *imagePixmapItem;
    bool mouseGrabbed;
    bool isPixmap;
    double zoom;
    bool zoomMax;
    bool zoomMin;

    ////image list////
    QString imagename;
    QStringList imagelist;
    int imagelist_indx;

    ////Context menu////
    void createContextMenu();
    QAction * actionProperties;
    QAction * actionDelete;
    QAction * actionFullscreen;
    QAction * actionWallpaper;
    QAction * actionSlideshow;
    QAction * actionZoomIn;
    QAction * actionZoomOut;
    QAction * actionZoomOriginal;
    QAction * actionZoomWindow;
    QDialog * propertiesWidget;
    Ui::Properties *ui_prop;

    ////Editing////
    bool wasEdited;

    ////Buffers////
    QList<QPixmap> buffer;
    int buffer_indx;

    ///Zoom grabbed move///
    QRectF lastMousePos;
    QRectF sumMousePos;
    bool isMouseGrabbed;

    ///Mouse///
    bool mouseZoom;
    bool mouseFullscreen;

private slots:
    void viewProperties();
    void horizontalSliderMoverd(int);
    void verticalSliderMoverd(int);

protected:
    //zoom grabbed move
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //Zoom in-out
    void wheelEvent( QWheelEvent * event );
    //fullscreen
    void mouseDoubleClickEvent(QMouseEvent *event);
    //changepictures (keyboard event)
    bool eventFilter(QObject *obj, QEvent *event);
    //context menu
    void contextMenuEvent(QContextMenuEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // IMAGE_H
