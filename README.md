# What is ``deltaTime``
Delta time is one of the useful variables in game development. This variable can sometimes be refer as many different names like 
ElpasedTime, TimeStep, FrameTime and etc. In general, deltaTime displays the amount time that has passed from X1frame to X2frame.

## Example(Python) : 
```python
#How to add deltaTime
import time # -> first we import a libary that can give us the time that has passed since application has started

last_frame = time.time() # -> here we will make a variable to store the latest time that has passed

while True: #-> we will make a running loop to update application
    current_frame = time.time() # -> we will get latest time that has passed since the application has started
    deltaTime = current_frame  # -> last_frame #-> We minus our current frame time with and our last frame time to get the elpasedTime or DeltaTime
    last_frame = current_frame # -> we will store our current frame time in last frame time for next loop
    
    print(f"Delta Time: {deltaTime:.6f} seconds") # -> debugging 
    time.sleep(0.016) # -> we will use this to simulate 60 frame 
```

Now that we know where we can use deltaTime it is good to know where we can use it.

# Where to use ``deltaTime``

In game development, we usually use deltaTime to make something frame independent. And when we talk about frame independent, 
we will try to make that X-thing do Y task regardless of what is the frame rate. that means even if the application frame rate
is 15 it should not make any difference with application that has 60 frame rate.

The most common usuage of deltaTime is when we want to make sure player speed is frame independent. means regardless of what 
frame rate is, player speed would always be the same. Below is an example of frame dependent and frame independent scenario :

# Frame dependent :
![Description](https://.gif)

in frame dependent we won't use deltaTime and update our carX by 15 block each frame.
```python
    self.x = (self.x + 15) % 10
```
This will result in this :


```python
import time  # -> first we import a libary that can give us the time that has passed since application has started
import os # -> to clear the terminal

# creating a car class
class Car():

    def __init__(self,x,Shape):
        self.x = x
        self.shape = Shape

    def Update(self,DeltaTime,Use_delta_Time): #->making an update function
        #Use_delta_Time : we will use this to say whether use deltaTime or not
        self.x = (self.x + (15  * DeltaTime if Use_delta_Time else 1)) % 10 -> move the car and return it to 0 when greater than 10
       

previous_frame = time.time()
Test_car = Car(0,"[[]]")
Test_car2 = Car(0,"[[]]")


while True :
    current_frame = time.time()
    deltaTime = current_frame - previous_frame
    previous_frame = current_frame
    Road = ['-'] * 10
    Road2 = ['-'] * 10

    Road[int(Test_car.x)] = Test_car.shape
    Road2[int(Test_car2.x)] = Test_car2.shape
    print(''.join(Road))
    time.sleep(0.016)
    print(''.join(Road2))
    time.sleep(0.0667)
    Test_car.Update(deltaTime,True)
    Test_car2.Update(deltaTime,False)
    os.system("cls" if os.name == "nt" else "clear")
   
```

