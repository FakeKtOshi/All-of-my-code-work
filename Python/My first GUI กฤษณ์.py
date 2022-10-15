from tkinter import *

window = Tk()

window.title('My frist GUI')
window.geometry('500x500')
window.config(bg = 'white')

Lb_main = Label(text = 'Hello World',fg = 'Black',bg = 'white',font = 'smile 30 bold').grid(row = 0,column = 1)

def BT_red():
    Label(text = 'Hello World',fg = 'red',bg = 'white',font = 'smile 30 bold').grid(row = 2,column = 4)
def BT_yellow():
    Label(text = 'Hello World',fg = 'yellow',bg = 'white',font = 'smile 30 bold').grid(row = 3,column = 4)
def BT_blue():
    Label(text = 'Hello World',fg = 'blue',bg = 'white',font = 'smile 30 bold').grid(row = 4,column = 4)
def BT_purple():
    Label(text = 'Hello World',fg = 'purple',bg = 'white',font = 'smile 30 bold').grid(row = 5,column = 4)

BT_red = Button(text = 'red',bg = 'red',fg = 'white',command = BT_red).grid(row = 2,column = 1)
BT_yellow = Button(text = 'yellow',bg = 'yellow',fg = 'black',command = BT_yellow).grid(row = 3,column = 1)
BT_blue = Button(text = 'blue',bg = 'blue',fg = 'white',command = BT_blue).grid(row = 4,column = 1)
BT_purple = Button(text = 'purple',bg = 'purple',fg = 'white',command = BT_purple).grid(row = 5,column = 1)


window.mainloop()