#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conversionengine.h"

#include <string>

conversionEngine convert;
int typeCategoryBox_currentIndex;
int valueA_currentIndex = 0;
int valueA_type_data_currentIndex = 1;
int valueA_type_time_currentIndex = 0;
int valueA_type_temp_currentIndex = 1;
int valueA_type_vol_currentIndex = 0;
int valueA_type_base_currentIndex = 0;
int valueB_currentIndex = 6;
int valueB_type_data_currentIndex = 0;
int valueB_type_time_currentIndex = 6;
int valueB_type_temp_currentIndex = 0;
int valueB_type_vol_currentIndex = 1;
int valueB_type_base_currentIndex = 1;
float input;
float output;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lengthTypes->setVisible(true);
    ui->timeTypes->setVisible(false);
    ui->tempTypes->setVisible(false);
    ui->volumeType->setVisible(false);
    ui->dataTypes_2->setVisible(false);
    ui->baseNumberTypes->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valueA_type_currentIndexChanged(int index)
{
   valueA_currentIndex = index;
   updateValueB_text();
}

void MainWindow::on_valueB_type_currentIndexChanged(int index)
{
    valueB_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueA_textChanged(const QString &arg1)
{
    input = arg1.toFloat();//Converts valueA (QString) to a float datatype

    updateValueB_text();
}

void MainWindow::updateValueB_text()
{
    if(typeCategoryBox_currentIndex == 0){
        if(valueA_currentIndex == 0){
            convert.fromCM(input);              //Everything Labeled "from..."(e.g. fromCM) will always convert to MM and set mm variable
        }else if(valueA_currentIndex == 1){
            convert.fromFt(input);
        }else if(valueA_currentIndex == 2){
            convert.fromIn(input);
        }else if(valueA_currentIndex == 3){
            convert.fromKm(input);
        }else if(valueA_currentIndex == 4){
            convert.fromM(input);
        }else if(valueA_currentIndex == 5){
            convert.fromMi(input);
        }else if(valueA_currentIndex == 6){
            convert.fromMM(input);
        }else if(valueA_currentIndex == 7){
            convert.fromYd(input);
        }

        if(valueB_currentIndex == 0){
            output = convert.getCm();
        }else if(valueB_currentIndex == 1){
            output = convert.getFt();
        }else if(valueB_currentIndex == 2){
            output = convert.getIn();
        }else if(valueB_currentIndex == 3){
            output = convert.getKm();
        }else if(valueB_currentIndex == 4){
            output = convert.getM();
        }else if(valueB_currentIndex == 5){
            output = convert.getMi();
        }else if(valueB_currentIndex == 6){
            output = convert.getMM();
        }else if(valueB_currentIndex == 7){
            output = convert.getYd();
        }
    } else if (typeCategoryBox_currentIndex == 1 ){
        if(valueA_type_time_currentIndex == 0){
            convert.fromDays(input);
        }else if(valueA_type_time_currentIndex == 1){
            convert.fromHours(input);
        }else if(valueA_type_time_currentIndex == 2){
            convert.fromuS(input);
        }else if(valueA_type_time_currentIndex == 3){
            convert.fromMS(input);
        }else if(valueA_type_time_currentIndex == 4){
            convert.fromMin(input);
        }else if(valueA_type_time_currentIndex == 5){
            convert.fromNS(input);
        }else if(valueA_type_time_currentIndex == 6){
            convert.fromSec(input);
        }else if(valueA_type_time_currentIndex == 7){
            convert.fromWeeks(input);
        }else if(valueA_type_time_currentIndex == 8){
            convert.fromYears(input);
        }

        if(valueB_type_time_currentIndex == 0){
            output = convert.getDays();
        } else if (valueB_type_time_currentIndex == 1){
            output = convert.getHours();
        } else if (valueB_type_time_currentIndex == 2){
            output = convert.getuS();
        } else if (valueB_type_time_currentIndex == 3){
            output = convert.getMS();
        } else if (valueB_type_time_currentIndex == 4){
            output = convert.getMin();
        } else if (valueB_type_time_currentIndex == 5){
            output = convert.getNS();
        } else if (valueB_type_time_currentIndex == 6){
            output = convert.getSec();
        } else if (valueB_type_time_currentIndex == 7){
            output = convert.getWeeks();
        } else if (valueB_type_time_currentIndex == 8){
            output = convert.getYears();
        }
    }else if (typeCategoryBox_currentIndex == 2){
        if(valueA_type_temp_currentIndex == 0){
            convert.fromC(input);
        } else if (valueA_type_temp_currentIndex == 1){
            convert.fromF(input);
        } else if (valueA_type_temp_currentIndex == 2){
            convert.fromK(input);
        }

        if (valueB_type_temp_currentIndex == 0){
            output = convert.getC();
        }else if (valueB_type_temp_currentIndex == 1){
            output = convert.getF();
        }else if (valueB_type_temp_currentIndex == 2){
            output = convert.getK();
        }
    }else if (typeCategoryBox_currentIndex == 3){
        if (valueA_type_vol_currentIndex == 0){
            convert.fromTSP(input);
        }else if (valueA_type_vol_currentIndex == 1){
            convert.fromTBSP(input);
        }else if (valueA_type_vol_currentIndex == 2){
            convert.fromGAL(input);
        }else if (valueA_type_vol_currentIndex == 3){
            convert.fromOZ(input);
        }else if (valueA_type_vol_currentIndex == 4){
            convert.fromCUPS(input);
        }

        if (valueB_type_vol_currentIndex == 0){
            output = convert.getTSP();
        }else if (valueB_type_vol_currentIndex == 1){
            output = convert.getTBSP();
        }else if (valueB_type_vol_currentIndex == 2){
            output = convert.getGAL();
        }else if (valueB_type_vol_currentIndex == 3){
            output = convert.getOZ();
        }else if (valueB_type_vol_currentIndex == 4){
            output = convert.getCUPS();
        }
    }else if (typeCategoryBox_currentIndex == 4){
        if(valueA_type_data_currentIndex == 0){
            convert.frombits(input);
        }else if (valueA_type_data_currentIndex == 1){
            convert.frombytes(input);
        }else if (valueA_type_data_currentIndex == 2){
            convert.fromkb(input);
        }else if (valueA_type_data_currentIndex ==3){
            convert.fromkB(input);
        }else if (valueA_type_data_currentIndex == 4){
            convert.fromMb(input);
        }else if (valueA_type_data_currentIndex == 5){
            convert.fromMB(input);
        }else if (valueA_type_data_currentIndex == 6){
            convert.fromGb(input);
        }else if (valueA_type_data_currentIndex == 7){
            convert.fromGB(input);
        }else if (valueA_type_data_currentIndex == 8){
            convert.fromTb(input);
        }else if (valueA_type_data_currentIndex == 9){
            convert.fromTB(input);
        }

        if(valueB_type_data_currentIndex == 0){
            output = convert.getBits();
        }else if (valueB_type_data_currentIndex == 1){
            output = convert.getBytes();
        }else if (valueB_type_data_currentIndex == 2){
            output = convert.getkb();
        }else if (valueB_type_data_currentIndex == 3){
            output = convert.getkB();
        }else if (valueB_type_data_currentIndex == 4){
            output = convert.getMb();
        }else if (valueB_type_data_currentIndex == 5){
            output = convert.getMB();
        }else if (valueB_type_data_currentIndex == 6){
            output = convert.getGb();
        }else if (valueB_type_data_currentIndex == 7){
            output = convert.getGB();
        }else if (valueB_type_data_currentIndex == 8){
            output = convert.getTb();
        }else if (valueB_type_data_currentIndex == 9){
            output = convert.getTB();
        }


    }else if (typeCategoryBox_currentIndex == 5){
        if(valueA_type_base_currentIndex == 0){
            convert.fromDecimal(input);
        }else if (valueA_type_base_currentIndex == 1){
            convert.fromBin(input);
        }else if (valueA_type_base_currentIndex == 2){
            convert.fromHex(std::to_string(input));
        }else if (valueA_type_base_currentIndex == 3){
            convert.fromOctal(input);
        }

        if(valueB_type_base_currentIndex == 0){
            output = convert.getDec();
        }else if (valueB_type_base_currentIndex == 1){
            output = convert.getBin();
        }else if (valueB_type_base_currentIndex == 2){
            //output = std::stoi(convert.getHex());
        }else if (valueB_type_base_currentIndex == 3){
            output = convert.getOctal();
        }
    }


    QString newText = QString::number(output);//converts back to QString
    ui->valueB->setText(newText);//sets valueB text
}

void MainWindow::on_flip_button_clicked()
{
    int hold;

    if(typeCategoryBox_currentIndex == 0){
        hold = valueA_currentIndex;
        ui->valueA_type->setCurrentIndex(valueB_currentIndex);
        ui->valueB_type->setCurrentIndex(hold);
    } else if( typeCategoryBox_currentIndex == 1){
        hold = valueA_type_time_currentIndex;
        ui->valueA_type_time->setCurrentIndex(valueB_type_time_currentIndex);
        ui->valueB_type_time->setCurrentIndex(hold);
    } else if( typeCategoryBox_currentIndex == 2){
        hold = valueA_type_temp_currentIndex;
        ui->valueA_type_temp->setCurrentIndex(valueB_type_temp_currentIndex);
        ui->valueb_type_temp->setCurrentIndex(hold);
    } else if( typeCategoryBox_currentIndex == 3){
        hold = valueA_type_vol_currentIndex;
        ui->valueA_type_vol->setCurrentIndex(valueB_type_vol_currentIndex);
        ui->valueB_type_vol->setCurrentIndex(hold);
    }else if ( typeCategoryBox_currentIndex == 4){
        hold = valueA_type_data_currentIndex;
        ui->valueA_type_data->setCurrentIndex(valueB_type_data_currentIndex);
        ui->valueB_type_data->setCurrentIndex(hold);
    }else if ( typeCategoryBox_currentIndex == 5){
        hold = valueA_type_base_currentIndex;
        ui->valueA_type_base->setCurrentIndex(valueB_type_base_currentIndex);
        ui->valueB_type_base->setCurrentIndex(hold);
    }
}



void MainWindow::on_typeCategoryBox_currentIndexChanged(int index)
{
    typeCategoryBox_currentIndex = index;
    if(index == 0){
        ui->lengthTypes->setVisible(true);
        ui->timeTypes->setVisible(false);
        ui->tempTypes->setVisible(false);
        ui->volumeType->setVisible(false);
        ui->dataTypes_2->setVisible(false);
        ui->baseNumberTypes->setVisible(false);
    }else if(index == 1){
        ui->lengthTypes->setVisible(false);
        ui->timeTypes->setVisible(true);
        ui->tempTypes->setVisible(false);
        ui->volumeType->setVisible(false);
        ui->dataTypes_2->setVisible(false);
        ui->baseNumberTypes->setVisible(false);
    }else if(index == 2){
        ui->lengthTypes->setVisible(false);
        ui->timeTypes->setVisible(false);
        ui->tempTypes->setVisible(true);
        ui->volumeType->setVisible(false);
        ui->dataTypes_2->setVisible(false);
        ui->baseNumberTypes->setVisible(false);
    }else if (index == 3){
        ui->lengthTypes->setVisible(false);
        ui->timeTypes->setVisible(false);
        ui->tempTypes->setVisible(false);
        ui->volumeType->setVisible(true);
        ui->dataTypes_2->setVisible(false);
        ui->baseNumberTypes->setVisible(false);
    }else if (index == 4){
        ui->lengthTypes->setVisible(false);
        ui->timeTypes->setVisible(false);
        ui->tempTypes->setVisible(false);
        ui->volumeType->setVisible(false);
        ui->dataTypes_2->setVisible(true);
        ui->baseNumberTypes->setVisible(false);
    }else if (index == 5){
        ui->lengthTypes->setVisible(false);
        ui->timeTypes->setVisible(false);
        ui->tempTypes->setVisible(false);
        ui->volumeType->setVisible(false);
        ui->dataTypes_2->setVisible(false);
        ui->baseNumberTypes->setVisible(true);
    }
    updateValueB_text();
}



void MainWindow::on_valueA_type_data_currentIndexChanged(int index)
{
    valueA_type_data_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueB_type_data_currentIndexChanged(int index)
{
    valueB_type_data_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueA_type_time_currentIndexChanged(int index)
{
    valueA_type_time_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueB_type_time_currentIndexChanged(int index)
{
    valueB_type_time_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueA_type_temp_currentIndexChanged(int index)
{
    valueA_type_temp_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueb_type_temp_currentIndexChanged(int index)
{
    valueB_type_temp_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueA_type_vol_currentIndexChanged(int index)
{
    valueA_type_vol_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueB_type_vol_currentIndexChanged(int index)
{
    valueB_type_vol_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueA_type_base_currentIndexChanged(int index)
{
    valueA_type_base_currentIndex = index;
    updateValueB_text();
}

void MainWindow::on_valueB_type_base_currentIndexChanged(int index)
{
    valueB_type_base_currentIndex = index;
    updateValueB_text();
}
