#ifndef READMEDIALOG_H
#define READMEDIALOG_H

#include <QDialog>

namespace Ui {
class ReadmeDialog;
}

class ReadmeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReadmeDialog(QWidget *parent = nullptr);
    ~ReadmeDialog();

private:
    Ui::ReadmeDialog *ui;
};

#endif // READMEDIALOG_H
