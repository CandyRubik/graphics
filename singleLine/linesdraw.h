#ifndef LINESDRAW_H
#define LINESDRAW_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class LinesDraw;
}

class LinesDraw : public QWidget
{
    Q_OBJECT

public:
    explicit LinesDraw(QWidget *parent = nullptr);
    ~LinesDraw();
    void initCoords(int x1, int y1, int x2, int y2);
    void changeRotation(int rotation);
    void chageScale(double scale);
private:
    Ui::LinesDraw *ui;
    int x1;
    int y1;
    int x2;
    int y2;
    int rotation = 0;
    int center_rotation_x;
    int center_rotation_y;
    double scale = 1;

protected:
    void paintEvent(QPaintEvent* e) override;
};

#endif // LINESDRAW_H
