#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "city.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto buildingManager = std::make_shared<BuildingManager>();
    auto resourceManager = std::make_shared<ResourceManager>();

    City city(buildingManager, resourceManager);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("city", &city);
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));

    engine.load(url);

    return app.exec();
}