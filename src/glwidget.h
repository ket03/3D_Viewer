#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include "parser.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
public:
  GLWidget(QWidget *parent = 0);
  ~GLWidget();

  Data data;

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

private:
  void mousePressEvent(QMouseEvent *mouse);
  void mouseMoveEvent(QMouseEvent *mouse);
  float rotate_mouse_x = 0.0f;
  float rotate_mouse_y = 0.0f;
  QPoint mouse_pos;


};

#endif // GLWIDGET_H
