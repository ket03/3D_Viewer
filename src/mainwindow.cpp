#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->open_obj, SIGNAL(clicked()), this, SLOT(OpenObj()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::OpenObj() {
  QString filename =
      QFileDialog::getOpenFileName(this, "Choose .obj file", "", tr("*.obj"));
  if (filename.size()) {
      Parser(filename.toStdString(), &ui->widget->data);
      qDebug() << ui->widget->data.min_x << "\n";
      qDebug() << ui->widget->data.max_x << "\n";
      qDebug() << ui->widget->data.min_y << "\n";
      qDebug() << ui->widget->data.max_y << "\n";
      qDebug() << ui->widget->data.min_z << "\n";
      qDebug() << ui->widget->data.max_z << "\n";
  }

}
