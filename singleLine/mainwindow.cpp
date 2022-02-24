#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    second_window.initCoords(x1, y1, x2, y2);
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

