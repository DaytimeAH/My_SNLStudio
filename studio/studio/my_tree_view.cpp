#include "my_tree_view.h"
#include "ui_my_tree_view.h"

my_tree_view::my_tree_view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::my_tree_view)
{
    ui->setupUi(this);
}

my_tree_view::~my_tree_view()
{
    delete ui;
}
