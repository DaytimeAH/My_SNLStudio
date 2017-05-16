#ifndef MY_TREE_VIEW_H
#define MY_TREE_VIEW_H

#include <QMainWindow>

namespace Ui {
class my_tree_view;
}

class my_tree_view : public QMainWindow
{
    Q_OBJECT

public:
    explicit my_tree_view(QWidget *parent = 0);
    ~my_tree_view();

private:
    Ui::my_tree_view *ui;
};

#endif // MY_TREE_VIEW_H
