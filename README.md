# CS 202 Semester Project
## Programming Team 35
#### Members:
###### Huy Tran, Lauren Feldman
#### Responsibilities:
###### Huy Tran: Reading in wav files, and wav processors.
###### Lauren Feldman: User interaction and input management.
#### Design
###### The design concept was to create a wave file reader in Wav class that properly read in files and its respective attributes and then pass that information into the other classes. Then the user interface would read the input of the user and call the proper processor classes based on the input for processing. Once that information is processed, the User interface would prompt the user if they would like to edit the meta data of a file, and then take care of these changes. Lastly, prompting if a CSV file is wanted before passing all the inputs back to the Wav class to write to a new file.
#### Challenges:
###### The biggest challenge of this entire project was definitely the communication in the group. With a member being completely missing and poorly coordinated meetings led to poor relations between the different roles of the projects. Additionally, while the concepts of reading and processing audio file appeared simple enough, the implementation that was required was quite the uphill battle. Another challenge was understanding how different types of data needed to be interpreted and processed differently, especially with the mixing of what data is allocated to the heap vs the stack made the project a task of data management difficult. Overall, the main challenge was working cohesively as a group and implementing the concepts of the data, leading to complications that needed to be addressed in different parts further down the line
