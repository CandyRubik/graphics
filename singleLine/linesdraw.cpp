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

void LinesDraw::init(int x1, int y1, int x2, int y2, int x3, int y3, int rotate, double scale)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    this->scale = scale;
    this->rotation = rotate;
    center_rotation_x = (x1+x2+x3)/3;
    center_rotation_y = (y1+y2+y3)/3;
}

void LinesDraw::changeRotation(int rotation)
{
    this->rotation = rotation;
    repaint();
}

void LinesDraw::chageScale(double scale)
{
    if(scale != this->scale) {
        x1 /= this->scale;
        x2 /= this->scale;
        x3 /= this->scale;

        y1 /= this->scale;
        y2 /= this->scale;
        y3 /= this->scale;

        x1 *= scale;
        x2 *= scale;
        x3 *= scale;

        y1 *= scale;
        y2 *= scale;
        y3 *= scale;

        this->scale = scale;

        center_rotation_x = (x1+x2+x3)/3;
        center_rotation_y = (y1+y2+y3)/3;

        repaint();
    }
}

void LinesDraw::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.setBrush(Qt::red);
    painter.translate(center_rotation_x, center_rotation_y);
    painter.rotate(rotation);
    painter.translate(-center_rotation_x, -center_rotation_y);
    const QPointF points[3] = {
        QPointF(x1, y1),
        QPointF(x2, y2),
        QPointF(x3, y3)
    };
    painter.drawPolygon(points, 3);
}
