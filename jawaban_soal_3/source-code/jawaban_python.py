import tkinter as tk

# Membuat instance dari Tkinter
root = tk.Tk()
root.title("Contoh GUI")

# Membuat label
label = tk.Label(root, text="Hello, World!")
label.pack()

# Membuat tombol
def on_button_click():
    label.config(text="Tombol diklik!")

button = tk.Button(root, text="Klik Saya", command=on_button_click)
button.pack()

# Menjalankan aplikasi
root.mainloop()
