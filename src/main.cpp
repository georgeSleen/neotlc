#include "atlc.h"

#include <QApplication>
#include <QPushButton>

// int exampleWindow(int argc, char *argv[]) {
//     QApplication app (argc, argv);
//
//     QPushButton button ("Hello world");
//     button.show();
//     return app.exec();
// }

int main(int argc, char *argv[]) {
    double Zodd = 0.0;
    double Zeven = 0.0;
    double Zo = 0.0;

    calculate_Zodd_and_Zeven(&Zodd, &Zeven, &Zo, 10, 10, 10, 1);

    printf("Zodd: %f\n", Zodd);
    printf("Zeven: %f\n", Zeven);
    printf("Zo: %f\n", Zo);

    return 0;
}

// void test() {
//     atlc::Solver solver;
// }