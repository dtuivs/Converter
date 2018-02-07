#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conversionengine.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_valueA_type_currentIndexChanged(int index);

    void on_valueA_textChanged(const QString &arg1);

    void on_valueB_type_currentIndexChanged(int index);

    void on_flip_button_clicked();

    void on_typeCategoryBox_currentIndexChanged(int index);

    void on_valueA_type_data_currentIndexChanged(int index);

    void on_valueB_type_data_currentIndexChanged(int index);

    void on_valueA_type_time_currentIndexChanged(int index);

    void on_valueB_type_time_currentIndexChanged(int index);

    void on_valueA_type_temp_currentIndexChanged(int index);

    void on_valueb_type_temp_currentIndexChanged(int index);

    void on_valueA_type_vol_currentIndexChanged(int index);

    void on_valueB_type_vol_currentIndexChanged(int index);

    void on_valueA_type_base_currentIndexChanged(int index);

    void on_valueB_type_base_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void updateValueB_text();
};

#endif // MAINWINDOW_H
