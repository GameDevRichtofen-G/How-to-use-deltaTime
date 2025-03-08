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
![Description](https://github.com/GameDevRichtofen-G/How-to-use-deltaTime/blob/main/Example_fd.gif))

in frame dependent we won't use deltaTime and update our carX by 15 block each frame.
```python
    self.x = (self.x + 15) % 10
```

```python
import time #-> import time
import os # -> use for reducing cpu overuse

# making a simple car class
class Car():
    def __init__(self, x, shape):
        self.x = x
        self.shape = shape

    def Update(self, DeltaTime, Use_delta_Time):
        self.x = (self.x + (15 * DeltaTime if Use_delta_Time else 1)) % 10 #->Update the car position by 15 block(in this case we say if Use_delta_time was true then we times it 15 or our speed,
        #in this case we won't use deltaTime)


Test_car = Car(0, "[[]]")  # -> making a car class
Test_car2 = Car(0, "[[]]") # -> making another car class


last_frame_60 = time.time() # -> getting the time that has passed for 60 frame
last_frame_15 = time.time()# -> getting the time that has passed  for 60 frame

FRAME_TIME_60 = 1 / 60  # -> getting the the frame time for 60 fps, in other word somewhere like 0.016
FRAME_TIME_15 = 1 / 15  # -> getting the the frame time for 15 fps in other word somewhere like 0.66

while True: #Our update loop
    current_time = time.time() # -> getting the current time

    
    if current_time - last_frame_60 >= FRAME_TIME_60: # -> saying if our elpased time was bigger or equal than our frame time(0.016) then calculate deltatIME for 60 fps and update the first car
       
        deltaTime_60 = current_time - previous_frame_60 #getting the delta_time for 60 frame
        last_frame_60 = current_time # -> store our current time in last frame
        Test_car.Update(deltaTime_60, False)  # -> update the first car without deltaTime

    
    if current_time - last_frame_15 >= FRAME_TIME_15: # -> saying if our elpased time was bigger or equal than our frame time(0.016) then calculate deltatIME for 15 fps and update the second car
        deltaTime_15 = current_time - last_frame_1 5#getting the delta_time for 15 frame
        last_frame_15 = current_time # -> store our current time in last frame
        Test_car2.Update(deltaTime_15, False)  # -> update the second car without deltaTime

    #clear the terminal
    os.system("cls" if os.name == "nt" else "clear") 

    #make 2 list which I use them for our game scene
    Road = ['-'] * 10
    Road2 = ['-'] * 10

    #make the x index where test_car x position is equal, to test_car.shape
    Road[int(Test_car.x)] = Test_car.shape
    Road2[int(Test_car2.x)] = Test_car2.shape

    #render both cars
    print("Test_car  (60 FPS):", ''.join(Road))
    print("Test_car2 (15 FPS):", ''.join(Road2))

    #stoping the cpu overuse
    time.sleep(0.005)
   
```


# Frame independent :

![Description](https://raw.githubusercontent.com/GameDevRichtofen-G/How-to-use-deltaTime/refs/heads/main/Example_fI.gif))

in frame independent we will use deltaTime to make both cars move in equal speed regardless of their current fps.

```python
    self.x = (self.x + 15 * DeltaTime) % 10
```


```python
import time #-> import time
import os # -> use for reducing cpu overuse

# making a simple car class
class Car():
    def __init__(self, x, shape):
        self.x = x
        self.shape = shape

    def Update(self, DeltaTime, Use_delta_Time):
        self.x = (self.x + (15 * DeltaTime if Use_delta_Time else 1)) % 10 #->Update the car position by 15 block(in this case we say if Use_delta_time was true then we times it 15 or our speed,
        #in this case we won't use deltaTime)


Test_car = Car(0, "[[]]")  # -> making a car class
Test_car2 = Car(0, "[[]]") # -> making another car class


last_frame_60 = time.time() # -> getting the time that has passed for 60 frame
last_frame_15 = time.time()# -> getting the time that has passed  for 60 frame

FRAME_TIME_60 = 1 / 60  # -> getting the the frame time for 60 fps, in other word somewhere like 0.016
FRAME_TIME_15 = 1 / 15  # -> getting the the frame time for 15 fps in other word somewhere like 0.66

while True: #Our update loop
    current_time = time.time() # -> getting the current time

    
    if current_time - last_frame_60 >= FRAME_TIME_60: # -> saying if our elpased time was bigger or equal than our frame time(0.016) then calculate deltatIME for 60 fps and update the first car
       
        deltaTime_60 = current_time - previous_frame_60 #getting the delta_time for 60 frame
        last_frame_60 = current_time # -> store our current time in last frame
        Test_car.Update(deltaTime_60, True)  # -> update the first car with deltaTime

    
    if current_time - last_frame_15 >= FRAME_TIME_15: # -> saying if our elpased time was bigger or equal than our frame time(0.016) then calculate deltatIME for 15 fps and update the second car
        deltaTime_15 = current_time - last_frame_1 5#getting the delta_time for 15 frame
        last_frame_15 = current_time # -> store our current time in last frame
        Test_car2.Update(deltaTime_15, True)  # -> update the second car with deltaTime

    #clear the terminal
    os.system("cls" if os.name == "nt" else "clear") 

    #make 2 list which I use them for our game scene
    Road = ['-'] * 10
    Road2 = ['-'] * 10

    #make the x index where test_car x position is equal, to test_car.shape
    Road[int(Test_car.x)] = Test_car.shape
    Road2[int(Test_car2.x)] = Test_car2.shape

    #render both cars
    print("Test_car  (60 FPS):", ''.join(Road))
    print("Test_car2 (15 FPS):", ''.join(Road2))

    #stoping the cpu overuse
    time.sleep(0.005)
   
```

Great, now we completely understand why it is so important to use deltaTime. 
But there are some things that you need to notice.These things can help you understand deltaTime better :

# Never use deltaTime on variables that get direct value :
Using a deltaTime on variables that will get direct value on a point of time is huge mistake,
The thing is you should always use deltaTime on variables that are getting change on point of time.
For example if you have character moving in x axis with speed 100 then we need to use deltaTime to make
speed frame independent :
```python
    player.position.x  = player.position.x + (speed * deltaTime)
```
this way is totally fine, but if you change player position directly and used deltaTime, it would be a mistake:
```python
    player.position.x = 10 * deltaTime#Dont do this

    #Except do this :
    player.position.x = 10
```

# Make your vairables fixed :

sometimes when we use deltaTime, if we assume our speed is 100 in 60 fps
we want same speed in 15 fps. the problem is if multipy it with deltaTime.
our speed in 60 fps will decrease to match same speed as 15 speed. sometimes,
we want speed of 15 be same as speed of 60, or speed 150 fps be same as 60.
in other word rather than decreasing speed of 60 fps we increase the speed
of fps 15 to match the speed of fps 60:

the formula to this is so simple :
```python
    player.position.x = player.position.x + (100 * (DeltaTime * (1/60)))
```
this ensures that speed(which is 100) stays the same in all other frame rates
Result : 

## 60 Frame-Normal:
![Description](https://github.com/GameDevRichtofen-G/How-to-use-deltaTime/blob/main/60_sec_fix.gif?raw=true))

## 15 Frame-NotFixed
![Description](https://github.com/GameDevRichtofen-G/How-to-use-deltaTime/blob/main/15_sec_no_fix.gif))

## 15 Frame-Fixed
![Description](https://github.com/GameDevRichtofen-G/How-to-use-deltaTime/blob/main/15_sec_fix.gif))
