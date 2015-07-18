#!/bin/bash

roscore &
yarpserver --ros &
yarp wait /root
iCub_SIM &
yarp wait /icubSim/face/eyelids
iKinGazeCtrl --from configSim.ini &
yarp wait /iKinGazeCtrl/angles:o
yarpidl_rosmsg --name /typ@/yarpidl
