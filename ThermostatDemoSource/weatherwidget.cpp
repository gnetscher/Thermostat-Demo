#include "weatherwidget.h"

weatherwidget::weatherwidget(QWidget *parent) :
        QWidget(parent)
{
    // set initial clock time in case no web access
    clock = new QTime(16,18);

    // create default current settings
    currentTemp = new QLabel("86°");
    currentIcon = new QLabel();
    QPixmap *partlySunny = new QPixmap(":Images/weather-few-clouds.png");
    *partlySunny = partlySunny->scaled(72,72,Qt::KeepAspectRatio);
    currentIcon->setPixmap(*partlySunny);
    currentCity = new QLabel("Dallas,TX");

    currentTemp->setObjectName("currentTemp");
    currentCity->setObjectName("currentCity");

    // create default forecast day 1 values
    day1Label = new QLabel("Mon");
    day1Icon = new QLabel();
    QPixmap *partlyCloudy = new QPixmap(":Images/weather-sunny-very-few-clouds.png");
    *partlyCloudy = partlyCloudy->scaled(40,40,Qt::KeepAspectRatio);
    day1Icon->setPixmap(*partlyCloudy);
    day1Low = new QLabel("83°");
    day1High = new QLabel("89°");

    // create default forecast day 2 values
    day2Label = new QLabel("Tue");
    day2Icon = new QLabel();
    QPixmap *overcast = new QPixmap(":Images/weather-overcast.png");
    *overcast = overcast->scaled(40,40,Qt::KeepAspectRatio);
    day2Icon->setPixmap(*overcast);
    day2Low = new QLabel("81°");
    day2High = new QLabel("85°");

    // create default forecast day 3 values
    day3Label = new QLabel("Wed");
    day3Icon = new QLabel();
    QPixmap *tshower = new QPixmap(":Images/weather-thundershower.png");
    *tshower = tshower->scaled(40,40,Qt::KeepAspectRatio);
    day3Icon->setPixmap(*tshower);
    day3Low = new QLabel("79°");
    day3High = new QLabel("83°");

    // create current layout
    QVBoxLayout *currentVLayout = new QVBoxLayout;
    currentVLayout->addWidget(currentTemp);
    currentVLayout->addWidget(currentCity);

    // add icon to current layout
    QHBoxLayout *currentHLayout = new QHBoxLayout;
    currentHLayout->addWidget(currentIcon);
    currentHLayout->addLayout(currentVLayout);

    // create day 1 layout
    QHBoxLayout *day1Layout = new QHBoxLayout;
    day1Layout->addWidget(day1Label);
    day1Layout->addWidget(day1Icon);
    day1Layout->addWidget(day1Low);
    day1Layout->addWidget(day1High);

    // create day 2 layout
    QHBoxLayout *day2Layout = new QHBoxLayout;
    day2Layout->addWidget(day2Label);
    day2Layout->addWidget(day2Icon);
    day2Layout->addWidget(day2Low);
    day2Layout->addWidget(day2High);

    // create day 3 layout
    QHBoxLayout *day3Layout = new QHBoxLayout;
    day3Layout->addWidget(day3Label);
    day3Layout->addWidget(day3Icon);
    day3Layout->addWidget(day3Low);
    day3Layout->addWidget(day3High);

    // create final layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(currentHLayout);
    mainLayout->addLayout(day1Layout);
    mainLayout->addLayout(day2Layout);
    mainLayout->addLayout(day3Layout);

    // show layout
    setLayout(mainLayout);

}

void weatherwidget::setCurrentTemp(QString temperature)
{
    // provide text for current temp label
    currentTemp->setText(temperature + "°");

}

QString weatherwidget::getCurrentTemp()
{
    // return current temp string
    return currentTemp->text();

}

