from tkinter import *
from tkinter import messagebox

window = Tk()
window.title("BMI Calculator")
window.geometry("330x190")

font1=("Comic Sans MS",16,"normal")
font2=("Comic Sans MS",18,"bold")

kg_var = StringVar()
cm_var = StringVar()

def CalMessage():
    kg = float(weight_et.get())
    cm = float(height_et.get())
    m = cm/100
    BMI = kg/(m*m)
    BMI = float("{:.2f}".format(BMI))
    if BMI == 0:
        return messagebox.showwarning("Warning",f" Your BMI is {BMI}")
    elif BMI <= 18.5:
        return messagebox.showinfo("BMI Calculator",f" Your BMI is {BMI} and you are underweight")
    elif BMI >= 18.5 and BMI <= 22.9:
        return messagebox.showinfo("BMI Calculator",f" Your BMI is {BMI} and you are normal")
    elif BMI >= 23 and BMI <= 24.9:
        return messagebox.showinfo("BMI Calculator",f" Your BMI is {BMI} and you are overweight")
    elif BMI >= 25 and BMI <= 29.9:
        return messagebox.showinfo("BMI Calculator",f" Your BMI is {BMI} and you are obese")
    elif BMI >= 30:
        return messagebox.showinfo("BMI Calculator",f" Your BMI is {BMI} and you are extremely obese")

def DelMessage():
    kg_var.set("")
    cm_var.set("")

Label(text = "BMI Calculator",font = font2).grid(row=0,column=1)
Label(text = "").grid(row=1,column=1)

Label(text = "Input weight",font = font1).grid(row = 2)
weight_et = Entry(textvariable = kg_var)
weight_et.grid(row=2,column=1)

Label(text = "Input height",font = font1).grid(row = 3)
height_et = Entry(textvariable = cm_var)
height_et.grid(row=3,column=1)

Button(text = "Calculate", command = CalMessage).grid(row = 4,column = 1)
Button(text = "Delete", command = DelMessage).grid(row = 5,column = 1)

mainloop()