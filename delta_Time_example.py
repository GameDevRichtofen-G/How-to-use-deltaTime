import time
import os

class Car():
    def __init__(self, x, shape):
        self.x = x
        self.shape = shape

    def Update(self, DeltaTime, Use_delta_Time):
        self.x = (self.x + (15 * DeltaTime if Use_delta_Time else 1)) % 10


Test_car = Car(0, "[[]]")  
Test_car2 = Car(0, "[[]]") 


previous_frame_60 = time.time()
previous_frame_15 = time.time()

FRAME_TIME_60 = 1 / 60  
FRAME_TIME_15 = 1 / 15 

while True:
    current_time = time.time()

    
    if current_time - previous_frame_60 >= FRAME_TIME_60:
        deltaTime_60 = current_time - previous_frame_60
        previous_frame_60 = current_time
        Test_car.Update(deltaTime_60, True)  

    
    if current_time - previous_frame_15 >= FRAME_TIME_15:
        deltaTime_15 = current_time - previous_frame_15
        previous_frame_15 = current_time
        Test_car2.Update(deltaTime_15, True)  


    os.system("cls" if os.name == "nt" else "clear") 


    Road = ['-'] * 10
    Road2 = ['-'] * 10

    Road[int(Test_car.x)] = Test_car.shape
    Road2[int(Test_car2.x)] = Test_car2.shape

    
    print("Test_car  (60 FPS):", ''.join(Road))
    print("Test_car2 (15 FPS):", ''.join(Road2))

    
    time.sleep(0.005)