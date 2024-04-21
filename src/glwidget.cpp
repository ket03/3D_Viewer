#include "glwidget.h"

// некорректное соединение вершин - скорее всего дело в неправильном парсере facets

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

GLWidget::~GLWidget() {}

void GLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glRotatef(rotate_mouse_x, 1, 0, 0);
  glRotatef(rotate_mouse_y, 0, 1, 0);

  glOrtho(-data.max, data.max, -data.max, data.max, -data.max * 1.5, data.max * 1.5);

  glVertexPointer(3, GL_DOUBLE, 0, data.vertexes.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawElements(GL_LINES, data.facets.size(), GL_UNSIGNED_INT, data.facets.data());
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void GLWidget::mousePressEvent(QMouseEvent *mouse) { mouse_pos = mouse->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mouse) {
    rotate_mouse_x += (mouse->pos().y() - mouse_pos.y()) / 2;
    rotate_mouse_y += (mouse->pos().x() - mouse_pos.x()) / 2;
    mouse_pos = mouse->pos();
    update();
}
