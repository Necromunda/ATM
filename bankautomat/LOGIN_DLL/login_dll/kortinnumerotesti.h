#ifndef KORTINNUMEROTESTI_H
#define KORTINNUMEROTESTI_H

#include <QDialog>

namespace Ui {
class Kortinnumerotesti;
}

class Kortinnumerotesti : public QDialog
{
    Q_OBJECT

public:
    explicit Kortinnumerotesti(QWidget *parent = nullptr);
    ~Kortinnumerotesti();

private:
    Ui::Kortinnumerotesti *ui;
};

#endif // KORTINNUMEROTESTI_H
