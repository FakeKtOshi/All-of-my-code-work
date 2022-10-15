from tkinter import *

window = Tk()
window.title("Data Entry")
window.geometry('300x200')

font1 = ('tahoma',10,'bold')

Label(text='ชื่อ',font=font1).grid(row=0)
Label(text='นามสกุล',font=font1).grid(row=1)
Label(text='เลขประจำตัวนักเรียน',font=font1).grid(row=2)

et1=Entry()
et1.grid(row=0,column=1)
et1.insert(0,'')
et1.config(font=font1)

et2=Entry()
et2.grid(row=1,column=1)
et2.insert(0,'ลี้ตระกูล')
et2.config(font=font1)

et3=Entry()
et3.grid(row=2,column=1)
et3.insert(0,'37608')
et3.config(font=font1)

def deleteText():
    et1.delete(0,END)
    et2.delete(0,END)
    et3.delete(0,END)

button=Button(text='ล้างข้อมูล',font=font1,command = deleteText).grid(row=3,column=1)

mainloop()