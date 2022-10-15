from tkinter import *
from tkinter import messagebox

window = Tk()
window.title("Circle Area Calculator")
window.geometry("400x200")

font1=("Comic Sans MS",16,"normal")
font2=("Comic Sans MS",18,"bold")

radius_var = StringVar()

def CalMessage():
    radius = float(radius_et.get())
    Circle = (22/7)*(radius*radius)
    Circle = float("{:.2f}".format(Circle))
    if Circle == 0:
        return messagebox.showwarning("Warning",f" Your Circle area is {Circle}")
    elif Circle < 0.1:
        return messagebox.showwarning("Warning",f" Your Circle area is {Circle}")
    elif Circle >= 0.1:
        return messagebox.showinfo("Circle Calculator",f" Your Circle area is {Circle}")

def DelMessage():
    radius_var.set("")

Label(text = "Circle Area Calculator",font = font2).grid(row=0,column=1)
Label(text = "").grid(row=1,column=1)

Label(text = "Input radius",font = font1).grid(row = 2)
radius_et = Entry(textvariable = radius_var)
radius_et.grid(row=2,column=1)

Button(text = "Calculate", command = CalMessage).grid(row = 3,column = 1)
Button(text = "Delete", command = DelMessage).grid(row = 4,column = 1)

mainloop()