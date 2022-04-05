#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setValue(1.0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int x1 = ui->first_x_coord_edit->text().toInt();
    int y1 = ui->first_y_coord_edit->text().toInt();
    int x2 = ui->second_x_coord_edit->text().toInt();
    int y2 = ui->second_y_coord_edit->text().toInt();
    int x3 = ui->third_x_coord_edit->text().toInt();
    int y3 = ui->third_y_coord_edit->text().toInt();
    int rotate = ui->rotateSlider->value();
    double scale = ui->doubleSpinBox->value();
    second_window.init(x1, y1, x2, y2, x3, y3, rotate, scale);
    second_window.show();
}


void MainWindow::on_rotateSlider_sliderMoved(int position)
{
    second_window.changeRotation(position);
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    second_window.chageScale(arg1);
}

