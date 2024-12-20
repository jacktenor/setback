#include "readmedialog.h"
#include "ui_readmedialog.h"

ReadmeDialog::ReadmeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReadmeDialog)
{
    ui->setupUi(this);
}

ReadmeDialog::~ReadmeDialog()
{
    delete ui;
}
