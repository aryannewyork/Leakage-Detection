
# Real-Time water leakage detection

[Demonstration Video](https://youtu.be/I_OcQwL6Ua4)

The vibrations in the pipe are measured using a vibration sensor which is attached to a programmed Arduino board to facilitate collection and transfer of real-time data to a computer and then after the data points are collected they are ran through the Machine learning algorithm and upon superimposing a calibrated curve (having 2 regions, red and green denoting leak and no-leak regions), if the majority of data points lie in the red region then there is a possibility of a leak and it grows as the percentage of points grow in the red region.
This is measured simply by taking the euclidean distance between the interface line of calibration curve and each individual point.



## Authors

- [Aryan Shukla](https://www.github.com/aryanewyork)
- [Mohammad Touseef](https://www.github.com/Touseef-md)
- [Akanksha Saini](https://github.com/Akanksha030)




