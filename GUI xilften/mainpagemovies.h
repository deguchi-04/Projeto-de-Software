#ifndef MAINPAGEMOVIES_H
#define MAINPAGEMOVIES_H

#include <QDialog>

namespace Ui {
class mainpagemovies;
}

class mainpagemovies : public QDialog
{
    Q_OBJECT

public:
    explicit mainpagemovies(QWidget *parent = nullptr);
    ~mainpagemovies();

private slots:
    void onTextChanged(const QString &a_strString);
    void on_ProfileButton_3_clicked();

    void on_TopMovies_clicked();

    void on_Catalog_clicked();

    void on_GoButton_3_clicked();

    void on_LogOut_clicked();

    void on_evalbutton_3_clicked();

    void on_leaveC_2_clicked();

    void on_seeAllC_clicked();

    void on_delete_4_clicked();

    void on_back_3_clicked();

    void on_delete_5_clicked();

    void on_back_4_clicked();

    void on_movieTitle_clicked();

    void on_movieTitle_2_clicked();

    void on_movieTitle_3_clicked();

    void on_movieTitle_4_clicked();

    void on_movieTitle_5_clicked();

    void on_movieTitle_6_clicked();

    void on_movieTitle_7_clicked();

    void on_movieTitle_8_clicked();

    void on_movieTitle_9_clicked();

    void on_movieTitle_10_clicked();

private:
    Ui::mainpagemovies *ui;
};

#endif // MAINPAGEMOVIES_H
