#pragma once
#include <QMainWindow>
#include "ui_MainWindow.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr) : QMainWindow(parent), ui(new Ui::MainWindow) { 
        ui->setupUi(this);

        ui->groupBox->setTitle("Радио кнопки");

        // Радио кнопки
        ui->setting_1->setChecked(true);
        ui->setting_1->setText("Настройка 1");
        ui->setting_2->setText("Настройка 2");

        // Кнопка переделанная в toggle
        ui->pb_button->setText("Нажми");
        ui->pb_button->setCheckable(true);

        // Установка минимального и максимального значения у прогрессбара
        ui->pb_bar->setMinimum(0);
        ui->pb_bar->setMaximum(10);

        // Заполнить выпадающий список
        for (int i=1; i <= 5; i++) 
            ui->cb_dropDownList->addItem("Элемент " + QString::number(i));
    }
	~MainWindow() { delete ui; }

private slots:
    void on_pb_button_toggled(bool) {
        if (ui->pb_bar->value() == 10)
            ui->pb_bar->setValue(0);
        else 
            ui->pb_bar->setValue(ui->pb_bar->value() + 1);
    }

private:
	Ui::MainWindow* ui;
};
