#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/kyle/SeniorDesign/src/ArduinoMotor"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/kyle/SeniorDesign/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/kyle/SeniorDesign/install/lib/python2.7/dist-packages:/home/kyle/SeniorDesign/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/kyle/SeniorDesign/build" \
    "/usr/bin/python" \
    "/home/kyle/SeniorDesign/src/ArduinoMotor/setup.py" \
    build --build-base "/home/kyle/SeniorDesign/build/ArduinoMotor" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/kyle/SeniorDesign/install" --install-scripts="/home/kyle/SeniorDesign/install/bin"
