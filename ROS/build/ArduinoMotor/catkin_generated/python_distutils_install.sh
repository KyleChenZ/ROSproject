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

echo_and_run cd "/home/nvidia/SeniorDesign/src/ArduinoMotor"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/nvidia/SeniorDesign/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/nvidia/SeniorDesign/install/lib/python2.7/dist-packages:/home/nvidia/SeniorDesign/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/nvidia/SeniorDesign/build" \
    "/usr/bin/python" \
    "/home/nvidia/SeniorDesign/src/ArduinoMotor/setup.py" \
    build --build-base "/home/nvidia/SeniorDesign/build/ArduinoMotor" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/nvidia/SeniorDesign/install" --install-scripts="/home/nvidia/SeniorDesign/install/bin"
