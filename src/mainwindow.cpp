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
      ui->lines_info->setText("");
      ui->vertices_info->setText("vertexes: " + QString::number(ui->widget->data.vertexes.size()));
      ui->lines_info->setText("lines: " + QString::number(ui->widget->data.facets.size()));
  }

}
