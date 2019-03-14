#include "qtprogramwin.h"
#include "ui_qtprogramwin.h"

int ans = 0;  //Answer (initially 0) will be modified by operators
int firstNumber;
int secondNumber;
int opSel; //Will store the operation

QtProgramWin::QtProgramWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtProgramWin)
{
    ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(setLineEditText())); //Legacy function
	connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(digits()));  //These are the numbers
	connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(digits()));
	connect(ui->pushButtonEquals, SIGNAL(clicked()), this, SLOT(equals())); //Triggers equal function
	connect(ui->pushButtonClear, SIGNAL(clicked()), this, SLOT(clear())); //Triggers clear function
	connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(operation())); //Triggers operation function
	connect(ui->pushButtonSub, SIGNAL(clicked()), this, SLOT(operation()));
	connect(ui->pushButtonMult, SIGNAL(clicked()), this, SLOT(operation()));
	connect(ui->pushButtonDiv, SIGNAL(clicked()), this, SLOT(operation()));
	// Dont need this since I can assign keyboard shortcuts to buttons I made already focused on lineedit //ui->lineEdit->setFocus(); //Sets focus to lineedit by default so user can start typing without having to click or tab
}

QtProgramWin::~QtProgramWin()
{
    delete ui;
}


void QtProgramWin::setLineEditText()
{
	ui->lineEdit->setText(QString("Arhum's Calculator B-)") );
}

void QtProgramWin::digits()
{
	QPushButton *button = (QPushButton*)sender();
	int number;
	QString finalNum;
	//if (ui->lineEdit->text() == "+" || "-" || "*" || "/") //So it won't concat operators
	//{
		//ui->lineEdit->setText("");
	//}

	number = (ui->lineEdit->text() + button->text()).toInt(); //concat numbers (as string) then convert back to int
	
	finalNum = QString::number(number);
	ui->lineEdit->setText(QString(finalNum));
}

void QtProgramWin::equals()
{
	secondNumber = ui->lineEdit->text().toInt();
	QString answer;
	if (opSel == 1) //Addition
	{
		ans = oct2dec(firstNumber) + oct2dec(secondNumber);
		ans = dec2oct(ans);
		answer = QString::number(ans);
		ui->lineEdit->setText(answer);
	}

	else if (opSel == 2) //Subtraction
	{
		ans = oct2dec(firstNumber) - oct2dec(secondNumber);
		ans = dec2oct(ans);
		answer = QString::number(ans);
		ui->lineEdit->setText(answer);
	}
	else if (opSel == 3) //Multiplication
	{
		ans = oct2dec(firstNumber) * oct2dec(secondNumber);
		ans = dec2oct(ans);
		answer = QString::number(ans);
		ui->lineEdit->setText(answer);
	}

	else if (opSel == 4) //Division
	{
		if (secondNumber == 0)
		{
			ui->lineEdit->setText("Cannot Divide by 0!");
			return;
		}
		ans = oct2dec(firstNumber) / oct2dec(secondNumber);
		ans = dec2oct(ans);
		answer = QString::number(ans);
		ui->lineEdit->setText(answer);
	}
}

int QtProgramWin::oct2dec(int a)
{
	int deci = 0;
	int x = 0;
	int rem;
	while (a != 0)
	{
		rem = a % 10;
		a /= 10;
		deci += rem * pow(8, x);
		++x;
	}
	return deci;
}

int QtProgramWin::dec2oct(int a)
{
	int rem;
	int x = 1;
	int oct = 0;
	while (a != 0)
		{
			rem = a % 8;
			a /= 8;
			oct += rem * x;
			x *= 10;
		}
		return oct;
}

void QtProgramWin::clear()
{
	ui->lineEdit->setText("");//Clears Display
	firstNumber = 0; 
	secondNumber = 0;
	ans = 0;
}

void QtProgramWin::operation()
{
	QPushButton *button = (QPushButton*)sender(); //Store which operation was clicked
	
	firstNumber = ui->lineEdit->text().toInt();
	ui->lineEdit->setText(""); //Clears the first number
	if (button->text() == "+")
	{
		opSel = 1; //Stores the operation so can be performed in equals function after second number is given
		ui->lineEdit->setText("+");
	}

	else if (button->text() == "-")
	{
		opSel = 2;
		//ui->lineEdit->setText("-");
	}

	else if (button->text() == "*")
	{
		opSel = 3;
		//ui->lineEdit->setText("*");
	}

	else if (button->text() == "/")  //Should I just make it else? slot function only gets signals from operator buttons so it has to be one of the four buttons anyways right?
	{
		opSel = 4;
		//ui->lineEdit->setText("/");
	}

}




