from tkinter import *
from tkinter import messagebox

window = Tk()
window.title('Test MessageBox')
window.geometry('300x200')

font1=('Tahoma',16,'bold')
Label(text='Messagebox Test',font=font1).pack(pady=10)

def Firstbtn_click():
    messagebox.showinfo('Show Information','Test message')

def Secondbtn_click():
    answer = messagebox.askquestion('Exit?','Exit(yes/no)')
    if answer == 'yes':
        window.destroy()

btn1 = Button(text='First Button',font=font1,command=Firstbtn_click).pack(pady=10)
btn2 = Button(text='Second Button',font=font1,command=Secondbtn_click).pack(pady=10)

mainloop()