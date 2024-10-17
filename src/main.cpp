#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "city.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto buildingManager = std::make_shared<BuildingManager>();
    auto resourceManager = std::make_shared<ResourceManager>();

    City city(buildingManager, resourceManager);

    engine.rootContext()->setContextProperty("city", &city);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