void weatherwidget::setCurrentIcon(QString icon)
{
    // set icon for current weather conditions
    if (icon == "partlysunny" || icon == "mostlycloudy" ) {
        if(clock->hour() < 5 || clock->hour() > 20) {
            QPixmap *partlyMoony = new QPixmap(":Images/weather-moony-few-clouds.png");
            *partlyMoony = partlyMoony->scaled(72, 72, Qt::KeepAspectRatio);
            currentIcon->setPixmap(*partlyMoony);
        } else {
            QPixmap *partlySunny = new QPixmap(":Images/weather-few-clouds.png");
            *partlySunny = partlySunny->scaled(72,72,Qt::KeepAspectRatio);
            currentIcon->setPixmap(*partlySunny);
        }
    }
    else if (icon == "fog") {
        QPixmap *fog = new QPixmap(":Images/weather-fog.png");
        *fog = fog->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*fog);
    }
    else if (icon == "hazy") {
        if(clock->hour() < 5 || clock->hour() > 20) {
            QPixmap *hazeyMoony = new QPixmap(":Images/weather-moony.png");
            *hazeyMoony = hazeyMoony->scaled(72, 72, Qt::KeepAspectRatio);
            currentIcon->setPixmap(*hazeyMoony);
        } else {
            QPixmap *haze = new QPixmap(":Images/weather-haze.png");
            *haze = haze->scaled(72,72,Qt::KeepAspectRatio);
            currentIcon->setPixmap(*haze);
        }
    }
    else if (icon == "cloudy") {
        QPixmap *cloudy = new QPixmap(":Images/weather-overcast.png");
        *cloudy = cloudy->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*cloudy);
    }
    else if (icon == "rain" || icon == "chancerain") {
        QPixmap *showers = new QPixmap(":Images/weather-showers.png");
        *showers = showers->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*showers);
    }
    else if (icon == "sleet" || icon == "chancesleet") {
        QPixmap *sleet = new QPixmap(":Images/weather-sleet.png");
        *sleet = sleet->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*sleet);
    }
    else if (icon == "flurries" || icon == "snow" ||
              icon == "chanceflurries" || icon == "chancesnow") {
        QPixmap *snow = new QPixmap(":Images/weather-snow.png");
        *snow = snow->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*snow);
    }
    else if (icon == "clear" || icon == "sunny") {
        if(clock->hour() < 5 || clock->hour() > 20) {
            QPixmap *moony = new QPixmap(":Images/weather-moony.png");
            *moony = moony->scaled(72, 72, Qt::KeepAspectRatio);
            currentIcon->setPixmap(*moony);
        } else {
            QPixmap *sunny = new QPixmap(":Images/weather-sunny.png");
            *sunny = sunny->scaled(72,72,Qt::KeepAspectRatio);
            currentIcon->setPixmap(*sunny);
        }
    }
    else if (icon == "mostlysunny" || icon == "partlycloudy" ||
             icon == "unknown") {
        if(clock->hour() < 5 || clock->hour() > 20) {
            QPixmap *partlyCloudy = new QPixmap(":Images/weather-moony-very-few-clouds");
            *partlyCloudy = partlyCloudy->scaled(72, 72, Qt::KeepAspectRatio);
            currentIcon->setPixmap(*partlyCloudy);
        } else {
            QPixmap *partlyCloudy = new QPixmap(":Images/weather-sunny-very-few-clouds.png");
            *partlyCloudy = partlyCloudy->scaled(72,72,Qt::KeepAspectRatio);
            currentIcon->setPixmap(*partlyCloudy);
        }
    }
    else if (icon == "tstorms" || icon == "chancetstorms") {
        QPixmap *thundershower = new QPixmap(":Images/weather-thundershower.png");
        *thundershower = thundershower->scaled(72,72,Qt::KeepAspectRatio);
        currentIcon->setPixmap(*thundershower);
    }


}

void weatherwidget::setDay1Icon(QString icon)
{
    // set icon for day 1 of forecast
    if (icon == "partlysunny" || icon == "mostlycloudy" ) {
        QPixmap *partlySunny = new QPixmap(":Images/weather-few-clouds.png");
        *partlySunny = partlySunny->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*partlySunny);
    }
    else if (icon == "fog") {
        QPixmap *fog = new QPixmap(":Images/weather-fog.png");
        *fog = fog->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*fog);
    }
    else if (icon == "hazy") {
        QPixmap *haze = new QPixmap(":Images/weather-haze.png");
        *haze = haze->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*haze);
    }
    else if (icon == "cloudy") {
        QPixmap *cloudy = new QPixmap(":Images/weather-overcast.png");
        *cloudy = cloudy->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*cloudy);
    }
    else if (icon == "rain" || icon == "chancerain") {
        QPixmap *showers = new QPixmap(":Images/weather-showers.png");
        *showers = showers->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*showers);
    }
    else if (icon == "sleet" || icon == "chancesleet") {
        QPixmap *sleet = new QPixmap(":Images/weather-sleet.png");
        *sleet = sleet->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*sleet);
    }
    else if (icon == "flurries" || icon == "snow" ||
              icon == "chanceflurries" || icon == "chancesnow") {
        QPixmap *snow = new QPixmap(":Images/weather-snow.png");
        *snow = snow->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*snow);
    }
    else if (icon == "clear" || icon == "sunny") {
        QPixmap *sunny = new QPixmap(":Images/weather-sunny.png");
        *sunny = sunny->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*sunny);
    }
    else if (icon == "mostlysunny" || icon == "partlycloudy" ||
             icon == "unknown") {
        QPixmap *partlyCloudy = new QPixmap(":Images/weather-sunny-very-few-clouds.png");
        *partlyCloudy = partlyCloudy->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*partlyCloudy);
    }
    else if (icon == "tstorms" || icon == "chancetstorms") {
        QPixmap *thundershower = new QPixmap(":Images/weather-thundershower.png");
        *thundershower = thundershower->scaled(40,40,Qt::KeepAspectRatio);
        day1Icon->setPixmap(*thundershower);
    }

}

