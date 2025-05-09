#include <QApplication>
#include <QMainWindow>

#include "stackup_definition.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow *mainWindow = new QMainWindow();
    QWidget *centralWidget = new QWidget(mainWindow);
    mainWindow->setCentralWidget(centralWidget);

    StackupDefinition *stackupDefinitionWidget = new StackupDefinition(centralWidget);

    mainWindow->setGeometry(0, 0, 800, 800);
    mainWindow->show();
    return app.exec();
}
