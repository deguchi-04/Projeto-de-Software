#ifndef NEWMOVIEADD_H
#define NEWMOVIEADD_H

#include <QDialog>

namespace Ui {
class NewMovieAdd;
}

class NewMovieAdd : public QDialog
{
    Q_OBJECT

public:
    explicit NewMovieAdd(QWidget *parent = nullptr);
    ~NewMovieAdd();

private slots:
    void on_submit_clicked();

    void on_Back_clicked();

private:
    Ui::NewMovieAdd *ui;
};

#endif // NEWMOVIEADD_H