void weatherwidget::setDay2Icon(QString icon)
{
    // set icon for day 2 of forecast
    if (icon == "partlysunny" || icon == "mostlycloudy" ) {
        QPixmap *partlySunny = new QPixmap(":Images/weather-few-clouds.png");
        *partlySunny = partlySunny->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*partlySunny);
    }
    else if (icon == "fog") {
        QPixmap *fog = new QPixmap(":Images/weather-fog.png");
        *fog = fog->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*fog);
    }
    else if (icon == "hazy") {
        QPixmap *haze = new QPixmap(":Images/weather-haze.png");
        *haze = haze->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*haze);
    }
    else if (icon == "cloudy") {
        QPixmap *cloudy = new QPixmap(":Images/weather-overcast.png");
        *cloudy = cloudy->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*cloudy);
    }
    else if (icon == "rain" || icon == "chancerain") {
        QPixmap *showers = new QPixmap(":Images/weather-showers.png");
        *showers = showers->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*showers);
    }
    else if (icon == "sleet" || icon == "chancesleet") {
        QPixmap *sleet = new QPixmap(":Images/weather-sleet.png");
        *sleet = sleet->scaled(72,72,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*sleet);
    }
    else if (icon == "flurries" || icon == "snow" ||
              icon == "chanceflurries" || icon == "chancesnow") {
        QPixmap *snow = new QPixmap(":Images/weather-snow.png");
        *snow = snow->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*snow);
    }
    else if (icon == "clear" || icon == "sunny") {
        QPixmap *sunny = new QPixmap(":Images/weather-sunny.png");
        *sunny = sunny->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*sunny);
    }
    else if (icon == "mostlysunny" || icon == "partlycloudy" ||
             icon == "unknown") {
        QPixmap *partlyCloudy = new QPixmap(":Images/weather-sunny-very-few-clouds.png");
        *partlyCloudy = partlyCloudy->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*partlyCloudy);
    }
    else if (icon == "tstorms" || icon == "chancetstorms") {
        QPixmap *thundershower = new QPixmap(":Images/weather-thundershower.png");
        *thundershower = thundershower->scaled(40,40,Qt::KeepAspectRatio);
        day2Icon->setPixmap(*thundershower);
    }


}

void weatherwidget::setDay3Icon(QString icon)
{
    // set icon for day 3 of forecast
    if (icon == "partlysunny" || icon == "mostlycloudy" ) {
        QPixmap *partlySunny = new QPixmap(":Images/weather-few-clouds.png");
        *partlySunny = partlySunny->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*partlySunny);
    }
    else if (icon == "fog") {
        QPixmap *fog = new QPixmap(":Images/weather-fog.png");
        *fog = fog->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*fog);
    }
    else if (icon == "hazy") {
        QPixmap *haze = new QPixmap(":Images/weather-haze.png");
        *haze = haze->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*haze);
    }
    else if (icon == "cloudy") {
        QPixmap *cloudy = new QPixmap(":Images/weather-overcast.png");
        *cloudy = cloudy->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*cloudy);
    }
    else if (icon == "rain" || icon == "chancerain") {
        QPixmap *showers = new QPixmap(":Images/weather-showers.png");
        *showers = showers->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*showers);
    }
    else if (icon == "sleet" || icon == "chancesleet") {
        QPixmap *sleet = new QPixmap(":Images/weather-sleet.png");
        *sleet = sleet->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*sleet);
    }
    else if (icon == "flurries" || icon == "snow" ||
              icon == "chanceflurries" || icon == "chancesnow") {
        QPixmap *snow = new QPixmap(":Images/weather-snow.png");
        *snow = snow->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*snow);
    }
    else if (icon == "clear" || icon == "sunny") {
        QPixmap *sunny = new QPixmap(":Images/weather-sunny.png");
        *sunny = sunny->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*sunny);
    }
    else if (icon == "mostlysunny" || icon == "partlycloudy" ||
             icon == "unknown") {
        QPixmap *partlyCloudy = new QPixmap(":Images/weather-sunny-very-few-clouds.png");
        *partlyCloudy = partlyCloudy->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*partlyCloudy);
    }
    else if (icon == "tstorms" || icon == "chancetstorms") {
        QPixmap *thundershower = new QPixmap(":Images/weather-thundershower.png");
        *thundershower = thundershower->scaled(40,40,Qt::KeepAspectRatio);
        day3Icon->setPixmap(*thundershower);
    }

}

