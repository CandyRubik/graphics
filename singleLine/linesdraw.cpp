#include "linesdraw.h"
#include "ui_linesdraw.h"

LinesDraw::LinesDraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LinesDraw)
{
    ui->setupUi(this);
}

LinesDraw::~LinesDraw()
{
    delete ui;
}

void LinesDraw::initCoords(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    center_rotation_x = (x2-x1)/2;
    center_rotation_y = (y2-y1)/2;
}

void LinesDraw::changeRotation(int rotation)
{
    this->rotation = rotation;
    repaint();
}

void LinesDraw::chageScale(double scale)
{
    if(scale != this->scale) {
        center_rotation_x /= this->scale;
        center_rotation_y /= this->scale;
        center_rotation_x *= scale;
        center_rotation_y *= scale;

        this->scale = scale;
        repaint();
    }
}

void LinesDraw::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.translate(center_rotation_x, center_rotation_y);
    painter.rotate(rotation);
    painter.translate(-center_rotation_x, -center_rotation_y);
    painter.scale(scale, scale);
    painter.drawLine(x1, y1, x2, y2);
}
