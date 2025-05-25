#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QLineEdit>
#include <QWidget>
#include <QStringListModel>
using namespace std;
double calcVal,solution =0.0;
double entryNum,result,CalcMinus,lastNum,CalcMult;
double numberStore[11];
bool divTriggerE = false;
bool divTrigger = false;
bool multTrigger= false;
bool subTrigger= false;
bool addTrigger= false;
bool EqualTrigger= false;
bool point= true;
bool cValue= false;
QString numStringLast;
QString numStringSymbel;
QString numStringPoint;
QString numStringDisplay;
QString numString;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->txtNum->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0; i <10;++i){
        QString butName="Button"+ QString::number(i);
        numButtons[i]=MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));

        model  = new QStringListModel(this);
        ui->listView->setModel(model);
}
}


MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::NumPressed(){
    QPushButton *button= (QPushButton *)sender();
    QString butVal= button->text();
    QString DisplayVal =ui->txtNum->text();
    if((DisplayVal.toDouble()==0)||(DisplayVal.toDouble()==0.0)){
        ui->txtNum->setText(butVal);    }
    else{
        QString newVal=DisplayVal+butVal;
        double dblNewValue = newVal.toDouble();
        ui->txtNum->setText(QString::number(dblNewValue));

    }
}


void MainWindow::on_btnSubtract_clicked()
{   ChackValues();
    if(cValue==true){
    subTrigger= false;
    entryNum=ui->txtNum->text().toDouble();
    if (multTrigger == true){
        numberStore[0]=numberStore[0]*entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" - ";
        ui->lblOutput->setText(numStringLast);
        multTrigger= false;
    }else if (divTrigger == true){
        if (entryNum==0){
            divTriggerE= true;
        }else{
        numberStore[0]=numberStore[0]/entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" - ";
        ui->lblOutput->setText(numStringLast);}
        divTrigger= false;
    }else if (addTrigger == true){
        numberStore[0]=numberStore[0]+entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" - ";
        ui->lblOutput->setText(numStringLast);
        addTrigger= false;
    }else if (numberStore[0]==0){
    numberStore[0]=entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" - ";
        ui->lblOutput->setText(numStringLast);
    }else{
        numberStore[0]=numberStore[0]-entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" - ";
        ui->lblOutput->setText(numStringLast);
    }
    if (divTriggerE== true){
        ui->lblOutput->setText("ERROR");
        numString="";
        numStringLast="";
        numStringDisplay="";
        entryNum=0;
        numberStore[0]=0;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        divTriggerE= false;
        divTrigger=false;
    }
    ui->txtNum->setText("");
    subTrigger= true;
    point=true;

    }
}


void MainWindow::on_btnEquel_clicked()
{   ChackValues();
    if(cValue==true){
    lastNum=ui->txtNum->text().toDouble();
    QString numStringFinal;
    QString numStringFinaltxt;

    if (divTrigger == true){
        if (lastNum==0){
            divTriggerE= true;
            numStringFinaltxt="";
            numStringLast="ERROR";
            entryNum=0;
            numberStore[0]=0;

    }else{
        numberStore[0]=numberStore[0]/lastNum;}
    };
    if (addTrigger == true){
        numberStore[0]=numberStore[0]+lastNum;

    };
    if (subTrigger == true){
        numberStore[0]=numberStore[0]-lastNum;

    };
    if (multTrigger == true){
        numberStore[0]=numberStore[0]*lastNum;

    };

    ui->txtNum->setText("");
    if(divTriggerE==true){
        ui->lblOutput->setText(numStringLast);
        divTriggerE=false;
    }else{
    numStringFinal=QString::number(numberStore[0]);
    numStringFinaltxt=QString::number(lastNum);
    numStringLast=numStringLast+numStringFinaltxt;
    ui->lblOutput->setText(numStringLast);
    ui->txtNum->setText(numStringFinal);}

    if (!numStringFinal.isEmpty()) {
        addItem(numStringFinal);
    }
    numStringFinal="";
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;
    divTrigger = false;
    point=true;
    numberStore[0]=0;
    numStringLast="";
    }
}


void MainWindow::on_btnMultiplay_clicked()
{   ChackValues();
    if(cValue==true){
    multTrigger= false;
    entryNum=ui->txtNum->text().toDouble();

    if (subTrigger == true){
        numberStore[0]=numberStore[0]-entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" x ";
        ui->lblOutput->setText(numStringLast);
        subTrigger= false;
         }else if (divTrigger == true){
        if (entryNum==0){
            divTriggerE= true;
        }else{
        numberStore[0]=numberStore[0]/entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" x ";
        ui->lblOutput->setText(numStringLast);}
        divTrigger= false;
    }else if (addTrigger == true){
        numberStore[0]=numberStore[0]+entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" x ";
        ui->lblOutput->setText(numStringLast);
        addTrigger= false;
    }else if (numberStore[0]==0){
        numberStore[0]=entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" x ";
        ui->lblOutput->setText(numStringLast);
    }else{
         numberStore[0]=entryNum*numberStore[0];
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" x ";
        ui->lblOutput->setText(numStringLast);
    }

    if (divTriggerE== true){
        ui->lblOutput->setText("ERROR");
        numString="";
        numStringLast="";
        numStringDisplay="";
        entryNum=0;
        numberStore[0]=0;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        divTriggerE= false;
        divTrigger=false;
    }

    ui->txtNum->setText("");
    multTrigger= true;
    point=true;
    }
}


