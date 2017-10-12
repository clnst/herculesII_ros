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

#include <hercules_base/hercules_base_node.h>


void HerculesBase::base_cb(const hercules_msgs::BaseOdomConstPtr& msg)
{
    //set the odometry
    odom.header.stamp = msg->header.stamp;
    odom.header.frame_id = frame_id;
    odom.child_frame_id = child_frame_id;

    odom.pose.pose.position.x = msg->pose.position.x;
    odom.pose.pose.position.y = msg->pose.position.y;
    odom.pose.pose.position.z = msg->pose.position.z;

    odom.pose.pose.orientation.x = msg->pose.orientation.x;
    odom.pose.pose.orientation.y = msg->pose.orientation.y;
    odom.pose.pose.orientation.z = msg->pose.orientation.z;
    odom.pose.pose.orientation.w = msg->pose.orientation.w;

    odom.twist.twist.linear.x = msg->twist.linear.x;
    odom.twist.twist.linear.y = msg->twist.linear.y;
    odom.twist.twist.linear.z = msg->twist.linear.z;

    odom.twist.twist.angular.x = msg->twist.angular.x;
    odom.twist.twist.angular.y = msg->twist.angular.y;
    odom.twist.twist.angular.z = msg->twist.angular.z;

    //set the tf
    tf.header.stamp = msg->header.stamp;
    tf.header.frame_id = frame_id;
    tf.child_frame_id = child_frame_id;

    tf.transform.translation.x = msg->pose.position.x;
    tf.transform.translation.y = msg->pose.position.y;
    tf.transform.translation.z = msg->pose.position.z;

    tf.transform.rotation.x = msg->pose.orientation.x;
    tf.transform.rotation.y = msg->pose.orientation.y;
    tf.transform.rotation.z = msg->pose.orientation.z;
    tf.transform.rotation.w = msg->pose.orientation.w;
}

HerculesBase::HerculesBase(void)
{
    //Init node
    ROS_ASSERT(init());
}

HerculesBase::~HerculesBase(void)
{
}

bool HerculesBase::init(void)
{
    ros::param::get("~frame_id", frame_id);
    ros::param::get("~child_frame_id", child_frame_id);
    ros::param::get("~pub_topic", pub_topic);
    ros::param::get("~sub_topic", sub_topic);

    odom_pub = nh.advertise<nav_msgs::Odometry>(pub_topic, 100);
    base_sub  = nh.subscribe(sub_topic, 100,  &HerculesBase::base_cb, this);

    return true;
}

bool HerculesBase::update(void)
{
    odom_pub.publish(odom);
    tb.sendTransform(tf);

    return true;
}

/*******************************************************************************
* Main function
*******************************************************************************/
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "hercules_base");
    HerculesBase base;
    ros::Rate rate(10);

    while (ros::ok())
    {
        base.update();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}