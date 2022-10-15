from tkinter import *
from tkinter import ttk
from tkinter import messagebox

window = Tk()
window.title('Select Your Birthday')
window.geometry("790x100")
window.config(bg='aqua')

window.option_add("*Font","redwing 16")
month = ['January','February','March','April','May','June','July','August','September','October','November','December']

day = ttk.Combobox(window,value=list(range(1,32)))
day.grid(row=0,column=0)

monthly = ttk.Combobox(window,value=month)
monthly.grid(row=0,column=1)

year = ttk.Combobox(window,value=list(range(1980,2023)))
year.grid(row=0,column=2)

def count():
    print(day.get(),monthly.get(),year.get())

bt = Button(text='enter',font='redwing 16 bold',fg='white',bg='teal',command=count).grid(row=2,column=1,pady=20)
window.mainloop()