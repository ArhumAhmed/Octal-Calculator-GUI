#ifndef QTPROGRAMWIN_H
#define QTPROGRAMWIN_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class QtProgramWin;
}

class QtProgramWin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtProgramWin(QWidget *parent = 0);
    ~QtProgramWin();
    
private:
    Ui::QtProgramWin *ui;


	
private slots:
	void setLineEditText();
	void digits();
	void clear();
	void equals();
	void operation();
	int oct2dec(int a);
	int dec2oct(int a);
};




#endif // QTPROGRAMWIN_H
