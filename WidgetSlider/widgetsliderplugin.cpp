#include "widgetslider.h"
#include "widgetsliderplugin.h"

#include <QtPlugin>

WidgetSliderPlugin::WidgetSliderPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void WidgetSliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool WidgetSliderPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *WidgetSliderPlugin::createWidget(QWidget *parent)
{
    return new WidgetSlider(parent);
}

QString WidgetSliderPlugin::name() const
{
    return QLatin1String("WidgetSlider");
}

QString WidgetSliderPlugin::group() const
{
    return QLatin1String("");
}

QIcon WidgetSliderPlugin::icon() const
{
    return QIcon();
}

QString WidgetSliderPlugin::toolTip() const
{
    return QLatin1String("");
}

QString WidgetSliderPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool WidgetSliderPlugin::isContainer() const
{
    return false;
}

QString WidgetSliderPlugin::domXml() const
{
    return QLatin1String("<widget class=\"WidgetSlider\" name=\"widgetSlider\">\n</widget>\n");
}

QString WidgetSliderPlugin::includeFile() const
{
    return QLatin1String("widgetslider.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(widgetsliderplugin, WidgetSliderPlugin)
#endif // QT_VERSION < 0x050000