void MainWindow::on_btnDevide_clicked()
{   ChackValues();
    divTrigger= false;
    entryNum=ui->txtNum->text().toDouble();

    if (subTrigger == true){
        numberStore[0]=numberStore[0]-entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" / ";
        ui->lblOutput->setText(numStringLast);
        subTrigger= false;
    }else if (multTrigger == true){
        numberStore[0]=numberStore[0]*entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" / ";
        ui->lblOutput->setText(numStringLast);
        multTrigger= false;
    }else if (addTrigger == true){
        numberStore[0]=numberStore[0]+entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" / ";
        ui->lblOutput->setText(numStringLast);
        addTrigger= false;
    }else if (numberStore[0]==0){
         numberStore[0]=entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" / ";
        ui->lblOutput->setText(numStringLast);
    }else{
        if (entryNum==0){
            divTriggerE= true;

        }else{
        numberStore[0]=numberStore[0]/entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" / ";
        ui->lblOutput->setText(numStringLast);
        }}

    if (divTriggerE== true){
    ui->lblOutput->setText("ERROR");
    numString="";
    numStringLast="";
    numStringDisplay="";
    entryNum=0;
    numberStore[0]=0;
    numStringDisplay=QString::number(entryNum);
    numString=QString::number(numberStore[0]);
    divTriggerE= false;
    divTrigger=false;
    }
    ui->txtNum->setText("");
    divTrigger= true;
    point=true;

}





void MainWindow::on_btnAdd_clicked()
{
    ChackValues();
    if(cValue==true){
    addTrigger= false;
    entryNum=ui->txtNum->text().toDouble();
    if (subTrigger == true){
        numberStore[0]=numberStore[0]-entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" + ";
        ui->lblOutput->setText(numStringLast);
        subTrigger= false;
    }else if (multTrigger == true){
        numberStore[0]=numberStore[0]*entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" + ";
        ui->lblOutput->setText(numStringLast);
        multTrigger= false;
    }else if (divTrigger == true){
        if (entryNum==0){
            divTriggerE= true;
        }else{
        numberStore[0]=numberStore[0]/entryNum;
        numStringLast=QString::number(numberStore[0]);
        numStringLast=numStringLast+" + ";
        ui->lblOutput->setText(numStringLast);
        divTrigger= false;}
    }else if (numberStore[0]==0){
        numberStore[0]=entryNum;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" + ";
        ui->lblOutput->setText(numStringLast);
    }else{
        numberStore[0]=entryNum+numberStore[0];
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        numStringLast=numStringLast+numStringDisplay+" + ";
        ui->lblOutput->setText(numStringLast);
    }
    if (divTriggerE== true){
        ui->lblOutput->setText("ERROR");
        numString="";
        numStringLast="";
        numStringDisplay="";
        entryNum=0;
        numberStore[0]=0;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        divTriggerE= false;
        divTrigger=false;
    }
    ui->txtNum->setText("");
    addTrigger= true;
    point=true;
    }
}


void MainWindow::on_btnBreak_clicked()
{   ChackValues();
    if(cValue==true){
    if(point==true){
    entryNum=ui->txtNum->text().toDouble();
    numStringPoint=QString::number(entryNum);
    ui->txtNum->setText(numStringPoint+".");
    point=false;
    }
    }
}

void MainWindow::ChackValues(){

    QString CheckValesNum=ui->txtNum->text();
    static QRegularExpression regex("^-?\\d*\\.?\\d*$");
    QRegularExpressionMatch match = regex.match(CheckValesNum);
    if (match.hasMatch()) {
        qDebug() << "Valid number";
        cValue=true;
    } else {
        cValue=false;
        numString="";
        numStringLast="";
        numStringDisplay="";
        entryNum=0;
        numberStore[0]=0;
        numStringDisplay=QString::number(entryNum);
        numString=QString::number(numberStore[0]);
        qDebug() << "Invalid number";
        ui->lblOutput->setText("Invalid number");

    }
}

void MainWindow::on_btnC_clicked()
{    ui->txtNum->setText("");
    ui->lblOutput->setText("");
    numString="";
    numStringLast="";
    numStringDisplay="";
    entryNum=0;
    numberStore[0]=0;
    numStringDisplay=QString::number(entryNum);
    numString=QString::number(numberStore[0]);

}


void MainWindow::on_btnCE_clicked()
{
    ui->txtNum->setText("");
}

void MainWindow::addItem(const QString &newItem) {
    dataList.append(newItem);

    // Keep only the last 10 items
    if (dataList.size() > 10) {
        dataList.removeFirst();
    }

    model->setStringList(dataList);
}