void weatherwidget::setDay1(QString day)
{
    // set day 1 abbreviation (i.e. Wed)
    day1Label->setText(day);
}

void weatherwidget::setDay2(QString day)
{
    // set day 2 abbreviation
    day2Label->setText(day);
}

void weatherwidget::setDay3(QString day)
{
    // set day 3 abbreviation
    day3Label->setText(day);
}

void weatherwidget::setDay1High(QString high)
{
    // set day 1 high
    day1High->setText(high + "°");
}

void weatherwidget::setDay2High(QString high)
{
    // set day 2 high
    day2High->setText(high + "°");
}

void weatherwidget::setDay3High(QString high)
{
    // set day 3 high
    day3High->setText(high + "°");
}

void weatherwidget::setDay1Low(QString low)
{
    // set day 1 low
    day1Low->setText(low + "°");
}

void weatherwidget::setDay2Low(QString low)
{
    // set day 2 low
    day2Low->setText(low + "°");
}

void weatherwidget::setDay3Low(QString low)
{
    // set day 3 low
    day3Low->setText(low + "°");
}

QString weatherwidget::getDay1High()
{
    // return day 1 high
    return day1High->text();
}

QString weatherwidget::getDay2High()
{
    // return day 2 high
    return day2High->text();
}

QString weatherwidget::getDay3High()
{
    // return day 3 high
    return day3High->text();
}

QString weatherwidget::getDay1Low()
{
    // return day 1 low
    return day1Low->text();
}

QString weatherwidget::getDay2Low()
{
    // return day 2 low
    return day2Low->text();
}

QString weatherwidget::getDay3Low()
{
    // return day 3 low
    return day3Low->text();
}

void weatherwidget::setCity(QString city)
{
    // set city from string passed form setting screen
    // format city string correctly to display properly
    QStringList cityList = city.split(",");
    QString cityShort = cityList.at(0);
    if(cityShort.size() > 9) {
        cityShort.resize(9);
    }
    QString countryShort;
    countryShort.clear();
    if(cityList.at(1).size() < 3) {
        countryShort = cityList.at(1);
    } else if (cityList.at(1) == "Japan") {
        countryShort.append("JP");
    } else if (cityList.at(1) == "South Korea") {
        countryShort.append("KR");
    } else if (cityList.at(1) == "Mexico") {
        countryShort.append("MX");
    } else if (cityList.at(1) == "India") {
        countryShort.append("IN");
    } else if (cityList.at(1) == "Indonesia") {
        countryShort.append("ID");
    } else if (cityList.at(1) == "Brazil") {
        countryShort.append("BR");
    } else if (cityList.at(1) == "China") {
        countryShort.append("CN");
    } else if (cityList.at(1) == "Germany") {
        countryShort.append("DE");
    }else if (cityList.at(1) == "Russia") {
        countryShort.append("RU");
    } else if (cityList.at(1) == "Egypt") {
        countryShort.append("EG");
    } else if (cityList.at(1) == "South Africa") {
        countryShort.append("ZA");
    } else if (cityList.at(1) == "Taiwan") {
        countryShort.append("TW");
    }

    currentCity->setText(cityShort + ", " + countryShort);

}

void weatherwidget::setClock(QTime webClock)
{
    // set clock that is used to display night icons
    *clock = webClock;
}
