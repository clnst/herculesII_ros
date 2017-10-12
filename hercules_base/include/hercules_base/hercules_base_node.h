/*******************************************************************************
* Copyright 2017 CLNST CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef __HERCULES_BASE_H__
#define __HERCULES_BASE_H__

#include <ros/ros.h>
#include <tf/tf.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Vector3.h>
#include <tf/transform_broadcaster.h>
#include <hercules_msgs/BaseOdom.h>

class HerculesBase{
public:
    HerculesBase(void);
    ~HerculesBase(void);

    bool init(void);
    bool update(void);

private:
    ros::NodeHandle nh;
    ros::Publisher odom_pub;
    ros::Subscriber base_sub;
    tf::TransformBroadcaster tb;

    std::string frame_id;
    std::string child_frame_id;

    std::string pub_topic;
    std::string sub_topic;

    nav_msgs::Odometry odom;
    geometry_msgs::TransformStamped tf;

    void base_cb(const hercules_msgs::BaseOdomConstPtr& msg);
};


#endif // __HERCULES_BASE_H__