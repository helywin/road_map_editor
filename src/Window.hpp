//
// Created by jiang on 2021/6/9.
//

#ifndef MAP_EDITOR_WINDOW_HPP
#define MAP_EDITOR_WINDOW_HPP

#include <QMainWindow>

class WindowPrivate;

class Window : public QMainWindow
{
Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override;
private:
    Q_DECLARE_PRIVATE(Window)
    Q_DISABLE_COPY(Window)
    QScopedPointer<WindowPrivate> d_ptr;
};

#endif //MAP_EDITOR_WINDOW_HPP
