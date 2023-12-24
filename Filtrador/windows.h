#ifndef WINDOWS_H
#define WINDOWS_H

#include <QWidget>

namespace Ui {
class windows;
}

class windows : public QWidget
{
    Q_OBJECT

public:
    explicit windows(QWidget *parent = nullptr);
    ~windows();

private:
    Ui::windows *ui;
};

#endif // WINDOWS_H
