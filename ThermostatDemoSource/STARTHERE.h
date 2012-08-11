/*

  Code written using Qt 4.8 by George Netscher for Texas Instruments
  Last modified: Aug 10, 2012


 * Author: George Netscher <gnetscher@gmail.com>
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *


  Summary:
    This software provides a demo thermostat application.  All values are
    initialized to hard-coded values first and then updated from the web
    if internet options have been enabled.  Each class defines a different
    part of the user interface.  They are defined as follows:
        - Keyboard: provides a touch screen soft keyboard
            This keyboard was looped in from another application and was
            not written by me personally.  It is the only part of the application
            that uses a .ui file created using Qt Designer.
        - awayscreen: provides the screen that defines the thermostat's function
            when in AWAY MODE
        - mainwindow: this base class provides the main screen. It acts as a
            container for the themostatwidget, weatherwidget, and optionswidget
        - openingscreen: provides the initial setup dialog.  It asks for internet
            and proxy settings.  If a proxy is required, control is passed to
            the proxysetupdialog class.  If not, control is passed straight to
            the mainwindow
        - proxysetupdialog: this class allows the user to enter proxy information
            if necessary
        - optionswidget: this class provides a container for the 3 options buttons
            allowing the user to pass control to the awayscreen, schedulescreen,
            or settingscreen
        - schedulescreen: this is by far the most complex class. It is the only
            one which implements a graphics view in the place of traditional
            widgets.  It allows the user to set a weekly schedule
        - settingscreen: this class allows the user to pick between a set of
            predefined cities across the world and alternate between Celsius
            and Fahrenheit
        - schedulepoint: this class defines each of the 28 individual time points
            within the schedulescreen.  It is the only class derived from a
            graphics item rather than a widget
        - thermostatwidget: this class provides the widget that allows the user
            to change the setpoint temperature and monitors the current indoor
            temperature
        - weatherwidget: this class provides the current outdoor temperature and
            weather conditions along with a 3 day forecast
        - webdata: this class is the only one that does not provide a ui element.
            This class is reponsible for providing the underlying web functionality
  More information can be found within each class definition.

  Style:
    Many of the style options were implemented using a style sheet.  The style sheet
    allows you to define the look and feel of the application.  These parameters
    are contained within thermostatdemo.qss

  Possible contributions:
    If you would like to contribute to this code, there are several areas that need
    improvement.
        - add error handling: at the current time, the program implements no error
            handling.  I simply ran out of time to add it.  If the user enters any
            invalid parameter (i.e. an incorrect proxy setting), the program will
            simply crash.  To the user, this appears as an unexplained program exit.
            At the very least, some helpful dialog should be provided explaining
            the nature of the crash
        - provide better size control: this demo was specifically developed for the
            AM335X Starter Kit which uses a 4.3" resistive touch screen. When
            porting the demo to other screen sizes, the widgets will maintain their
            size leaving lots of open space on larger screens.  A mechanism should
            be provided that allows the widgets to grow and shrink with the screen
            size
        - add 24 hour time option to settingscreen: just as the user can alternate
            between Celsius and Fahrenheit, he or she should be able to change to a
            24 hour clock.  This is more difficult than it sounds.  Before trying to
            do this, study the way the C/F shift is implemented.  It requires
            communication between several classes and will also require exploring
            the QTime API
        - have temperature buttons change colors: an easy way to get introduced to
            using Qt graphics would be to provide a function within schedulepoint
            that causes the points to get more red as the set temperature is
            increased and more blue as it is decreased
        - add functionality to buttons at bottom of mainwindow (i.e. have energy
            Button pop up a screen with a dial that shows current consumption)

