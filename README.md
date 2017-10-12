# herculesII_ros
HerculesII is a small, low cost, fully programmable, ROS­ based mobile robot. It is intended to be used for the purpose of education, research, product prototyping, and hobby application.

The goal of the HerculesII is to drastically reduce the size and the price of the platform without sacrificing capability, functionality, and quality. Since the additional options, such as the chassis, the computers, and the sensors, are available, the HerculesII can be customized in various ways. The HerculesII is willing to be in the center of the maker movement by applying the latest technical advances of the SBC(Single­Board Computer), the Depth sensor, and so on.


# Instruction

- Software tools:     PyCharm(2017+)

- Hardware tools:     MacBook Pro(2015)

- Operating system:   Ubuntu 16.04

- Ros version:        kinetic


# Support applications
- xf_voice(tts)


# Support peripherals

- kinect(v1), rplidar(v1/v2), joystick(betop), arduino(due)


# Documents

- http://www.clnst.com/


# Install ros(Kinetic) for ubuntu

- sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

- sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116

- sudo apt-get update

- sudo apt-get install ros-kinetic-desktop-full

- sudo rosdep init

- rosdep update

- sudo apt-get install python-rosinstall python-rosinstall-generator python-wstool build-essential

- echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc

- source ~/.bashrc


# Install packages for ros

- sudo apt-get install ros-kinetic-hector-slam

- sudo apt-get install ros-kinetic-slam-gmapping

- sudo apt-get install ros-kinetic-map-server

- sudo apt-get install ros-kinetic-joystick-drivers

- sudo apt-get install ros-kinetic-amcl

- sudo apt-get install ros-kinetic-move-base

- sudo apt-get install ros-kinetic-dwa-local-planner

- sudo apt-get install ros-kinetic-openni-camera

- sudo apt-get install ros-kinetic-openni-launch

- sudo apt-get install ros-kinetic-rgbd-launch

- sudo apt-get install ros-kinetic-depthimage-to-laserscan

- sudo apt-get install ros-kinetic-rosserial-arduino
    (notic: modify "/opt/ros/kinetic/share/rosserial_arduino/src/ros_lib/ArduinoHardware.h" for arduino due)
    - 72:   /* Leonardo support */
    -       --- iostream = &Serial1;
    -       +++ iostream = &Serial;

- sudo apt-get install ros-kinetic-rosserial


# Install tools for herculesII

- sudo apt-get install apache2

- sudo apt-get install php7.0

- sudo apt-get install libapache2-mod-php7.0

- sudo apt-get install chrony

- sudo apt-get install tree

- sudo apt-get install cutecom


# Usage method

- roslaunch hercules hercules.launch