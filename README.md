# Introduction
ROS (Robot Operating System) is an open-source platform widely used in Robotics. For developers and researchers, ROS provides plenty of open-source tools and packages. <br>
If you want to know about Robotics, which is an interesting researching area in Compute Science, you might want to get familiar with ROS first. It could provides Robot simulation, open-source algorithm demos and easily implementation of you ideas with open-source tools. 

# Pre-requests
Before you start working on this project, you should:
- Be familiar with at least one programming language. (Unfortunately, currently ROS only support Python2/C++). 
- Know the basic concepts of ROS system, including:
	+ Topic
	+ Node
	+ Message
	+ Publisher and subscriber
	+ Bag
	+ ...
- [The tutorial of ROS](http://wiki.ros.org/ROS/Tutorials)

# Project Description
SLAM is an important part in Robotics. This project provides you an opportunity to use [BLAM (Berkeley Localization And Mapping)](https://github.com/erik-nelson/blam) for 3D mapping, as a beginner-level introduction to the Robotics.
The algorithm takes 3D pointclouds as input, and build a sparse 3D PointCloud Map. 
## Part 1: use BLAM to build 3D map
- refer to https://github.com/erik-nelson/blam for installation
- Note that some file in the current framework is wrong (cause compile error), you might need to change those files.

## Part 2: save the pointcloud
You need to write a simple tool to save the resulting pointcloud. An solution code is provided in the source code.

## Part 3: view the pointcloud
Cloudcompare, the open-source tool is able to visualize the pointcloud, you might find it helpful.

## Part 4: improve the pointcloud quality
As you might have noticed, the pointcloud contains some outliners. You might be interested in removing those outliners. An option is to use PCL library for doing this. A simple out-liner removal program is provided in the source code.

# FAQ
- Q: I'm not sure whether I meet the programming pre-requests. <br>
A: Refer to other questions first. You should pass the median level of the programming first.
- Q: How to get basic concepts of ROS?<br>
A: Refer to ROS official tutorial, beginner level tutorial should be sufficient enough. The tutorial is available [here](http://wiki.ros.org/ROS/Tutorials).